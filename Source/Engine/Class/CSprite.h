//
//	CSprite.h
//		Author:HIROMASA IEKDA	DATE:2018/10/01
//===============================================
#pragma once

#ifndef CSPRITE_H
#define CSPRITE_H

#include<d3dx9.h>

#include"CTransform.h"
#include"Texture.h"

namespace NRender2D
{
	//===========================================
	//	CSprite
	//===========================================
	class CSprite
	{
	private:
		Transform2* m_transform;
		NTexture::Texture* m_texture;
		D3DCOLOR m_Color;
	public:
		//�R���X�g���N�^
		CSprite();
		CSprite(Transform2* transform,NTexture::Texture* texture,D3DCOLOR Color);
		//�f�X�g���N�^
		~CSprite();
	public:
		//------------------------------------
		//	�|�C���^
		//------------------------------------
		Transform2* CSprite::Transform()
		{
			return this->m_transform;
		}

		NTexture::Texture* CSprite::Texture()
		{
			return this->m_texture;
		}
	public:
		//Getter
		Transform2 Get_Transform();
		NTexture::Texture Get_Texture();
		D3DCOLOR Get_Color();
	public:
		//Setter
		void Set_Transform(Transform2* transform);
		void Set_Texture(NTexture::Texture* texture);
		void Set_Color(D3DCOLOR color);
	public:
		void Render();
	};
}


#endif // !CSPRITE_H