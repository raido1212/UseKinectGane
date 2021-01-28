#include "Includes.h"

// パッド
short pad[16];
// アナログスティック
short ThumbLX;
short ThumbLY;
short ThumbRX;
short ThumbRY;

int PadInput() {

	XINPUT_STATE xinput;
	GetJoypadXInputState(DX_INPUT_PAD1, &xinput);

	// ボタン処理
	for (int i = 0; i < 16; i++) {
		if (xinput.Buttons[i] != 0 && pad[i] < 10000) {
			pad[i]++;
		}
		else if (xinput.Buttons[i] == 0) {
			pad[i] = 0;
		}
	}

	// アナログスティック処理
	ThumbLX = xinput.ThumbLX;
	ThumbLY = xinput.ThumbLY;
	ThumbRX = xinput.ThumbRX;
	ThumbRY = xinput.ThumbRY;

	return 0;
}