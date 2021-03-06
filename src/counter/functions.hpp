#ifndef counter_functions
#define counter_functions

#include "./number.hpp"


namespace counter
 {
  namespace functions
   {


    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > cos
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_cos );
       return ::counter::number< underlying_name, class_name >( ::cos( right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > sin
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_sin );
       return ::counter::number< underlying_name, class_name >( ::sin( right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > tan
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_tan );
       return ::counter::number< underlying_name, class_name >( ::tan( right.get() ) );
      }


    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > acos
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_acos );
       return ::counter::number< underlying_name, class_name >( ::acos( right.get() ) );
      }


    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > asin
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_asin );
       return ::counter::number< underlying_name, class_name >( ::asin( right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > atan
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_atan );
       return ::counter::number< underlying_name, class_name >( ::atan( right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > atan2
      (
        ::counter::number< underlying_name, class_name > const& left
       ,::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_atan2 );
       return ::counter::number< underlying_name, class_name >( ::atan2( left.get(), right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > cosh
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_cosh );
       return ::counter::number< underlying_name, class_name >( ::cosh( right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > sinh
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_sinh );
       return ::counter::number< underlying_name, class_name >( ::sinh( right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > tanh
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_tanh );
       return ::counter::number< underlying_name, class_name >( ::tanh( right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > acosh
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_acosh );
       return ::counter::number< underlying_name, class_name >( ::acosh( right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > asinh
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_asinh );
       return ::counter::number< underlying_name, class_name >( ::asinh( right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > atanh
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_atanh );
       return ::counter::number< underlying_name, class_name >( ::atanh( right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > pow
      (
        ::counter::number< underlying_name, class_name > const& left
       ,::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_pow );
       return ::counter::number< underlying_name, class_name >( ::pow( left.get(), right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > sqrt
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_sqrt );
       return ::counter::number< underlying_name, class_name >( ::sqrt( right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > cbrt
      (
       ::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_cbrt );
       return ::counter::number< underlying_name, class_name >( ::cbrt( right.get() ) );
      }

    template < typename underlying_name, typename class_name >
     inline
     ::counter::number< underlying_name, class_name > hypot
      (
        ::counter::number< underlying_name, class_name > const& left
       ,::counter::number< underlying_name, class_name > const& right
      )
      {
       ::counter::number< underlying_name, class_name >::statistics().increase( ::counter::constant::function_hypot );
       return ::counter::number< underlying_name, class_name >( ::hypot( left.get(), right.get() ) );
      }

   }

 }

#endif
