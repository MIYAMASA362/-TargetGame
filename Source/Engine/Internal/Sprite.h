//
//	Sprite.h
//		Author:HIROMASA IEDA	Date:2018/09/13
//===============================================
#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include<d3dx9.h>
#include"CTransform.h"
#include"Texture.h"
#include"CSprite.h"


//===============================================
//	�}�N����`
//===============================================
#define FVF_VERTEX2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
#define FVF_TEXVERTEX2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

//===============================================
//	�\����
//===============================================

//-------------------------------------
//	Vertex2D
//-------------------------------------
typedef struct Vertex2D_tag
{
	D3DXVECTOR4 Position;
	D3DCOLOR Color;
}Vertex2D;

//-------------------------------------
//	TexVertex2D
//-------------------------------------
typedef struct TexVertex2D_tag
{
	D3DXVECTOR4 Position;
	D3DCOLOR Color;
	D3DXVECTOR2 TexCoord;
}TexVertex2D;

//===============================================
//	�֐�
//===============================================


void Sprite_SetDevice(LPDIRECT3DDEVICE9 pD3DDevice);							//�f�o�C�X�ݒ�
/*
void Render2D_Porigon(Transform2* const pTransform2,const D3DCOLOR Color);							//�|���S���`��
void Render2D_Porigon_Circle(Transform2* const pTransform2,const float radius,const D3DCOLOR Color);		//�~�|���S��
void Render2D_Line(D3DXVECTOR2 Vector1, D3DXVECTOR2 Vector2);					//��(�����Ƃ��ݒ�ł����)
void Render2D_Porigon_Rotate(Transform2* const pTransform2, const D3DCOLOR Color);					//�|���S����]
void Render2D_Texture_Size(Transform2* const pTransform2, NTexture::Texture* const pTexture, const D3DCOLOR Color);	//�摜�T�C�Y�`��
void Render2D_Texture_Fill(Transform2* const pTransform2, NTexture::Texture* const pTexture, const D3DCOLOR Color);			//�|���S���T�C�Y�ɕ`��
void Render2D_Texture_Clip(Transform2* const pTransform2, NTexture::Texture* const pTexture, const D3DCOLOR Color);			//�e�N�X�`���؂蔲���T�C�Y�`��
void Render2D_Sprite(Transform2* const pTransform2, NTexture::Texture* const pTexture, const D3DCOLOR Color);				//�X�v���C�g�`��
void Render2D_Sprite_Rotate(Transform2* const pTransform2, NTexture::Texture* const pTexture, const D3DCOLOR Color);		//��
*/

namespace NRender2D
{
	void Set_Device(LPDIRECT3DDEVICE9 pD3DDevice);

	//Vertex2D		�e�N�X�`���Ȃ�
	void Sprite(D3DXVECTOR2 Position, D3DXVECTOR2 Scale);
	void Sprite(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, float Rotate);
	void Sprite(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, D3DCOLOR Color);
	void Sprite(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, D3DCOLOR Color,float Rotate);	
	void Sprite(Transform2* const pTransform2, const D3DCOLOR Color);
	void Sprite_Rotate(Transform2* const pTransform2, const D3DCOLOR Color);

	//TexVertex2D	�e�N�X�`������
	void Sprite(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, LPDIRECT3DTEXTURE9 pTexture);
	void Sprite(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, D3DCOLOR Color, LPDIRECT3DTEXTURE9 pTexture);
	void Sprite(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, D3DCOLOR Color, LPDIRECT3DTEXTURE9 pTexture, D3DXVECTOR2 origin, D3DXVECTOR2 uv);
	void Sprite(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, D3DCOLOR Color, LPDIRECT3DTEXTURE9 pTexture, D3DXVECTOR2 origin, D3DXVECTOR2 uv, float Rotate);
	void Sprite(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, D3DCOLOR Color, LPDIRECT3DTEXTURE9 pTexture, float Rotate);

	void Sprite(Transform2* const pTransform2, NTexture::Texture* const pTexture, const D3DCOLOR Color);			//�X�v���C�g�`��
	void Sprite_TexSize(Transform2* const pTransform2, NTexture::Texture* const pTexture,const D3DCOLOR Color);	//�摜�T�C�Y�`��
	void Sprite_TexFill(Transform2* const pTransform2, NTexture::Texture* const pTexture,const D3DCOLOR Color);	//�|���S���T�C�Y�ɕ`��
	void Sprite_Rotate(Transform2* const pTransform2, NTexture::Texture* const pTexture, const D3DCOLOR Color);	//��

	//���̑�
	void Circle(D3DXVECTOR2 Position, D3DCOLOR Color, float radius);
	void Circle(D3DXVECTOR2 Position, D3DCOLOR Color, float radius, PDIRECT3DTEXTURE9* pTexture, D3DXVECTOR2 origin, float texRadius);
	void Line(D3DXVECTOR2 Vector1, D3DXVECTOR2 Vector2, D3DCOLOR Color, float Width);
}

#endif

