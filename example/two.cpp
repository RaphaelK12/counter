#include <iostream>
#include <iomanip>
#include <typeinfo>

#include "counter/counter.hpp"

typedef ::counter::number< float > MyFirstFloat;
typedef ::counter::number< int   > MySecondFloat;


void print( ::counter::statistics const& stat )
 {
  int index=0;
  for( auto const& c : stat.container() )
  {
   if( 0 == c )
    continue;

   std::cout << "    ";
   std::cout << ::counter::constant::to_string( index ) << " = ";
   std::cout << c;
   std::cout << std::endl;
   ++index;
  }
 }

void func0( )
 {
  MyFirstFloat f1, f2(7);

  f1 = f2;

  f1 = f2 + f2;
  f1 += f2;

  f1  = f1 - f2;
  f1 -= f2;

  f1  = f1 * f2;
  f1 *= f2;

  f1  = f1 / f2;
  f1 /= f2;
 }

void func1( )
 {
  MyFirstFloat f1, f2(9);

  f1 = f2;

  f1 = f2 + f2;
  f1 += f2;

  f1  = f1 - f2;
  f1 -= f2;

  f1  = f1 * f2;
  f1 *= f2;

  f1  = f1 / f2;
  f1 /= f2;
 }

void process()
 {
  MySecondFloat f1, f2(24);

  f1 = f2;

  f1 = f2 + f2;
  f1 += f2;

  f1  = f1 - f2;
  f1 -= f2;

  f1  = f1 * f2;
  f1 *= f2;

  f1  = f1 / f2;
  f1 /= f2;
 }


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyFirstFloat::statistics().reset();
  MySecondFloat::statistics().reset();

  func0();
  func1();
  process();

  std::cout << "Statistics for MyFirstFloat" << std::endl;
  print( MyFirstFloat::statistics() );
  std::cout << std::endl;
  std::cout << "Statistics for MySecondFloat" << std::endl;
  print( MySecondFloat::statistics() );


  std::cin.get();
  return EXIT_SUCCESS;
 }
