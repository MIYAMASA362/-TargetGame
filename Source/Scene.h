//
//	Scene.h
//		Author:	DATE:
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

#pragma once
#ifndef SCENE_H
#define SCENE_H

//================================================
//	�C���N���[�h	include
//================================================
#include"common.h"

#include<d3dx9.h>
#include<vector>
#include"Behavior.h"
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
namespace NSCENE
{
	//-------------------------------------
	//	AScene
	//-------------------------------------
	class AScene
	{
	private:
		char* pName;						//Scene�𔻕ʂ����

	public:
		AScene(char* Name);
		~AScene();
	public:
		virtual void Initialize() PURE;		//������
		virtual void UpdateBegin() PURE;	//�O�X�V
		virtual void Render() PURE;			//�`��
		virtual void UpdateEnd() PURE;		//��X�V
		virtual void Finalize() PURE;		//�I��
	public:
		char* Get_Name()
		{
			return pName;
		}
	};
	 
	void Initialize();
	void UpdateBegin();
	void Render();
	void UpdateEnd();
	void Finalize();

	void Check();
	void LoadScene(AScene* SceneName);

}

#endif