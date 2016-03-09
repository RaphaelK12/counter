
namespace counter
 {

  template
   <
     typename class_name
    ,typename inderlying_name
   >
   class scalar
    : public ::counter::number<class_name,inderlying_name>
    {
    };

 }