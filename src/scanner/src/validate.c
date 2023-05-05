

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "validate.h"
#include "../scanner.h"

/*
        Note to self
        A dir with only x perm set for the accessing user is accessable.
        also, that user can enter another x-marked dir in that directory even 
        though they cannot ls to see that directory.
*/



int validate_file( const char* path, int isLastFile, int mask_need ){
        if( isLastFile ){

        }

        if( mask_need == 0 ){   //default behaviour
                mask_need = MASK_DEFAULT;
        }
        
}

int validate_dir( const char* path, int mask_need ){

}


int access_validate( const char* path, int mask ){
        if( access( path, F_OK) != 0 ){
                
        }

        if( (mask & X_OK) != X_OK ){    

        }

        if( (mask & W_OK) != W_OK ){

        }       

        if( (mask & R_OK) != R_OK ){

        }       

}
