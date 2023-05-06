#include "../parse_access.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

static void parse_owner_perms( access_t* access, uint32_t st_mode );
static void parse_group_perms( access_t* access, uint32_t st_mode );
static void parse_other_perms( access_t* access, uint32_t st_mode );
static char parse_get_fileType_char( access_t* access );


access_t access_from_stat( uint32_t st_mode ){
        access_t access;
        memset( &access, 0, sizeof(access_t) );


        access.st_mode = st_mode;       

        parse_owner_perms( &access, st_mode );
        parse_group_perms( &access, st_mode );
        parse_other_perms( &access, st_mode );

        


        return access;
}




static void parse_owner_perms( access_t* access, uint32_t st_mode ){
        perms_t* owner = &access->owner;


        if( (S_IRUSR & st_mode) && S_IRUSR ){ owner->R = 1; }
        if( (S_IWUSR & st_mode) && S_IWUSR ){ owner->W = 1; }
        if( (S_IXUSR & st_mode) && S_IXUSR ){ owner->X = 1; }

        //Earlier memset to init data to 0
}

static void parse_group_perms( access_t* access, uint32_t st_mode ){
        perms_t* group = &access->group;

        if( (S_IRGRP & st_mode) && S_IRGRP ){ group->R = 1; }
        if( (S_IWGRP & st_mode) && S_IWGRP ){ group->W = 1; }
        if( (S_IXGRP & st_mode) && S_IXGRP ){ group->X = 1; }

        //Earlier memset to init data to 0
}

static void parse_other_perms( access_t* access, uint32_t st_mode ){
        perms_t* other = &access->other;

        if( (S_IROTH & st_mode) && S_IROTH ){ other->R = 1; }
        if( (S_IWOTH & st_mode) && S_IWOTH ){ other->W = 1; }
        if( (S_IXOTH & st_mode) && S_IXOTH ){ other->X = 1; }

        //Earlier memset to init data to 0
}

static char parse_get_fileType_char( access_t* access ){
        uint32_t m = access->st_mode;

        if( S_ISBLK(m)  ){ return 'b' ;}
        if( S_ISCHR(m)  ){ return 'c' ;}
        if( S_ISDIR(m)  ){ return 'd' ;}
        if( S_ISFIFO(m) ){ return 'p' ;}        /* TODO Verify */
        if( S_ISREG(m)  ){ return '-' ;}
        if( S_ISLNK(m)  ){ return 'l' ;}
        if( S_ISSOCK(m) ){ return 's' ;}
}

// u  g  o
// rwxrwxrwx
access_str_t access_to_str( access_t* access ){
        access_str_t access_str;
        memset( &access_str, ' ', sizeof(access_str_t) );

        size_t str_len = sizeof(access_str_t) -1;       //-1 for '\0'
        access_str.str[str_len] = '\0';
        
        //I sadly have no better solution at the moment
        
        if( access->owner.R ){ access_str.str[1] = 'r'; }else{ access_str.str[1] = '-'; }
        if( access->owner.W ){ access_str.str[2] = 'w'; }else{ access_str.str[2] = '-'; }
        if( access->owner.X ){ access_str.str[3] = 'x'; }else{ access_str.str[3] = '-'; }
        
        if( access->group.R ){ access_str.str[4] = 'r'; }else{ access_str.str[4] = '-'; }
        if( access->group.W ){ access_str.str[5] = 'w'; }else{ access_str.str[5] = '-'; }
        if( access->group.X ){ access_str.str[6] = 'x'; }else{ access_str.str[6] = '-'; }

        if( access->other.R ){ access_str.str[7] = 'r'; }else{ access_str.str[7] = '-'; }
        if( access->other.W ){ access_str.str[8] = 'w'; }else{ access_str.str[8] = '-'; }
        if( access->other.X ){ access_str.str[9] = 'x'; }else{ access_str.str[9] = '-'; }
        

        return access_str;

}
