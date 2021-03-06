// Created file "Lib\src\strmiids\X64\strmiids"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(AM_KSCATEGORY_VBICODEC_MI, 0x9c24a977, 0x0951, 0x451a, 0x80, 0x06, 0x0e, 0x49, 0xbd, 0x28, 0xcd, 0x5f);

