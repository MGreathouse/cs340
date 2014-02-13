#include <stdio.h>


// setbits:     returns x from position p for n spots as well as the rightmost n in y
unsigned setbits(unsigned x, int p, int n, unsigned y);


int main() {
    printf("%u\n", setbits(1234, 5, 2, 789));

    return 0;
}


unsigned setbits(unsigned x, int p, int n, unsigned y) {
    /*
        1234 = 10011010010
        p = 5 ~01234567890 
                    010010
                    01
        n = 2      ~010000 == 16

    */
    unsigned a = (x & ~(~(~0u << n) << (p + 1 - n)));
    printf("%u\n", a);

    /*
        789 =  1100010101
        n = 2 ~0123456789
                       01

        10011 00 0010 < number sent in
        10011 01 0010 < number with the two above swapped in

        10011010010 = 1218
    */
    unsigned b = ((y & ~(~0u << n)) << (p + 1 - n));
    printf("%u\n", b);

    //I think this acts like a mask
    return a | b; // and this should return the number sent in
}
