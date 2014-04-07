#include "Object.h"
#include "Behavior.h"

Object::Object()
{

}

Object::~Object()
{
	while(_m_Children.size())
	{
		Object * c = _m_Children.back();
		_m_Children.pop_back();
		delete c;
	}

	while(_m_Behaviors.size())
	{
		detach(_m_Behaviors.back()->getId());
	}
}

bool Object::onEvent(const sf::Event & event)
{
	bool eventWasCatched = false;

	for(unsigned int i=0; i<_m_Behaviors.size(); ++i)
	{
		eventWasCatched = _m_Behaviors[i]->onEvent(event, eventWasCatched);
	}

	if(eventWasCatched) return true;

	for(unsigned int i=0; i<_m_Children.size(); ++i)
	{
		if(_m_Children[i]->onEvent(event)) return true;
	}
	return false;
}

void Object::draw(sf::RenderTarget * target)
{
	for(unsigned int i=0; i<_m_Behaviors.size(); ++i)
	{
		if(_m_Behaviors[i]->m_FireOnDraw)
			_m_Behaviors[i]->draw(target);
	}

	for(unsigned int i=0; i<_m_Children.size(); ++i)
	{
		_m_Children[i]->draw(target);
	}
}

void Object::update(float delta)
{
	for(unsigned int i=0; i<_m_Behaviors.size(); ++i)
	{
		if(_m_Behaviors[i]->m_FireOnUpdate)
			_m_Behaviors[i]->update(delta);
	}

	for(unsigned int i=0; i<_m_Children.size(); ++i)
	{
		_m_Children[i]->update(delta);
	}
}

std::vector<Object *> * Object::getChildren()
{
	return &_m_Children;
}

Object * Object::add(Object * object)
{
	for(unsigned int i=0; i<_m_Children.size(); ++i)
	{
		if(_m_Children[i] == object) return 0;
	}
	_m_Children.push_back(object);
	return object;
}

Object * Object::remove(Object * object)
{
	for(unsigned int i=0; i<_m_Children.size(); ++i)
	{
		if(_m_Children[i] == object)
		{
			for(unsigned int j=i; j<_m_Children.size()-1; ++j)
			{
				_m_Children[j] = _m_Children[j+1];
			}
			_m_Children.pop_back();
		}
	}
	return object;
}

Behavior * Object::attach(Behavior * behavior)
{
	if(behavior->m_Object) return 0;

	_m_Behaviors.push_back(behavior);
	behavior->m_Object = this;
	behavior->onAttached();
	return behavior;
}

Behavior * Object::detach(std::string behaviorId)
{
	for(unsigned int i=0; i<_m_Behaviors.size(); ++i)
	{
		if(_m_Behaviors[i]->getId().compare(behaviorId) == 0)
		{

			Behavior * b = _m_Behaviors[i];

			b->onAboutToDetach();

			b->m_Object = 0;
			_m_Behaviors[i] = _m_Behaviors.back();
			_m_Behaviors.pop_back();
			return b;
		}
	}
	return 0;
}

float Object::getProperty(std::string propertyId)
{
	std::map<std::string, float>::iterator it;
	it = _m_Properties.find(propertyId);
	if(it == _m_Properties.end()) return 0.f;
	return it->second;
}

std::string Object::getString(std::string stringId)
{
	std::map<std::string, std::string>::iterator it;
	it = _m_Strings.find(stringId);
	if(it == _m_Strings.end()) return "";
	return it->second;
}

void Object::setProperty(std::string propertyId, float value)
{
	_m_Properties[propertyId] = value;
}

void Object::setString(std::string stringId, std::string string)
{
	_m_Strings[stringId] = string;
}
