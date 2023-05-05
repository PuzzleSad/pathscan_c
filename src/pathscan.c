#include "../pathscan.h"
#include "scanner/scanner.h"
#include "messaging/messaging.h"
#include <stdio.h>


const char *patha = "/sys/class/thermal/thermal_zone0";
const char *pathb = "/sys/class/thermal/thermal_zone0/";
const char *pathc = "/sys/class/thermal//thermal_zone0/";


void pathstep(const char* path){
        step_validate(path);

}

void harness(){
        pathstep(patha);  
}

