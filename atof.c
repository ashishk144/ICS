#include <stdio.h>
#include <math.h>
#define SIZE 1000


float atof(char s[]) {
    float res = 0, point_exp = 0.1;
    int sign = 1, sign_exp = 1, exp = 0;
    int point_flag = 0, exp_flag = 0, j = 0;
    if(s[j] == '-') {
        sign = -1;
        j++;
    } else if(s[j] == '+') {
        j++;
    }
    for(int i = j; s[i] != '\0'; i++) {
        //printf("%c\n", s[i]);            
        //printf("%f\n", res);
        if(exp_flag) {
            exp = exp*10 + (s[i] - '0');
            continue;
        }        
        if(s[i] == '.') {
            point_flag = 1;
            continue;
        }
        if(s[i] == 'E' || s[i] == 'e') {
            //printf("here");
            exp_flag = 1;
            if(s[i+1] == '-') {
                sign_exp = -1;
                i++;
                continue;           
            } else if(s[i+1] == '+') {
                i++;
                continue;
            } else {
                continue;
            }        
        }
        if (point_flag && !(exp_flag)) {
            res = res + ((s[i] - '0')*point_exp);
            //printf("%f\n", res);
            point_exp *= 0.1;
            continue;            
            //res *= 0.1;
            //printf("%f\n", res);
    
        }
        res = res*10 + (s[i] - '0');
    }
    exp = sign_exp * exp;
    //printf("%d\n", exp);
    res = res * pow(10, exp) * sign;
    return res;
}

void main() {
    char line[SIZE],c ;
    int i = 0;
    while((c=getchar()) != EOF && c!= '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    printf("%f", atof(line));
}
