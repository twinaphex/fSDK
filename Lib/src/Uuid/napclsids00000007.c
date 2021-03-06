// Created file "Lib\src\Uuid\napclsids"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(CLSID_NapServerManagement, 0xbfcb2c6d, 0x04aa, 0x4fb9, 0xbc, 0x72, 0x58, 0xe1, 0xaf, 0x64, 0xbe, 0x39);

