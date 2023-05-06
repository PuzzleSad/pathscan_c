#include <stdio.h>
#include <sys/stat.h>
#include <stdint.h>
#include "src/parsing/parse_access.h"

#include "pathscan.h"


int main(){
        printf("PATHSCAN self-test\n");

        // harness();

        struct stat st;
        // int i = stat("/sys/class/thermal/thermal_zone0/temp", &st);
        int i = stat("/sys/class/thermal/thermal_zone0/sustainable_power", &st);

        printf("%u\n", st.st_mode);

        for(int i = 0; i < 32; i++){
                int x = 1 & (st.st_mode >> (31-i) );
                printf("%i", x);
        }
        puts("");

        access_t access = access_from_stat( st.st_mode );
        printf("%i\n", access.other.R);
        access_str_t astr = access_to_str( &access );
        printf("%s\n", astr.str);
        


}
