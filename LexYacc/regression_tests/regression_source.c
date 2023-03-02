// int check_scope()
// {
//     int x = 5;
//     {
//       int x = 10;
//     }
//     return x;
// }

int equals_expression(int x) {
    x=(x=2)+1;
    return x;
}

int is_five(int x) {
    if(x == 5) {
        return 1;
    }
    return 0;
}

int y = 5;
int check_global() {
    return y;
}

// int get_sign(int x) {
//     if (x==0) return 0;
//     if (x>0) return 1;
//     return -1;
// }

// int dont_break_pls(int x) {
    // if(x > 0) {
    //     x = -x;
    //     return x;
    // }
    // return -12345;

    // x = (x=2)+2;
    // return x;

    //return x++;
    //return ++x;

    // if(x != 0 && x != 1) {
    //     return 2;
    // }
    // return 0;

    // int y = x++;
    // x;
    // return --x;

    // if(x > 0) {
    //     return x % 3;
    // }
    // return -12345;


    // x = x+1;
    // x = x-1;
    // x = x+-1;
    // x = x+x-x+x-x;
    // x = 5-0;
    // return x;
// }

// int get_sign_return_expressions(int x) {
//     if (x==0) return 0+x;
//     if (x>0) return 1+x;
//     return -1-x;
// }

// int bad_return(int x) {
//     return 1+(2<5);
// }

// int destructive_assignment(int x,int y) {
//     x = x + y;
//     if (x > 0) {
//         return 1;
//     }
//     x = x + 1;
//     if(x >= 1) {
//         return x;
//     }
//     return 42;
// }

// int number_return() {
//     return 5;
// }

// char check_password(char *buf) {
//   if (buf[0] == 'h' && buf[1] == 'e' && buf[2] == 'l' && buf[3] == 'l' && buf[4] == 'o')
//     return 'a';
//   return 'b';
// }


// int check_password(int *buf) {
//   if (buf[0] == 15 && buf[1] == 1 && buf[2] == 99 && buf[3] == -5 && buf[4] == 0)
//     return 1;
//   return 0;
// }

// void lots_of_types() {
//     char c = 'a';
//     int i = 1;
//     double d = 1.0;
//     float f = 1.0;
//     long l = 1;
//     short s = 1;
//     // Something below causes a crash
//     // unsigned char uc = 'a';
//     // unsigned int ui = 1;
//     // unsigned long ul = 1;
//     // unsigned short us = 1;
// }