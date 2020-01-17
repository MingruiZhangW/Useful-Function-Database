# The C++ mutable lambda expressions as stateful function objects

https://www.nextptr.com/question/a195007104/the-cplusplus-mutable-lambda-expressions-as-stateful-function-objects

```
int x = 0;
auto foo = [x] () mutable { 
    /* "x" cannot be modified without 
         keyword mutable. */
     x++; 
     return x;
};
```

https://isocpp.org/wiki/faq/cpp14-language#lambda-captures
