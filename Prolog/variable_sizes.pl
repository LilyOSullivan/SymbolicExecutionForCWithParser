%% get_type_information/4
%% get_type_information(+Type, -Size_in_bytes, -Minimum_bound, -Maximum_bound)
%% Gets the size of a c type in bytes
%% Parameters:
%%   Type: The type to get the size of
%%   Size_in_bytes: The size of the type in bytes
%%   Minimum_bound: The minimum value of the type
%%   Maximum_bound: The maximum value of the type

get_type_information(char,1,-128,127).
get_type_information(signed_char,1,-128,127).
get_type_information(unsigned_char,1,0,255).
get_type_information(short,2,-32768,32767).
get_type_information(signed_short,2,-32768,32767).
get_type_information(unsigned_short,2,0,65535).
get_type_information(short_int,2,-32768,32767).
get_type_information(signed_short_int,2,-32768,32767).
get_type_information(unsigned_short_int,2,0,65535).
get_type_information(int,4,-2147483648,2147483647).
get_type_information(signed_int,4,-2147483648,2147483647).
get_type_information(unsigned_int,4,0,4294967295).
get_type_information(signed,4,-2147483648,2147483647).
get_type_information(unsigned,4,0,4294967295).
get_type_information(long,8,-9223372036854775808,9223372036854775807).
get_type_information(signed_long,8,-9223372036854775808,9223372036854775807).
get_type_information(unsigned_long,8,0,18446744073709551615).
get_type_information(long_int,8,-9223372036854775808,9223372036854775807).
get_type_information(signed_long_int,8,-9223372036854775808,9223372036854775807).
get_type_information(unsigned_long_int,8,0,18446744073709551615).
get_type_information(long_long,8,-9223372036854775808,9223372036854775807).
get_type_information(signed_long_long,8,-9223372036854775808,9223372036854775807).
get_type_information(unsigned_long_long,8,0,18446744073709551615).
get_type_information(long_long_int,8,-9223372036854775808,9223372036854775807).
get_type_information(signed_long_long_int,8,-9223372036854775808,9223372036854775807).
get_type_information(unsigned_long_long_int,8,0,18446744073709551615).
get_type_information(float,4,1.17549e-38,3.40282e+38).
get_type_information(double,8,2.22507e-308,1.79769e+308).
get_type_information(long_double,8,2.22507e-308,1.79769e+308).
get_type_information(pointer,8,0,200000).
get_type_information('_Bool',1,0,1).
get_type_information(enum,4,-2147483648,2147483647).
