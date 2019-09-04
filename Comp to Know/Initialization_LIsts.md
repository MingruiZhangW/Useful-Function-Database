# Initialization Lists And How It Functions

> Conventional wisdom is defined by the standard which claims that object's fields must be initialized before 
the constructor method's body is entered. So, if you don't initialize your members, 
C++ will do it for you, using default initialization. This is just wasteful, 
so initialization list should be the preferred way to initialize your members.

    An interesting side effect is that this implies, that if you make assignments to members in the constructor body, 
    you are not invoking their copy constructors, as you normally would in assignment to uninitialized objects, 
    but rather their copy assignment operators, as they are in fact already constructed for you.

https://www.quora.com/What-is-the-conventional-wisdom-in-choosing-between-initialization-lists-and-constructor-bodies-in-C++

### Initialization list always be processed before the constructor code

> If we do assignments in constructor, the actual members are already constructed (c++ does it) which is inefficient,
we can do it in Initialization list 

https://stackoverflow.com/questions/723973/will-the-initialization-list-always-be-processed-before-the-constructor-code

**One thing to note that, in QT, since a lot of objects needs a parent ("this" pointer) to construct, which may leads to a problem where "this" pointer is not fully initialized and being used by others
