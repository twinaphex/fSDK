// Created file "Lib\src\Uuid\termmgr_i"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(IID_ITPluggableTerminalSuperclassRegistration, 0x60d3c08a, 0xc13e, 0x4195, 0x9a, 0xb0, 0x8d, 0xe7, 0x68, 0x09, 0x0f, 0x25);

