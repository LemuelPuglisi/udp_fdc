#include <stdio.h>
#include "errh.h"

int report_error (char* error) 
{
    printf ("%s\n", error); 
    return -1; 
} 
