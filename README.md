Behonge
=======

SFML boilerplate code for Ludum Dare.
It's a simple state system. Events and draw and update calls are passed down from the main loop to the current game state. States are stored in stack form. States pass calls down to objects, which may or may not have children. Objects are to be subclassed, but feature attachable behaviors.

Comes with SFML 2.1 static Windows binaries and required DLL files.

Not guaranteed to even work, not to mention not setting your computer on fire.
