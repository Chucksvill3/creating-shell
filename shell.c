#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char** arg) {
    char input[1024];
    char *token;
    while (1){
        printf("prompt$ ");
       if( fgets(input, sizeof(input), stdin)==NULL){
           perror("problem with input");
           exit(1);
       }

        strtok(input, "\n");
        token = strtok(input, " ");
        if (token == NULL){
            continue;
        }
        if (strncmp(token, "exit", 4) == 0 ){
            char *code = token+4;
            while(*code &&isspace(*code)){
                code++;
            }

            if(isdigit(*code)){
                exit(atoi(code));
            }else{
                exit(0);
            }

            
        }

        

    

    }


// if (fork()==0){


//     execvp(av[1], av+1);
//     perror("execvp");
// }

return EXIT_SUCCESS;
}
