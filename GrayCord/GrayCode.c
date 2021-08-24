//
//  GrayCode.c
//  GrayCode
//
//  Created by rabbit on 2021/08/16.
//


unsigned int binaryToGrayCode(unsigned int b) {
    return b ^ (b >> 1);
}

unsigned int grayCodeToBinary(unsigned int g) {
    unsigned int b = g ^ (g >> 1);

    for (int i=2; i<sizeof(g)*8; i*=2) {
        b = b ^ (b >> i);
    }
    return b;
}
