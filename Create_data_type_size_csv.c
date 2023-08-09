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
    FILE *file = fopen("variable_sizes.csv", "w");

    if(file == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }

    // Writing the headers
    fprintf(file, "Type,Size_in_bytes,Minimum,Maximum\n");

    fprintf(file, "char,%lu,%d,%d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    fprintf(file, "signed char,%lu,%d,%d\n", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    fprintf(file, "unsigned char,%lu,0,%u\n", sizeof(unsigned char), UCHAR_MAX);

    fprintf(file, "short,%lu,%d,%d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    fprintf(file, "signed short,%lu,%d,%d\n", sizeof(signed short), SHRT_MIN, SHRT_MAX);
    fprintf(file, "unsigned short,%lu,0,%u\n", sizeof(unsigned short), USHRT_MAX);

    fprintf(file, "short int,%lu,%d,%d\n", sizeof(short int), SHRT_MIN, SHRT_MAX);
    fprintf(file, "signed short int,%lu,%d,%d\n", sizeof(signed short int), SHRT_MIN, SHRT_MAX);
    fprintf(file, "unsigned short int,%lu,0,%u\n", sizeof(unsigned short int), USHRT_MAX);

    fprintf(file, "int,%lu,%d,%d\n", sizeof(int), INT_MIN, INT_MAX);
    fprintf(file, "signed int,%lu,%d,%d\n", sizeof(signed int), INT_MIN, INT_MAX);
    fprintf(file, "unsigned int,%lu,0,%u\n", sizeof(unsigned int), UINT_MAX);
    fprintf(file, "signed,%lu,%d,%d\n", sizeof(signed), INT_MIN, INT_MAX);
    fprintf(file, "unsigned,%lu,0,%u\n", sizeof(unsigned), UINT_MAX);

    fprintf(file, "long,%lu,%ld,%ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    fprintf(file, "signed long,%lu,%ld,%ld\n", sizeof(signed long), LONG_MIN, LONG_MAX);
    fprintf(file, "unsigned long,%lu,0,%lu\n", sizeof(unsigned long), ULONG_MAX);

    fprintf(file, "long int,%lu,%ld,%ld\n", sizeof(long int), LONG_MIN, LONG_MAX);
    fprintf(file, "signed long int,%lu,%ld,%ld\n", sizeof(signed long int), LONG_MIN, LONG_MAX);
    fprintf(file, "unsigned long int,%lu,0,%lu\n", sizeof(unsigned long int), ULONG_MAX);

    fprintf(file, "long long,%lu,%lld,%lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    fprintf(file, "signed long long,%lu,%lld,%lld\n", sizeof(signed long long), LLONG_MIN, LLONG_MAX);
    fprintf(file, "unsigned long long,%lu,0,%llu\n", sizeof(unsigned long long), ULLONG_MAX);

    fprintf(file, "long long int,%lu,%lld,%lld\n", sizeof(long long int), LLONG_MIN, LLONG_MAX);
    fprintf(file, "signed long long int,%lu,%lld,%lld\n", sizeof(signed long long int), LLONG_MIN, LLONG_MAX);
    fprintf(file, "unsigned long long int,%lu,0,%llu\n", sizeof(unsigned long long int), ULLONG_MAX);

    fprintf(file, "float,%lu,%g,%g\n", sizeof(float), FLT_MIN, FLT_MAX);
    fprintf(file, "double,%lu,%g,%g\n", sizeof(double), DBL_MIN, DBL_MAX);
    fprintf(file, "long double,%lu,%Lg,%Lg\n", sizeof(long double), LDBL_MIN, LDBL_MAX);

    fprintf(file, "pointer,%lu,0,%d\n", sizeof(void*), 0, UINTPTR_MAX);
    fprintf(file, "_Bool,%lu,%d,%d\n", sizeof(_Bool), 0, 1);

    fprintf(file, "enum,%lu,%d,%d\n", sizeof(enum week), INT_MIN, INT_MAX); // Enumerated types usually have the size of 'int'

//    fprintf(file, "sampleStruct,%lu\n", sizeof(struct sampleStruct)); // This has alignment/padding to account for. 8 * 3 = 24
//    fprintf(file, "int array[10],%lu\n", sizeof(int[10]));

    fclose(file);
    printf("File created and data written successfully.\n");
    return 0;
}
