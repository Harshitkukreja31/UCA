#include "calculator.h"

// Bitwise arithmetic 
int add(int a, int b) {
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int subtract(int a, int b) {
    return add(a, add(~b, 1));
}

int multiply(int a, int b) {
    int result = 0;
    while (b != 0) {
        if (b & 1) {
            result = add(result, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}

int divide(int dividend, int divisor) {
    if (divisor == 0) {
        return -1;  
    }

    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    dividend = dividend < 0 ? -dividend : dividend;
    divisor = divisor < 0 ? -divisor : divisor;
    
    int quotient = 0;
    while (dividend >= divisor) {
        int temp = divisor, multiple = 1;
        while (dividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dividend -= temp;
        quotient = add(quotient, multiple);
    }
    return sign * quotient;
}