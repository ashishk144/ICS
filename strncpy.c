#include <stdio.h>
#include <stdlib.h>

int strncpy(char *s1, char *s2, int n) {
    // printf("%s%s%d\n",s1,s2,n);
    int size = 0;
    while(n > 0) {
        *s1++ = *s2++;
        n--;
        size++;
    }
    // printf("%s%d\n", s1,size);
    while(*s1) {
        *s1 = '\0';
        *s1++;
        size++;
    }
    // printf("%d\n", size);
    while(size-- > 0) {
        *s1--;
    }
    printf("%s\n", s1);
    return 0;
}

int main(int argc, char const *argv[])
{
    char l1[1000], l2[1000], l3[1000],c;
    int i;
    for(i = 0; (c=getchar()) != EOF && c != '\n'; i++) {
        l1[i] = c;
    }
    l1[i] = '\0';
    for(i = 0; (c=getchar()) != EOF && c != '\n'; i++) {
        l2[i] = c;
    }
    l2[i] = '\0';
    for(i = 0; (c=getchar()) != EOF && c != '\n'; i++) {
        l3[i] = c;
    }
    l3[i] = '\0';
    i = atoi(l3);
    strncpy(l1,l2,i);
    return 0;
}