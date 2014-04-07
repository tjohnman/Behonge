Behonge
=======

SFML boilerplate code for Ludum Dare.
It's a simple state system. Events and draw and update calls are passed down from the main loop to the current game state. States are stored in stack form. States pass calls down to objects, which may or may not have children. Objects are to be subclassed, but feature attachable behaviors.

All the header files are plentifully commented.

Comes with SFML 2.1 static Windows binaries and required DLL files. Everything compiled with CodeBlocks/MinGW, so you might need to get your own binaries for development if your environment varies.

####Disclaimer

Not guaranteed to even work, not to mention not setting your computer on fire.

This code was very hastily cobbled together and is intended as a personal way of having boilerplate stuff already in place for prototyping, Ludum Dares and whatnot. It is intended to be cut, modified or expanded as needed, not as a production framework. Performance, good coding practices and even functionality are **not** guaranteed.

Suggestions and comments are welcome, but please keep the above in mind when doing so.

The code (not including external libraries) is public domain.
