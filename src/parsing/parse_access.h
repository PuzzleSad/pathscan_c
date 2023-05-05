#ifndef PARSE_ACCESS_H
#define PARSE_ACCESS_H

#include <stdint.h>

typedef struct perms_t{
        uint8_t R;
        uint8_t W;
        uint8_t X;
}perms_t;

typedef struct access_t{
        perms_t owner;
        perms_t group;
        perms_t other;

        int file_type;
}access_t;

typedef struct access_str_t{
        char str[20];
}access_str_t;

access_t access_from_stat( uint32_t st_mode );

access_str_t access_to_str( access_t* access );

#endif