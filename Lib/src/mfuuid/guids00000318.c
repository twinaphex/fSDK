// Created file "Lib\src\mfuuid\guids"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(MF_TIMESTAMP_SOURCE_SERVICE, 0xc85102a7, 0xd528, 0x4fb2, 0xb4, 0xc7, 0xf8, 0x04, 0xcb, 0x00, 0x24, 0xa9);

