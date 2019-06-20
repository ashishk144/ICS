#include <stdio.h>
#define SIZE 1000

int strrindex(char s[], char t) {
int result = -1;
for(int i = 0; s[i] != '\0'; i++) {
    if(s[i] == t) {
        result = i;
    }
}
return result;
}

void main() {

char line[SIZE], c;
int i = 0;
while((c=getchar()) != EOF && c!='\n') {
    line[i++] = c;
}
line[i] = '\0';
c = getchar();
printf("%d\n", strrindex(line, c));

}
