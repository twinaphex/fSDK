// Created file "Lib\src\Uuid\uuids"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(IID_IOfflineFilesEvents, 0xe25585c1, 0x0caa, 0x4eb1, 0x87, 0x3b, 0x1c, 0xae, 0x5b, 0x77, 0xc3, 0x14);

DEFINE_GUID(IID_IOfflineFilesEvents2, 0x1ead8f56, 0xff76, 0x4faa, 0xa7, 0x95, 0x6f, 0x6e, 0xf7, 0x92, 0x49, 0x8b);

DEFINE_GUID(IID_IOfflineFilesEvents3, 0x9ba04a45, 0xee69, 0x42f0, 0x9a, 0xb1, 0x7d, 0xb5, 0xc8, 0x80, 0x58, 0x08);

DEFINE_GUID(IID_IOfflineFilesEventsFilter, 0x33fc4e1b, 0x0716, 0x40fa, 0xba, 0x65, 0x6e, 0x62, 0xa8, 0x4a, 0x84, 0x6f);

DEFINE_GUID(IID_IOfflineFilesErrorInfo, 0x7112fa5f, 0x7571, 0x435a, 0x8e, 0xb7, 0x19, 0x5c, 0x7c, 0x14, 0x29, 0xbc);

DEFINE_GUID(IID_IOfflineFilesSyncErrorItemInfo, 0xecdbaf0d, 0x6a18, 0x4d55, 0x80, 0x17, 0x10, 0x8f, 0x76, 0x60, 0xba, 0x44);

DEFINE_GUID(IID_IOfflineFilesSyncErrorInfo, 0x59f95e46, 0xeb54, 0x49d1, 0xbe, 0x76, 0xde, 0x95, 0x45, 0x8d, 0x01, 0xb0);

DEFINE_GUID(IID_IOfflineFilesProgress, 0xfad63237, 0xc55b, 0x4911, 0x98, 0x50, 0xbc, 0xf9, 0x6d, 0x4c, 0x97, 0x9e);

DEFINE_GUID(IID_IOfflineFilesSimpleProgress, 0xc34f7f9b, 0xc43d, 0x4f9d, 0xa7, 0x76, 0xc0, 0xeb, 0x6d, 0xe5, 0xd4, 0x01);

DEFINE_GUID(IID_IOfflineFilesSyncProgress, 0x6931f49a, 0x6fc7, 0x4c1b, 0xb2, 0x65, 0x56, 0x79, 0x3f, 0xc4, 0x51, 0xb7);

DEFINE_GUID(IID_IOfflineFilesSyncConflictHandler, 0xb6dd5092, 0xc65c, 0x46b6, 0x97, 0xb8, 0xfa, 0xdd, 0x08, 0xe7, 0xe1, 0xbe);

DEFINE_GUID(IID_IOfflineFilesItemFilter, 0xf4b5a26c, 0xdc05, 0x4f20, 0xad, 0xa4, 0x55, 0x1f, 0x10, 0x77, 0xbe, 0x5c);

DEFINE_GUID(IID_IOfflineFilesItem, 0x4a753da6, 0xe044, 0x4f12, 0xa7, 0x18, 0x5d, 0x14, 0xd0, 0x79, 0xa9, 0x06);

DEFINE_GUID(IID_IOfflineFilesServerItem, 0x9b1c9576, 0xa92b, 0x4151, 0x8e, 0x9e, 0x7c, 0x7b, 0x3e, 0xc2, 0xe0, 0x16);

DEFINE_GUID(IID_IOfflineFilesShareItem, 0xbab7e48d, 0x4804, 0x41b5, 0xa4, 0x4d, 0x0f, 0x19, 0x9b, 0x06, 0xb1, 0x45);

DEFINE_GUID(IID_IOfflineFilesDirectoryItem, 0x2273597a, 0xa08c, 0x4a00, 0xa3, 0x7a, 0xc1, 0xae, 0x4e, 0x9a, 0x1c, 0xfd);

DEFINE_GUID(IID_IOfflineFilesFileItem, 0x8dfadead, 0x26c2, 0x4eff, 0x8a, 0x72, 0x6b, 0x50, 0x72, 0x3d, 0x9a, 0x00);

DEFINE_GUID(IID_IEnumOfflineFilesItems, 0xda70e815, 0xc361, 0x4407, 0xbc, 0x0b, 0x0d, 0x70, 0x46, 0xe5, 0xf2, 0xcd);

