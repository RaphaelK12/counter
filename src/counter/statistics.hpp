
namespace counter
 {

  template 
   <
     typename class_name
    ,typename underlaying_name
   >
   class statistics
    {
     public:
       typedef  class_name    class_name;
       typedef  underlaying_name    underlaying_name;
       
       typedef  statistics< class_name,underlaying_name >statistics, this_type;
       
       statistics(){}
       ~statistics(){}
     
  
       void set();
       void get();
       void increase();
       void clear();
       container();
    }; 
 }
 