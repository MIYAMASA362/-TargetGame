//
//	CBurst.h
//		Author:	DATE:
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

#pragma once
#ifndef CBURST_H
#define CBURST_H

//================================================
//	�C���N���[�h	include
//================================================
#include"common.h"
#include<d3dx9.h>

//Class
#include"Texture.h"
#include"Animation.h"
#include"Billboard.h"

//================================================
//	�}�N����`	define
//================================================


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

//-------------------------------------
//	CBurst
//-------------------------------------
class CBurst:public ABillboard
{
private:
	bool bDepthTest;
public:
	NTexture::Texture* texture;
	NTexture::CAnimation* animation;
public:
	CBurst(D3DXVECTOR3 Position,D3DXVECTOR3 Scale, bool bDepthTest);
	CBurst(D3DXVECTOR3 Position, D3DXVECTOR3 Scale, NTexture::Texture* texture, NTexture::CAnimation* animation, bool bDepthTest);
	~CBurst();
public:
	//�����o
	void Update() override;
	void Render() override;
};



#endif