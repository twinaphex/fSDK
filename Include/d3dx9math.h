/*+@@file@@----------------------------------------------------------------*//*!
 \file		d3dx9math.h
 \par Description 
            Extension and update of headers for PellesC compiler suite.
 \par Project: 
            PellesC Headers extension
 \date		Created  on Fri Nov 11 16:33:45 2016
 \date		Modified on Fri Nov 11 16:33:45 2016
 \author	frankie
\*//*-@@file@@----------------------------------------------------------------*/

#include <d3dx9.h>
#ifndef __D3DX9MATH_H__
#define __D3DX9MATH_H__
#if __POCC__ >= 500
#pragma once
#endif
#include <math.h>
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable:4201)
#define D3DX_PI    ((FLOAT)  3.141592654f)
#define D3DX_1BYPI ((FLOAT)  0.318309886f)
#define D3DXToRadian( degree ) ((degree) * (D3DX_PI / 180.0f))
#define D3DXToDegree( radian ) ((radian) * (180.0f / D3DX_PI))
#define D3DX_16F_DIG          3
#define D3DX_16F_EPSILON      4.8875809e-4f
#define D3DX_16F_MANT_DIG     11
#define D3DX_16F_MAX          6.550400e+004
#define D3DX_16F_MAX_10_EXP   4
#define D3DX_16F_MAX_EXP      15
#define D3DX_16F_MIN          6.1035156e-5f
#define D3DX_16F_MIN_10_EXP   (-4)
#define D3DX_16F_MIN_EXP      (-14)
#define D3DX_16F_RADIX        2
#define D3DX_16F_ROUNDS       1
typedef struct D3DXFLOAT16 {

	WORD value;
} D3DXFLOAT16, *LPD3DXFLOAT16;
typedef struct D3DXVECTOR2 {

	FLOAT x, y;
} D3DXVECTOR2, *LPD3DXVECTOR2;
typedef struct D3DXVECTOR2_16F {

	D3DXFLOAT16 x, y;
} D3DXVECTOR2_16F, *LPD3DXVECTOR2_16F;

typedef struct _D3DVECTOR D3DXVECTOR3, *LPD3DXVECTOR3;

typedef struct D3DXVECTOR3_16F {

	D3DXFLOAT16 x, y, z;
} D3DXVECTOR3_16F, *LPD3DXVECTOR3_16F;
typedef struct D3DXVECTOR4 {

	FLOAT x, y, z, w;
} D3DXVECTOR4, *LPD3DXVECTOR4;
typedef struct D3DXVECTOR4_16F {

	D3DXFLOAT16 x, y, z, w;
} D3DXVECTOR4_16F, *LPD3DXVECTOR4_16F;

typedef struct _D3DMATRIX D3DXMATRIX, *LPD3DXMATRIX;

typedef D3DXMATRIX _D3DXMATRIXA16;

#if _MSC_VER >= 1300
#define D3DX_ALIGN16 __declspec(align(16))
#else
#define D3DX_ALIGN16
#endif
typedef D3DX_ALIGN16 _D3DXMATRIXA16 D3DXMATRIXA16, *LPD3DXMATRIXA16;
typedef struct D3DXQUATERNION {

	FLOAT x, y, z, w;
} D3DXQUATERNION, *LPD3DXQUATERNION;
typedef struct D3DXPLANE {

	FLOAT a, b, c, d;
} D3DXPLANE, *LPD3DXPLANE;
typedef struct D3DXCOLOR {

	FLOAT r, g, b, a;
} D3DXCOLOR, *LPD3DXCOLOR;

D3DXFLOAT16 *WINAPI D3DXFloat32To16Array(D3DXFLOAT16 *pOut, CONST FLOAT *pIn, UINT n);
FLOAT *WINAPI D3DXFloat16To32Array(FLOAT *pOut, CONST D3DXFLOAT16 *pIn, UINT n);

