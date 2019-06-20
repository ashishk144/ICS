# include<stdio.h>
#define SIZE 1000

void main() {

    char line[SIZE];

    int i = 0;
    char c;
    while((c = getchar())!=EOF && c != '\n') {
        line[i++] = c;
    }

    while(i>=1) {
        printf("%c",line[--i]);
    }

}
