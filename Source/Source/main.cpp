//
//	Main.cpp
//		Author:HIROMASA IKEDA		Date:2018/10/22
//================================================
#include"common.h"
#include<time.h>
#include<math.h>
#include"System.h"
#include"input.h"

#include"Lighting.h"
#include"XModel.h"

#include"Billboard.h"
#include"Fade.h"

//Class
#include"CUI.h"
#include"CGameObject.h"
#include"CCamera.h"

#include"CTransform.h"

#include"WinSock.h"
#include"Grid.h"
#include"Animation.h"

#include"MeshField.h"
#include"FbxModel.h"

//Scene
#include"Scene.h"
#include"GameScene.h"
#include"TitleScene.h"
#include"SecondScene.h"

//===============================================
//	�O���[�o���ϐ�
//===============================================

//�J����
static OperationCamera g_Camera(
	{0,5,5}
);

static NTexture::NameTexture texture(NTexture::Billboard_Burst);
static NTexture::CAnimation animation(18,6,4);

//=============================================================
//	����������
//=============================================================
void Main_Initialize(void)
{
	texture.Clip(0,0,128,128);
	Billboard_Initialize();
	NModel::Initialize();
	Fade_Initialize();

	//g_Camera.Set_Main();
	
	//Grid_Initialize();
	NMeshField::Initialize();
	//fbx::Initialize();
	//fbx::Finalize();

	//�ŏ��̃V�[���ǂݍ���
	NSCENE::LoadScene(Get_TitleScene());

	//������
	NSCENE::Initialize();
}

//=============================================================
//	�O �X�V����
//=============================================================
void Main_UpdateBegin(void)
{
	Fade_Update();

	if(Fade_IsFade())return;

	//�t�F�[�h�C��������//

	NTexture::FrameUpdate();

	ABillboard::g_Update();

	
	//	�J�����̌����ňړ�������
	//----------------------------------------------
	//g_Camera.Update();

	NSCENE::UpdateBegin();
}

//=============================================================
//	�`�揈��
//=============================================================
void Main_Render(void)
{
	ACamera::Begin();		//�`��J�n
	ABillboard::g_Render();

	//Grid_Render();
	NSCENE::Render();

	Fade_Render();
}


//=============================================================
//	�� ����
//=============================================================
void Main_UpdateEnd()
{
	NSCENE::Check();
	if (Fade_IsFade())return;
	//NSCENE::Check();
	NSCENE::UpdateEnd();
	

}

//=============================================================
//	�I������
//=============================================================
void Main_Finalize(void)
{
	NSCENE::Finalize();
	BillBoard_Finalaize();
	NMeshField::Finalize();
	NModel::Finalize();
}
