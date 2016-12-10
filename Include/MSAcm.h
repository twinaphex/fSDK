/*+@@file@@----------------------------------------------------------------*//*!
 \file		MSAcm.h
 \par Description 
            Extension and update of headers for PellesC compiler suite.
 \par Project: 
            PellesC Headers extension
 \date		Created  on Sun Aug  7 23:12:02 2016
 \date		Modified on Sun Aug  7 23:12:02 2016
 \author	frankie
\*//*-@@file@@----------------------------------------------------------------*/

#ifndef _INC_ACM
#define _INC_ACM
#if __POCC__ >= 500
#pragma once
#endif
#if !defined(_INC_MMREG) || (_INC_MMREG < 142)
#ifndef RC_INVOKED
#error MMREG.H version 142 or greater to be included first
#endif
#endif
#if defined(WIN32) && !defined(_WIN32)
#ifndef RC_INVOKED
#pragma message("MSACM.H: defining _WIN32 because application defined WIN32")
#endif
#define _WIN32
#endif
#if defined(UNICODE) && !defined(_UNICODE)
#ifndef RC_INVOKED
#pragma message("MSACM.H: defining _UNICODE because application defined UNICODE")
#endif
#define _UNICODE
#endif
#include <pshpack1.h>
#ifndef DRV_MAPPER_PREFERRED_INPUT_GET
#define DRV_MAPPER_PREFERRED_INPUT_GET  (DRV_USER + 0)
#endif
#ifndef DRV_MAPPER_PREFERRED_OUTPUT_GET
#define DRV_MAPPER_PREFERRED_OUTPUT_GET (DRV_USER + 2)
#endif
#ifndef DRVM_MAPPER_STATUS
#define DRVM_MAPPER             (0x2000)
#define DRVM_MAPPER_STATUS      (DRVM_MAPPER+0)
#endif
#ifndef WIDM_MAPPER_STATUS
#define WIDM_MAPPER_STATUS              (DRVM_MAPPER_STATUS + 0)
#define WAVEIN_MAPPER_STATUS_DEVICE     0
#define WAVEIN_MAPPER_STATUS_MAPPED     1
#define WAVEIN_MAPPER_STATUS_FORMAT     2
#endif
#ifndef WODM_MAPPER_STATUS
#define WODM_MAPPER_STATUS              (DRVM_MAPPER_STATUS + 0)
#define WAVEOUT_MAPPER_STATUS_DEVICE    0
#define WAVEOUT_MAPPER_STATUS_MAPPED    1
#define WAVEOUT_MAPPER_STATUS_FORMAT    2
#endif
#ifdef _WIN32
    #define ACMAPI              WINAPI
#else
#ifdef _WINDLL
    #define ACMAPI              _far _pascal _loadds
#else
    #define ACMAPI              _far _pascal