FLOAT D3DXVec2Length(CONST D3DXVECTOR2 *pV);
FLOAT D3DXVec2LengthSq(CONST D3DXVECTOR2 *pV);
FLOAT D3DXVec2Dot(CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2);
FLOAT D3DXVec2CCW(CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2);
D3DXVECTOR2 *D3DXVec2Add(D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2);
D3DXVECTOR2 *D3DXVec2Subtract(D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2);
D3DXVECTOR2 *D3DXVec2Minimize(D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2);
D3DXVECTOR2 *D3DXVec2Maximize(D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2);
D3DXVECTOR2 *D3DXVec2Scale(D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV, FLOAT s);
D3DXVECTOR2 *D3DXVec2Lerp(D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2, FLOAT s);

D3DXVECTOR2 *WINAPI D3DXVec2Normalize(D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV);
D3DXVECTOR2 *WINAPI D3DXVec2Hermite(D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pT1, CONST D3DXVECTOR2 *pV2, CONST D3DXVECTOR2 *pT2, FLOAT s);
D3DXVECTOR2 *WINAPI D3DXVec2CatmullRom(D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV0, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2, CONST D3DXVECTOR2 *pV3, FLOAT s);
D3DXVECTOR2 *WINAPI D3DXVec2BaryCentric(D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2, CONST D3DXVECTOR2 *pV3, FLOAT f, FLOAT g);
D3DXVECTOR4 *WINAPI D3DXVec2Transform(D3DXVECTOR4 *pOut, CONST D3DXVECTOR2 *pV, CONST D3DXMATRIX *pM);
D3DXVECTOR2 *WINAPI D3DXVec2TransformCoord(D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV, CONST D3DXMATRIX *pM);
D3DXVECTOR2 *WINAPI D3DXVec2TransformNormal(D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV, CONST D3DXMATRIX *pM);
D3DXVECTOR4 *WINAPI D3DXVec2TransformArray(D3DXVECTOR4 *pOut, UINT OutStride, CONST D3DXVECTOR2 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n);
D3DXVECTOR2 *WINAPI D3DXVec2TransformCoordArray(D3DXVECTOR2 *pOut, UINT OutStride, CONST D3DXVECTOR2 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n);
D3DXVECTOR2 *WINAPI D3DXVec2TransformNormalArray(D3DXVECTOR2 *pOut, UINT OutStride, CONST D3DXVECTOR2 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n);

FLOAT D3DXVec3Length(CONST D3DXVECTOR3 *pV);
FLOAT D3DXVec3LengthSq(CONST D3DXVECTOR3 *pV);
FLOAT D3DXVec3Dot(CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2);
D3DXVECTOR3 *D3DXVec3Cross(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2);
D3DXVECTOR3 *D3DXVec3Add(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2);
D3DXVECTOR3 *D3DXVec3Subtract(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2);
D3DXVECTOR3 *D3DXVec3Minimize(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2);
D3DXVECTOR3 *D3DXVec3Maximize(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2);
D3DXVECTOR3 *D3DXVec3Scale(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, FLOAT s);
D3DXVECTOR3 *D3DXVec3Lerp(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2, FLOAT s);

