#include <stdio.h>
#include <math.h>
#define SIZE 1000


int htoi(char s[], int len) {
int val = 0;
int i = 0;
//printf("%d", s);
if((s[0] == '0' && s[1] == 'x') || (s[0] == '0' && s[1] == 'X')) {
        i+=2;
}
while(i < len) {
    //printf("c = %c\n", s[i]);
    //printf("d = %d\n", (len - (i + 1)));
    if (s[i] >= '0' && s[i] <= '9') {
        val += (s[i] - '0')*pow(16, len-(i+1));
    } else if (s[i] == 'a' || s[i] == 'A') {
        val += 10*pow(16, len-(i+1));
    } else if (s[i] == 'B' || s[i] == 'b') {
        val += 11*pow(16, len-(i+1));
    } else if (s[i] == 'c' || s[i] == 'C') {
        val += 12*pow(16, len-(i+1));
    } else if (s[i] == 'D' || s[i] == 'd') {
        val += 13*pow(16, len-(i+1));
    } else if (s[i] == 'e' || s[i] == 'E') {
        val += 14*pow(16, len-(i+1));
    } else if (s[i] == 'f' || s[i] == 'F') {
        val += 15*pow(16, len-(i+1));
    } else {
        break;
    }
    //printf("%d\n", val);
    i++;
}
return val;
}

void main() {

int i = 0;
char line[SIZE];
char c;
while((c=getchar()) != EOF && c != '\n') {
    //printf("%c", c);
    line[i++] = c;
}
//line[i++] = '\0';
//printf("%s",line);
printf("%d", htoi(line, i));

}
