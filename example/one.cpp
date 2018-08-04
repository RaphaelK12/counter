#include <iostream>
#include <iomanip>
#include <typeinfo>

#include "counter/counter.hpp"

typedef ::counter::number< float > MyFloat;
typedef ::counter::number< int   > MyInt;


using namespace counter::functions;


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

void invoke_arithmetic()
 {
  MyInt f1, f2(2);

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

void invoke_trigonometric()
 {
   MyFloat a=0.1,b = 0.5;
   a = cos( b );
   a = sin( b );
   a = tan( b );
   a = acos( b );
   a = asin( b );
   a = atan( b );
   a = atan2( a, b );
 }

void invoke_hyperbolic()
 {
   MyFloat a,b = 0.5;
   a = cosh( b );
   a = sinh( b );
   a = tanh( b );
   a = acosh( b );
   a = asinh( b );
   a = atanh( b );
 }

void invoke_power()
 {
   MyFloat a=0.1,b = 0.5,c;
   c = pow( a, b );
   c = sqrt( b );
   c = cbrt( b );
   c = hypot( a, b );
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
  invoke_trigonometric();
  invoke_hyperbolic();
  invoke_power();

  std::cout << "Statistics for MyFloat" << std::endl;
  print( MyFloat::statistics() );

  std::cout << "Statistics for MyInt" << std::endl;
  print( MyInt::statistics() );

  return EXIT_SUCCESS;
 }
