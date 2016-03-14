#ifndef counter_constant
#define counter_constant


namespace counter
 {
  namespace constant
   {

    enum list
     {
       construction_blank
      ,construction_assign
      ,construction_underlying
      ,destruction
      ,member_get_const
      ,member_get_modify
      ,operator_assign
      ,operator_convert
      ,operator_plus_unary
      ,operator_plus_binary
      ,operator_plus_accumulate
      ,operator_minus_unary
      ,operator_minus_binary
      ,operator_minus_accumulate
      ,operator_multiply_binary
      ,operator_multiply_accumulate
      ,operator_divide_binary
      ,operator_divide_accumulate
      ,operator_module_binary
      ,operator_module_accumulate
      ,operator_increment_left
      ,operator_increment_right
      ,operator_decremet_left
      ,operator_decremet_right
      ,operator_or_bit_accumulate
      ,operator_or_bit_binary
      ,operator_or_logic_accumulate
      ,operator_not
      ,operator_or_logic_binary
      ,operator_and_bit_accumulate
      ,operator_and_bit_binary
      ,operator_and_logic_accumulate
      ,operator_and_logic_binary
      ,operator_xor_bit_accumulate
      ,operator_bit_not
      ,operator_xor_bit_binary
      ,operator_shift_left_binary
      ,operator_shift_left_accumulate
      ,operator_shift_right_binary
      ,operator_shift_right_accumulate
      ,operator_equal_strict
      ,operator_not_equal_strict
      ,operator_less_strict
      ,operator_less_equal
      ,operator_great_strict
      ,operator_great_equal
      ,function_cos
      ,function_sin
      ,function_tan
      ,function_acos
      ,function_asin
      ,function_atan
      ,function_cosh
      ,function_sinh
      ,function_tanh
      ,function_acosh
      ,function_asinh
      ,function_atanh
      ,_last
      };


      inline std::string const& to_string( int const& index )
       {
        static std::vector< std::string > s_name
         {
          "construction_blank",
          "construction_assign",
          "construction_underlying",
          "destruction",
          "member_get_const",
          "member_get_modify",
          "operator_assign",
          "operator_convert",
          "operator_plus_unary",
          "operator_plus_binary",
          "operator_plus_accumulate",
          "operator_minus_unary",
          "operator_minus_binary",
          "operator_minus_accumulate",
          "operator_multiply",
          "operator_multiply_accumulate",
          "operator_divide_binary",
          "operator_divide_accumulate",
          "operator_module_binary",
          "operator_module_accumulate",
          "operator_increment_left",
          "operator_increment_right",
          "operator_decremet_left",
          "operator_decremet_right",
          "operator_or_bit_accumulate",
          "operator_or_bit_binary",
          "operator_or_logic_binary",          
          "operator_or_logic_accumulate",
          "operator_not",
          "operator_and_bit_accumulate",
          "operator_and_bit_binary",
          "operator_and_logic_accumulate",
          "operator_and_logic_binary",
          "operator_xor_bit_accumulate",
          "operator_bit_not",
          "operator_xor_bit_binary",
          "operator_shift_left_binary",
          "operator_shift_left_accumulate",
          "operator_shift_right_binary",
          "operator_shift_right_accumulate",
          "operator_equal_strict",
          "operator_not_equal_strict",
          "operator_less_strict",
          "operator_less_equal",
          "operator_great_strict",
          "operator_great_equal",
          "function_cos",
          "function_sin",
          "function_tan",
          "function_acos",
          "function_asin",
          "function_atan",
          "function_cosh",
          "function_sinh",
          "function_tanh",
          "function_acosh",
          "function_asinh",
          "function_atanh",
          "_last"
         };

         return s_name[ index ];
       }

   }
 }
 
#endif



