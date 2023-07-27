#include <stdio.h>

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
    fprintf(file, "Type,Size_in_bytes\n");

    fprintf(file, "char,%lu\n", sizeof(char));
    fprintf(file, "signed char,%lu\n", sizeof(signed char));
    fprintf(file, "unsigned char,%lu\n", sizeof(unsigned char));

    fprintf(file, "short,%lu\n", sizeof(short));
    fprintf(file, "signed short,%lu\n", sizeof(signed short));
    fprintf(file, "unsigned short,%lu\n", sizeof(unsigned short));

    fprintf(file, "short int,%lu\n", sizeof(short int));
    fprintf(file, "signed short int,%lu\n", sizeof(signed short int));
    fprintf(file, "unsigned short int,%lu\n", sizeof(unsigned short int));

    fprintf(file, "int,%lu\n", sizeof(int));
    fprintf(file, "signed int,%lu\n", sizeof(signed int));
    fprintf(file, "unsigned int,%lu\n", sizeof(unsigned int));
    fprintf(file, "signed,%lu\n", sizeof(signed));
    fprintf(file, "unsigned,%lu\n", sizeof(unsigned));

    fprintf(file, "long,%lu\n", sizeof(long));
    fprintf(file, "unsigned long,%lu\n", sizeof(unsigned long));
    fprintf(file, "signed long,%lu\n", sizeof(signed long));

    fprintf(file, "long int,%lu\n", sizeof(long int));
    fprintf(file, "signed long int,%lu\n", sizeof(signed long int));
    fprintf(file, "unsigned long int,%lu\n", sizeof(unsigned long int));


    fprintf(file, "long long,%lu\n", sizeof(long long));
    fprintf(file, "unsigned long long,%lu\n", sizeof(unsigned long long));
    fprintf(file, "signed long long,%lu\n", sizeof(signed long long));

    fprintf(file, "long long int,%lu\n", sizeof(long long int));
    fprintf(file, "signed long long int,%lu\n", sizeof(signed long long int));
    fprintf(file, "unsigned long long int,%lu\n", sizeof(unsigned long long int));

    fprintf(file, "float,%lu\n", sizeof(float));
    fprintf(file, "double,%lu\n", sizeof(double));
    fprintf(file, "long double,%lu\n", sizeof(long double));

    fprintf(file, "pointer,%lu\n", sizeof(void*));
    fprintf(file, "_Bool,%lu\n", sizeof(_Bool));

//    fprintf(file, "sampleStruct,%lu\n", sizeof(struct sampleStruct)); // This has alignment/padding to account for. 8 * 3 = 24
//    fprintf(file, "int array[10],%lu\n", sizeof(int[10]));
    fprintf(file, "enum,%lu\n", sizeof(enum week)); // Usually int size

    fclose(file);
    printf("File created and data written successfully.\n");
    return 0;
}
