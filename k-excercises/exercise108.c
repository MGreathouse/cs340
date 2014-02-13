#include <stdio.h>

// store distance
typedef struct {
    int m, cm;
} Length;

Length ladd(Length p1, Length p2);
Length lminus(Length p1, Length p2);
int lcompare(Length p1, Length p2);

int main() {
    Length l1, l2, l3, l4;

    l1.m = 110;
    l1.cm = 120;

    l2.m = 120;
    l2.cm = 130;

    l3.m = 120;
    l3.cm = 110;

    if(lcompare(l1, l2) == 0)
        printf("Compare Broken\n");
    if(lcompare(l3, l2) == 0)
        printf("Compare Broken\n");
    if(lcompare(l1, l1) == 0 && lcompare(l2,l3) > 0)
        printf("Compare Works\n");
        
    l4 = ladd(l1, l2);
    printf("%dm %dcm + %dm %dcm = %dm %dcm\n", l1.m, l1.cm, l2.m, l2.cm, l4.m, l4.cm);
        
    l4 = lminus(l1, l2);
    printf("%dm %dcm - %dm %dcm = %dm %dcm\n", l1.m, l1.cm, l2.m, l2.cm, l4.m, l4.cm);
        
    l4 = lminus(l3, l2);
    printf("%dm %dcm - %dm %dcm = %dm %dcm\n", l3.m, l3.cm, l2.m, l2.cm, l4.m, l4.cm);
    
    return 0;
}

int lcompare(Length p1, Length p2) {
    int total1, total2;
    total1 = p1.m * 100 + p1.cm;
    total2 = p2.m * 100 + p2.cm;
    if (total1 > total2) return 1;  //p1 is greater than p2
    if (total1 < total2) return -1; //p1 is less than p2
    if (total1 == total2) return 0; //p1 is equal to p2
}

Length ladd(Length p1, Length p2) {
    Length total;
    int m=0, cm=0;
    
    cm = p1.cm + p2.cm;
    while(cm > 100) {
        cm -= 100;
        m++;
    }
    
    m += p1.m + p2.m;
    
    total.m = m;
    total.cm = cm;
    return total;
}

Length lminus(Length p1, Length p2) {
    Length total;
    int m=0;
    int total1, total2, total3;
    total1 = p1.m * 100 + p1.cm;
    total2 = p2.m * 100 + p2.cm;
    
    total3 = total1 - total2;
    
    while(total3 > 100) {
        total3 -= 100;
        m++;
    }
    
    while(total3 < -100) {
        total3 += 100;
        m--;
    }
    
    total.m = m;
    total.cm = total3;
    return total;
}
