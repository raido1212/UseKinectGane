#include "Includes.h"

// �F�̓I�����W�E��
// ���΁E�s���N
// ���Ԃ�����Η�����������



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(FALSE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	Init();
	// �T�E���h�֌W�����ׂă��[�h
	LoadMusicSE();

	SetMainWindowText("ObjectChach"); //�E�C���h�E�̃^�C�g����ݒ�
								  
									  // while( ����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A )
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && PadInput() == 0) {
		
		Updata();
	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}