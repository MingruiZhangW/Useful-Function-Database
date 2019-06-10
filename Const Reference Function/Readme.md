https://stackoverflow.com/questions/41469165/reference-sign-after-method-declaration-c
### Reference sign after method declaration c++

In what case is it benificial to declare a method or function using const& instead of just using const?<br/>
I know that using const is saying that this method does not modify the members of a class but what exactly happens when i add the reference sign after?

Example:

    int myclass::getInteger() const& {
        return theInt;
    }

Yes, this is a ref-qualified member function. The lvalue-reference notation on the right makes this function callable only on lvalues of myclass, that is:

    myclass c;
    c.getInteger(); // OK
    myclass{}.getInteger(); // Compile-time error
