#include <iostream>
#include <iomanip>

#include "counter/counter.hpp"

typedef ::counter::number<double> MyDouble;

int main( int argc, char *argv[] )
 {
  
  MyDouble a, b, c;

  a = a + b + - c;

  std::cout << "Assigment operator: " 
            << MyDouble::statistics()[ ::counter::constant::operator_assign ]
            << std::endl
            << "Binary plus operator: " 
            << MyDouble::statistics()[ ::counter::constant::operator_plus_binary ]
            << std::endl
            << "Unary minus: " 
            << MyDouble::statistics()[ ::counter::constant::operator_minus_unary ]
            << std::endl;

  std::cin.get();
  return EXIT_SUCCESS;
 }