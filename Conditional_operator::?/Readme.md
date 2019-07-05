# Conditional Operator ?

It works like this:

> (condition) ? true-clause : false-clause

It's most commonly used in assignment operations, although it has other uses as well. The ternary operator ? is a way of shortening an if-else clause, and is also called an immediate-if statement in other languages (IIf(condition,true-clause,false-clause) in VB, for example).
```
For example:

bool Three = SOME_VALUE;
int x = Three ? 3 : 0;
is the same as

bool Three = SOME_VALUE;
int x;
if (Three)
    x = 3;
else
    x = 0;
    ```
