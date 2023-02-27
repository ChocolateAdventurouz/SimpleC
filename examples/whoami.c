// A whoami implementation using SimpleC


#include <stdio.h>
#include <stdlib.h>
#include "../simplec.h"

int main(){

    char *whoami_;
    whoami_ = whoami();
    printf("Logged in as: %s", whoami);
}
