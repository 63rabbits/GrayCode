#include <stdio.h>
#include "GrayCode.h"

char *toBinaryStr(unsigned int v, char *s, char sp) {
    char *p = s;
    int skip = 0;
    int count = 0;    // for separate

    for (int i=sizeof(v)*8-1; i>=0; i--) {
        unsigned b = (v >> i) & 0x01;
        p[0] = 0x30 + b;
        p[1] = '\0';
        skip = 1;

        if (sp != '\0') {
            count++;
            if (count > 4) {
                count = 1;
                p[0] = sp;
                p[1] = 0x30 + b;
                p[2] = '\0';
                skip = 2;
            }
        }

        p += skip;
    }
    return s;
}

int main(void) {
    printf("4 bit Binary -> Gray code -> Binary\n");
    printf("-----------------------------------\n");

    char s1[256];
    char s2[256];
    char s3[256];
    for (int i=0; i<16; i++) {

        int g = binaryToGrayCode(i);    // convert to gray code.
        int b = grayCodeToBinary(g);    // convert to binary.

        printf("%s -> %s -> %s\n", &toBinaryStr(i, s1, ' ')[35], &toBinaryStr(g, s2, ' ')[35], &toBinaryStr(b, s3, ' ')[35]);
    }
    return 0;
}
