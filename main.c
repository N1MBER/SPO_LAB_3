#include <stdio.h>
#include <string.h>
#include "Server/server.h"
#include "Client/client.h"
#include <stdlib.h>

#define WGET_PATH "/usr/local/bin/wget"

int main(int argc, char *argv[]) {
    printf("Good morning\n");
    printf("Checking arguments...\n");

    if(argc < 2){
        printf("Not enough arguments");
        return 0;
    }

    if(strcmp(argv[1],"server") == 0 && argc ){
        printf("Start as server\n");
        if(argc < 3){
            printf("Not enough arguments for server");
            return 0;
        }
        execute_server(argv[2], argv[3]);
    }else if (strcmp(argv[1],"client") == 0 && argc ){
        printf("Start as client\n");
        start_client(argc, argv);
        char *arr = malloc(1000*sizeof(char));
        if (argc < 4) {
       	   char *boilerplate = strcat(WGET_PATH, "  -q -p --header=\"User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_0) AppleWebKit/600.1.17 (KHTML, like Gecko) Version/8.0 Safari/600.1.17\" -e robots=off ");
       	   strcat(arr, boilerplate);
       	   strcat(arr, argv[argc - 1]);
    	   system(arr);
    	} else {
           char *boilerplate = strcat(WGET_PATH, "  -q ");
           strcat(arr, boilerplate);
       	   strcat(arr, argv[argc - 1]);
    	   system(arr);
        }
    } else {
        printf("Startup arguments are incorrect\n");
    }

    printf("Bye\n");
    return 0;
}
