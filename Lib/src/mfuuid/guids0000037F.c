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

DEFINE_GUID(SDPBUILDER_ALLOW_CACHING, 0x3fd5a5b2, 0xa840, 0x4d48, 0x82, 0x77, 0x3f, 0x3d, 0x47, 0xdf, 0xd4, 0x65);

