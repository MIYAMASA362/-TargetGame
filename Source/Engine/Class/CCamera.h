//
//	CCamera.h
//		Author:HIROMASA IKEDA	DATE:2018/10/16
//===============================================
//	変更者 Changed By
//		Name:	DATE:
//
//-----------------------------------------------

#pragma once
#ifndef CCAMERA_H
#define CCAMERA_H

//================================================
//	インクルード	include
//================================================
#include"common.h"
#include<d3dx9.h>

//Class
#include"CTransform.h"

//===============================================
//	マクロ定義	define
//===============================================


//================================================
//	列挙型		enum
//================================================


//===============================================
//	マクロ定義
//===============================================
#define CAMERA_POS (D3DXVECTOR3(0.0f, 5.0f, 5.0f))		//カメラ位置
#define CAMERA_AT (D3DXVECTOR3(0.0f, 0.0f, 0.0f))		//カメラの注視点
#define CAMERA_UP (D3DXVECTOR3(0.0f,1.0f,0.0f))			//カメラの上方向 (どういう捩れで見るの？)
#define CAMERA_FORWARD (D3DXVECTOR3(0.0f,0.0f,1.0f))	//カメラ前
#define CAMERA_INITIALSPEED (0.05f)						//カメラの初期速度

#define CAMERA_NEAR (0.1f)
#define CAMERA_WAR (100.0f)

#define SCREEN_ASPECT ((float)WINDOWSCREEN_WIDTH / WINDOWSCREEN_HEIGHT)
#define CAMERA_ATDISTANCE (10.0f)
#define CAMERA_FOV (D3DXToRadian(60))

//================================================
//	グローバル変数　global
//================================================

//================================================
//	クラス		class
//================================================

//-------------------------------------
//	absCamera　抽象クラス
//-------------------------------------
class ACamera
{
private:
	static ACamera* pMainCamera;	//メインカメラ

public:
	static ACamera* Get_Main();	//メインカメラ取得
	static D3DXMATRIX Get_ViewMatrix();	//View行列
	static bool Begin();		//描画開始

public:
	D3DXMATRIX MtxView;			//View行列
	D3DXMATRIX MtxProjection;	//Projection

	D3DXVECTOR3 position;		//位置
	D3DXVECTOR3 m_Rotation;		//回転
	D3DXVECTOR3 at;				//注視点

	float atDistance;			//注視点までの距離
	float fov;					//画角

public:
	D3DXVECTOR3 Get_Forward();
	D3DXVECTOR3 Get_Up();
	D3DXVECTOR3 Get_Right();
	D3DXVECTOR3 Get_ScreenToWorld(float z);

public:
	ACamera() :ACamera(CAMERA_POS, CAMERA_AT, CAMERA_ATDISTANCE, CAMERA_FOV) {};
	ACamera(D3DXVECTOR3 Position) :ACamera(Position,CAMERA_AT,CAMERA_ATDISTANCE,CAMERA_FOV) {};
	ACamera(D3DXVECTOR3 Position, D3DXVECTOR3 At) :ACamera(Position, At, CAMERA_ATDISTANCE, CAMERA_FOV) {};
	ACamera(D3DXVECTOR3 Position, D3DXVECTOR3 At, float AtDistance) :ACamera(Position, At, AtDistance, CAMERA_FOV) {};
	ACamera(D3DXVECTOR3 Position,D3DXVECTOR3 At,float AtDistance,float fov);

public:
	void Set_Main();			//メインカメラに設定
	void LookingAt(D3DXVECTOR3 AtPosition);
public:
	virtual void Update() PURE;	//更新処理
};

//-------------------------------------
//	Camera　クラス
//-------------------------------------
class Camera:public ACamera
{
public:
	Camera():Camera(CAMERA_POS, CAMERA_AT, CAMERA_ATDISTANCE, CAMERA_FOV) {};
	Camera(D3DXVECTOR3 Position) : Camera(Position, CAMERA_AT, CAMERA_ATDISTANCE, CAMERA_FOV) {};
	Camera(D3DXVECTOR3 Position, D3DXVECTOR3 At) :Camera(Position, At, CAMERA_ATDISTANCE, CAMERA_FOV) {};
	Camera(D3DXVECTOR3 Position, D3DXVECTOR3 At, float AtDistance, float fov);

public:
	virtual void Update() override;		//更新
};

//-------------------------------------
//	マウス・キー操作などができるカメラ
//-------------------------------------
class OperationCamera:public ACamera
{
private:
	float Speed;
	float SpeedMag;
public:
	OperationCamera() :OperationCamera(CAMERA_POS, CAMERA_AT, CAMERA_ATDISTANCE, CAMERA_FOV) {};
	OperationCamera(D3DXVECTOR3 Position) : OperationCamera(Position, CAMERA_AT, CAMERA_ATDISTANCE, CAMERA_FOV) {};
	OperationCamera(D3DXVECTOR3 Position, D3DXVECTOR3 At, float AtDistance, float fov);
public:
	void Update() final;		//更新
};

#endif