
namespace counter
 {

  template
   <
     typename class_name
    ,typename inderlying_name
   >
   class number
    {
     public:
       typedef  class_name    class_type;
       typedef  inderlying_name    inderlying_type;

       typedef  number< class_name, inderlying_name > T_number, this_type;

       number()
        {
         get_statistics().increase( statistics_type::construction_enum );
        }

       number( this_type const& that )
        {
         *this = that;
         get_statistics().increase( statistics_type::initialization_enum );
        }

       ~number()
        {
         get_statistics().increase( statistics_type::destruction_enum );
        }

       this_type & operator=( this_type const& that )
        {
         get_statistics().increase( statistics_type::assign_enum );
         return *this;
        }

       this_type & operator=( inderlying_type const& that )
        {
         get_statistics().increase( statistics_type::assign_enum );
         return *this;
        }

       operator inderlying_type()
        {
         get_statistics().increase( statistics_type::convert_enum );
         return m_inderlying;
        }

     public:
       static statistics_type & get_statistics()
        {
         static statistics_type s_statistics;
         return statistics_type;
        }

     private:
      inderlying_type m_inderlying;

    };

 }