D3DXVECTOR3 *WINAPI D3DXVec3Normalize(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV);
D3DXVECTOR3 *WINAPI D3DXVec3Hermite(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pT1, CONST D3DXVECTOR3 *pV2, CONST D3DXVECTOR3 *pT2, FLOAT s);
D3DXVECTOR3 *WINAPI D3DXVec3CatmullRom(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV0, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2, CONST D3DXVECTOR3 *pV3, FLOAT s);
D3DXVECTOR3 *WINAPI D3DXVec3BaryCentric(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2, CONST D3DXVECTOR3 *pV3, FLOAT f, FLOAT g);
D3DXVECTOR4 *WINAPI D3DXVec3Transform(D3DXVECTOR4 *pOut, CONST D3DXVECTOR3 *pV, CONST D3DXMATRIX *pM);
D3DXVECTOR3 *WINAPI D3DXVec3TransformCoord(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, CONST D3DXMATRIX *pM);
D3DXVECTOR3 *WINAPI D3DXVec3TransformNormal(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, CONST D3DXMATRIX *pM);
D3DXVECTOR4 *WINAPI D3DXVec3TransformArray(D3DXVECTOR4 *pOut, UINT OutStride, CONST D3DXVECTOR3 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n);
D3DXVECTOR3 *WINAPI D3DXVec3TransformCoordArray(D3DXVECTOR3 *pOut, UINT OutStride, CONST D3DXVECTOR3 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n);
D3DXVECTOR3 *WINAPI D3DXVec3TransformNormalArray(D3DXVECTOR3 *pOut, UINT OutStride, CONST D3DXVECTOR3 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n);
D3DXVECTOR3 *WINAPI D3DXVec3Project(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, CONST D3DVIEWPORT9 *pViewport, CONST D3DXMATRIX *pProjection, CONST D3DXMATRIX *pView, CONST D3DXMATRIX *pWorld);
D3DXVECTOR3 *WINAPI D3DXVec3Unproject(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, CONST D3DVIEWPORT9 *pViewport, CONST D3DXMATRIX *pProjection, CONST D3DXMATRIX *pView, CONST D3DXMATRIX *pWorld);
D3DXVECTOR3 *WINAPI D3DXVec3ProjectArray(D3DXVECTOR3 *pOut, UINT OutStride, CONST D3DXVECTOR3 *pV, UINT VStride, CONST D3DVIEWPORT9 *pViewport, CONST D3DXMATRIX *pProjection, CONST D3DXMATRIX *pView, CONST D3DXMATRIX *pWorld, UINT n);
D3DXVECTOR3 *WINAPI D3DXVec3UnprojectArray(D3DXVECTOR3 *pOut, UINT OutStride, CONST D3DXVECTOR3 *pV, UINT VStride, CONST D3DVIEWPORT9 *pViewport, CONST D3DXMATRIX *pProjection, CONST D3DXMATRIX *pView, CONST D3DXMATRIX *pWorld, UINT n);

FLOAT D3DXVec4Length(CONST D3DXVECTOR4 *pV);
FLOAT D3DXVec4LengthSq(CONST D3DXVECTOR4 *pV);
FLOAT D3DXVec4Dot(CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);
D3DXVECTOR4 *D3DXVec4Add(D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);
D3DXVECTOR4 *D3DXVec4Subtract(D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);
D3DXVECTOR4 *D3DXVec4Minimize(D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);
D3DXVECTOR4 *D3DXVec4Maximize(D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);
D3DXVECTOR4 *D3DXVec4Scale(D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV, FLOAT s);
D3DXVECTOR4 *D3DXVec4Lerp(D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2, FLOAT s);

D3DXVECTOR4 *WINAPI D3DXVec4Cross(D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2, CONST D3DXVECTOR4 *pV3);
D3DXVECTOR4 *WINAPI D3DXVec4Normalize(D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV);
D3DXVECTOR4 *WINAPI D3DXVec4Hermite(D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pT1, CONST D3DXVECTOR4 *pV2, CONST D3DXVECTOR4 *pT2, FLOAT s);
D3DXVECTOR4 *WINAPI D3DXVec4CatmullRom(D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV0, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2, CONST D3DXVECTOR4 *pV3, FLOAT s);
D3DXVECTOR4 *WINAPI D3DXVec4BaryCentric(D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2, CONST D3DXVECTOR4 *pV3, FLOAT f, FLOAT g);
D3DXVECTOR4 *WINAPI D3DXVec4Transform(D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV, CONST D3DXMATRIX *pM);
D3DXVECTOR4 *WINAPI D3DXVec4TransformArray(D3DXVECTOR4 *pOut, UINT OutStride, CONST D3DXVECTOR4 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n);

D3DXMATRIX *D3DXMatrixIdentity(D3DXMATRIX *pOut);
BOOL D3DXMatrixIsIdentity(CONST D3DXMATRIX *pM);

