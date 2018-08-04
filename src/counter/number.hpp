#ifndef counter_number
#define counter_number

#include "./category.hpp"
#include "./constant.hpp"
#include "./statistics.hpp"

namespace counter
 {

  template
   <
     typename underlying_name
    ,typename class_name     = ::counter::category::common
   >
   class number
    {
     public:
       typedef  class_name         class_type;

       typedef  underlying_name   underlying_type;

       typedef  ::counter::number< underlying_name, class_type > this_type;
       typedef  ::counter::statistics  statistics_type;

       number()
        {
         statistics().increase( ::counter::constant::construction_blank );
        }

       number( underlying_type const& underlying )
        {
         this->m_underlying = underlying;
         statistics().increase( ::counter::constant::construction_underlying );
        }
       template< typename other_underlying_name >
        number( other_underlying_name const& other_underlying )
         {
          this->m_underlying = underlying_type( other_underlying );
          statistics().increase( ::counter::constant::construction_other_underlying );
         }

       number( this_type const& that )
        {
         *this = that;
         statistics().increase( ::counter::constant::construction_assign );
        }

       ~number()
        {
         statistics().increase( ::counter::constant::destruction );
        }

       this_type & operator=( this_type const& that )
        {
         statistics().increase( ::counter::constant::operator_assign );
         this->set( that.get() );
         return *this;
        }

       this_type & operator=( underlying_type const& that )
        {
         statistics().increase( ::counter::constant::operator_assign );
         this->get() = that;
         return *this;
        }

       operator  underlying_type const&()const
        {
         statistics().increase( ::counter::constant::operator_convert_const );
         return m_underlying;
        }

       operator  underlying_type &()
        {
         statistics().increase( ::counter::constant::operator_convert_direct );
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

       void set( underlying_type const& that )
        { 
         m_underlying = that;
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
