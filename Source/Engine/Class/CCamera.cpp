//
//	CCamera.cpp
//		Author:HIROMASA IKEDA	DATE:2018/10/17
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

//===============================================
//	�C���N���[�h	include
//===============================================
#include<d3dx9.h>
#include"common.h"
#include"input.h"
#include"System.h"

//classs
#include"CCamera.h"

//===============================================
//	�}�N����`		define
//===============================================

//===============================================
//	�O���[�o���ϐ�	global
//===============================================
ACamera*  ACamera::pMainCamera = NULL;

//===============================================
//	ACamera
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
ACamera::ACamera(D3DXVECTOR3 Position, D3DXVECTOR3 At, float AtDistance, float fov)
{
	this->m_Rotation = D3DXVECTOR3(0.0f,0.0f,0.0f);
	this->position = Position;
	this->at = At;
	this->atDistance = AtDistance;
	this->fov = fov;
}

//-------------------------------------
//	���C���J�����̎擾
//-------------------------------------
ACamera* ACamera::Get_Main()
{
	return pMainCamera;
}

//-------------------------------------
//	�`��
//-------------------------------------
bool ACamera::Begin()
{
	if (pMainCamera == NULL)
	{
		MessageBox(*System_GethWnd(), "���C���J�������ݒ肳��Ă��܂���B", "CCamera.cpp", MB_OK);
		DestroyWindow(*System_GethWnd());
		return false;
	}

	//------------------------------------
	//	�r���[�ϊ��s��
	//------------------------------------
	D3DXMATRIX mtxView;							//�r���[�ϊ��s��
	D3DXMatrixLookAtLH(&mtxView, &pMainCamera->position, &pMainCamera->at, &pMainCamera->Get_Up());	//�ϊ�
	System_GetDevice()->SetTransform(D3DTS_VIEW, &mtxView);		//�f�o�C�X�֓o�^
	pMainCamera->MtxView = mtxView;

	//------------------------------------
	//	�v���W�F�N�V�����ϊ��s��
	//------------------------------------
	D3DXMATRIX mtxProjection;		//�v���W�F�N�V�����ϊ��s��
	D3DXMatrixPerspectiveFovLH(&mtxProjection, D3DXToRadian(60), (float)WINDOWSCREEN_WIDTH / WINDOWSCREEN_HEIGHT, 0.1f, 100.0f);	//Fov�͉�p�@�ϊ�
	System_GetDevice()->SetTransform(D3DTS_PROJECTION, &mtxProjection);	//�f�o�C�X�֓o�^
	pMainCamera->MtxProjection = mtxProjection;

	return true;
}

D3DXVECTOR3 ACamera::Get_ScreenToWorld(float z)
{
	D3DXVECTOR3 pOut(0.0f,0.0f,0.0f);

	D3DXMATRIX InvView, InvPrj, VP, InvViewport;
	D3DXMatrixInverse( &InvView,NULL, &this->MtxView);
	D3DXMatrixInverse( &InvPrj, NULL, &this->MtxProjection);
	D3DXMatrixIdentity( &VP );

	VP._11 = WINDOWSCREEN_WIDTH_2;
	VP._22 = WINDOWSCREEN_HEIGHT_2;
	VP._41 = WINDOWSCREEN_WIDTH_2;
	VP._42 = WINDOWSCREEN_HEIGHT_2;

	D3DXMatrixInverse(&InvViewport, NULL, &VP);

	D3DXMATRIX tmp = InvViewport * InvPrj * InvView;
	D3DXVec3TransformCoord( &pOut,&D3DXVECTOR3(Mouse_IsMouseX(),Mouse_IsMouseY(),z),&tmp);

	return pOut;
}

//-------------------------------------
//	View�s��擾
//-------------------------------------
D3DXMATRIX ACamera::Get_ViewMatrix()
{
	return pMainCamera->MtxView;
}

//-------------------------------------
//	���C���J�����ɐݒ�
//-------------------------------------
void ACamera::Set_Main()
{
	pMainCamera = this;
}

void ACamera::LookingAt(D3DXVECTOR3 AtPosition)
{
	this->at = AtPosition;
	this->position = AtPosition - (this->Get_Forward() * this->atDistance);
}

D3DXVECTOR3 ACamera::Get_Forward()
{
	D3DXMATRIX MtxRotation;
	D3DXMatrixRotationYawPitchRoll(&MtxRotation, this->m_Rotation.y, this->m_Rotation.x, this->m_Rotation.z);

	//right
	D3DXVECTOR3 forward(0.0f, 0.0f, 1.0f);
	D3DXVec3TransformNormal(&forward, &forward, &MtxRotation);
	D3DXVec3Normalize(&forward, &forward);

	return forward;
}

D3DXVECTOR3 ACamera::Get_Up()
{
	D3DXMATRIX MtxRotation;
	D3DXMatrixRotationYawPitchRoll(&MtxRotation, this->m_Rotation.y, this->m_Rotation.x, this->m_Rotation.z);

	//up
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXVec3TransformNormal(&up, &up, &MtxRotation);
	D3DXVec3Normalize(&up, &up);

	return up;
}

D3DXVECTOR3 ACamera::Get_Right()
{
	D3DXMATRIX MtxRotation;
	D3DXMatrixRotationYawPitchRoll(&MtxRotation, this->m_Rotation.y, this->m_Rotation.x, this->m_Rotation.z);

	//right
	D3DXVECTOR3 right(1.0f, 0.0f, 0.0f);
	D3DXVec3TransformNormal(&right, &right, &MtxRotation);
	D3DXVec3Normalize(&right, &right);

	return right;
}