FLOAT WINAPI D3DXMatrixDeterminant(CONST D3DXMATRIX *pM);
HRESULT WINAPI D3DXMatrixDecompose(D3DXVECTOR3 *pOutScale, D3DXQUATERNION *pOutRotation, D3DXVECTOR3 *pOutTranslation, CONST D3DXMATRIX *pM);
D3DXMATRIX *WINAPI D3DXMatrixTranspose(D3DXMATRIX *pOut, CONST D3DXMATRIX *pM);
D3DXMATRIX *WINAPI D3DXMatrixMultiply(D3DXMATRIX *pOut, CONST D3DXMATRIX *pM1, CONST D3DXMATRIX *pM2);
D3DXMATRIX *WINAPI D3DXMatrixMultiplyTranspose(D3DXMATRIX *pOut, CONST D3DXMATRIX *pM1, CONST D3DXMATRIX *pM2);
D3DXMATRIX *WINAPI D3DXMatrixInverse(D3DXMATRIX *pOut, FLOAT *pDeterminant, CONST D3DXMATRIX *pM);
D3DXMATRIX *WINAPI D3DXMatrixScaling(D3DXMATRIX *pOut, FLOAT sx, FLOAT sy, FLOAT sz);
D3DXMATRIX *WINAPI D3DXMatrixTranslation(D3DXMATRIX *pOut, FLOAT x, FLOAT y, FLOAT z);
D3DXMATRIX *WINAPI D3DXMatrixRotationX(D3DXMATRIX *pOut, FLOAT Angle);
D3DXMATRIX *WINAPI D3DXMatrixRotationY(D3DXMATRIX *pOut, FLOAT Angle);
D3DXMATRIX *WINAPI D3DXMatrixRotationZ(D3DXMATRIX *pOut, FLOAT Angle);
D3DXMATRIX *WINAPI D3DXMatrixRotationAxis(D3DXMATRIX *pOut, CONST D3DXVECTOR3 *pV, FLOAT Angle);
D3DXMATRIX *WINAPI D3DXMatrixRotationQuaternion(D3DXMATRIX *pOut, CONST D3DXQUATERNION *pQ);
D3DXMATRIX *WINAPI D3DXMatrixRotationYawPitchRoll(D3DXMATRIX *pOut, FLOAT Yaw, FLOAT Pitch, FLOAT Roll);
D3DXMATRIX *WINAPI D3DXMatrixTransformation(D3DXMATRIX *pOut, CONST D3DXVECTOR3 *pScalingCenter, CONST D3DXQUATERNION *pScalingRotation, CONST D3DXVECTOR3 *pScaling, CONST D3DXVECTOR3 *pRotationCenter, CONST D3DXQUATERNION *pRotation, CONST D3DXVECTOR3 *pTranslation);
D3DXMATRIX *WINAPI D3DXMatrixTransformation2D(D3DXMATRIX *pOut, CONST D3DXVECTOR2 *pScalingCenter, FLOAT ScalingRotation, CONST D3DXVECTOR2 *pScaling, CONST D3DXVECTOR2 *pRotationCenter, FLOAT Rotation, CONST D3DXVECTOR2 *pTranslation);
D3DXMATRIX *WINAPI D3DXMatrixAffineTransformation(D3DXMATRIX *pOut, FLOAT Scaling, CONST D3DXVECTOR3 *pRotationCenter, CONST D3DXQUATERNION *pRotation, CONST D3DXVECTOR3 *pTranslation);
D3DXMATRIX *WINAPI D3DXMatrixAffineTransformation2D(D3DXMATRIX *pOut, FLOAT Scaling, CONST D3DXVECTOR2 *pRotationCenter, FLOAT Rotation, CONST D3DXVECTOR2 *pTranslation);
D3DXMATRIX *WINAPI D3DXMatrixLookAtRH(D3DXMATRIX *pOut, CONST D3DXVECTOR3 *pEye, CONST D3DXVECTOR3 *pAt, CONST D3DXVECTOR3 *pUp);
D3DXMATRIX *WINAPI D3DXMatrixLookAtLH(D3DXMATRIX *pOut, CONST D3DXVECTOR3 *pEye, CONST D3DXVECTOR3 *pAt, CONST D3DXVECTOR3 *pUp);
D3DXMATRIX *WINAPI D3DXMatrixPerspectiveRH(D3DXMATRIX *pOut, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf);
D3DXMATRIX *WINAPI D3DXMatrixPerspectiveLH(D3DXMATRIX *pOut, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf);
D3DXMATRIX *WINAPI D3DXMatrixPerspectiveFovRH(D3DXMATRIX *pOut, FLOAT fovy, FLOAT Aspect, FLOAT zn, FLOAT zf);
D3DXMATRIX *WINAPI D3DXMatrixPerspectiveFovLH(D3DXMATRIX *pOut, FLOAT fovy, FLOAT Aspect, FLOAT zn, FLOAT zf);
D3DXMATRIX *WINAPI D3DXMatrixPerspectiveOffCenterRH(D3DXMATRIX *pOut, FLOAT l, FLOAT r, FLOAT b, FLOAT t, FLOAT zn, FLOAT zf);
D3DXMATRIX *WINAPI D3DXMatrixPerspectiveOffCenterLH(D3DXMATRIX *pOut, FLOAT l, FLOAT r, FLOAT b, FLOAT t, FLOAT zn, FLOAT zf);
D3DXMATRIX *WINAPI D3DXMatrixOrthoRH(D3DXMATRIX *pOut, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf);
D3DXMATRIX *WINAPI D3DXMatrixOrthoLH(D3DXMATRIX *pOut, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf);
D3DXMATRIX *WINAPI D3DXMatrixOrthoOffCenterRH(D3DXMATRIX *pOut, FLOAT l, FLOAT r, FLOAT b, FLOAT t, FLOAT zn, FLOAT zf);
D3DXMATRIX *WINAPI D3DXMatrixOrthoOffCenterLH(D3DXMATRIX *pOut, FLOAT l, FLOAT r, FLOAT b, FLOAT t, FLOAT zn, FLOAT zf);
D3DXMATRIX *WINAPI D3DXMatrixShadow(D3DXMATRIX *pOut, CONST D3DXVECTOR4 *pLight, CONST D3DXPLANE *pPlane);
D3DXMATRIX *WINAPI D3DXMatrixReflect(D3DXMATRIX *pOut, CONST D3DXPLANE *pPlane);

