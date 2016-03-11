#ifndef counter_number
#define counter_number 

#include "./model.hpp"


namespace counter
 {

   template< typename underlying_name, typename class_name = ::counter::category::common >
    using number = ::counter::model< underlying_name, class_name >;
 }
 
#endif
