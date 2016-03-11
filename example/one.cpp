#include <iostream>
#include <iomanip>
#include <typeinfo>

#include "counter/counter.hpp"

typedef ::counter::number< float > MyFloat;
typedef ::counter::number< int   > MyInt;


void print( ::counter::statistics const& stat )
 {
 	int index=0;
 	for( auto const& c : stat.container() )
 	{
 		std::cout << ::counter::constant::to_string( index ) << " = ";
 		std::cout << c;
 		std::cout << std::endl;
 		++index;
 	}
 }

void invoke_arithmetic()
 {
  MyInt f1, f2;

  f1 = f2;

  f1 = f2 + f2;
  f1 += f2;

  f1  = f1 - f2;
  f1 -= f2;

  f1  = f1 * f2;
  f1 *= f2;

  f1  = f1 / f2;
  f1 /= f2;

  f1  = f1 % f2;
  f1 %= f2;
 }

void invoke_logic()
 {
  MyInt f1, f2;

  f1 = f2;

  f1  = f1 && f2;
  //f1 &&= f2;

  f1  = f1 || f2;
  //f1 ||= f2;
 }

void invoke_bit()
 {
  MyInt f1, f2;

  f1 = f2;

  f1 = f2 | f2;
  f1 |= f2;

  f1  = f1 & f2;
  f1 &= f2;

  f1  = f1 ^ f2;
  f1 ^= f2;

  f1  = f1 >> f2;
  f1 >>= f2;

  f1  = f1 << f2;
  f1 <<= f2;

  f1 = ~ f2;

 }

void invoke_comparison()
 {
  MyInt f1, f2(10);
  MyInt f3( f2);

 f1 == f2;
 f1 != f2;
 f1 <  f2;
 f1 >  f2;
 f1 <= f2;
 f1 >= f2;
 }

void invoke_crement()
 {

  MyInt a;
  ++a;
  --a;
  a++;
  a--;

 }


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyFloat::statistics().reset();

  invoke_arithmetic();
  invoke_logic();
  invoke_bit();
  invoke_comparison();
  invoke_crement();

  //print( MyFloat::statistics() );
  print( MyInt::statistics() );

  return EXIT_SUCCESS;
 }
