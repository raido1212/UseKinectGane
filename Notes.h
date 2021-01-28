#pragma once

// ���肷��ꏊ�̐�
#define LANE_SIZE 4
// �m�[�c�̍ő吔
#define MAX_NOTES 40
// BPM
#define BPM 120
// �m�[�c�̏c��
#define NOTES_H 10
class cNotes {

	// 0,1,2,3 ����A�E��A�E���A����
	short notes_posCenter[MAX_NOTES];
	float notes_ULposX[MAX_NOTES];
	float notes_ULposY[MAX_NOTES];
	float notes_BMposX[MAX_NOTES];
	float notes_BMposY[MAX_NOTES];
	int   notes_time[MAX_NOTES];
	bool  notes_flag[MAX_NOTES];

	short play_level;

	// ���Ԋ֌W
	LONGLONG start_time;
	LONGLONG now_time;
	int		 current_time;		// �o�ߎ���
	int		 counter;			

	const int offset = 4000;

	// �m�[�c�ݒ�
	const float notes_speed = 0.5f;

	// ���ݒ�
	int beat;

public:

	cNotes(){
		play_level = 0;
	}
	void SetNotes();
	bool bFallandPlayNotes(int life);

};
