// Ensure excessive semi-colons are ignored

int excess_comma(int x) {
    int y = 5;;
    ;y += 1;;;;;
    ;;;
;
    ;
        ; ;   ;     ;
    return x;
}