# Const member functions in C++

A function becomes const when const keyword is used in function’s declaration. 
The idea of const functions is not allow them to modify the object on which they are called. 
It is recommended practice to make as many functions const as possible so that accidental changes to objects are avoided.

- Following is a simple example of const function.

    #include<iostream> 
    using namespace std; 

    class Test { 
        int value; 
    public: 
        Test(int v = 0) {value = v;} 

    // We get compiler error if we add a line like "value = 100;" 
    // in this function. 
    int getValue() const {return value;}   
    }; 

    int main() { 
        Test t(20); 
        cout<<t.getValue(); 
        return 0; 
    } 
  
        Output:

        20

When a function is declared as const, 
it can be called on any type of object. Non-const functions can only be called by non-const objects.

For example the following program has compiler errors.

    #include<iostream> 
    using namespace std; 

    class Test { 
        int value; 
    public: 
        Test(int v = 0) {value = v;} 
        int getValue() {return value;} 
    }; 

    int main() { 
        const Test t; 
        cout << t.getValue(); 
        return 0; 
    } 

        Output:
        passing 'const Test' as 'this' argument of 'int 
        Test::getValue()' discards qualifiers
