#include "../scanner.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Re-defines for easier short-hand
#define MAX_FLEN MAX_FILE_NAME_LEN
#define MAX_PLEN MAX_PATH_LEN

typedef struct sc_args_t{
        char* path;
        size_t len;
}sc_args_t;

static int step_twopointer( sc_args_t* sc );
static int step_token( sc_args_t* sc );


int step_validate( const char* path ){
        size_t str_len = strlen(path);

        
        
        //Create copy of path
        char pathcopy[str_len +1];
        memcpy( pathcopy, path, str_len );
        pathcopy[str_len] = '\0';

        sc_args_t sc_args;
        sc_args.path = pathcopy;
        sc_args.len = str_len;


        step_twopointer( &sc_args );
        
        


        return 1;

}


static int step_twopointer( sc_args_t* sc ){
        printf("%s\n", sc->path);
        int offset = 0;
        // int delim_offset = 0;

        int i = 0;

        if( sc->path[i] == '/' ){       //Edge case, see explanation below
                i++;
        }

        /*      
                (first iteration)
                step until we hit '/'
                if we get '/', we set the CURRENT '/' to be a string terminator
                thus, any prints will print up to where we are

                set delim to current pos
                when we find a new '/', set char at delim to be '/'
                and the new '/' to '\0'
                repeat
        */

        for( i ; i < sc->len; i++){

                if( sc->path[i] == '/' ){
                        
                        sc->path[i] = '\0';
                        sc->path[offset] = '/';

                        printf("%s\n", sc->path);
                        offset = i;
                } 

        }

}


static int csssstep_twopointer( sc_args_t* sc ){
        printf("%s\n", sc->path);
        int offset = 0;
        // int delim_offset = 0;

        int i = 0;

        if( sc->path[i] == '/' ){
                i++;
                offset++;
        }

        for( i ; i < sc->len; i++){

                if( sc->path[i] == '/' ){
                        sc->path[i] = '\0';
                        printf("%s\n", &sc->path[offset]);
                        offset = i + 1;
                } 

        }

}

static int step_token( sc_args_t* sc ){
        char* token = NULL;
        char delim[2] = "/";

        token = strtok( sc->path, delim );

        while( token != NULL){
                printf("%s\n", token);

                token = strtok( NULL, delim );
        }

}
