# Language design

In this document will be redacted all the current information about the syntax and design of the Quarzum programming language.

## Table of contents

- [Language design](#language-design)
  - [Table of contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Not a definitive design](#not-a-definitive-design)
    - [First contact with Quarzum](#first-contact-with-quarzum)
  - [Data types](#data-types)
    - [Functions](#functions)

## Introduction

This document shows everything about the Quarzum syntax: types, functions, statements... The objective of this document is to illustrate the original idea of the Quarzum design.

### Not a definitive design
 
The majority of this content is purely provisional and can change at any time. Do not take this design document as the final version of the language design.


### First contact with Quarzum

Here is an example of a Quarzum code:

```
int n, i
unsigned long int fact = 1
n = toInt(input("Enter an integer: ) )
if(n < 0){
    out("Error! Factorial of a negative number doesn't esist.)
}
else{
    for(i = 1; i < n; i++){
        fact *= i
    }
    out("Factorial of @{n} is @{fact})
}

```
As you can see, the syntax of Quarzum is similar to the C programming language family, but using more modern syntax and more simple code.

## Data types

In Quarzum, as several languages, all the variables have a data type assigned. Basic data types in Quarzum are `int` , `number` , `string` , `bool` and `var`. The last one is an exception, since it can store any type of value. 

### Functions

If you want to create a procedure, it must return a value with a data type. For example, this function will add 1.5 to a number and then return the value.

```
number sumOne(number x){
    return x + 1.5
}
number myNum = sumOne(4)
```

In the case that no value is returned, the keyword `function` is the correct. For example, this function will print a message:

```
function print(any x){
    out("Hi! This is the message: @{x}")
}
print("Hello world from Quarzum!")
```