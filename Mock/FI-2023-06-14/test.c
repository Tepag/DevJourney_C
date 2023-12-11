#include <stdio.h>

typedef struct{
    char str[100];
}node;

void getString(char* str) {
    printf("Enter a string: ");
    scanf("%s", str);
}

int main() {
    node nd1;
    getString(nd1.str);
    printf("String entered: %s\n", nd1.str);
    return 0;
}
