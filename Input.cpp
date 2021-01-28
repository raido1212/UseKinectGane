#include "Includes.h"

// �p�b�h
short pad[16];
// �A�i���O�X�e�B�b�N
short ThumbLX;
short ThumbLY;
short ThumbRX;
short ThumbRY;

int PadInput() {

	XINPUT_STATE xinput;
	GetJoypadXInputState(DX_INPUT_PAD1, &xinput);

	// �{�^������
	for (int i = 0; i < 16; i++) {
		if (xinput.Buttons[i] != 0 && pad[i] < 10000) {
			pad[i]++;
		}
		else if (xinput.Buttons[i] == 0) {
			pad[i] = 0;
		}
	}

	// �A�i���O�X�e�B�b�N����
	ThumbLX = xinput.ThumbLX;
	ThumbLY = xinput.ThumbLY;
	ThumbRX = xinput.ThumbRX;
	ThumbRY = xinput.ThumbRY;

	return 0;
}