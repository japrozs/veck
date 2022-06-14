# Veck

Just a custom implementation for `std::vector` in `C++`.

## Features

The library is easy-to-use and very simple and fast.

### Initializion

There are 4 ways in which you can initialize a new vector in `veck`

-   Basic

```c++
#include <veck.hpp>

int main(){
	Vector v;
}
```

-   Contructors:

```c++
#include <veck.hpp>

int main(){
	Vector v(10, 5); // initialize a vector with 10 elements with value 5
}
```

-   With another vector

```c++
#include <veck.hpp>

int main(){
	Vector v;
	v.push(10);
	v.push(20);
	Vector w(v);  // w = {10, 20};
}
```

-   With a initializer list

```c++
#include <veck.hpp>

int main(){
	Vector v {1, 2, 3, 4, 5, 6, 7};
}
```

### Functions

-   `push(int x)`
    Add an `int x` to a vector

-   `pop()`
    Remove an element from a vector

-   `empty()`
    Tells if the vector is empty.

-   `size()`
    Find the size of the vector

-   `capacity()`
    Find the capacity of the vector

-   `front()`
    Find the capacity of the vector

-   `back()`
    Find the capacity of the vector

-   `insert(int index, int value)`
    Add a element at a certain index

-   `erase(int index)`
    Remove the element at the `index`

-   `clear()`
    Clear the entire list

-   `at(int index)`
    Find an element at a certain index

## Operators

-   `<<`
    Used to print out a vector

```c++
#include <veck.hpp>

int main(){
	Vector w{1, 2, 3, 4, 5};
	std::cout << w << std::endl; // prints outs 1, 2, 3, 4, 5
}
```

-   `[]`
    Access a certain element of a list

```c++
#include <veck.hpp>

int main(){
	Vector w{1, 2 ,3, 4, 5};
	std::cout << w[0] << std::endl; // 1
}
```

-   `==`
    Check if 2 vectors are equal

```c++
#include <veck.hpp>

int main(){
	Vector w{1, 2 ,3, 4, 5};
	Vector v{1, 2 ,3, 4, 5};
	std::cout << w == v << std::endl; // true
}
```

-   `!=`
    Check if 2 vectors are not equal

```c++
#include <veck.hpp>

int main(){
	Vector w{1, 2 ,3, 4, 5};
	Vector v{1, 2, 4, 5};
	std::cout << w != v << std::endl; // true
}
```

## Building from source

```bash
cd veck
make
./bin/main
```
