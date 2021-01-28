#include "Includes.h"
/*
void cObjects::Init(float setposx,float setposy,int color)
{
	// 色決め
	
	hit_counter = 0;
	obj_flag = true;
	srand((unsigned int)time(NULL));
	color_type = color;
	if (color_type == 0) Cr = GetColor(255, 0, 0);
	else if (color_type == 1) Cr = GetColor(0, 0, 255);
	else if (color_type == 2) Cr = GetColor(255, 255, 0);
	else if (color_type == 3) Cr = GetColor(0, 255, 255);
	else if (color_type == 4) Cr = GetColor(0, 255, 0);
	pos_center = rand() % 400 + 120;

	posx = setposx;
	posy = setposy;
	
}

// オブジェクトの挙動は火花が散っている電気ケーブルのような挙動
// ゲームプログラミング・物理学の本を参照する

void cObjects::Update(cKinectTracking myKienct)
{

	if (color_type == 0)
		if (myKienct.GetPartX(0) > posx - OBJ_W &&
			myKienct.GetPartX(0) < posx + OBJ_W &&
			myKienct.GetPartY(0) > posy - OBJ_H &&
			myKienct.GetPartY(0) < posy + OBJ_H) {

			obj_flag = false;
		}

	if (color_type == 1)
		if (myKienct.GetPartX(1) > posx - OBJ_W &&
			myKienct.GetPartX(1) < posx + OBJ_W &&
			myKienct.GetPartY(1) > posy - OBJ_H &&
			myKienct.GetPartY(1) < posy + OBJ_H) {

			obj_flag = false;
		}

	if (color_type == 2)
		if (myKienct.GetPartX(2) > posx - OBJ_W &&
			myKienct.GetPartX(2) < posx + OBJ_W &&
			myKienct.GetPartY(2) > posy - OBJ_H &&
			myKienct.GetPartY(2) < posy + OBJ_H) {

			obj_flag = false;
		}

	if (color_type == 3)
		if (myKienct.GetPartX(3) > posx - OBJ_W &&
			myKienct.GetPartX(3) < posx + OBJ_W &&
			myKienct.GetPartY(3) > posy - OBJ_H &&
			myKienct.GetPartY(3) < posy + OBJ_H) {

			obj_flag = false;
		}
	if (color_type == 4)
		if (myKienct.GetPartX(4) > posx - OBJ_W &&
			myKienct.GetPartX(4) < posx + OBJ_W &&
			myKienct.GetPartY(4) > posy - OBJ_H &&
			myKienct.GetPartY(4) < posy + OBJ_H) {

			obj_flag = false;
		}

	// 3頭 7左手 11右手 15左足 19右足

		
	
}

void cObjects::Draw()
{
	if (obj_flag) {
		DrawCircle(posx, posy, 30, Cr, true);
	}
}
*/