#include "../pathscan.h"
#include "scanner/scanner.h"
#include "messaging/messaging.h"
#include <stdio.h>


const char *patha = "/sys/class/thermal/thermal_zone0";
const char *patha = "/sys/class/thermal/thermal_zone0/";


void pathstep(const char* path){


}

void harness(){
        pathstep(patha);  
}

