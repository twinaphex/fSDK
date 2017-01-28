/*+@@file@@----------------------------------------------------------------*//*!
 \file		WindowsSideShow.h
 \par Description 
            Extension and update of headers for PellesC compiler suite.
 \par Project: 
            PellesC Headers extension
 \date		Created  on Sun Sep  4 16:52:07 2016
 \date		Modified on Sun Sep  4 16:52:07 2016
 \author	frankie
\*//*-@@file@@----------------------------------------------------------------*/

#ifndef __WINDOWSSIDESHOW_H__
#define __WINDOWSSIDESHOW_H__
#if __POCC__ >= 500
#pragma once
#endif
#if (_WIN32_WINNT >= 0x0600)
#include <propkeydef.h>
const CONTENT_ID CONTENT_ID_GLANCE = 0;
const DWORD SIDESHOW_EVENTID_APPLICATION_ENTER = 0xFFFF0000;
const DWORD SIDESHOW_EVENTID_APPLICATION_EXIT = 0xFFFF0001;
DEFINE_GUID(SIDESHOW_ENDPOINT_SIMPLE_CONTENT_FORMAT,    0xa9a5353f, 0x2d4b, 0x47ce, 0x93, 0xee, 0x75, 0x9f, 0x3a, 0x7d, 0xda, 0x4f);
DEFINE_GUID(SIDESHOW_ENDPOINT_ICAL,                     0x4dff36b5, 0x9dde, 0x4f76, 0x9a, 0x2a, 0x96, 0x43, 0x50, 0x47, 0x06, 0x3d);
DEFINE_GUID(SIDESHOW_CAPABILITY_DEVICE_PROPERTIES,          0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_DEVICE_ID,           0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 1);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_SCREEN_TYPE,         0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 2);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_SCREEN_WIDTH,        0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 3);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_SCREEN_HEIGHT,       0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 4);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_COLOR_DEPTH,         0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 5);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_COLOR_TYPE,          0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 6);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_DATA_CACHE,          0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 7);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_SUPPORTED_LANGUAGES, 0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 8);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_CURRENT_LANGUAGE,    0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 9);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_SUPPORTED_THEMES,    0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 10);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_SUPPORTED_IMAGE_FORMATS, 0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 14);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_CLIENT_AREA_WIDTH,   0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 15);
DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_CLIENT_AREA_HEIGHT,  0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 16);
typedef enum tagSIDESHOW_SCREEN_TYPE
{
    SIDESHOW_SCREEN_TYPE_BITMAP  =   0,
    SIDESHOW_SCREEN_TYPE_TEXT    =   1,
} SIDESHOW_SCREEN_TYPE;
typedef enum tagSIDESHOW_COLOR_TYPE
{
    SIDESHOW_COLOR_TYPE_COLOR            = 0,
    SIDESHOW_COLOR_TYPE_GREYSCALE        = 1,
    SIDESHOW_COLOR_TYPE_BLACK_AND_WHITE  = 2,
} SIDESHOW_COLOR_TYPE;
const CONTENT_ID    CONTENT_ID_HOME     = 1;
typedef enum tagSCF_EVENT_IDS
{
    SCF_EVENT_NAVIGATION        = 1,
    SCF_EVENT_MENUACTION        = 2,
    SCF_EVENT_CONTEXTMENU       = 3,
} SCF_EVENT_IDS;
typedef enum tagSCF_BUTTON_IDS
{
    SCF_BUTTON_MENU     = 1,
    SCF_BUTTON_SELECT   = 2,   
    SCF_BUTTON_UP       = 3,
    SCF_BUTTON_DOWN     = 4,
    SCF_BUTTON_LEFT     = 5,
    SCF_BUTTON_RIGHT    = 6,
    SCF_BUTTON_PLAY     = 7,
    SCF_BUTTON_PAUSE    = 8,
    SCF_BUTTON_FASTFORWARD = 9,
    SCF_BUTTON_REWIND   = 10,
    SCF_BUTTON_STOP     = 11,
    SCF_BUTTON_BACK     = 65280,
} SCF_BUTTON_IDS;
typedef struct tagSCF_EVENT_HEADER
{
    CONTENT_ID  PreviousPage;
    CONTENT_ID  TargetPage;
} SCF_EVENT_HEADER, *PSCF_EVENT_HEADER;
typedef struct tagSCF_NAVIGATION_EVENT
{
    CONTENT_ID  PreviousPage;
    CONTENT_ID  TargetPage;
    UINT32      Button;
} SCF_NAVIGATION_EVENT, *PSCF_NAVIGATION_EVENT;
typedef struct tagSCF_MENUACTION_EVENT
{
    CONTENT_ID  PreviousPage;
    CONTENT_ID  TargetPage;
    UINT32      Button;
    UINT32      ItemId;
} SCF_MENUACTION_EVENT, *PSCF_MENUACTION_EVENT;
typedef struct tagSCF_CONTEXTMENU_EVENT
{
    CONTENT_ID  PreviousPage;
    CONTENT_ID  TargetPage;
    UINT32      PreviousItemId;
    CONTENT_ID  MenuPage;
    UINT32      MenuItemId;
} SCF_CONTEXTMENU_EVENT, *PSCF_CONTEXTMENU_EVENT;
#endif
#endif