FLOAT D3DXQuaternionLength(CONST D3DXQUATERNION *pQ);
FLOAT D3DXQuaternionLengthSq(CONST D3DXQUATERNION *pQ);
FLOAT D3DXQuaternionDot(CONST D3DXQUATERNION *pQ1, CONST D3DXQUATERNION *pQ2);
D3DXQUATERNION *D3DXQuaternionIdentity(D3DXQUATERNION *pOut);
BOOL D3DXQuaternionIsIdentity(CONST D3DXQUATERNION *pQ);
D3DXQUATERNION *D3DXQuaternionConjugate(D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ);

void WINAPI D3DXQuaternionToAxisAngle(CONST D3DXQUATERNION *pQ, D3DXVECTOR3 *pAxis, FLOAT *pAngle);
D3DXQUATERNION *WINAPI D3DXQuaternionRotationMatrix(D3DXQUATERNION *pOut, CONST D3DXMATRIX *pM);
D3DXQUATERNION *WINAPI D3DXQuaternionRotationAxis(D3DXQUATERNION *pOut, CONST D3DXVECTOR3 *pV, FLOAT Angle);
D3DXQUATERNION *WINAPI D3DXQuaternionRotationYawPitchRoll(D3DXQUATERNION *pOut, FLOAT Yaw, FLOAT Pitch, FLOAT Roll);
D3DXQUATERNION *WINAPI D3DXQuaternionMultiply(D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ1, CONST D3DXQUATERNION *pQ2);
D3DXQUATERNION *WINAPI D3DXQuaternionNormalize(D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ);
D3DXQUATERNION *WINAPI D3DXQuaternionInverse(D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ);
D3DXQUATERNION *WINAPI D3DXQuaternionLn(D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ);
D3DXQUATERNION *WINAPI D3DXQuaternionExp(D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ);
D3DXQUATERNION *WINAPI D3DXQuaternionSlerp(D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ1, CONST D3DXQUATERNION *pQ2, FLOAT t);
D3DXQUATERNION *WINAPI D3DXQuaternionSquad(D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ1, CONST D3DXQUATERNION *pA, CONST D3DXQUATERNION *pB, CONST D3DXQUATERNION *pC, FLOAT t);
void WINAPI D3DXQuaternionSquadSetup(D3DXQUATERNION *pAOut, D3DXQUATERNION *pBOut, D3DXQUATERNION *pCOut, CONST D3DXQUATERNION *pQ0, CONST D3DXQUATERNION *pQ1, CONST D3DXQUATERNION *pQ2, CONST D3DXQUATERNION *pQ3);
D3DXQUATERNION *WINAPI D3DXQuaternionBaryCentric(D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ1, CONST D3DXQUATERNION *pQ2, CONST D3DXQUATERNION *pQ3, FLOAT f, FLOAT g);

