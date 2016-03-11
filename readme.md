#Count every usage of arithmetic/mathematic functions

- Status:
 - Ready for use!

Key features:
- Headers only
- No third parties
- No additional binaries
- One file to include to start the fun
- Easy to integrate
- Easy to disintegrate
- Out of the box ready
 - No need to recompile or start some install process.

Example:

```c++

#include <iostream>
#include <iomanip>

#include "counter/counter.hpp"

typedef ::counter::number<double> MyDouble;

int main( int argc, char *argv[] )
 {
  
  MyDouble a, b, c;

  a = a + b + - c;

  std::cout << "Number of calls of assignment operator: " 
            << MyDouble::statistics().container()[ ::counter::constant::operator_assign ]
            << std::endl
            << "Number of calls of binary plus operator: " 
            << MyDouble::statistics().container()[ ::counter::constant::operator_plus_full ]
            << std::endl
            << "Number of calls of unary minus: " 
            << MyDouble::statistics().container()[ ::counter::constant::operator_minus_unary ]
            << std::endl;

  return EXIT_SUCCESS;
 }

 ```

 Want to see more:
  - [HTML Documentation ](doc/index.html)
  - [Wiki page](https://github.com/dmilos/counter/wiki)