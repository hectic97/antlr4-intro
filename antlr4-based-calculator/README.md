# ANTLR4-based-calculator

## Development Environments

OS: Ubuntu 20.04.1 LTS<br>
Compiler: g++ 9.3.0<br>
Parser: ANTLR 4.8<br>
Programming language: C++11<br>

## Description
ANTLR4 based calculator <br>
### feature
the four arithmetical operations<br>
Use Parentheses to specify the order of calculation<br>
Assign values to variable<br>

## How to use

$ make<br>
$ ./expreval input.txt

## Test

$ cat input.txt<br>
a = -100;<br>
a + -2.1 * 34;<br>
10 * (+5.0/2);<br>
a = +30;<br>
a * a;<br>
$ ./expreval input.txt<br>
-171.4<br>
25.0<br>
900.0<br>

