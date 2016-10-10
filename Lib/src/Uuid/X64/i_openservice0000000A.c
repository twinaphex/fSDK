// Created file "Lib\src\Uuid\X64\i_openservice"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(IID_IOpenServiceActivity, 0x13645c88, 0x221a, 0x4905, 0x8e, 0xd1, 0x4f, 0x51, 0x12, 0xcf, 0xc1, 0x08);
