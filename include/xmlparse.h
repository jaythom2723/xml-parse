#ifndef XML_PARSE_H
#define XML_PARSE_H

#ifdef __cplusplus
extern "C" {
#endif

enum XMLTYPE {
    SELF_CLOSING, // TODO: prototype
    NESTED,
    NORMAL
};

// TODO: Process the source from XML into XMLOBJs
typedef struct xml_obj {
    enum XMLTYPE type;
    const char *tag_name;
    union {
        const char *contents_str;
        struct xml_obj *contents_obj;
    };
} XMLOBJ;

struct xml_obj;
typedef struct xml_obj XMLOBJ;

// TODO: repurpose both functions to use XMLOBJs instead of const char**
const char **open_xml_file(const char *path);
void close_xml_file(const char **src);

#ifdef __cplusplus
}
#endif

#endif // XML_PARSE_H