DEFINE_GUID(IID_IOfflineFilesItemContainer, 0x3836f049, 0x9413, 0x45dd, 0xbf, 0x46, 0xb5, 0xaa, 0xa8, 0x2d, 0xc3, 0x10);

DEFINE_GUID(IID_IOfflineFilesChangeInfo, 0xa96e6fa4, 0xe0d1, 0x4c29, 0x96, 0x0b, 0xee, 0x50, 0x8f, 0xe6, 0x8c, 0x72);

DEFINE_GUID(IID_IOfflineFilesDirtyInfo, 0x0f50ce33, 0xbac9, 0x4eaa, 0xa1, 0x1d, 0xda, 0x0e, 0x52, 0x7d, 0x04, 0x7d);

DEFINE_GUID(IID_IOfflineFilesFileSysInfo, 0xbc1a163f, 0x7bfd, 0x4d88, 0x9c, 0x66, 0x96, 0xea, 0x9a, 0x6a, 0x3d, 0x6b);

DEFINE_GUID(IID_IOfflineFilesPinInfo, 0x5b2b0655, 0xb3fd, 0x497d, 0xad, 0xeb, 0xbd, 0x15, 0x6b, 0xc8, 0x35, 0x5b);

DEFINE_GUID(IID_IOfflineFilesPinInfo2, 0x623c58a2, 0x42ed, 0x4ad7, 0xb6, 0x9a, 0x0f, 0x1b, 0x30, 0xa7, 0x2d, 0x0d);

DEFINE_GUID(IID_IOfflineFilesTransparentCacheInfo, 0xbcaf4a01, 0x5b68, 0x4b56, 0xa6, 0xa1, 0x8d, 0x27, 0x86, 0xed, 0xe8, 0xe3);

DEFINE_GUID(IID_IOfflineFilesGhostInfo, 0x2b09d48c, 0x8ab5, 0x464f, 0xa7, 0x55, 0xa5, 0x9d, 0x92, 0xf9, 0x94, 0x29);

DEFINE_GUID(IID_IOfflineFilesConnectionInfo, 0xefb23a09, 0xa867, 0x4be8, 0x83, 0xa6, 0x86, 0x96, 0x9a, 0x7d, 0x08, 0x56);

DEFINE_GUID(IID_IOfflineFilesShareInfo, 0x7bcc43e7, 0x31ce, 0x4ca4, 0x8c, 0xcd, 0x1c, 0xff, 0x2d, 0xc4, 0x94, 0xda);

DEFINE_GUID(IID_IOfflineFilesSuspend, 0x62c4560f, 0xbc0b, 0x48ca, 0xad, 0x9d, 0x34, 0xcb, 0x52, 0x8d, 0x99, 0xa9);

DEFINE_GUID(IID_IOfflineFilesSuspendInfo, 0xa457c25b, 0x4e9c, 0x4b04, 0x85, 0xaf, 0x89, 0x32, 0xcc, 0xd9, 0x78, 0x89);

DEFINE_GUID(IID_IOfflineFilesSetting, 0xd871d3f7, 0xf613, 0x48a1, 0x82, 0x7e, 0x7a, 0x34, 0xe5, 0x60, 0xff, 0xf6);

DEFINE_GUID(IID_IEnumOfflineFilesSettings, 0x729680c4, 0x1a38, 0x47bc, 0x9e, 0x5c, 0x02, 0xc5, 0x15, 0x62, 0xac, 0x30);

DEFINE_GUID(IID_IOfflineFilesCache, 0x855d6203, 0x7914, 0x48b9, 0x8d, 0x40, 0x4c, 0x56, 0xf5, 0xac, 0xff, 0xc5);

DEFINE_GUID(LIBID_OfflineFilesObjects, 0x7f342421, 0x6f28, 0x4548, 0xb7, 0xab, 0x4a, 0x43, 0xce, 0xec, 0x99, 0x9e);

DEFINE_GUID(CLSID_OfflineFilesSetting, 0xfd3659e9, 0xa920, 0x4123, 0xad, 0x64, 0x7f, 0xc7, 0x6c, 0x7a, 0xac, 0xdf);

DEFINE_GUID(CLSID_OfflineFilesCache, 0x48c6be7c, 0x3871, 0x43cc, 0xb4, 0x6f, 0x14, 0x49, 0xa1, 0xbb, 0x2f, 0xf3);
