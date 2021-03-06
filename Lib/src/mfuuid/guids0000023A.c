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

DEFINE_GUID(MFOUTPUT_ANALOGVIDEO, 0x4e9e809c, 0xc2f4, 0x402a, 0x87, 0x66, 0xed, 0x91, 0xd3, 0xf7, 0x16, 0x0f);

