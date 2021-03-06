// Created file "Lib\src\Uuid\ctfutb_i"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(IID_ITfLangBarMgr, 0x87955690, 0xe627, 0x11d2, 0x8d, 0xdb, 0x00, 0x10, 0x5a, 0x27, 0x99, 0xb5);

DEFINE_GUID(IID_ITfLangBarEventSink, 0x18a4e900, 0xe0ae, 0x11d2, 0xaf, 0xdd, 0x00, 0x10, 0x5a, 0x27, 0x99, 0xb5);

DEFINE_GUID(IID_ITfLangBarItemSink, 0x57dbe1a0, 0xde25, 0x11d2, 0xaf, 0xdd, 0x00, 0x10, 0x5a, 0x27, 0x99, 0xb5);

DEFINE_GUID(IID_IEnumTfLangBarItems, 0x583f34d0, 0xde25, 0x11d2, 0xaf, 0xdd, 0x00, 0x10, 0x5a, 0x27, 0x99, 0xb5);

DEFINE_GUID(IID_ITfLangBarItemMgr, 0xba468c55, 0x9956, 0x4fb1, 0xa5, 0x9d, 0x52, 0xa7, 0xdd, 0x7c, 0xc6, 0xaa);

DEFINE_GUID(IID_ITfLangBarItem, 0x73540d69, 0xedeb, 0x4ee9, 0x96, 0xc9, 0x23, 0xaa, 0x30, 0xb2, 0x59, 0x16);

DEFINE_GUID(IID_ITfSystemLangBarItemSink, 0x1449d9ab, 0x13cf, 0x4687, 0xaa, 0x3e, 0x8d, 0x8b, 0x18, 0x57, 0x43, 0x96);

DEFINE_GUID(IID_ITfSystemLangBarItem, 0x1e13e9ec, 0x6b33, 0x4d4a, 0xb5, 0xeb, 0x8a, 0x92, 0xf0, 0x29, 0xf3, 0x56);

DEFINE_GUID(IID_ITfSystemLangBarItemText, 0x5c4ce0e5, 0xba49, 0x4b52, 0xac, 0x6b, 0x3b, 0x39, 0x7b, 0x4f, 0x70, 0x1f);

DEFINE_GUID(IID_ITfSystemDeviceTypeLangBarItem, 0x45672eb9, 0x9059, 0x46a2, 0x83, 0x8d, 0x45, 0x30, 0x35, 0x5f, 0x6a, 0x77);

DEFINE_GUID(IID_ITfLangBarItemButton, 0x28c7f1d0, 0xde25, 0x11d2, 0xaf, 0xdd, 0x00, 0x10, 0x5a, 0x27, 0x99, 0xb5);

DEFINE_GUID(IID_ITfLangBarItemBitmapButton, 0xa26a0525, 0x3fae, 0x4fa0, 0x89, 0xee, 0x88, 0xa9, 0x64, 0xf9, 0xf1, 0xb5);

DEFINE_GUID(IID_ITfLangBarItemBitmap, 0x73830352, 0xd722, 0x4179, 0xad, 0xa5, 0xf0, 0x45, 0xc9, 0x8d, 0xf3, 0x55);

DEFINE_GUID(IID_ITfLangBarItemBalloon, 0x01c2d285, 0xd3c7, 0x4b7b, 0xb5, 0xb5, 0xd9, 0x74, 0x11, 0xd0, 0xc2, 0x83);

DEFINE_GUID(IID_ITfMenu, 0x6f8a98e4, 0xaaa0, 0x4f15, 0x8c, 0x5b, 0x07, 0xe0, 0xdf, 0x0a, 0x3d, 0xd8);

