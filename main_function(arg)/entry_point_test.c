#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int arg, char** argc, char** envp) {
    int i = 0;
    while (envp[i])
    printf("%s\n", envp[i++]);
}