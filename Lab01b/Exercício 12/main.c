#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    const char* str = "Valor";
    int busca = 'l';
    int pos = strchr(str, busca) - str;
    printf("%d\n", pos);
    return 0;
}