FLOAT D3DXPlaneDot(CONST D3DXPLANE *pP, CONST D3DXVECTOR4 *pV);
FLOAT D3DXPlaneDotCoord(CONST D3DXPLANE *pP, CONST D3DXVECTOR3 *pV);
FLOAT D3DXPlaneDotNormal(CONST D3DXPLANE *pP, CONST D3DXVECTOR3 *pV);
D3DXPLANE *D3DXPlaneScale(D3DXPLANE *pOut, CONST D3DXPLANE *pP, FLOAT s);

D3DXPLANE *WINAPI D3DXPlaneNormalize(D3DXPLANE *pOut, CONST D3DXPLANE *pP);
D3DXVECTOR3 *WINAPI D3DXPlaneIntersectLine(D3DXVECTOR3 *pOut, CONST D3DXPLANE *pP, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2);
D3DXPLANE *WINAPI D3DXPlaneFromPointNormal(D3DXPLANE *pOut, CONST D3DXVECTOR3 *pPoint, CONST D3DXVECTOR3 *pNormal);
D3DXPLANE *WINAPI D3DXPlaneFromPoints(D3DXPLANE *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2, CONST D3DXVECTOR3 *pV3);
D3DXPLANE *WINAPI D3DXPlaneTransform(D3DXPLANE *pOut, CONST D3DXPLANE *pP, CONST D3DXMATRIX *pM);
D3DXPLANE *WINAPI D3DXPlaneTransformArray(D3DXPLANE *pOut, UINT OutStride, CONST D3DXPLANE *pP, UINT PStride, CONST D3DXMATRIX *pM, UINT n);

D3DXCOLOR *D3DXColorNegative(D3DXCOLOR *pOut, CONST D3DXCOLOR *pC);
D3DXCOLOR *D3DXColorAdd(D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2);
D3DXCOLOR *D3DXColorSubtract(D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2);
D3DXCOLOR *D3DXColorScale(D3DXCOLOR *pOut, CONST D3DXCOLOR *pC, FLOAT s);
D3DXCOLOR *D3DXColorModulate(D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2);
D3DXCOLOR *D3DXColorLerp(D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2, FLOAT s);

D3DXCOLOR *WINAPI D3DXColorAdjustSaturation(D3DXCOLOR *pOut, CONST D3DXCOLOR *pC, FLOAT s);
D3DXCOLOR *WINAPI D3DXColorAdjustContrast(D3DXCOLOR *pOut, CONST D3DXCOLOR *pC, FLOAT c);

FLOAT WINAPI D3DXFresnelTerm(FLOAT CosTheta, FLOAT RefractionIndex);

typedef interface ID3DXMatrixStack ID3DXMatrixStack;
typedef interface ID3DXMatrixStack *LPD3DXMATRIXSTACK;
DEFINE_GUID(IID_ID3DXMatrixStack, 0xc7885ba7, 0xf990, 0x4fe7, 0x92, 0x2d, 0x85, 0x15, 0xe4, 0x77, 0xdd, 0x85);
#undef INTERFACE
#define INTERFACE ID3DXMatrixStack
DECLARE_INTERFACE_(ID3DXMatrixStack, IUnknown)
{
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID * ppvObj)PURE;
	STDMETHOD_(ULONG, AddRef) (THIS)PURE;
	STDMETHOD_(ULONG, Release) (THIS)PURE;
	STDMETHOD(Pop) (THIS)PURE;
	STDMETHOD(Push) (THIS)PURE;
	STDMETHOD(LoadIdentity) (THIS)PURE;
	STDMETHOD(LoadMatrix) (THIS_ CONST D3DXMATRIX * pM)PURE;
	STDMETHOD(MultMatrix) (THIS_ CONST D3DXMATRIX * pM)PURE;
	STDMETHOD(MultMatrixLocal) (THIS_ CONST D3DXMATRIX * pM)PURE;
	STDMETHOD(RotateAxis) (THIS_ CONST D3DXVECTOR3 * pV, FLOAT Angle)PURE;
	STDMETHOD(RotateAxisLocal) (THIS_ CONST D3DXVECTOR3 * pV, FLOAT Angle)PURE;
	STDMETHOD(RotateYawPitchRoll) (THIS_ FLOAT Yaw, FLOAT Pitch, FLOAT Roll)PURE;
	STDMETHOD(RotateYawPitchRollLocal) (THIS_ FLOAT Yaw, FLOAT Pitch, FLOAT Roll)PURE;
	STDMETHOD(Scale) (THIS_ FLOAT x, FLOAT y, FLOAT z)PURE;
	STDMETHOD(ScaleLocal) (THIS_ FLOAT x, FLOAT y, FLOAT z)PURE;
	STDMETHOD(Translate) (THIS_ FLOAT x, FLOAT y, FLOAT z)PURE;
	STDMETHOD(TranslateLocal) (THIS_ FLOAT x, FLOAT y, FLOAT z)PURE;
	STDMETHOD_(D3DXMATRIX *, GetTop) (THIS)PURE;
};

