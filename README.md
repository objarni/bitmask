# bitmask
A header only library for expressing bitmasks readably in C/C++ pre C++14


# How to use?

```
#include <stdio.h>
#include "bitmask.h"

int main() {
  printf("We can now write bitmasks in C easily, no need for C++14 envy. :)\n");
  unsigned int value1 = b("1111'1111'1111'1101");
  unsigned int value2 = 0xFFFD;
  printf("value1 and value2 have same value: %d == %d\n", value1, value2);
}
```
