//
//	TitleScene.h
//		Author:	DATE:
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

#pragma once
#ifndef TITLESCENE_H
#define TITLESCENE_H

//================================================
//	�C���N���[�h	include
//================================================
#include"common.h"

//Class
#include"Scene.h"


//================================================
//	�N���X		class
//================================================
class TitleScene : public NSCENE::AScene
{
public:
	TitleScene() :AScene("title") {};
public:
	void Initialize();
	void UpdateBegin();
	void Render();
	void UpdateEnd();
	void Finalize();
};

NSCENE::AScene* Get_TitleScene();

#endif