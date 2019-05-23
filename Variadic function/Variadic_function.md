
Variadic function

In mathematics and in computer programming, a variadic function is a function of indefinite arity, i.e., 
   -one which accepts a variable number of arguments. 
   Support for variadic functions differs widely among programming languages.

There are many mathematical and logical operations that come across naturally as variadic functions. For instance, the summing of numbers or the concatenation of strings or other sequences are operations that can logically apply to any number of operands.

        #include <iostream>
        #include <string>


        template<typename... Args>
        auto adder(Args... args) {
          return (... + args);
          // or (args + ...)
        }

        int main(){
          long sum = adder(1, 2, 3, 8, 7);
          std::cout << sum << std::endl; // 21

          std::string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
          std::string ssum = adder(s1, s2, s3, s4);

          std::cout << ssum << std::endl; //xaabbyy
        }
