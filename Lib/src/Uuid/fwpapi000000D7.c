// Created file "Lib\src\Uuid\fwpapi"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(FWPM_CALLOUT_TCP_CHIMNEY_CONNECT_LAYER_V4, 0xf3e10ab3, 0x2c25, 0x4279, 0xac, 0x36, 0xc3, 0x0f, 0xc1, 0x81, 0xbe, 0xc4);

