// Created file "Lib\src\WiaGuid\X64\wiamindr_guids"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(IID_IWiaMiniDrvCallBack, 0x33a57d5a, 0x3de8, 0x11d2, 0x9a, 0x36, 0x00, 0xc0, 0x4f, 0xa3, 0x61, 0x45);

