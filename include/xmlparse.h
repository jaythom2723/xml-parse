#ifndef XML_PARSE_H
#define XML_PARSE_H

#ifdef __cplusplus
extern "C" {
#endif

// TODO: Process the source from XML into XMLOBJs
typedef struct {
    const char *type;
    union {
        const char *contents_str;
        XMLOBJ contents_obj;
    };
} XMLOBJ;

const char **open_xml_file(const char *path);
void close_xml_file(const char **src);

#ifdef __cplusplus
}
#endif

#endif // XML_PARSE_H