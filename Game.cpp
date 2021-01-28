#include "Includes.h"

using namespace Game;

Mode mode;
const	int iTurnMax = 5;
CGame *game;

bool finish = false;


void Init() 
{
	finish = false;

	mode = ModeGame;
	game = new CGame(iTurnMax);
	
	// ���ԃ��Z�b�g
	ResetTimer();

	// �����L���O���Z�b�g
	ResetRanking();
}

void Updata() 
{
	switch (mode)
	{
	case ModeInit:
		Init();
		break;
	case ModeTitle:
		mode = ModeGame;
		break;

	case ModeSelect:
		break;
	case ModeGame:

		//nBackGround::Draw();

		game->Update();

		// if (CheckSoundMem(MusicLoop) == false)
		//	PlaySoundMem(MusicLoop, DX_PLAYTYPE_BACK, TRUE);

		//cobjects[hit_counter].Update(myKinect);
		//cobjects[hit_counter].Draw();
		//if (cobjects[hit_counter].Objects_Flag() == false) {
		//	PlaySoundMem(GoodSE, DX_PLAYTYPE_BACK);
		//	hit_counter++;
		//}

		// �I�u�W�F�N�g���ׂĎ擾������
		//if (hit_counter == MAX_OBJ) {
		//	// �����L���O�X�V
		//	SaveRanking(timer);
		//	mode = ModeTitle;
		//}

		
		StartTimer();

		if (finish == true) {

			SaveRanking(timer);
			mode = ModeFinish;
		}
		break;
	case ModeResult:
		break;
	case ModeFinish:
		DrawRanking();

		
		if (CheckHitKey(KEY_INPUT_SPACE) == 1){
			Init();
			mode = ModeGame;
		}

		break;
	default:
		break;
	}
}