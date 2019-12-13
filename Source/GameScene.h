//
//	GameScene.h
//		Author:	DATE:
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H

//================================================
//	�C���N���[�h	include
//================================================
#include"common.h"

//Class
#include"Scene.h"

//================================================
//	�N���X		class
//================================================

class GameScene : public NSCENE::AScene
{
public:
	GameScene() :AScene("Game") {};
public:
	void Initialize();
	void UpdateBegin();
	void Render();
	void UpdateEnd();
	void Finalize();
};

NSCENE::AScene* Get_GameScene();
int Get_GameTime();
#endif