#include <stdio.h>


unsigned invert(unsigned x, int p, int n);


int main() {
     printf("%u\n", invert(129, 2, 4));

     return 0;
}


unsigned invert(unsigned x, int p, int n) {
    unsigned val;
    /*
        129 =  10000001
        p = 2 ~01234567
        n = 4  10----01
                 0000
                 1111
               10111101 == 189
    */
    val = x ^ (~(~0u << n) << p);
}
