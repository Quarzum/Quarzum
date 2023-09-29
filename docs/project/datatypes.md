# Datatypes

One of the most important features in Quarzum is the **optional typing system**, that divides in 2 types of variables:

### Mutable Type Variables

This type of variables can have any type of value, even if it was initializated before. Example:

``` 
var someData = 0
someData = "Hello world!"
someData = null
```

The keyword to make a variable of any type is `var`.

### Constant Type Variables

This type of variables has a specific type at the moment of the initialization. Example:

```
int someData
someData = 2 // Good
someData = "Hello world!" // ERROR

```

#### Primitive data types

Here is a simple example of how every primitive datatype works:

```
int i = 0
number pi = 3.1415
string text = "Hello world!"
bool condition = true
```

#### Non-Primitive data types

Here is a simple example of how every non-primitive datatype works:

```
struct User {
    string name
    int id
}

enum State {
    OFF, ON, NOT_CONNECTED
}
```