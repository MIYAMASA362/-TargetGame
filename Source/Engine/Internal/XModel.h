//
//	XModel.h
//		Author:HIROMASA IKEDA	DATE:2018/10/19
//===============================================
//	�ύX�� Changed By
//		Name:Minoda Takamasa	DATE:2018/10/23
//
//-----------------------------------------------
//�G���[�\��
//
//	�EModels//�@
//		XModel::Name��Path�̐��������Ă��Ȃ�
//
//===============================================
#pragma once
#ifndef XMODEL_H
#define XMODEL_H

//================================================
//	�C���N���[�h	include
//================================================
#include<d3dx9.h>
#include<string.h>

//================================================
//	�}�N����`	define
//================================================
#define MODELS_FILE ("Models/")
#define MODELS_FILE_NUM (60)
#define MODELS_NAME_NUM (30)

//===============================================
//	XModel ���O���
//===============================================
namespace NModel
{
	//==============================================
	//	�\����
	//==============================================

	//���f���̃f�[�^�^
	struct Data
	{
		LPD3DXMESH pMesh;
		D3DMATERIAL9* pMaterials;
		LPDIRECT3DTEXTURE9* pTextures;
		DWORD dwNumMaterials;
	};

	//==============================================
	//	��
	//==============================================

	//���f����
	const enum Name
	{
		AIRPLANE_BODY,
		AIRPLANE_PROPELLER,
		AIRPLANE_WingBD,
		AIRPLANE_WingBU,
		AIRPLANE_WingLD,
		AIRPLANE_WingLU,
		AIRPLANE_WingRD,
		AIRPLANE_WingRU,
		AIRPLANE_MODEL,
		TREE,
		BULLET,
		GUN,
		TARGET,
		NAME_END,
		MODEL_NONE
	};

	//==============================================
	//	�֐�
	//==============================================
	void XModel_Load(Data* LoadData, const char* File, const char* ModelFile);
	void Render(const LPD3DXMESH pMesh,const D3DMATERIAL9* pMaterials,const LPDIRECT3DTEXTURE9* pTextures, const DWORD dwNumMaterials);
	void Render(const Name index);
	void Initialize();
	void Finalize();
	Data* Get(const Name name);
}

#endif