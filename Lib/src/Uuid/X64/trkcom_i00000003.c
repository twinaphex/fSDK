// Created file "Lib\src\Uuid\X64\trkcom_i"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(CLSID_TrackFile, 0x8790c947, 0xa30b, 0x11d0, 0x8c, 0xab, 0x00, 0xc0, 0x4f, 0xd9, 0x0f, 0x85);

