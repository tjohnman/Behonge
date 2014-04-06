#include "Object.h"

Object::Object(int x, int y)
{

}

Object::~Object()
{

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
