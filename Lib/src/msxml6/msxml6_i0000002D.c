// Created file "Lib\src\msxml6\msxml6_i"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(IID_IVBSAXDTDHandler, 0x24fb3297, 0x302d, 0x4620, 0xba, 0x39, 0x3a, 0x73, 0x2d, 0x85, 0x05, 0x58);

