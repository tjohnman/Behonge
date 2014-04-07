#include "includes.h"

#ifndef ROOT_H
#define ROOT_H

/*
**
**	This is a singleton that manages the game loop.
**	Fill it with your code and dreams.
**
**	Use the static Root::Instance() to get a pointer.
**
*/

class State;

class Root
{
public:
	~Root();

	/*
		Called every time the application receives an event.
		However, by default the main loop captures sf::Event::Close
		and closes the application.
	*/
	void onEvent(const sf::Event & event);

	/*
		Called every frame.
	*/
	void draw(sf::RenderWindow * window);

	/*
		Called every frame.
	*/
	void update(float delta);

	/*
		Put a state on top of the stack. If force is true,
		it will be stacked even if the same instance is already
		on top of the stack.
	*/
	void pushState(State * state, bool force = false);

	/*
		Pop a state from the stack. Returns the removed state
		if succeded, otherwise returns NULL.
	*/
	State * popState();

	/*
        Empties the state stack and _deletes_
        all the states that were in it.
	*/
	void clearStateStack();

	/*
		Use this to access the singleton.
	*/
	static Root * Instance();

	bool m_Done;

private:
	Root();
	std::vector<State *> _m_StateStack;
	static Root * _s_Instance;
};

#endif // ROOT_H
