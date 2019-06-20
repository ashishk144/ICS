#include <stdio.h>
#include <stdlib.h>

int strend(char *s, char *t) {

    int lens, lent;
    for(lens = 0; *(s+lens); lens++) {
        // printf("s = %c\n", *(s+lens));
    }
    for(lent = 0; *(t+lent); lent++) {
        // printf("t = %c\n", *(s+lent));
    }
    // printf("lens = %d\nlent = %d\n", lens, lent);
    // printf("s = %d\n", *s);
    if (lent <= lens) {
        // printf("s0 = %s\n", s);
        s += (lens - lent);
        // printf("news = %c\n", s[0]);
        while(*s++ == *t++) {
            // printf("s = %c\nt = %c\n", *s, *t);
            if(!*s) {
                return 1;
            }
        }
    }
    return 0;

}

void main(int argc, char const *argv[])
{
    char s[1000],c;
    char t[1000];
    int i = 0;
    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    s[i] = '\0';
    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        t[i] = c;
    }
    t[i] = '\0';
    printf("%s\n", s + (6-3));
    printf("%d\n", strend(s, t));
}