#endif
#endif
DECLARE_HANDLE(HACMDRIVERID);
typedef HACMDRIVERID *PHACMDRIVERID;
typedef HACMDRIVERID FAR *LPHACMDRIVERID;
DECLARE_HANDLE(HACMDRIVER);
typedef HACMDRIVER *PHACMDRIVER;
typedef HACMDRIVER FAR *LPHACMDRIVER;
DECLARE_HANDLE(HACMSTREAM);
typedef HACMSTREAM *PHACMSTREAM;
typedef HACMSTREAM FAR *LPHACMSTREAM;
DECLARE_HANDLE(HACMOBJ);
typedef HACMOBJ *PHACMOBJ;
typedef HACMOBJ FAR *LPHACMOBJ;
#ifndef _MMRESULT_
#define _MMRESULT_
typedef UINT MMRESULT;
#endif
#define ACMERR_BASE         (512)
#define ACMERR_NOTPOSSIBLE  (ACMERR_BASE + 0)
#define ACMERR_BUSY         (ACMERR_BASE + 1)
#define ACMERR_UNPREPARED   (ACMERR_BASE + 2)
#define ACMERR_CANCELED     (ACMERR_BASE + 3)
#define MM_ACM_OPEN         (MM_STREAM_OPEN)
#define MM_ACM_CLOSE        (MM_STREAM_CLOSE)
#define MM_ACM_DONE         (MM_STREAM_DONE)
DWORD ACMAPI acmGetVersion(void);
MMRESULT ACMAPI acmMetrics(HACMOBJ hao, UINT uMetric, LPVOID pMetric);
#define ACM_METRIC_COUNT_DRIVERS            1
#define ACM_METRIC_COUNT_CODECS             2
#define ACM_METRIC_COUNT_CONVERTERS         3
#define ACM_METRIC_COUNT_FILTERS            4
#define ACM_METRIC_COUNT_DISABLED           5
#define ACM_METRIC_COUNT_HARDWARE           6
#define ACM_METRIC_COUNT_LOCAL_DRIVERS      20
#define ACM_METRIC_COUNT_LOCAL_CODECS       21
#define ACM_METRIC_COUNT_LOCAL_CONVERTERS   22
#define ACM_METRIC_COUNT_LOCAL_FILTERS      23
#define ACM_METRIC_COUNT_LOCAL_DISABLED     24
#define ACM_METRIC_HARDWARE_WAVE_INPUT      30
#define ACM_METRIC_HARDWARE_WAVE_OUTPUT     31
#define ACM_METRIC_MAX_SIZE_FORMAT          50
#define ACM_METRIC_MAX_SIZE_FILTER          51
#define ACM_METRIC_DRIVER_SUPPORT           100
#define ACM_METRIC_DRIVER_PRIORITY          101
typedef BOOL(CALLBACK *ACMDRIVERENUMCB) (HACMDRIVERID hadid, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmDriverEnum(ACMDRIVERENUMCB fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
#define ACM_DRIVERENUMF_NOLOCAL     0x40000000L
#define ACM_DRIVERENUMF_DISABLED    0x80000000L
MMRESULT ACMAPI acmDriverID(HACMOBJ hao, LPHACMDRIVERID phadid, DWORD fdwDriverID);
#ifdef _WIN32
MMRESULT ACMAPI acmDriverAddA(LPHACMDRIVERID phadid, HINSTANCE hinstModule, LPARAM lParam, DWORD dwPriority, DWORD fdwAdd);
MMRESULT ACMAPI acmDriverAddW(LPHACMDRIVERID phadid, HINSTANCE hinstModule, LPARAM lParam, DWORD dwPriority, DWORD fdwAdd);
#ifdef _UNICODE
#define acmDriverAdd        acmDriverAddW
#else
#define acmDriverAdd        acmDriverAddA
#endif
#else
MMRESULT ACMAPI acmDriverAdd(LPHACMDRIVERID phadid, HINSTANCE hinstModule, LPARAM lParam, DWORD dwPriority, DWORD fdwAdd);
#endif
#define ACM_DRIVERADDF_NAME         0x00000001L
#define ACM_DRIVERADDF_FUNCTION     0x00000003L
#define ACM_DRIVERADDF_NOTIFYHWND   0x00000004L
#define ACM_DRIVERADDF_TYPEMASK     0x00000007L
#define ACM_DRIVERADDF_LOCAL        0x00000000L
#define ACM_DRIVERADDF_GLOBAL       0x00000008L
typedef LRESULT (CALLBACK *ACMDRIVERPROC)(DWORD_PTR, HACMDRIVERID, UINT, LPARAM, LPARAM);
typedef ACMDRIVERPROC FAR *LPACMDRIVERPROC;
MMRESULT ACMAPI acmDriverRemove(HACMDRIVERID hadid, DWORD fdwRemove);
MMRESULT ACMAPI acmDriverOpen(LPHACMDRIVER phad, HACMDRIVERID hadid, DWORD fdwOpen);
MMRESULT ACMAPI acmDriverClose(HACMDRIVER had, DWORD fdwClose);
LRESULT ACMAPI acmDriverMessage(HACMDRIVER had, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
#define ACMDM_USER                  (DRV_USER + 0x0000)
#define ACMDM_RESERVED_LOW          (DRV_USER + 0x2000)
#define ACMDM_RESERVED_HIGH         (DRV_USER + 0x2FFF)
#define ACMDM_BASE                  ACMDM_RESERVED_LOW
#define ACMDM_DRIVER_ABOUT          (ACMDM_BASE + 11)
MMRESULT ACMAPI acmDriverPriority(HACMDRIVERID hadid, DWORD dwPriority, DWORD fdwPriority);
#define ACM_DRIVERPRIORITYF_ENABLE      0x00000001L
#define ACM_DRIVERPRIORITYF_DISABLE     0x00000002L
#define ACM_DRIVERPRIORITYF_ABLEMASK    0x00000003L
#define ACM_DRIVERPRIORITYF_BEGIN       0x00010000L
#define ACM_DRIVERPRIORITYF_END         0x00020000L
#define ACM_DRIVERPRIORITYF_DEFERMASK   0x00030000L
#define ACMDRIVERDETAILS_SHORTNAME_CHARS    32
#define ACMDRIVERDETAILS_LONGNAME_CHARS     128
#define ACMDRIVERDETAILS_COPYRIGHT_CHARS    80
#define ACMDRIVERDETAILS_LICENSING_CHARS    128
#define ACMDRIVERDETAILS_FEATURES_CHARS     512
#ifdef _WIN32
typedef struct tACMDRIVERDETAILSA
{
    DWORD           cbStruct;
    FOURCC          fccType;
    FOURCC          fccComp;
    WORD            wMid;
    WORD            wPid;
    DWORD           vdwACM;
    DWORD           vdwDriver;
    DWORD           fdwSupport;
    DWORD           cFormatTags;
    DWORD           cFilterTags;
    HICON           hicon;
    char            szShortName[ACMDRIVERDETAILS_SHORTNAME_CHARS];
    char            szLongName[ACMDRIVERDETAILS_LONGNAME_CHARS];
    char            szCopyright[ACMDRIVERDETAILS_COPYRIGHT_CHARS];
    char            szLicensing[ACMDRIVERDETAILS_LICENSING_CHARS];
    char            szFeatures[ACMDRIVERDETAILS_FEATURES_CHARS];
} ACMDRIVERDETAILSA, *PACMDRIVERDETAILSA, FAR *LPACMDRIVERDETAILSA;
typedef struct tACMDRIVERDETAILSW
{
    DWORD           cbStruct;
    FOURCC          fccType;
    FOURCC          fccComp;
    WORD            wMid;
    WORD            wPid;
    DWORD           vdwACM;
    DWORD           vdwDriver;
    DWORD           fdwSupport;
    DWORD           cFormatTags;
    DWORD           cFilterTags;
    HICON           hicon;
    WCHAR           szShortName[ACMDRIVERDETAILS_SHORTNAME_CHARS];
    WCHAR           szLongName[ACMDRIVERDETAILS_LONGNAME_CHARS];
    WCHAR           szCopyright[ACMDRIVERDETAILS_COPYRIGHT_CHARS];
    WCHAR           szLicensing[ACMDRIVERDETAILS_LICENSING_CHARS];
    WCHAR           szFeatures[ACMDRIVERDETAILS_FEATURES_CHARS];
} ACMDRIVERDETAILSW, *PACMDRIVERDETAILSW, FAR *LPACMDRIVERDETAILSW;
#ifdef _UNICODE
#define ACMDRIVERDETAILS        ACMDRIVERDETAILSW
#define PACMDRIVERDETAILS       PACMDRIVERDETAILSW
#define LPACMDRIVERDETAILS      LPACMDRIVERDETAILSW
#else
#define ACMDRIVERDETAILS        ACMDRIVERDETAILSA
#define PACMDRIVERDETAILS       PACMDRIVERDETAILSA
#define LPACMDRIVERDETAILS      LPACMDRIVERDETAILSA
#endif
#else
typedef struct tACMDRIVERDETAILS
{
    DWORD           cbStruct;
    FOURCC          fccType;
    FOURCC          fccComp;
    WORD            wMid;
    WORD            wPid;
    DWORD           vdwACM;
    DWORD           vdwDriver;
    DWORD           fdwSupport;
    DWORD           cFormatTags;
    DWORD           cFilterTags;
    HICON           hicon;
    char            szShortName[ACMDRIVERDETAILS_SHORTNAME_CHARS];
    char            szLongName[ACMDRIVERDETAILS_LONGNAME_CHARS];
    char            szCopyright[ACMDRIVERDETAILS_COPYRIGHT_CHARS];
    char            szLicensing[ACMDRIVERDETAILS_LICENSING_CHARS];
    char            szFeatures[ACMDRIVERDETAILS_FEATURES_CHARS];
} ACMDRIVERDETAILS, *PACMDRIVERDETAILS, FAR *LPACMDRIVERDETAILS;
#endif
#define ACMDRIVERDETAILS_FCCTYPE_AUDIOCODEC mmioFOURCC('a', 'u', 'd', 'c')
#define ACMDRIVERDETAILS_FCCCOMP_UNDEFINED  mmioFOURCC('\0', '\0', '\0', '\0')
#define ACMDRIVERDETAILS_SUPPORTF_CODEC     0x00000001L
#define ACMDRIVERDETAILS_SUPPORTF_CONVERTER 0x00000002L
#define ACMDRIVERDETAILS_SUPPORTF_FILTER    0x00000004L
#define ACMDRIVERDETAILS_SUPPORTF_HARDWARE  0x00000008L
#define ACMDRIVERDETAILS_SUPPORTF_ASYNC     0x00000010L
#define ACMDRIVERDETAILS_SUPPORTF_LOCAL     0x40000000L
#define ACMDRIVERDETAILS_SUPPORTF_DISABLED  0x80000000L
#ifdef _WIN32
MMRESULT ACMAPI acmDriverDetailsA(HACMDRIVERID hadid, LPACMDRIVERDETAILSA padd, DWORD fdwDetails);
MMRESULT ACMAPI acmDriverDetailsW(HACMDRIVERID hadid, LPACMDRIVERDETAILSW padd, DWORD fdwDetails);
#ifdef _UNICODE
#define acmDriverDetails    acmDriverDetailsW
#else
#define acmDriverDetails    acmDriverDetailsA
#endif
#else
MMRESULT ACMAPI acmDriverDetails(HACMDRIVERID hadid, LPACMDRIVERDETAILS padd, DWORD fdwDetails);
#endif
#define ACMFORMATTAGDETAILS_FORMATTAG_CHARS 48
#ifdef _WIN32
typedef struct tACMFORMATTAGDETAILSA
{
    DWORD           cbStruct;
    DWORD           dwFormatTagIndex;
    DWORD           dwFormatTag;
    DWORD           cbFormatSize;
    DWORD           fdwSupport;
    DWORD           cStandardFormats;
    char            szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
} ACMFORMATTAGDETAILSA, *PACMFORMATTAGDETAILSA, FAR *LPACMFORMATTAGDETAILSA;
typedef struct tACMFORMATTAGDETAILSW
{
    DWORD           cbStruct;
    DWORD           dwFormatTagIndex;
    DWORD           dwFormatTag;
    DWORD           cbFormatSize;
    DWORD           fdwSupport;
    DWORD           cStandardFormats;
    WCHAR           szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
} ACMFORMATTAGDETAILSW, *PACMFORMATTAGDETAILSW, FAR *LPACMFORMATTAGDETAILSW;
#ifdef _UNICODE
#define ACMFORMATTAGDETAILS     ACMFORMATTAGDETAILSW
#define PACMFORMATTAGDETAILS    PACMFORMATTAGDETAILSW
#define LPACMFORMATTAGDETAILS   LPACMFORMATTAGDETAILSW
#else
#define ACMFORMATTAGDETAILS     ACMFORMATTAGDETAILSA
#define PACMFORMATTAGDETAILS    PACMFORMATTAGDETAILSA
#define LPACMFORMATTAGDETAILS   LPACMFORMATTAGDETAILSA
#endif
#else
typedef struct tACMFORMATTAGDETAILS
{
    DWORD           cbStruct;
    DWORD           dwFormatTagIndex;
    DWORD           dwFormatTag;
    DWORD           cbFormatSize;
    DWORD           fdwSupport;
    DWORD           cStandardFormats;
    char            szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
} ACMFORMATTAGDETAILS, *PACMFORMATTAGDETAILS, FAR *LPACMFORMATTAGDETAILS;
#endif
#ifdef _WIN32
MMRESULT ACMAPI acmFormatTagDetailsA(HACMDRIVER had, LPACMFORMATTAGDETAILSA paftd, DWORD fdwDetails);
MMRESULT ACMAPI acmFormatTagDetailsW(HACMDRIVER had, LPACMFORMATTAGDETAILSW paftd, DWORD fdwDetails
);
#ifdef _UNICODE
#define acmFormatTagDetails     acmFormatTagDetailsW
#else
#define acmFormatTagDetails     acmFormatTagDetailsA
#endif
#else
MMRESULT ACMAPI acmFormatTagDetails(HACMDRIVER had, LPACMFORMATTAGDETAILS paftd, DWORD fdwDetails);
#endif
#define ACM_FORMATTAGDETAILSF_INDEX         0x00000000L
#define ACM_FORMATTAGDETAILSF_FORMATTAG     0x00000001L
#define ACM_FORMATTAGDETAILSF_LARGESTSIZE   0x00000002L
#define ACM_FORMATTAGDETAILSF_QUERYMASK     0x0000000FL
#ifdef _WIN32
typedef BOOL(CALLBACK *ACMFORMATTAGENUMCBA) (HACMDRIVERID hadid, LPACMFORMATTAGDETAILSA paftd, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmFormatTagEnumA(HACMDRIVER had, LPACMFORMATTAGDETAILSA paftd, ACMFORMATTAGENUMCBA fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
typedef BOOL(CALLBACK *ACMFORMATTAGENUMCBW) (HACMDRIVERID hadid, LPACMFORMATTAGDETAILSW paftd, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmFormatTagEnumW(HACMDRIVER had, LPACMFORMATTAGDETAILSW paftd, ACMFORMATTAGENUMCBW fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
#ifdef _UNICODE
#define ACMFORMATTAGENUMCB      ACMFORMATTAGENUMCBW
#define acmFormatTagEnum        acmFormatTagEnumW
#else
#define ACMFORMATTAGENUMCB      ACMFORMATTAGENUMCBA
#define acmFormatTagEnum        acmFormatTagEnumA
#endif
#else
typedef BOOL(CALLBACK *ACMFORMATTAGENUMCB) (HACMDRIVERID hadid, LPACMFORMATTAGDETAILS paftd, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmFormatTagEnum(HACMDRIVER had, LPACMFORMATTAGDETAILS paftd, ACMFORMATTAGENUMCB fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
#endif
#define ACMFORMATDETAILS_FORMAT_CHARS   128
#ifdef _WIN32
typedef struct tACMFORMATDETAILSA
{
    DWORD           cbStruct;
    DWORD           dwFormatIndex;
    DWORD           dwFormatTag;
    DWORD           fdwSupport;
    LPWAVEFORMATEX  pwfx;
    DWORD           cbwfx;
    char            szFormat[ACMFORMATDETAILS_FORMAT_CHARS];
} ACMFORMATDETAILSA, *PACMFORMATDETAILSA, FAR *LPACMFORMATDETAILSA;
typedef struct tACMFORMATDETAILSW
{
    DWORD           cbStruct;
    DWORD           dwFormatIndex;
    DWORD           dwFormatTag;
    DWORD           fdwSupport;
    LPWAVEFORMATEX  pwfx;
    DWORD           cbwfx;
    WCHAR           szFormat[ACMFORMATDETAILS_FORMAT_CHARS];
} ACMFORMATDETAILSW, *PACMFORMATDETAILSW, FAR *LPACMFORMATDETAILSW;
#ifdef _UNICODE
#define ACMFORMATDETAILS    ACMFORMATDETAILSW
#define PACMFORMATDETAILS   PACMFORMATDETAILSW
#define LPACMFORMATDETAILS  LPACMFORMATDETAILSW
#else
#define ACMFORMATDETAILS    ACMFORMATDETAILSA
#define PACMFORMATDETAILS   PACMFORMATDETAILSA
#define LPACMFORMATDETAILS  LPACMFORMATDETAILSA
#endif
#else
typedef struct tACMFORMATDETAILS
{
    DWORD           cbStruct;
    DWORD           dwFormatIndex;
    DWORD           dwFormatTag;
    DWORD           fdwSupport;
    LPWAVEFORMATEX  pwfx;
    DWORD           cbwfx;
    char            szFormat[ACMFORMATDETAILS_FORMAT_CHARS];
} ACMFORMATDETAILS, *PACMFORMATDETAILS, FAR *LPACMFORMATDETAILS;
#endif
#ifdef _WIN32
MMRESULT ACMAPI acmFormatDetailsA(HACMDRIVER had, LPACMFORMATDETAILSA pafd, DWORD fdwDetails);
MMRESULT ACMAPI acmFormatDetailsW(HACMDRIVER had, LPACMFORMATDETAILSW pafd, DWORD fdwDetails);
#ifdef _UNICODE
#define acmFormatDetails    acmFormatDetailsW
#else
#define acmFormatDetails    acmFormatDetailsA
#endif
#else
MMRESULT ACMAPI acmFormatDetails(HACMDRIVER had, LPACMFORMATDETAILS pafd, DWORD fdwDetails);
#endif
#define ACM_FORMATDETAILSF_INDEX        0x00000000L
#define ACM_FORMATDETAILSF_FORMAT       0x00000001L
#define ACM_FORMATDETAILSF_QUERYMASK    0x0000000FL
#ifdef _WIN32
typedef BOOL(CALLBACK *ACMFORMATENUMCBA) (HACMDRIVERID hadid, LPACMFORMATDETAILSA pafd, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmFormatEnumA(HACMDRIVER had, LPACMFORMATDETAILSA pafd, ACMFORMATENUMCBA fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
typedef BOOL(CALLBACK *ACMFORMATENUMCBW) (HACMDRIVERID hadid, LPACMFORMATDETAILSW pafd, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmFormatEnumW(HACMDRIVER had, LPACMFORMATDETAILSW pafd, ACMFORMATENUMCBW fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
#ifdef _UNICODE
#define ACMFORMATENUMCB     ACMFORMATENUMCBW
#define acmFormatEnum       acmFormatEnumW
#else
#define ACMFORMATENUMCB     ACMFORMATENUMCBA
#define acmFormatEnum       acmFormatEnumA
#endif
#else
typedef BOOL(CALLBACK *ACMFORMATENUMCB) (HACMDRIVERID hadid, LPACMFORMATDETAILS pafd, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmFormatEnum(HACMDRIVER had, LPACMFORMATDETAILS pafd, ACMFORMATENUMCB fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
#endif
#define ACM_FORMATENUMF_WFORMATTAG       0x00010000L
#define ACM_FORMATENUMF_NCHANNELS        0x00020000L
#define ACM_FORMATENUMF_NSAMPLESPERSEC   0x00040000L
#define ACM_FORMATENUMF_WBITSPERSAMPLE   0x00080000L
#define ACM_FORMATENUMF_CONVERT          0x00100000L
#define ACM_FORMATENUMF_SUGGEST          0x00200000L
#define ACM_FORMATENUMF_HARDWARE         0x00400000L
#define ACM_FORMATENUMF_INPUT            0x00800000L
#define ACM_FORMATENUMF_OUTPUT           0x01000000L
MMRESULT ACMAPI acmFormatSuggest(HACMDRIVER had, LPWAVEFORMATEX pwfxSrc, LPWAVEFORMATEX pwfxDst, DWORD cbwfxDst, DWORD fdwSuggest);
#define ACM_FORMATSUGGESTF_WFORMATTAG       0x00010000L
#define ACM_FORMATSUGGESTF_NCHANNELS        0x00020000L
#define ACM_FORMATSUGGESTF_NSAMPLESPERSEC   0x00040000L
#define ACM_FORMATSUGGESTF_WBITSPERSAMPLE   0x00080000L
#define ACM_FORMATSUGGESTF_TYPEMASK         0x00FF0000L
#ifdef _WIN32
#define ACMHELPMSGSTRINGA       "acmchoose_help"
#define ACMHELPMSGSTRINGW       L"acmchoose_help"
#define ACMHELPMSGCONTEXTMENUA  "acmchoose_contextmenu"
#define ACMHELPMSGCONTEXTMENUW  L"acmchoose_contextmenu"
#define ACMHELPMSGCONTEXTHELPA  "acmchoose_contexthelp"
#define ACMHELPMSGCONTEXTHELPW  L"acmchoose_contexthelp"
#ifdef _UNICODE
#define ACMHELPMSGSTRING        ACMHELPMSGSTRINGW
#define ACMHELPMSGCONTEXTMENU   ACMHELPMSGCONTEXTMENUW
#define ACMHELPMSGCONTEXTHELP   ACMHELPMSGCONTEXTHELPW
#else
#define ACMHELPMSGSTRING        ACMHELPMSGSTRINGA
#define ACMHELPMSGCONTEXTMENU   ACMHELPMSGCONTEXTMENUA
#define ACMHELPMSGCONTEXTHELP   ACMHELPMSGCONTEXTHELPA
#endif
#else
#define ACMHELPMSGSTRING        "acmchoose_help"
#define ACMHELPMSGCONTEXTMENU   "acmchoose_contextmenu"
#define ACMHELPMSGCONTEXTHELP   "acmchoose_contexthelp"
#endif
#define MM_ACM_FORMATCHOOSE             (0x8000)
#define FORMATCHOOSE_MESSAGE            0
#define FORMATCHOOSE_FORMATTAG_VERIFY   (FORMATCHOOSE_MESSAGE+0)
#define FORMATCHOOSE_FORMAT_VERIFY      (FORMATCHOOSE_MESSAGE+1)
#define FORMATCHOOSE_CUSTOM_VERIFY      (FORMATCHOOSE_MESSAGE+2)
#ifdef _WIN32
typedef UINT(CALLBACK *ACMFORMATCHOOSEHOOKPROCA) (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
typedef UINT(CALLBACK *ACMFORMATCHOOSEHOOKPROCW) (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#ifdef _UNICODE
#define ACMFORMATCHOOSEHOOKPROC     ACMFORMATCHOOSEHOOKPROCW
#else
#define ACMFORMATCHOOSEHOOKPROC     ACMFORMATCHOOSEHOOKPROCA
#endif
#else
typedef UINT(CALLBACK *ACMFORMATCHOOSEHOOKPROC) (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#endif
#ifdef _WIN32
typedef struct tACMFORMATCHOOSEA
{
    DWORD           cbStruct;
    DWORD           fdwStyle;
    
    HWND            hwndOwner;
    LPWAVEFORMATEX  pwfx;
    DWORD           cbwfx;
    LPCSTR          pszTitle;
    
    char            szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
    char            szFormat[ACMFORMATDETAILS_FORMAT_CHARS];    
    LPSTR           pszName;
    DWORD           cchName;
    DWORD           fdwEnum;
    LPWAVEFORMATEX  pwfxEnum;
    
    HINSTANCE       hInstance;
    LPCSTR          pszTemplateName;
    LPARAM          lCustData;
    ACMFORMATCHOOSEHOOKPROCA pfnHook;
} ACMFORMATCHOOSEA, *PACMFORMATCHOOSEA, FAR *LPACMFORMATCHOOSEA;
typedef struct tACMFORMATCHOOSEW
{
    DWORD           cbStruct;
    DWORD           fdwStyle;
    
    HWND            hwndOwner;
    LPWAVEFORMATEX  pwfx;
    DWORD           cbwfx;
    LPCWSTR         pszTitle;
    
    WCHAR           szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
    WCHAR           szFormat[ACMFORMATDETAILS_FORMAT_CHARS];    
    LPWSTR          pszName;
    DWORD           cchName;
    DWORD           fdwEnum;
    LPWAVEFORMATEX  pwfxEnum;
    
    HINSTANCE       hInstance;
    LPCWSTR         pszTemplateName;
    LPARAM          lCustData;
    ACMFORMATCHOOSEHOOKPROCW pfnHook;
} ACMFORMATCHOOSEW, *PACMFORMATCHOOSEW, FAR *LPACMFORMATCHOOSEW;
#ifdef _UNICODE
#define ACMFORMATCHOOSE     ACMFORMATCHOOSEW
#define PACMFORMATCHOOSE    PACMFORMATCHOOSEW
#define LPACMFORMATCHOOSE   LPACMFORMATCHOOSEW
#else
#define ACMFORMATCHOOSE     ACMFORMATCHOOSEA
#define PACMFORMATCHOOSE    PACMFORMATCHOOSEA
#define LPACMFORMATCHOOSE   LPACMFORMATCHOOSEA
#endif
#else
typedef struct tACMFORMATCHOOSE
{
    DWORD           cbStruct;
    DWORD           fdwStyle;
    
    HWND            hwndOwner;
    LPWAVEFORMATEX  pwfx;
    DWORD           cbwfx;
    LPCSTR          pszTitle;
    
    char            szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
    char            szFormat[ACMFORMATDETAILS_FORMAT_CHARS];    
    LPSTR           pszName;
    DWORD           cchName;
    DWORD           fdwEnum;
    LPWAVEFORMATEX  pwfxEnum;
    
    HINSTANCE       hInstance;
    LPCSTR          pszTemplateName;
    LPARAM          lCustData;
    ACMFORMATCHOOSEHOOKPROC pfnHook;
} ACMFORMATCHOOSE, *PACMFORMATCHOOSE, FAR *LPACMFORMATCHOOSE;
#endif
#define ACMFORMATCHOOSE_STYLEF_SHOWHELP              0x00000004L
#define ACMFORMATCHOOSE_STYLEF_ENABLEHOOK            0x00000008L
#define ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATE        0x00000010L
#define ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATEHANDLE  0x00000020L
#define ACMFORMATCHOOSE_STYLEF_INITTOWFXSTRUCT       0x00000040L
#define ACMFORMATCHOOSE_STYLEF_CONTEXTHELP           0x00000080L
#ifdef _WIN32
MMRESULT ACMAPI acmFormatChooseA(LPACMFORMATCHOOSEA pafmtc);
MMRESULT ACMAPI acmFormatChooseW(LPACMFORMATCHOOSEW pafmtc);
#ifdef _UNICODE
#define acmFormatChoose     acmFormatChooseW
#else
#define acmFormatChoose     acmFormatChooseA
#endif
#else
MMRESULT ACMAPI acmFormatChoose(LPACMFORMATCHOOSE pafmtc);
#endif
#define ACMFILTERTAGDETAILS_FILTERTAG_CHARS 48
#ifdef _WIN32
typedef struct tACMFILTERTAGDETAILSA
{
    DWORD           cbStruct;
    DWORD           dwFilterTagIndex;
    DWORD           dwFilterTag;
    DWORD           cbFilterSize;
    DWORD           fdwSupport;
    DWORD           cStandardFilters;
    char            szFilterTag[ACMFILTERTAGDETAILS_FILTERTAG_CHARS];
} ACMFILTERTAGDETAILSA, *PACMFILTERTAGDETAILSA, FAR *LPACMFILTERTAGDETAILSA;
typedef struct tACMFILTERTAGDETAILSW
{
    DWORD           cbStruct;
    DWORD           dwFilterTagIndex;
    DWORD           dwFilterTag;
    DWORD           cbFilterSize;
    DWORD           fdwSupport;
    DWORD           cStandardFilters;
    WCHAR           szFilterTag[ACMFILTERTAGDETAILS_FILTERTAG_CHARS];
} ACMFILTERTAGDETAILSW, *PACMFILTERTAGDETAILSW, FAR *LPACMFILTERTAGDETAILSW;
#ifdef _UNICODE
#define ACMFILTERTAGDETAILS     ACMFILTERTAGDETAILSW
#define PACMFILTERTAGDETAILS    PACMFILTERTAGDETAILSW
#define LPACMFILTERTAGDETAILS   LPACMFILTERTAGDETAILSW
#else
#define ACMFILTERTAGDETAILS     ACMFILTERTAGDETAILSA
#define PACMFILTERTAGDETAILS    PACMFILTERTAGDETAILSA
#define LPACMFILTERTAGDETAILS   LPACMFILTERTAGDETAILSA
#endif
#else
typedef struct tACMFILTERTAGDETAILS
{
    DWORD           cbStruct;
    DWORD           dwFilterTagIndex;
    DWORD           dwFilterTag;
    DWORD           cbFilterSize;
    DWORD           fdwSupport;
    DWORD           cStandardFilters;
    char            szFilterTag[ACMFILTERTAGDETAILS_FILTERTAG_CHARS];
} ACMFILTERTAGDETAILS, *PACMFILTERTAGDETAILS, FAR *LPACMFILTERTAGDETAILS;
#endif
#ifdef _WIN32
MMRESULT ACMAPI acmFilterTagDetailsA(HACMDRIVER had, LPACMFILTERTAGDETAILSA paftd, DWORD fdwDetails);
MMRESULT ACMAPI acmFilterTagDetailsW(HACMDRIVER had, LPACMFILTERTAGDETAILSW paftd, DWORD fdwDetails);
#ifdef _UNICODE
#define acmFilterTagDetails     acmFilterTagDetailsW
#else
#define acmFilterTagDetails     acmFilterTagDetailsA
#endif
#else
MMRESULT ACMAPI acmFilterTagDetails(HACMDRIVER had, LPACMFILTERTAGDETAILS paftd, DWORD fdwDetails);
#endif
#define ACM_FILTERTAGDETAILSF_INDEX         0x00000000L
#define ACM_FILTERTAGDETAILSF_FILTERTAG     0x00000001L
#define ACM_FILTERTAGDETAILSF_LARGESTSIZE   0x00000002L
#define ACM_FILTERTAGDETAILSF_QUERYMASK     0x0000000FL
#ifdef _WIN32
typedef BOOL(CALLBACK *ACMFILTERTAGENUMCBA) (HACMDRIVERID hadid, LPACMFILTERTAGDETAILSA paftd, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmFilterTagEnumA(HACMDRIVER had, LPACMFILTERTAGDETAILSA paftd, ACMFILTERTAGENUMCBA fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
typedef BOOL(CALLBACK *ACMFILTERTAGENUMCBW) (HACMDRIVERID hadid, LPACMFILTERTAGDETAILSW paftd, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmFilterTagEnumW(HACMDRIVER had, LPACMFILTERTAGDETAILSW paftd, ACMFILTERTAGENUMCBW fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
#ifdef _UNICODE
#define ACMFILTERTAGENUMCB  ACMFILTERTAGENUMCBW
#define acmFilterTagEnum    acmFilterTagEnumW
#else
#define ACMFILTERTAGENUMCB  ACMFILTERTAGENUMCBA
#define acmFilterTagEnum    acmFilterTagEnumA
#endif
#else
typedef BOOL(CALLBACK *ACMFILTERTAGENUMCB) (HACMDRIVERID hadid, LPACMFILTERTAGDETAILS paftd, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmFilterTagEnum(HACMDRIVER had, LPACMFILTERTAGDETAILS paftd, ACMFILTERTAGENUMCB fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
#endif
#define ACMFILTERDETAILS_FILTER_CHARS   128
#ifdef _WIN32
typedef struct tACMFILTERDETAILSA
{
    DWORD           cbStruct;
    DWORD           dwFilterIndex;
    DWORD           dwFilterTag;
    DWORD           fdwSupport;
    LPWAVEFILTER    pwfltr;
    DWORD           cbwfltr;
    char            szFilter[ACMFILTERDETAILS_FILTER_CHARS];
} ACMFILTERDETAILSA, *PACMFILTERDETAILSA, FAR *LPACMFILTERDETAILSA;
typedef struct tACMFILTERDETAILSW
{
    DWORD           cbStruct;
    DWORD           dwFilterIndex;
    DWORD           dwFilterTag;
    DWORD           fdwSupport;
    LPWAVEFILTER    pwfltr;
    DWORD           cbwfltr;
    WCHAR           szFilter[ACMFILTERDETAILS_FILTER_CHARS];
} ACMFILTERDETAILSW, *PACMFILTERDETAILSW, FAR *LPACMFILTERDETAILSW;
#ifdef _UNICODE
#define ACMFILTERDETAILS    ACMFILTERDETAILSW
#define PACMFILTERDETAILS   PACMFILTERDETAILSW
#define LPACMFILTERDETAILS  LPACMFILTERDETAILSW
#else
#define ACMFILTERDETAILS    ACMFILTERDETAILSA
#define PACMFILTERDETAILS   PACMFILTERDETAILSA
#define LPACMFILTERDETAILS  LPACMFILTERDETAILSA
#endif
#else
typedef struct tACMFILTERDETAILS
{
    DWORD           cbStruct;
    DWORD           dwFilterIndex;
    DWORD           dwFilterTag;
    DWORD           fdwSupport;
    LPWAVEFILTER    pwfltr;
    DWORD           cbwfltr;
    char            szFilter[ACMFILTERDETAILS_FILTER_CHARS];
} ACMFILTERDETAILS, *PACMFILTERDETAILS, FAR *LPACMFILTERDETAILS;
#endif
#ifdef _WIN32
MMRESULT ACMAPI acmFilterDetailsA(HACMDRIVER had, LPACMFILTERDETAILSA pafd, DWORD fdwDetails);
MMRESULT ACMAPI acmFilterDetailsW(HACMDRIVER had, LPACMFILTERDETAILSW pafd, DWORD fdwDetails);
#ifdef _UNICODE
#define acmFilterDetails    acmFilterDetailsW
#else
#define acmFilterDetails    acmFilterDetailsA
#endif
#else
MMRESULT ACMAPI acmFilterDetails(HACMDRIVER had, LPACMFILTERDETAILS pafd, DWORD fdwDetails);
#endif
#define ACM_FILTERDETAILSF_INDEX        0x00000000L
#define ACM_FILTERDETAILSF_FILTER       0x00000001L
#define ACM_FILTERDETAILSF_QUERYMASK    0x0000000FL
#ifdef _WIN32
typedef BOOL(CALLBACK *ACMFILTERENUMCBA) (HACMDRIVERID hadid, LPACMFILTERDETAILSA pafd, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmFilterEnumA(HACMDRIVER had, LPACMFILTERDETAILSA pafd, ACMFILTERENUMCBA fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
typedef BOOL(CALLBACK *ACMFILTERENUMCBW) (HACMDRIVERID hadid, LPACMFILTERDETAILSW pafd, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmFilterEnumW(HACMDRIVER had, LPACMFILTERDETAILSW pafd, ACMFILTERENUMCBW fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
#ifdef _UNICODE
#define ACMFILTERENUMCB     ACMFILTERENUMCBW
#define acmFilterEnum       acmFilterEnumW
#else
#define ACMFILTERENUMCB     ACMFILTERENUMCBA
#define acmFilterEnum       acmFilterEnumA
#endif
#else
typedef BOOL(CALLBACK *ACMFILTERENUMCB) (HACMDRIVERID hadid, LPACMFILTERDETAILS pafd, DWORD_PTR dwInstance, DWORD fdwSupport);
MMRESULT ACMAPI acmFilterEnum(HACMDRIVER had, LPACMFILTERDETAILS pafd, ACMFILTERENUMCB fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
#endif
#define ACM_FILTERENUMF_DWFILTERTAG         0x00010000L
#define MM_ACM_FILTERCHOOSE             (0x8000)
#define FILTERCHOOSE_MESSAGE            0
#define FILTERCHOOSE_FILTERTAG_VERIFY   (FILTERCHOOSE_MESSAGE+0)
#define FILTERCHOOSE_FILTER_VERIFY      (FILTERCHOOSE_MESSAGE+1)
#define FILTERCHOOSE_CUSTOM_VERIFY      (FILTERCHOOSE_MESSAGE+2)
#ifdef _WIN32
typedef UINT(CALLBACK *ACMFILTERCHOOSEHOOKPROCA) (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
typedef UINT(CALLBACK *ACMFILTERCHOOSEHOOKPROCW) (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#ifdef _UNICODE
#define ACMFILTERCHOOSEHOOKPROC     ACMFILTERCHOOSEHOOKPROCW
#else
#define ACMFILTERCHOOSEHOOKPROC     ACMFILTERCHOOSEHOOKPROCA
#endif
#else
typedef UINT(CALLBACK *ACMFILTERCHOOSEHOOKPROC) (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#endif
#ifdef _WIN32
typedef struct tACMFILTERCHOOSEA
{
    DWORD           cbStruct;
    DWORD           fdwStyle;
    HWND            hwndOwner;
    LPWAVEFILTER    pwfltr;
    DWORD           cbwfltr;
    LPCSTR          pszTitle;
    char            szFilterTag[ACMFILTERTAGDETAILS_FILTERTAG_CHARS];
    char            szFilter[ACMFILTERDETAILS_FILTER_CHARS];
    LPSTR           pszName;
    DWORD           cchName;
    DWORD           fdwEnum;
    LPWAVEFILTER    pwfltrEnum;
    
    HINSTANCE       hInstance;
    LPCSTR          pszTemplateName;
    LPARAM          lCustData;
    ACMFILTERCHOOSEHOOKPROCA pfnHook;
} ACMFILTERCHOOSEA, *PACMFILTERCHOOSEA, FAR *LPACMFILTERCHOOSEA;
typedef struct tACMFILTERCHOOSEW
{
    DWORD           cbStruct;
    DWORD           fdwStyle;
    HWND            hwndOwner;
    LPWAVEFILTER    pwfltr;
    DWORD           cbwfltr;
    LPCWSTR         pszTitle;
    WCHAR           szFilterTag[ACMFILTERTAGDETAILS_FILTERTAG_CHARS];
    WCHAR           szFilter[ACMFILTERDETAILS_FILTER_CHARS];
    LPWSTR          pszName;
    DWORD           cchName;
    DWORD           fdwEnum;
    LPWAVEFILTER    pwfltrEnum;
    
    HINSTANCE       hInstance;
    LPCWSTR         pszTemplateName;
    LPARAM          lCustData;
    ACMFILTERCHOOSEHOOKPROCW pfnHook;
} ACMFILTERCHOOSEW, *PACMFILTERCHOOSEW, FAR *LPACMFILTERCHOOSEW;
#ifdef _UNICODE
#define ACMFILTERCHOOSE     ACMFILTERCHOOSEW
#define PACMFILTERCHOOSE    PACMFILTERCHOOSEW
#define LPACMFILTERCHOOSE   LPACMFILTERCHOOSEW
#else
#define ACMFILTERCHOOSE     ACMFILTERCHOOSEA
#define PACMFILTERCHOOSE    PACMFILTERCHOOSEA
#define LPACMFILTERCHOOSE   LPACMFILTERCHOOSEA
#endif
#else
typedef struct tACMFILTERCHOOSE
{
    DWORD           cbStruct;
    DWORD           fdwStyle;
    HWND            hwndOwner;
    LPWAVEFILTER    pwfltr;
    DWORD           cbwfltr;
    LPCSTR          pszTitle;
    char            szFilterTag[ACMFILTERTAGDETAILS_FILTERTAG_CHARS];
    char            szFilter[ACMFILTERDETAILS_FILTER_CHARS];
    LPSTR           pszName;
    DWORD           cchName;
    DWORD           fdwEnum;
    LPWAVEFILTER    pwfltrEnum;
    
    HINSTANCE       hInstance;
    LPCSTR          pszTemplateName;
    LPARAM          lCustData;
    ACMFILTERCHOOSEHOOKPROC pfnHook;
} ACMFILTERCHOOSE, *PACMFILTERCHOOSE, FAR *LPACMFILTERCHOOSE;
#endif
#define ACMFILTERCHOOSE_STYLEF_SHOWHELP              0x00000004L
#define ACMFILTERCHOOSE_STYLEF_ENABLEHOOK            0x00000008L
#define ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATE        0x00000010L
#define ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATEHANDLE  0x00000020L
#define ACMFILTERCHOOSE_STYLEF_INITTOFILTERSTRUCT    0x00000040L
#define ACMFILTERCHOOSE_STYLEF_CONTEXTHELP           0x00000080L
#ifdef _WIN32
MMRESULT ACMAPI acmFilterChooseA(LPACMFILTERCHOOSEA pafltrc);
MMRESULT ACMAPI acmFilterChooseW(LPACMFILTERCHOOSEW pafltrc);
#ifdef _UNICODE
#define acmFilterChoose     acmFilterChooseW
#else
#define acmFilterChoose     acmFilterChooseA
#endif
#else
MMRESULT ACMAPI acmFilterChoose(LPACMFILTERCHOOSE pafltrc);
#endif
#ifdef  _WIN64
#define _DRVRESERVED    15
#else
#define _DRVRESERVED    10
#endif
typedef struct tACMSTREAMHEADER
{
    DWORD           cbStruct;
    DWORD           fdwStatus;
    DWORD_PTR       dwUser;
    LPBYTE          pbSrc;
    DWORD           cbSrcLength;
    DWORD           cbSrcLengthUsed;
    DWORD_PTR       dwSrcUser;
    LPBYTE          pbDst;
    DWORD           cbDstLength;
    DWORD           cbDstLengthUsed;
    DWORD_PTR       dwDstUser;
    DWORD           dwReservedDriver[_DRVRESERVED];
} ACMSTREAMHEADER, *PACMSTREAMHEADER, FAR *LPACMSTREAMHEADER;
#define ACMSTREAMHEADER_STATUSF_DONE        0x00010000L
#define ACMSTREAMHEADER_STATUSF_PREPARED    0x00020000L
#define ACMSTREAMHEADER_STATUSF_INQUEUE     0x00100000L
MMRESULT ACMAPI acmStreamOpen(LPHACMSTREAM phas, HACMDRIVER had, LPWAVEFORMATEX pwfxSrc, LPWAVEFORMATEX pwfxDst, LPWAVEFILTER pwfltr, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
#define ACM_STREAMOPENF_QUERY           0x00000001
#define ACM_STREAMOPENF_ASYNC           0x00000002
#define ACM_STREAMOPENF_NONREALTIME     0x00000004
MMRESULT ACMAPI acmStreamClose(HACMSTREAM has, DWORD fdwClose);
MMRESULT ACMAPI acmStreamSize(HACMSTREAM has, DWORD cbInput, LPDWORD pdwOutputBytes, DWORD fdwSize);
#define ACM_STREAMSIZEF_SOURCE          0x00000000L
#define ACM_STREAMSIZEF_DESTINATION     0x00000001L
#define ACM_STREAMSIZEF_QUERYMASK       0x0000000FL
MMRESULT ACMAPI acmStreamReset(HACMSTREAM has, DWORD fdwReset);
MMRESULT ACMAPI acmStreamMessage(HACMSTREAM has, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
MMRESULT ACMAPI acmStreamConvert(HACMSTREAM has, LPACMSTREAMHEADER pash, DWORD fdwConvert);
#define ACM_STREAMCONVERTF_BLOCKALIGN   0x00000004
#define ACM_STREAMCONVERTF_START        0x00000010
#define ACM_STREAMCONVERTF_END          0x00000020
MMRESULT ACMAPI acmStreamPrepareHeader(HACMSTREAM has, LPACMSTREAMHEADER pash, DWORD fdwPrepare);
MMRESULT ACMAPI acmStreamUnprepareHeader(HACMSTREAM has, LPACMSTREAMHEADER pash, DWORD fdwUnprepare);
#include <poppack.h>
#endif
