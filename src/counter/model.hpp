#ifndef counter_model
#define counter_model

#include "./constant.hpp"
#include "./statistics.hpp"

namespace counter
 {

  template
   <
     typename class_name
    ,typename underlying_name
   >
   class model
    {
     public:
       typedef  class_name       class_type;

       typedef  underlying_name   underlying_type;

       typedef  ::counter::model< class_name, underlying_name > this_type;
       typedef  ::counter::statistics  statistics_type;

       model()
        {
         statistics().increase( ::counter::constant::construction_blank );
        }

       model( underlying_type const& underlying )
        {
         this->m_underlying = underlying;
         statistics().increase( ::counter::constant::construction_underlying );
        }

       model( this_type const& that )
        {
         *this = that;
         statistics().increase( ::counter::constant::construction_assign );
        }

       ~model()
        {
         statistics().increase( ::counter::constant::destruction );
        }

       this_type & operator=( this_type const& that )
        {
         statistics().increase( ::counter::constant::operator_assign );
         return *this;
        }

       this_type & operator=( underlying_type const& that )
        {
         statistics().increase( ::counter::constant::operator_assign );
         return *this;
        }

       operator  underlying_type const&()const
        {
         statistics().increase( ::counter::constant::operator_convert );
         return m_underlying;
        }

       underlying_type const& get()const
        {
         statistics().increase( ::counter::constant::member_get_const );
         return m_underlying;
        }

       underlying_type & get()
        {
         statistics().increase( ::counter::constant::member_get_modify );
         return m_underlying;
        }

     public:
       static statistics_type & statistics()
        {
         static statistics_type s_statistics;
         return s_statistics;
        }

     private:
      underlying_type m_underlying;

    };

 }
 
#endif
