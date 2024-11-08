#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <Windows.h>

#include "xmlparse.h"

#define MAX_LINES 0xFFFF

FILE *_open_file(const char *path, size_t *size);
void _get_file_source(FILE *file);
void _clean_file_source(void);

static char *src[MAX_LINES] = { 0 };
static char **src_ptr = src;

const char **open_xml_file(const char *path)
{
    size_t size = 0;
    FILE *file = _open_file(path, &size);
    if(file == NULL)
        return NULL;

    _get_file_source(file);
    _clean_file_source();

    fclose(file);

    return (const char **) src;
}

void close_xml_file(const char **src)
{
    int i = 0;
    for(; i < MAX_LINES; i++)
    {
        free((void*) src[i]);
        src[i] = NULL;
    }
}

FILE *_open_file(const char *path, size_t *size)
{
    FILE *ret = fopen(path, "r");
    if(ret == NULL)
        return NULL;

    fseek(ret, 0L, SEEK_END);
    (*size) = ftell(ret);
    rewind(ret);

    return ret;
}

void _get_file_source(FILE *file)
{
    char *line = NULL;
    size_t len = 0;

    while(getline(&line, &len, file) != -1)
    {
        (*src_ptr) = strdup(line);
        src_ptr++;
    }
}

void _clean_file_source(void)
{
    int i = 0;
    char *cptr = NULL;
    int ci = 0;

    for(; i < MAX_LINES; i++)
    {
        if(src[i] == NULL)
            break;

        cptr = strchr(src[i], '\n');
        if(cptr == NULL)
            continue;
        ci = (cptr - (src[i]));
        src[i][ci] = '\0';
    }
}