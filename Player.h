#pragma once

#define PLAYER_SIZE 30

class cPlayer {
	int image;
	double posx, posy;
	double speed;
public:
	cPlayer() {
		posx = 0;
		posy = 0;
		speed = 10;
	}
	
	void Init();
	void Updata();
	void Draw();
	void ChangeImage(char name[]);
	void Move();
};