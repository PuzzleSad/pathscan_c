#ifndef PSCN_MESSAGING_H
#define PSCN_MESSAGING_H

#include <stdio.h>
#include <stdint.h>
#include "../../pathscan.h"


typedef struct message_t{
        uint32_t status;
        char* input_path;
        char* valid_section;
        char* file;
        uint32_t used_mask;
        int file_valid;
}message_t;

int message_init( message_t* message );

int m_inputpath(  message_t* message, const char* path );
int m_valid_sect( message_t* message, const char* section );
int m_file(       message_t* message, const char* file );
int m_testmask(   message_t* message, const int mask );
int m_filevalid(  message_t* message, const int file_valid );

/*
        Path speficied not valid
        Input path
        Valid section
        File
        mask | file not exist
*/

typedef struct messages_t{
        uint32_t count;
        message_t *messages;
}messages_t;


#endif
