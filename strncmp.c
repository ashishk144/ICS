#include <stdio.h>

int strcmp(char *s1, char *s2, int n) {

    int ls = 0, lt = 0;

    for(;*(s1+ls);ls++);
    for(;*(s1+lt);lt++);
    // if(ls != lt) {
    //     return 0;
    // }
    while(n-- > 0 && *s1++ == *s2++) {
        if(n==1 || n==0) {
            return 1;
        }
    }
    return 0;

}


int main(int argc, char const *argv[])
{
    char s[1000], c;
    char t[1000];
    int i;
    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    s[i] = '\0';
    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        t[i] = c;
    }
    t[i] = '\0';
    printf("%d\n",strcmp(s, t, 4));
    return 0;
}