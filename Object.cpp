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
		Behavior * b = _m_Behaviors.back();
		_m_Behaviors.pop_back();
		delete b;
	}
}

bool Object::onEvent(const sf::Event & event)
{
	for(unsigned int i=0; i<_m_Children.size(); ++i)
	{
		if(_m_Children[i]->onEvent(event)) return true;
	}
	return false;
}

void Object::draw(sf::RenderTarget * target)
{
	for(unsigned int i=0; i<_m_Children.size(); ++i)
	{
		_m_Children[i]->draw(target);
	}
}

void Object::update(float delta)
{
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
			delete object;
		}
	}
	return object;
}

void Object::attach(Behavior * behavior)
{
	_m_Behaviors.push_back(behavior);
	behavior->m_Object = this;
}

void Object::detach(std::string behaviorId)
{
	for(unsigned int i=0; i<_m_Behaviors.size(); ++i)
	{
		if(_m_Behaviors[i]->getId().compare(behaviorId))
		{
			Behavior * b = _m_Behaviors.back();
			_m_Behaviors.pop_back();
			delete b;
		}
	}
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
