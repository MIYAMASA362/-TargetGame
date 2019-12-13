//
//	CBullert.h
//		Author:	DATE:
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

#pragma once
#ifndef CBULLET_H
#define CBULLET_H

//================================================
//	�C���N���[�h	include
//================================================
#include"common.h"

//Class
#include"CGameObject.h"
#include"CCollision.h"

//================================================
//	�}�N����`	define
//================================================
#define BULLET_SPEED (1.0f)
#define BULLET_NUM (256)

//================================================
//	�񋓌^		enum
//================================================


//================================================
//	�\����		struct/typedef
//================================================


//================================================
//	�O���[�o���ϐ��@global
//================================================


//================================================
//	�N���X		class
//================================================

class CBullet:public NRender3D::CGameObject
{
private:
	NTexture::CAnimation animation;
public:
	bool bEnable;
	int frame;
	Collision::Sphere ColSphere;
public:
	//�R���X�g���N�^
	CBullet();
	~CBullet();

public:
	static void Initialize();
	static void Render();
	static void Update();
	static void Finalize();

public:
	static void Create(D3DXVECTOR3 position,D3DXVECTOR3 at,float x);

public:
	void update();
	void render();
	void destroy();
	void hit();
};

CBullet* Get_Bullet(int num);
bool Get_BulletIsEnable(int num);

#endif