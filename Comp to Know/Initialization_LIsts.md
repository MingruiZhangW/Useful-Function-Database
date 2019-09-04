# Initialization Lists And How It Functions

> Conventional wisdom is defined by the standard which claims that object's fields must be initialized before 
the constructor method's body is entered. So, if you don't initialize your members, 
C++ will do it for you, using default initialization. This is just wasteful, 
so initialization list should be the preferred way to initialize your members.

    An interesting side effect is that this implies, that if you make assignments to members in the constructor body, 
    you are not invoking their copy constructors, as you normally would in assignment to uninitialized objects, 
    but rather their copy assignment operators, as they are in fact already constructed for you.

Your argument is not ideally phrased, 
but I guess you could say that. 
Clients of your newly constructed object 
cannot tell the difference about whether you initialized your object with a list, 
or assigned the very same values in the constructor body. However, it is good practice, 
saves some processor cycles and looks more explicit, 
as it provides a single place where you will invoke all of your 
base class constructors and initialize all members - 
making sure that the order of initialization matches the order of declarations, 
all of which also tells the reader of your code that you have given much thought to how you want your object to be initialized, 
which is always a good thing,.

https://www.quora.com/What-is-the-conventional-wisdom-in-choosing-between-initialization-lists-and-constructor-bodies-in-C++
