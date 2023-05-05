#ifndef PSCN_SCANNER_H
#define PSCN_SCANNER_H

#include <unistd.h>
#include "../../pathscan.h" /* Obtain Max length defines */

#define MASK_DEFAULT (R_OK|W_OK)        //Entering 0 in mask field will force MASK_DEFAULT use

int step_validate( const char* path );


#endif