HRESULT WINAPI D3DXCreateMatrixStack(DWORD Flags, LPD3DXMATRIXSTACK *ppStack);

#define D3DXSH_MINORDER 2
#define D3DXSH_MAXORDER 6
FLOAT *WINAPI D3DXSHEvalDirection(FLOAT *pOut, UINT Order, CONST D3DXVECTOR3 *pDir);
FLOAT *WINAPI D3DXSHRotate(FLOAT *pOut, UINT Order, CONST D3DXMATRIX *pMatrix, CONST FLOAT *pIn);
FLOAT *WINAPI D3DXSHRotateZ(FLOAT *pOut, UINT Order, FLOAT Angle, CONST FLOAT *pIn);
FLOAT *WINAPI D3DXSHAdd(FLOAT *pOut, UINT Order, CONST FLOAT *pA, CONST FLOAT *pB);
FLOAT *WINAPI D3DXSHScale(FLOAT *pOut, UINT Order, CONST FLOAT *pIn, CONST FLOAT Scale);
FLOAT WINAPI D3DXSHDot(UINT Order, CONST FLOAT *pA, CONST FLOAT *pB);
FLOAT *WINAPI D3DXSHMultiply2(FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);
FLOAT *WINAPI D3DXSHMultiply3(FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);
FLOAT *WINAPI D3DXSHMultiply4(FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);
FLOAT *WINAPI D3DXSHMultiply5(FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);
FLOAT *WINAPI D3DXSHMultiply6(FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);
HRESULT WINAPI D3DXSHEvalDirectionalLight(UINT Order, CONST D3DXVECTOR3 *pDir, FLOAT RIntensity, FLOAT GIntensity, FLOAT BIntensity, FLOAT *pROut, FLOAT *pGOut, FLOAT *pBOut);
HRESULT WINAPI D3DXSHEvalSphericalLight(UINT Order, CONST D3DXVECTOR3 *pPos, FLOAT Radius, FLOAT RIntensity, FLOAT GIntensity, FLOAT BIntensity, FLOAT *pROut, FLOAT *pGOut, FLOAT *pBOut);
HRESULT WINAPI D3DXSHEvalConeLight(UINT Order, CONST D3DXVECTOR3 *pDir, FLOAT Radius, FLOAT RIntensity, FLOAT GIntensity, FLOAT BIntensity, FLOAT *pROut, FLOAT *pGOut, FLOAT *pBOut);
HRESULT WINAPI D3DXSHEvalHemisphereLight(UINT Order, CONST D3DXVECTOR3 *pDir, D3DXCOLOR Top, D3DXCOLOR Bottom, FLOAT *pROut, FLOAT *pGOut, FLOAT *pBOut);
HRESULT WINAPI D3DXSHProjectCubeMap(UINT uOrder, LPDIRECT3DCUBETEXTURE9 pCubeMap, FLOAT *pROut, FLOAT *pGOut, FLOAT *pBOut);

#include <d3dx9math.inl>
#if _MSC_VER >= 1200
#pragma warning(pop)
#else
#pragma warning(default:4201)
#endif
#endif
