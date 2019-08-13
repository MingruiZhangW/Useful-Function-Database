# Const reference and lvalue

- Question:
We cannot write ```int& ref = 40 ```because we need **lvalue** on right side.<br>
But we can write ```const int& ref = 40 ```. Why is this possible? 40 is rvalue instead lvalue<br>
I know that this is an exception but why?<br>

As Stroustrup says:

- The initializer for a const T& need not be an lvalue or even of type T. In such cases:

> [1] First, implicit type conversion to T is applied if necessary.

> [2] Then, the resulting value is placed in a temporary variable of type T.

> [3] Finally, this temporary variable is used as the value of the initializer.

So, when you type ```const int& ref = 40```, the temporary int variable is created behind the scenes, and ref is bound to this temporary variable.
