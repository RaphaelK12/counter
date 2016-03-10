#ifndef counter_operators
#define counter_operators

#include "./model.hpp"


namespace counter
 {
  namespace operators
   {

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > operator+
      (
       ::counter::model< class_name, underlying_name > const& left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_plus_full );
       return ::counter::model< class_name, underlying_name >( left.get() + right.get() );
      }


    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > & operator+=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_plus_accumulate );
       left.get() += right.get();
       return left;
      }



    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > operator-
      (
       ::counter::model< class_name, underlying_name > const& left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_minus_full );
       return ::counter::model< class_name, underlying_name >( left.get() - right.get() );
      }


    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > & operator-=
      (
       ::counter::model< class_name, underlying_name >     & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_minus_accumulate );
       left.get() -= right.get();
       return left;
      }

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > operator*
      (
       ::counter::model< class_name, underlying_name > const& left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_multiply_full );
       return ::counter::model< class_name, underlying_name >( left.get() * right.get() );
      }


    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > & operator *=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_multiply_accumulate );
       left.get() *= right.get();
       return left;
      }

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > operator/
      (
       ::counter::model< class_name, underlying_name > const& left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_divide_full );
       return ::counter::model< class_name, underlying_name >( left.get() / right.get() );
      }


    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > & operator /=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_divide_accumulate );
       left.get() /= right.get();
       return left;
      }

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > operator%
      (
       ::counter::model< class_name, underlying_name > const& left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_module_full );
       return ::counter::model< class_name, underlying_name >( left.get() % right.get() );
      }


    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > & operator %=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_module_accumulate );
       left.get() %= right.get();
       return left;
      }


    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > operator|
      (
       ::counter::model< class_name, underlying_name > const& left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_or_bit_full );
       return ::counter::model< class_name, underlying_name >( left.get() | right.get() );
      }


    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > & operator |=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_or_bit_accumulate );
       left.get() |= right.get();
       return left;
      }

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > operator&
      (
       ::counter::model< class_name, underlying_name > const& left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_and_bit_full );
       return ::counter::model< class_name, underlying_name >( left.get() & right.get() );
      }


    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > & operator &=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_and_bit_accumulate );
       left.get() &= right.get();
       return left;
      }

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > operator^
      (
       ::counter::model< class_name, underlying_name > const& left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_xor_bit_full );
       return ::counter::model< class_name, underlying_name >( left.get() ^ right.get() );
      }


    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > & operator ^=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_xor_bit_accumulate );
       left.get() ^= right.get();
       return left;
      }

    template < typename class_name , typename underlying_name >
     inline
     underlying_name operator ~
      (
       ::counter::model< class_name, underlying_name >      & left
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_bit_not );
       return ~left.get();
      }      


    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > operator &&
      (
       ::counter::model< class_name, underlying_name > const& left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_and_logic_full );
       return ::counter::model< class_name, underlying_name >( left.get() && right.get() );
      }

/*
    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > & operator &&=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_and_logic_accumulate );
       left.get() &&= right.get();
       return left;
      }
*/

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > operator ||
      (
       ::counter::model< class_name, underlying_name > const& left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_or_logic_full );
       return ::counter::model< class_name, underlying_name >( left.get() || right.get() );
      }

/*
    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > & operator ||=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_or_logic_accumulate );
       left.get() &&= right.get();
       return left;
      }
*/

    template < typename class_name , typename underlying_name >
     inline
     underlying_name operator !
      (
       ::counter::model< class_name, underlying_name >     const& left
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_not );
       return !left.get();
      }

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > operator>>
      (
       ::counter::model< class_name, underlying_name > const& left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_shift_right_full );
       return ::counter::model< class_name, underlying_name >( left.get() >> right.get() );
      }


    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > & operator >>=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_shift_right_accumulate );
       left.get() >>= right.get();
       return left;
      }

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > operator<<
      (
       ::counter::model< class_name, underlying_name > const& left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_shift_left_full );
       return ::counter::model< class_name, underlying_name >( left.get() << right.get() );
      }

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name > & operator <<=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_shift_left_accumulate );
       left.get() <<= right.get();
       return left;
      }

    template < typename class_name , typename underlying_name >
     inline
     bool operator ==
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_equal_strict );
       return left.get() == right.get();
      }

    template < typename class_name , typename underlying_name >
     inline
     bool operator !=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_not_equal_strict );
       return left.get() != right.get();
      }

    template < typename class_name , typename underlying_name >
     inline
     bool operator <
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_less_strict );
       return left.get() < right.get();
      }

    template < typename class_name , typename underlying_name >
     inline
     bool operator <=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_less_equal );
       return left.get() <= right.get();
      }

    template < typename class_name , typename underlying_name >
     inline
     bool operator >
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_great_strict );
       return left.get() > right.get();
      }

    template < typename class_name , typename underlying_name >
     inline
     bool operator >=
      (
       ::counter::model< class_name, underlying_name >      & left, ::counter::model< class_name, underlying_name > const& right
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_great_equal );
       return left.get() >= right.get();
      }

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name >& operator ++
      (
       ::counter::model< class_name, underlying_name >      & left
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_increment_left );
       return left;
      }

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name >& operator ++
      (
       ::counter::model< class_name, underlying_name >      & left, int dummy
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_increment_right );
       return left;
      }

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name >& operator --
      (
       ::counter::model< class_name, underlying_name >      & left
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_decremet_left );
       return left;
      }

    template < typename class_name , typename underlying_name >
     inline
     ::counter::model< class_name, underlying_name >& operator --
      (
       ::counter::model< class_name, underlying_name >      & left, int dummy
      )
      {
       ::counter::model< class_name, underlying_name >::statistics().increase( ::counter::constant::operator_decremet_right );
       return left;
      }

   } 

 }
 
#endif
