#include "Includes.h"

// 初期化
void cPlayer::Init()
{
	posx = 320;
	posy = 240;
}

// 更新
void cPlayer::Updata()
{
	Move();
}

// 描画処理
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
		// 下
	case 1:
		posy += speed;
		break;
		// 左
	case 2:
		posx -= speed;
		break;
		// 左下
	case 3:
		posx -= sin(45) * speed;
		posy += cos(45) * speed;
		break;
		// 上
	case 4:
		posy -= speed;
		break;
		// 左上
	case 6:
		posx -= sin(45) * speed;
		posy -= cos(45) * speed;
		break;
		// 右
	case 8:
		posx += speed;
		break;
		// 右下
	case 9:
		posx += sin(45) * speed;
		posy += cos(45) * speed;
		break;
		// 右上
	case 12:
		posx += sin(45) * speed;
		posy -= cos(45) * speed;
		break;
	}
}
