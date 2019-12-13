//
//	Animetion.cpp
//		Author:HIROMASA IKEDA	DATE:2018/09/28
//===============================================
#include<d3dx9.h>
#include<math.h>

#include"Texture.h"
#include"CTransform.h"
#include"Animation.h"

//==============================================
//	�O���[�o���ϐ��錾
//==============================================
static int g_FrameCounter;	//�E�t���[���J�E���^

namespace NTexture
{
	//------------------------------------
	//	Initialize()
	//------------------------------------
	void FrameInit()
	{
		g_FrameCounter = 0;
	}

	//------------------------------------
	//	FrameUpdate()
	//------------------------------------
	void FrameUpdate()
	{
		g_FrameCounter++;
	}

	//------------------------------------
	//	Get_Frame()
	//------------------------------------
	int Get_Frame()
	{
		return g_FrameCounter;
	}

	//------------------------------------
	//	�A�j���[�V����
	//------------------------------------
	int Animation(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, D3DCOLOR Color, LPDIRECT3DTEXTURE9 pTexture, D3DXVECTOR2 origin, D3DXVECTOR2 uv, int MaxPatern, int YMaxPatern, int Waitframe, int Createframe, bool loop)
	{
		int Patern;
		if (loop)
		{
			Patern = (g_FrameCounter - Createframe / Waitframe % MaxPatern);
		}
		else
		{
			Patern = min((g_FrameCounter - Createframe / Waitframe),MaxPatern);
		}
		origin += {uv.x * (Patern % YMaxPatern),uv.y * (Patern / YMaxPatern)};
		NRender2D::Sprite(Position,Scale,Color,pTexture,origin,uv);
		return Patern;
	}

	//------------------------------------
	//	��]�A�j���[�V����
	//------------------------------------
	int Animation(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, D3DCOLOR Color, LPDIRECT3DTEXTURE9 pTexture, D3DXVECTOR2 origin, D3DXVECTOR2 uv, int MaxPatern, int YMaxPatern, int Waitframe, int Createframe,float Rotate ,bool loop)
	{
		int Patern;
		if (loop)
		{
			Patern = (g_FrameCounter - Createframe / Waitframe % MaxPatern);
		}
		else
		{
			Patern = min((g_FrameCounter - Createframe / Waitframe), MaxPatern);
		}
		origin += {uv.x * (Patern % YMaxPatern), uv.y * (Patern / YMaxPatern)};
		NRender2D::Sprite(Position, Scale, Color, pTexture, origin, uv,Rotate);
		return Patern;
	}

}

/*
//===============================================
//	�A�j���[�V���� NOLOOP
//===============================================
bool Animation_NoLoop(Transform2* pTransform,NTexture::CTexture* pTexture,NTexture::CAnimation* pAnimetion)
{
	float width  = (float)pTexture->Get_Width();
	float height = (float)pTexture->Get_Height();

	pAnimetion->AnimaPatern  = min((g_FrameCounter / pAnimetion->Waitframe),pAnimetion->MaxPatern);

	NTexture::CTexture Tex = *pTexture;
	Tex.Coord = { pTexture->Scale.x * (pAnimetion->AnimaPatern % pAnimetion->YMaxPatern),pTexture->Scale.y * (pAnimetion->AnimaPatern / pAnimetion->YMaxPatern) };
	Render2D_Texture_Clip(pTransform,&Tex);

	return pAnimetion->AnimaPatern >= pAnimetion->MaxPatern;
}

//===============================================
//	�A�j���[�V���� LOOP
//===============================================
void Animation_Loop(Transform2* pTransform,NTexture::CTexture* pTexture,NTexture::CAnimation* pAnimetion)
{
	float width  = (float)pTexture->Get_Width();
	float height = (float)pTexture->Get_Height();

	pAnimetion->AnimaPatern = (g_FrameCounter / pAnimetion->Waitframe) % pAnimetion->MaxPatern;

	NTexture::CTexture Tex = *pTexture;
	Tex.Coord = { pTexture->Scale.x * (pAnimetion->AnimaPatern % pAnimetion->YMaxPatern),pTexture->Scale.y * (pAnimetion->AnimaPatern / pAnimetion->YMaxPatern) };
	Render2D_Texture_Clip(pTransform,&Tex);
}

//===============================================
//	��]�A�j���[�V����
//===============================================
void Animation_Loop_Rotate(Transform2* pTransform,NTexture::CTexture* pTexture,NTexture::CAnimation* pAnimetion)
{
	float width  = (float)pTexture->Get_Width();
	float height = (float)pTexture->Get_Height();

	pAnimetion->AnimaPatern = (g_FrameCounter / pAnimetion->Waitframe) % pAnimetion->MaxPatern;

	NTexture::CTexture Tex = *pTexture;
	Tex.Coord = { pTexture->Scale.x * (pAnimetion->AnimaPatern % pAnimetion->YMaxPatern),pTexture->Scale.y * (pAnimetion->AnimaPatern / pAnimetion->YMaxPatern) };
	Render2D_Sprite_Rotate(pTransform,&Tex);
}


//===============================================
//	�X�R�A�A�j���[�V����
//===============================================
*/

