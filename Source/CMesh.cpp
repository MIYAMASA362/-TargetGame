//
//	CMesh.cpp
//		Author:HIROMASA IKEDA	DATE:2018/11/14
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

//===============================================
//	�C���N���[�h	include
//===============================================
#define _CRT_SECURE_NO_WARNINGS
#include"common.h"
#include"System.h"
#include"Lighting.h"

//class	
#include"Cube.h"
#include"CMesh.h"

//===============================================
//	�}�N����`		define
//===============================================

//===============================================
//	�O���[�o���ϐ�	global
//===============================================

//===============================================
//	CMesh ����
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
AMesh::AMesh()
{
	
}

//===============================================
//	CStandardMesh
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
CStandardMesh::CStandardMesh():AMesh()
{
	this->pTexture = new NTexture::Texture();
	this->Material.Diffuse = this->Material.Ambient = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	this->FVF = FVF_CUBE_VERTEX3D;
	this->PrimitiveType = CUBE_PRIMITIVE_TYPE;
	this->Model = GetModel_Cube();
	this->DataSize = sizeof(CubeVertex3D);
	this->PrimitiveCount = CUBE_PRIMITIVE_NUM;
}

//-------------------------------------
//	�`��
//-------------------------------------
void CStandardMesh::begin()
{
	LPDIRECT3DDEVICE9 Device = System_GetDevice();
	Device->SetMaterial(&this->Material);

	Device->SetFVF(this->FVF);
	Device->SetTexture(0, pTexture->lpTexture());

	Device->DrawPrimitiveUP(this->PrimitiveType, this->PrimitiveCount, this->Model, this->DataSize);

	return;
}

//-------------------------------------
//	�e�N�X�`���ݒ�
//-------------------------------------
void CStandardMesh::Set_Texture(NTexture::Texture Texture)
{
	this->pTexture = &Texture;
}

void CStandardMesh::Set_Texture(NTexture::Texture* pTexture)
{
	this->pTexture = pTexture;
}

//===============================================
//	CXModelMesh X���f���f�[�^
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
CXModelMesh::CXModelMesh()
{
	this->pMesh = NULL;
	this->pMeshMaterials = NULL;
	this->pMeshTextures = NULL;
	this->dwNumMaterials = NULL;
}

CXModelMesh::CXModelMesh(char* ModelFile, char* path)
{
	NModel::Load_XModelMesh(this,ModelFile,path);
}

//-------------------------------------
//	�`��
//-------------------------------------
void CXModelMesh::begin()
{
	NLighting::Set_Light(TRUE);

	//�}�e���A���̐��������[�v������
	for (DWORD i = 0; i < this->dwNumMaterials; i++)
	{
		//�}�e���A���ݒ�
		System_GetDevice()->SetMaterial(&this->pMeshMaterials[i]);
		//�e�N�X�`���ݒ�
		System_GetDevice()->SetTexture(0, this->pMeshTextures[i]);
		//�����_�����O
		this->pMesh->DrawSubset(i);
	}

	NLighting::Set_Light(FALSE);
}

//===============================================
//	���f����
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
CXModelName::CXModelName(NModel::Name name)
{
	this->Model = name;
}

//-------------------------------------
//	�`��
//-------------------------------------
void CXModelName::begin()
{
	NModel::Data* pMesh = NModel::Get(Model);

	NLighting::Set_Light(TRUE);

	for(DWORD i = 0; i < pMesh->dwNumMaterials; i++)
	{
		System_GetDevice()->SetMaterial(&pMesh->pMaterials[i]);
		System_GetDevice()->SetTexture(0,pMesh->pTextures[i]);
		pMesh->pMesh->DrawSubset(i);
	}

	NLighting::Set_Light(FALSE);
}

namespace NModel
{
	void Load_XModelMesh(CXModelMesh* LoadMesh, char* ModelFile, char* path)
	{
		Data LoadData;
		XModel_Load(&LoadData, path, ModelFile);

		LoadMesh->pMesh = LoadData.pMesh;
		LoadMesh->pMeshMaterials = LoadData.pMaterials;
		LoadMesh->pMeshTextures = LoadData.pTextures;
		LoadMesh->dwNumMaterials = LoadData.dwNumMaterials;
	}
}
