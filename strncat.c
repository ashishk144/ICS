#include <stdio.h>
#include <stdlib.h>

int strncat(char *s,char *t,int n) {
    // printf("%s\n%s\n%d\n",s,t,n);
    int size = 0;
    char *temp = s;
    // *temp = s;
    while(*s++){
        size++;
    }
    *s--;
    // printf("%d\n", size);
    while(n > 0) {
        printf("%s\n", t);
        *s++ = *t++;
        n--;
        size++;
    }
    s = temp;
    s[size] = '\0';
    // printf("%d\n", size);
    // printf("%s\n", --s);
    // while(size > 0) {
    //     *s--;
    //     // printf("%s\n", s);
    //     size--;
    // }
    // s[17] = '\0';
    // printf("%c\n", s[17]);

    // printf("%d\n", size);
    // s = s - size;
    printf("%s\n", s);
    return 0;
}

int main(int argc, char const *argv[])
{
    char l1[1000], c;
    char l2[1000], l3[1000];
    int i;
    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        l1[i] = c;
    }
    l1[i] = '\0';
    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        l2[i] = c;
    }
    l2[i] = '\0';
    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        l3[i] = c;
    }
    l3[i] = '\0';
    i = atoi(l3);
    strncat(l1, l2, i);
    return 0;
}