#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
// #define NUMBER_OF_LINES 10
void tail_file(int nolines) {
        char character;
        // char * tail=NULL; 
        // tail = (char *) malloc(sizeof(char));
        void *abc;
        int num_lines=1,N_Lines_To_Print = nolines;
        FILE *fd;
 
        if((fd = fopen("log.txt","r")) == NULL){
                printf("Unable to open the file\n");
        }
 
        while(fread(&abc,1,1,fd))
        {
                character = (char *)abc;
                // printf("%c\n", character);
                if(character == '\n')
                        num_lines++;
        }
 		// printf("%d\n", num_lines);
        fseek(fd,0L,SEEK_SET);
        if(num_lines > N_Lines_To_Print)
                num_lines -= N_Lines_To_Print;
        else
                num_lines = 0;
 		// printf("%d\n", num_lines);
        while(fread(&abc,1,1,fd)){
                character = (char *)abc;
                if(!(num_lines)) {  
					printf("%c",character);
                }
                else if(character == '\n') {
                    num_lines--;
                }
        }
        printf("\n");
 
    // return tail;
}

int main (int argc, char *argv[]) {
	int opt, n = 10;
    // char * text;
    while((opt = getopt(argc, argv, "v:")) != -1) {
        // printf("%s\n", optarg);
        switch(opt) {
            case 'v': n = atoi(optarg);
            // printf("%d\n", n);
            break;
            default:
            break;
        }
    }
    tail_file(n);
    // printf("%s\n", text);
    // free(text);
    return 0;
}
