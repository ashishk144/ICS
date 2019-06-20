#include <stdio.h>
#define SIZE 1000

void main() {

char line[SIZE];
char c;
int i = 0;
while ((c = getchar()) != EOF && c != '\n') {
    line[i++] = c;
}

int j = 0;
int count = 0;
while (j < i) {
    if(line[j] == '_') {
        if(count == 0) {
            printf("%c",line[j]);
        }
        count++;
    } else {
        count = 0;
        printf("%c",line[j]);
    }
    j++;
}

}
