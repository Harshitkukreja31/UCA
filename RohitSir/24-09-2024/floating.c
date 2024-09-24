#include <stdio.h>

int main() {
    int num = 42;
    double pi = 3.14159;
    char str[] = "Hello, stdout!";
    FILE *file = fopen("examples.txt", "a");
    fprintf(stdout, "Integer: %d\n", num);
    fprintf(stdout, "Floating-point: %f\n", pi);//writing in console
    fprintf(file, "String: %s\n", str); //writing in examples.txt

    return 0;
}