//===============================================
//	Camera
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
Camera::Camera(D3DXVECTOR3 Position, D3DXVECTOR3 At, float AtDistance, float fov)
:
	ACamera(Position,At,AtDistance,fov)
{
	
}

//-------------------------------------
//	�X�V
//-------------------------------------
void Camera::Update()
{

}

//===============================================
//	OperationCamera
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
OperationCamera::OperationCamera(D3DXVECTOR3 Position, D3DXVECTOR3 At,float AtDistance,float fov)
:
	ACamera(Position,At,AtDistance,fov)
{
	this->Speed = CAMERA_INITIALSPEED;
	this->SpeedMag = 1.0f;
}

//-------------------------------------
//	�X�V
//-------------------------------------
void OperationCamera::Update()
{
	//------------------------------------
	//	�J����
	//------------------------------------

	D3DXVECTOR3 front = this->Get_Forward();
	D3DXVECTOR3 right = this->Get_Right();
	right.y = 0.0f;

	if(Keyboard_IsPress(DIK_LCONTROL))
	{
		if(Mouse_IsRightDown())
		{
			this->m_Rotation.y += Mouse_IsAccelerationX() * 0.001f;
			this->m_Rotation.x += Mouse_IsAccelerationY() * 0.001f;

			/*
			D3DXMATRIX mtxRotation;
			D3DXVECTOR3 AxisVec = this->at;
			AxisVec.x = 0;
			AxisVec.z = 0;
			D3DXMatrixRotationAxis(&mtxRotation,&AxisVec,Mouse_IsAccelerationX() * 0.001f);
			D3DXVec3TransformNormal(&this->forward, &this->forward, &mtxRotation);	//�x�N�g�����W�ϊ�
			D3DXVec3TransformNormal(&this->right, &this->right, &mtxRotation);
			D3DXVec3Cross(&this->up, &this->right, &this->forward);

			D3DXMatrixIdentity(&mtxRotation);
			AxisVec = this->right;
			D3DXMatrixRotationAxis(&mtxRotation,&AxisVec,Mouse_IsAccelerationY() * 0.001f);
			D3DXVec3TransformNormal(&this->forward, &this->forward, &mtxRotation);	//�x�N�g�����W�ϊ�
			D3DXVec3TransformNormal(&this->right, &this->right, &mtxRotation);
			D3DXVec3Cross(&this->up, &this->right, &this->forward);
			D3DXMatrixTranslation(&mtxRotation,this->at.x,this->at.y,this->at.z);
			D3DXVec3TransformNormal(&at,&at,&mtxRotation);
			*/
		}

		this->position = at - this->Get_Forward() * this->atDistance;
	}
	else
	{
		if(Keyboard_IsPress(DIK_LSHIFT))
		{
			SpeedMag += 0.05f;
			SpeedMag = min(SpeedMag,20.0f);
		}
		else
		{
			SpeedMag = 1.0f;
		}

		if (Mouse_IsRightDown())
		{
			this->m_Rotation.y += Mouse_IsAccelerationX() * 0.001f;
			this->m_Rotation.x += Mouse_IsAccelerationY() * 0.001f;
			/*
			D3DXMATRIX mtxRotation;
			D3DXMatrixRotationY(&mtxRotation, Mouse_IsAccelerationX() * 0.001f);
			D3DXVec3TransformNormal(&this->forward, &this->forward, &mtxRotation);	//�x�N�g�����W�ϊ�
			D3DXVec3TransformNormal(&this->right, &this->right, &mtxRotation);
			D3DXVec3Cross(&this->up, &this->right, &this->forward);

			D3DXMatrixIdentity(&mtxRotation);
			D3DXMatrixRotationAxis(&mtxRotation, &this->right, Mouse_IsAccelerationY() * -0.001f);
			D3DXVec3TransformNormal(&this->forward, &this->forward, &mtxRotation);	//�x�N�g�����W�ϊ�
			D3DXVec3TransformNormal(&this->right, &this->right, &mtxRotation);
			D3DXVec3Cross(&this->up, &this->right, &this->forward);
			*/
			
		}

		if (Keyboard_IsPress(DIK_W))
		{
			this->position += front * this->Speed * SpeedMag;
		}

		if (Keyboard_IsPress(DIK_S))
		{
			this->position -= front * this->Speed * SpeedMag;
		}

		if (Keyboard_IsPress(DIK_A))
		{
			this->position += right * this->Speed * SpeedMag;
		}

		if (Keyboard_IsPress(DIK_D))
		{
			this->position -= right * this->Speed * SpeedMag;
		}

		if (Keyboard_IsPress(DIK_Q))
		{
			this->position.y -= this->Speed * SpeedMag;
		}

		if (Keyboard_IsPress(DIK_E))
		{
			this->position.y += this->Speed * SpeedMag;
		}

		this->atDistance += Mouse_IsAccelerationZ() *0.005f;

		if (this->atDistance > 1.0f)
		{
			this->position -= this->Get_Forward() * Mouse_IsAccelerationZ() * 0.005f;
		}
		else
		{
			this->atDistance = 1.0f;
		}
	}

	this->at = this->Get_Forward() * this->atDistance + this->position;

	return;
}

