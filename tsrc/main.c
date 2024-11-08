#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xmlparse.h"

int main(void)
{
    int i = 0;
    const char **src = open_xml_file("./inventory.xml");
    if(src == NULL)
    {
        printf("FAILED!\n");
        getc(stdin);
        return -1;
    }

    close_xml_file(src);

    getc(stdin);

    return 0;
}