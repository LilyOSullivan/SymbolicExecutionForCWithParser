int check_scope(int y)
{
    int x = y + 2;
    if (x > 0) {
        return 1;
    } else {
        x = x + 1;
        return x;
    }
}

// int get_sign(int x) {
//     if (x==0) return 0;
//     if (x>0) return 1;
//     return -1;
// }

int is_five(int x) {
    if(x == 5) {
        return 1;
    }
    return 0;
}

// int get_sign(int x) {
//     if (x==0) return 0+x;
//     if (x>0) return 1+x;
//     return -1-x;
// }

int valid_return(int x) {
   return 1+(2<5);
}

// int give_five() {
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
