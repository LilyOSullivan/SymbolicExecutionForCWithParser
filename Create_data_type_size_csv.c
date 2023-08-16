#include <stdio.h>
#include <limits.h>
#include <float.h>

// A sample structure
struct sampleStruct {
    int a;
    double b;
    char c;
};

// An enumeration type
enum week{Mon, Tue, Wed, Thu, Fri, Sat, Sun};

int main(void) {
    FILE *file = fopen("variable_sizes.pl", "w");

    if(file == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }

    fprintf(file, "get_type_information(char, %lu, %d, %d).\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    fprintf(file, "get_type_information(signed_char, %lu, %d, %d).\n", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    fprintf(file, "get_type_information(unsigned_char, %lu, 0, %u).\n", sizeof(unsigned char), UCHAR_MAX);

    fprintf(file, "get_type_information(short, %lu, %d, %d).\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    fprintf(file, "get_type_information(unsigned_short, %lu, 0, %u).\n", sizeof(unsigned short), USHRT_MAX);
    fprintf(file, "get_type_information(signed_short, %lu, %d, %d).\n", sizeof(signed short), SHRT_MIN, SHRT_MAX);

    fprintf(file, "get_type_information(short_int, %lu, %d, %d).\n", sizeof(short int), SHRT_MIN, SHRT_MAX);
    fprintf(file, "get_type_information(unsigned_short_int, %lu, 0, %u).\n", sizeof(unsigned short int), USHRT_MAX);
    fprintf(file, "get_type_information(signed_short_int, %lu, %d, %d).\n", sizeof(signed short int), SHRT_MIN, SHRT_MAX);

    fprintf(file, "get_type_information(int, %lu, %d, %d).\n", sizeof(int), INT_MIN, INT_MAX);
    fprintf(file, "get_type_information(signed_int, %lu, %d, %d).\n", sizeof(signed int), INT_MIN, INT_MAX);
    fprintf(file, "get_type_information(unsigned_int, %lu, 0, %u).\n", sizeof(unsigned int), UINT_MAX);
    fprintf(file, "get_type_information(signed, %lu, %d, %d).\n", sizeof(signed), INT_MIN, INT_MAX);
    fprintf(file, "get_type_information(unsigned, %lu, 0, %u).\n", sizeof(unsigned), UINT_MAX);

    fprintf(file, "get_type_information(long, %lu, %ld, %ld).\n", sizeof(long), LONG_MIN, LONG_MAX);
    fprintf(file, "get_type_information(signed_long, %lu, %ld, %ld).\n", sizeof(signed long), LONG_MIN, LONG_MAX);
    fprintf(file, "get_type_information(unsigned_long, %lu, 0, %lu).\n", sizeof(unsigned long), ULONG_MAX);

    fprintf(file, "get_type_information(long_int, %lu, %ld, %ld).\n", sizeof(long int), LONG_MIN, LONG_MAX);
    fprintf(file, "get_type_information(signed_long_int, %lu, %ld, %ld).\n", sizeof(signed long int), LONG_MIN, LONG_MAX);
    fprintf(file, "get_type_information(unsigned_long_int, %lu, 0, %lu).\n", sizeof(unsigned long int), ULONG_MAX);

    fprintf(file, "get_type_information(long_long, %lu, %lld, %lld).\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    fprintf(file, "get_type_information(signed_long_long, %lu, %lld, %lld).\n", sizeof(signed long long), LLONG_MIN, LLONG_MAX);
    fprintf(file, "get_type_information(unsigned_long_long, %lu, 0, %llu).\n", sizeof(unsigned long long), ULLONG_MAX);

    fprintf(file, "get_type_information(long_long_int, %lu, %lld, %lld).\n", sizeof(long long int), LLONG_MIN, LLONG_MAX);
    fprintf(file, "get_type_information(signed_long_long_int, %lu, %lld, %lld).\n", sizeof(signed long long int), LLONG_MIN, LLONG_MAX);
    fprintf(file, "get_type_information(unsigned_long_long_int, %lu, 0, %llu).\n", sizeof(unsigned long long int), ULLONG_MAX);

    fprintf(file, "get_type_information(float, %lu, %g, %g).\n", sizeof(float), FLT_MIN, FLT_MAX);
    fprintf(file, "get_type_information(double, %lu, %g, %g).\n", sizeof(double), DBL_MIN, DBL_MAX);
    fprintf(file, "get_type_information(long_double, %lu, %Lg, %Lg).\n", sizeof(long double), LDBL_MIN, LDBL_MAX);

    // fprintf(file, "get_type_information(pointer, %lu, 0, %d).\n", sizeof(void*), UINTPTR_MAX);
    fprintf(file, "get_type_information(pointer, %lu, 0, %d).\n", sizeof(void*), 200000);
    fprintf(file, "get_type_information('_Bool', %lu, 0, 1).\n", sizeof(_Bool));

    // Enumerated types usually have the size of 'int'
    fprintf(file, "get_type_information(enum, %lu, %d, %d).\n", sizeof(enum week), INT_MIN, INT_MAX);


//    fprintf(file, "sampleStruct,%lu\n", sizeof(struct sampleStruct)); // This has alignment/padding to account for. 8 * 3 = 24
//    fprintf(file, "int array[10],%lu\n", sizeof(int[10]));

    fclose(file);
    printf("File created and data written successfully.\n");
    return 0;
}
