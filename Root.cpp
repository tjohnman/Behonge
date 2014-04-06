#include "Root.h"
#include "State.h"

Root * Root::_s_Instance = 0;

Root::Root()
{

}

Root::~Root()
{

}

void Root::onEvent(const sf::Event & event)
{
	if(_m_StateStack.size())
	{
		_m_StateStack.back()->onEvent(event);
	}
}

void Root::draw(sf::RenderWindow * window)
{
	if(_m_StateStack.size())
		_m_StateStack.back()->draw(window);
}

void Root::update(float delta)
{
	if(_m_StateStack.size())
		_m_StateStack.back()->update(delta);
}

void Root::pushState(State * state)
{
	if(_m_StateStack.back() != state)
		_m_StateStack.push_back(state);
}

State * Root::popState()
{
	if(_m_StateStack.size())
	{
		State * s = _m_StateStack.back();
		_m_StateStack.pop_back();
		return s;
	}
	return 0;
}

void Root::clearStateStack()
{
	while(_m_StateStack.size())
	{
		delete popState();
	}
	_m_StateStack.clear();
}



// STATIC

Root * Root::Instance()
{
	if(!_s_Instance) _s_Instance = new Root();
	return _s_Instance;
}
