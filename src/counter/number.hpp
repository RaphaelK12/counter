#ifndef counter_number
#define counter_number 

#include "./model.hpp"


namespace counter
 {


   template< typename class_name, typename underlying_name >
    using number = ::counter::model< class_name, underlying_name >;
 }
 
#endif
