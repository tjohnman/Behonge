#include "includes.h"

#ifndef ROOT_H
#define ROOT_H

class State;

class Root
{
public:
	Root();
	~Root();

	void onEvent(const sf::Event & event);
	void draw(sf::RenderWindow * window);
	void update(float delta);

	void pushState(State * state);
	State * popState();
	void clearStateStack();

	static Root * Instance();

	bool m_Done;

private:
	std::vector<State *> _m_StateStack;
	static Root * _s_Instance;
};

#endif // ROOT_H
