// Created file "Lib\src\MsXml2\X64\msxml2_i"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(CLSID_XMLSchemaCache, 0x373984c9, 0xb845, 0x449b, 0x91, 0xe7, 0x45, 0xac, 0x83, 0x03, 0x6a, 0xde);

