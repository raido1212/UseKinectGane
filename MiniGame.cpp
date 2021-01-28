#include "Includes.h"

void cMiniGameBace::Count(int & playtime)
{
	
	// タイマー処理
	if (playtime != 0)playtime--;
	// クリア判定
	if (clearjudge && playtime == 0) Clear();
}

void cMiniGameBace::DrawCount(int & playtime)
{
	DrawFormatString(200, 0, 0xfffff0, "%02d:%02d:%02d", playtime / 60, playtime % 60,playtime / 100);
}

void cSampleGame::Updata()
{
	
}
