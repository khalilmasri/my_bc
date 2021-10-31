## my_bc

My bc is a basic calculator that can take input as an argument and return the result.

The project is using [lexeical analysis](https://en.wikipedia.org/wiki/Lexical_analysis) and then parsing the input using basic parser.

The method used to solve the input after parsing is [reversed polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation).

## Example
###### Input
` my_bc "1 + 2 * (3 - 42) % 5" `

###### Notation
` 1 2 3 42 - * 5 % + `

###### Output
> -2

## Description

A valid expression:
  - must only contain the operators +, -, *, /, and %
  - must only have integer values
  - can contain parentheses, but each group must be properly closed
  - can contain spaces

## Allowed function 
 - malloc(3)
 - free(3)
 - printf(3)
 - write(2)

## HOW TO USE

 1. `make` to make the files.
 2. `./my_bc` followed by the expresion. 
    - *example* `./my_bc "1 + 2 * (3 - 42) % 5"`
 4. After finishing using **my_bc** you can `make clean`
