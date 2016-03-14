#include <iostream>
#include <iomanip>

#include "counter/counter.hpp"

typedef ::counter::number<double> MyDouble;

int main( int argc, char *argv[] )
 {
  
  MyDouble a, b, c;

  a = a + b + - c;

  std::cout << "Number of used assigment operator: " 
            << MyDouble::statistics()[ ::counter::constant::operator_assign ]
            << std::endl
            << "Number of used binary plus operator: " 
            << MyDouble::statistics()[ ::counter::constant::operator_plus_binary ]
            << std::endl
            << "Number of used unary minus: " 
            << MyDouble::statistics()[ ::counter::constant::operator_minus_unary ]
            << std::endl;

  return EXIT_SUCCESS;
 }