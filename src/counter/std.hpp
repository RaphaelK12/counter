#ifndef counter_std_
#define counter_std_

#include "./number.hpp"

  template< typename class_name > struct std::is_floating_point< ::counter::number< float,       class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_floating_point< ::counter::number< double,      class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_floating_point< ::counter::number< long double, class_name > >: std::true_type{ };

  template< typename class_name > struct std::is_integral< ::counter::number< bool,                 class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< char,                 class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< signed char ,         class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< unsigned char,        class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< wchar_t,              class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< char16_t,             class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< char32_t,             class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< short,                class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< unsigned short,       class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< int,                  class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< unsigned int,         class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< long,                 class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< unsigned long,        class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< long long,            class_name > >: std::true_type{ };
  template< typename class_name > struct std::is_integral< ::counter::number< unsigned long long,   class_name > >: std::true_type{ };
 //template< typename class_name > struct std::is_integral< ::counter::number< std::uint8_t,         class_name > >: std::true_type{ };
 //template< typename class_name > struct std::is_integral< ::counter::number< std::uint16_t,        class_name > >: std::true_type{ };
 //template< typename class_name > struct std::is_integral< ::counter::number< std::uint32_t,        class_name > >: std::true_type{ };
 //template< typename class_name > struct std::is_integral< ::counter::number< std::uint64_t,        class_name > >: std::true_type{ };
 //template< typename class_name > struct std::is_integral< ::counter::number< std::int8_t,          class_name > >: std::true_type{ };
 //template< typename class_name > struct std::is_integral< ::counter::number< std::int16_t,         class_name > >: std::true_type{ };
 //template< typename class_name > struct std::is_integral< ::counter::number< std::int32_t,         class_name > >: std::true_type{ };
 //template< typename class_name > struct std::is_integral< ::counter::number< std::int64_t,         class_name > >: std::true_type{ };

 // TODO is_signed
 // TODO is_exact
 // TODO is_bounded
// std::numeric_limits::is_integer

#endif
