// Ensure excessive semi-colons are ignored

void excess_comma(int x) {
    int y = 5;;
    y += 1;;;;;
    ;;;
;
    ;
        ; ;   ;     ;
    return x;
}