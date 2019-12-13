//
//	Texture.h
//		Auther:HIROMASA IKEDA	Date:2018/09/13
//===============================================
#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include<d3dx9.h>
#include"common.h"
//===============================================
//	�}�N����`
//===============================================
#define TEXTURE_FILENAME_MAX (64)

//===============================================
//	���O���
//===============================================
namespace NTexture
{
	//==============================================
	//	�e�N�X�`����
	//==============================================
	enum Name
	{
		CubeTexture,
		BillBoardTex,
		MeshFieldTex,
		MeshCylinderTex,
		Billboard_Burst,
		Billboard_Shadow,
		Mesh_Wall,
		Reticle,
		TargetText,
		NumberTex,
		NAME_NONE,		//�w�薳���ꍇ
		NAME_END,	//�e�N�X�`���I���
	};

	//==============================================
	//	�f�[�^
	//==============================================
	//
	//	int num;			�e�N�X�`���ԍ�
	//	char* TexturePath;	�e�N�X�`��URL
	//	UINT width;			���摜�@��
	//	UINT height;		���摜�@����
	//	LPDIRECT3DTEXTURE9;	�e�N�X�`���f�[�^
	//
	struct Data
	{
		int num;
		const char* TexturePath;
		UINT width;
		UINT height;
		LPDIRECT3DTEXTURE9 pTexture;
	};

	//==============================================
	//	�֐�
	//==============================================
	void Initialize();
	void Finalize();
	bool Load(Data* LoadData, const char* path);
	bool Load_Index(Data* LoadData,int Size);
	void UnLoad(Data* data);
	LPDIRECT3DTEXTURE9 Get_Texture(const Name name);
	Data* Get_Data(const Name name);
	
	UINT Get_Width(const Name name);
	UINT Get_Height(const Name name);

	//==============================================
	//	Class
	//==============================================

	//=========================================
	//	Texture
	//=========================================
	class Texture
	{
	public:
		Texture();
		~Texture();
	public:
		virtual LPDIRECT3DTEXTURE9 lpTexture();
		virtual UINT Width();
		virtual UINT Height();
		virtual D3DXVECTOR2 TexCoord();
		virtual D3DXVECTOR2 TexScale();
	};

	//====================================
	//	NameTexture
	//====================================
	class NameTexture:public Texture
	{
	public:
		D3DXVECTOR2 Coord;
		D3DXVECTOR2 Scale;
	private:
		Name name;
	public:
		NameTexture(Name name) :NameTexture(name, { 0.0f,0.0f }, { 1.0f,1.0f }) {};
		NameTexture(Name name, D3DXVECTOR2 TexCoord, D3DXVECTOR2 TexScale);
		~NameTexture();
	public:
		//override
		LPDIRECT3DTEXTURE9 lpTexture() override;
		UINT Width() override;
		UINT Height() override;
		D3DXVECTOR2 TexCoord() override;
		D3DXVECTOR2 TexScale() override;
	public:
		void Clip(UINT x,UINT y,UINT w,UINT h);
	};

	//====================================
	//	CTexture
	//====================================
	class CTexture:public Texture
	{
	private:
		D3DXVECTOR2 m_Coord;
		D3DXVECTOR2 m_Scale;
	private:
		Data* m_lpdata;
	public:
		CTexture(Data* data,UINT x,UINT y,UINT w,UINT h);
		~CTexture();
	public:
		//overrride
		LPDIRECT3DTEXTURE9 lpTexture() override;
		UINT Width() override;
		UINT Height() override;
		D3DXVECTOR2 TexCoord() override;
		D3DXVECTOR2 TexScale() override;
	public:
		void Clip(UINT x, UINT y, UINT w, UINT h);
	};

	//====================================
	//	PathTexture
	//====================================
	class PathTexture:public Texture
	{
	private:
		D3DXVECTOR2 Coord;
		D3DXVECTOR2 Scale;
	private:
		Data data;
	public:
		PathTexture(const char* path) :PathTexture(path, { 0.0f,0.0f }, { 1.0f,1.0f }) {};
		PathTexture(const char* path, UINT TexW, UINT TexH, UINT x, UINT y, UINT w, UINT h);
		PathTexture(const char* path,D3DXVECTOR2 TexCoord,D3DXVECTOR2 TexScale);
		~PathTexture();
	public:
		//override
		LPDIRECT3DTEXTURE9 lpTexture() override;
		UINT Width() override;
		UINT Height() override;
		D3DXVECTOR2 TexCoord() override;
		D3DXVECTOR2 TexScale() override;
	public:
		void Clip(UINT x,UINT y,UINT w,UINT h);
	};

	//====================================
	//	CAnimation
	//====================================
	class CAnimation
	{
	public:
		int AnimaPatern;			//�A�j���[�V����
		int MaxPatern;				//�ő�A�j���[�V����
		int YMaxPatern;				//���ő�A�j���[�V����
		int Waitframe;				//�A�j���[�V�������x
		int Createframe;			//�������ꂽ���̃t���[��

	public:
		//�R���X�g���N�^
		CAnimation(int MaxPatern, int YMaxPatern, int Waitframe);
	};

}
#endif
