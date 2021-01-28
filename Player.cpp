#include "Includes.h"

// ������
void cPlayer::Init()
{
	posx = 320;
	posy = 240;
}

// �X�V
void cPlayer::Updata()
{
	Move();
}

// �`�揈��
void cPlayer::Draw()
{
	DrawCircle((int)posx, (int)posy, PLAYER_SIZE,0xffffff, true);
}


void cPlayer::ChangeImage(char name[])
{
	if (image != 0) {
		
	}
}

void cPlayer::Move()
{
	short dir = 0;

	if (pad[XINPUT_BUTTON_DPAD_DOWN] != 0) dir += 1;
	if (pad[XINPUT_BUTTON_DPAD_LEFT] != 0) dir += 2;
	if (pad[XINPUT_BUTTON_DPAD_UP] != 0) dir += 4;
	if (pad[XINPUT_BUTTON_DPAD_RIGHT] != 0) dir += 8;

	switch (dir) {
		// ��
	case 1:
		posy += speed;
		break;
		// ��
	case 2:
		posx -= speed;
		break;
		// ����
	case 3:
		posx -= sin(45) * speed;
		posy += cos(45) * speed;
		break;
		// ��
	case 4:
		posy -= speed;
		break;
		// ����
	case 6:
		posx -= sin(45) * speed;
		posy -= cos(45) * speed;
		break;
		// �E
	case 8:
		posx += speed;
		break;
		// �E��
	case 9:
		posx += sin(45) * speed;
		posy += cos(45) * speed;
		break;
		// �E��
	case 12:
		posx += sin(45) * speed;
		posy -= cos(45) * speed;
		break;
	}
}
