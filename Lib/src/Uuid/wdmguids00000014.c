// Created file "Lib\src\Uuid\wdmguids"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(GUID_INT_ROUTE_INTERFACE_STANDARD, 0x70941bf4, 0x0073, 0x11d1, 0xa0, 0x9e, 0x00, 0xc0, 0x4f, 0xc3, 0x40, 0xb1);