void Animation_Score(Transform2* pTransform,NTexture::NameTexture* pTexture,NTexture::CAnimation* pAnimetion, int Score, bool bLeft, bool bZero, int digitNum)
{
	int digit = 0, MaxScore = 1;
	D3DXVECTOR2 AnimaTex = {};

	//���擾
	for (digit = 0; digit < digitNum; digit++)
	{
		MaxScore *= 10;
	}

	//�J�E���g�I�[�o�[
	if (Score >= MaxScore)
	{
		Score = MaxScore - 1;
	}

	//���l��
	if (bLeft)
	{
		//�����擾
		digit = 0;
		for (int score = Score; score > 0; digit++)
		{
			score /= 10;
		}

		//���l��
		D3DXVECTOR2 position = { pTransform->Position()->x + (pTransform->Scale()->x * 0.5f) * digit,pTransform->Position()->y };
		while (digit > 0)
		{
			Transform2 transform2 = *pTransform;
			NTexture::NameTexture AnimaTex = *pTexture;
			int AnimePatern = Score % 10;
			AnimaTex.Coord = { pTexture->Scale.x * (AnimePatern % pAnimetion->YMaxPatern), pTexture->Scale.y *(AnimePatern / pAnimetion->YMaxPatern) };
			transform2.Set_Position({ position.x + (pTransform->Get_Scale().x) * digit,position.y });
			NRender2D::Sprite(&transform2,&AnimaTex,D3DCOLOR_RGBA(255,255,255,255));
			Score /= 10;
			digit--;
		}
	}
	//�E�l��
	else
	{
		//�ʒu����
		D3DXVECTOR2 position( (pTransform->Scale()->x * 0.7f) * digit,pTransform->Position()->y );

		//0����
		if (!bZero)
		{
			digit = 0;
			int score = Score;
			do
			{
				score /= 10;
				digit++;
			} while (score > 0);
		}
		//�E�l��
		while (digit > 0)
		{
			Transform2 transform2 = *pTransform;
			NTexture::NameTexture AnimaTex = *pTexture;
			
			int AnimaPatern = Score % 10;
			AnimaTex.Coord = { pTexture->Scale.x * (AnimaPatern % pAnimetion->YMaxPatern),pTexture->Scale.y *(AnimaPatern / pAnimetion->YMaxPatern) };
			transform2.Set_Position({ position.x - (pTransform->Get_Scale().x * 0.75f),position.y });
			NRender2D::Sprite(&transform2, &AnimaTex, D3DCOLOR_RGBA(255, 255, 255, 255));
			Score /= 10;
			digit--;
		}
	}
}


