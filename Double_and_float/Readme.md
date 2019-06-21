# Difference between Double and Float

As the name implies, a double has 2x the precision of float[1]. <br>
In general a double has 15 decimal digits of precision, while float has 7. <br>

Here's how the number of digits are calculated:<br>

> double has 52 mantissa bits + 1 hidden bit: log(253)÷log(10) = 15.95 digits

> float has 23 mantissa bits + 1 hidden bit: log(224)÷log(10) = 7.22 digits

This precision loss could lead to greater truncation errors being accumulated when repeated calculations are done, e.g.
```
float a = 1.f / 81;
float b = 0;
for (int i = 0; i < 729; ++ i)
    b += a;
printf("%.7g\n", b); // prints 9.000023
```
while
```
double a = 1.0 / 81;
double b = 0;
for (int i = 0; i < 729; ++ i)
    b += a;
printf("%.15g\n", b); // prints 8.99999999999996
```
Also, the maximum value of float is about 3e38, but double is about 1.7e308, so using float can hit "infinity" (i.e. a special floating-point number) much more easily than double for something simple, e.g. computing the factorial of 60.<br>

During testing, maybe a few test cases contain these huge numbers, which may cause your programs to fail if you use floats.<br>

Of course, sometimes, even double isn't accurate enough, hence we sometimes have long double[1] (the above example gives 9.000000000000000066 on Mac), but all floating point types suffer from round-off errors, so if precision is very important (e.g. money processing) you should use int or a fraction class.

Furthermore, don't use += to sum lots of floating point numbers, as the errors accumulate quickly. If you're using Python, use fsum. Otherwise, try to implement the Kahan summation algorithm.<br>

[1]: The C and C++ standards do not specify the representation of float, double and long double. It is possible that all three are implemented as IEEE double-precision. Nevertheless, for most architectures (gcc, MSVC; x86, x64, ARM) float is indeed a IEEE single-precision floating point number (binary32), and double is a IEEE double-precision floating point number (binary64).
