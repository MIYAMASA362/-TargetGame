//
//	CGun.h
//		Author:	DATE:
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

#pragma once
#ifndef CGUN_H
#define CGUN_H

//================================================
//	�C���N���[�h	include
//================================================
#include"common.h"

//Class
#include"CGameObject.h"

//================================================
//	�}�N����`	define
//================================================
#define GUN_SHAKE (20)			//�u��
#define GUN_SHAKE_VAR (1)		//�u���ω��l
#define GUN_SHAKE_MAG (0.1f)	//�u���{��

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

class CGun:public NRender3D::CGameObject
{
private:
	D3DXVECTOR3 Muzzle;		//�e���ʒu

private:
	int rate;		//���[�g(frame)
	int wait;		//�ҋ@(frame)
	int BulletNum;	//�e��
	int Shake;		//�u�� (x0.1)

public:
	CGun();
	// �E�ʒu��� �E�e���ʒu �E�e�� �E�ˌ����x
	CGun(CTransform* transform,D3DXVECTOR3 Muzzle,int BulletNum,int rate);
	~CGun();

public:
	void Update();

public:
	D3DXVECTOR3 Get_Muzzle();
	void Set_Muzzle(D3DXVECTOR3 position);
	void render();
	void Burst(D3DXVECTOR3 target, float x);
};


#endif