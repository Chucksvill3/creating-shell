#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int handle_exit(char* token){
    char *code = token+4;
            while(*code &&isspace(*code)){
                code++;
            }
        int status = atoi(code);

return status;
}


int handle_cd(char* token){
    char* path = token+3;
    while(*path &&isspace(*path)){
        path++;
    }


    if(chidir(*path) == -1){
        perror("cd");
        return -1;
    }
    else{
        sentenv("PWD", path,1);
        return 0;
    }




}


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
            int status = handle_exit(token);

            if(status != 0){
                printf("exit status %d\n", status);
                exit(status);
            }
            else{
                exit(0);

            
            }

           

            
        }

        if (strncmp(token, "cd", 2) == 0){
            int status = handle_cd(token);
            if(status != 0){
                printf("cd failed\n");
            }else{
                printf("cd success\n");
            }
        }

        

    

    }


// if (fork()==0){


//     execvp(av[1], av+1);
//     perror("execvp");
// }

return EXIT_SUCCESS;
}
