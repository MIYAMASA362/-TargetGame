//
//	CRender.cpp
//		Author:HIROMASA IKEDA	DATE:2018/10/19
//===============================================
#include<d3dx9.h>
#include<math.h>
#include<vector>

#include"CRender.h"
#include"System.h"
#include"Texture.h"
#include"Sprite.h"
#include"Animation.h"

#include"Cube.h"
#include"Lighting.h"

//===============================================
//	���O���
//===============================================
namespace NRender3D
{
	void Render(AMesh* pModel, CTransform* pTransform)
	{
		if (pModel == NULL || pTransform == NULL) return;

		//�s��ݒ�
		System_GetDevice()->SetTransform(D3DTS_WORLD, &pTransform->Get_MtxWorld());

		pModel->begin();		//���f���̕`��
	}

	void Render(AMesh* pModel,D3DXMATRIX* MtxWorld)
	{
		if (pModel == NULL || MtxWorld == NULL) return;

		//�s��ݒ�
		System_GetDevice()->SetTransform(D3DTS_WORLD, MtxWorld);

		pModel->begin();		//���f���̕`��
	}
}
