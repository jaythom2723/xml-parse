#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "xmlparse.h"

int main(void)
{
    const char *ret = open_xml_file("inventory.xml");
    if(ret == NULL)
        printf("FAILED!\n");

    getc(stdin);

    return 0;
}