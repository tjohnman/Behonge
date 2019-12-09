#include "State.h"
#include "Object.h"

bool State::onEvent(const sf::Event & event)
{
	for(unsigned int i=0; i<_m_Objects.size(); ++i)
	{
		if(_m_Objects[i]->onEvent(event)) return true;
	}
	return false;
}

void State::draw(sf::RenderTarget * renderTarget)
{
	for(unsigned int i=0; i<_m_Objects.size(); ++i)
	{
		_m_Objects[i]->draw(renderTarget);
	}
}

void State::update(double delta)
{
	for(unsigned int i=0; i<_m_Objects.size(); ++i)
	{
		_m_Objects[i]->update(delta);
	}
}

Object * State::add(Object * object)
{
	for(unsigned int i=0; i<_m_Objects.size(); ++i)
	{
		if(_m_Objects[i] == object) return 0;
	}
	_m_Objects.push_back(object);
	return object;
}

Object * State::remove(Object * object)
{
	for(unsigned int i=0; i<_m_Objects.size(); ++i)
	{
		if(_m_Objects[i] == object)
		{
			for(unsigned int j=i; j<_m_Objects.size()-1; ++j)
			{
				_m_Objects[j] = _m_Objects[j+1];
			}
			_m_Objects.pop_back();
			return object;
		}
	}

	return object;
}

