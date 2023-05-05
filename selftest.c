#include <stdio.h>
#include <sys/stat.h>
#include <stdint.h>

#include "pathscan.h"


int main(){
        printf("PATHSCAN self-test\n");

        // harness();

        struct stat st;
        int i = stat("/sys/class/thermal/thermal_zone0/temp", &st);

        printf("%lu\n", st.st_mode);

        for(int i = 0; i < 32; i++){
                int x = 1 & (st.st_mode >> (31-i) );
                printf("%i", x);
        }
        puts("");

        


}
