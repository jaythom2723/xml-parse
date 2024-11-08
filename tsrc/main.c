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
        

    for(; i < 0xFFFF; i++)
    {
        if(src[i] == NULL)
            break;
    
        printf("%s\n", src[i]);
    }

    close_xml_file(src);

    getc(stdin);

    return 0;
}