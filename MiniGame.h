#pragma once

class cMiniGameBace {
protected:
	bool clearjudge;
	int playtime;
public:
	cMiniGameBace() {
		clearjudge = false;
	}
	void Clear() { clearjudge = true; }
	void Count(int &playtime);
	void DrawCount(int &playtime);
};

class cSampleGame : public cMiniGameBace {
	cEnemy *cenemy;
public:
	cSampleGame() {
		cenemy = new cEnemy[10];
	}
	~cSampleGame()
	{
		delete[]cenemy;
	}
	void Updata();
};