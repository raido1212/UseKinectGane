#pragma once

const int WinX = 640;
const int WinY = 480;

const int ObjMax = 5;

extern bool finish;




namespace Game
{
	enum Mode {
		ModeInit,
		ModeTitle,
		ModeSelect,
		ModeGame,
		ModeResult,
		ModeFinish,
	};

	enum eBody {
		Error = -1,
		Head = 3,
		Hand_L = 7,
		Hand_R = 11,
		Foot_L = 15,
		Foot_R = 19,
	};

	typedef struct {
		float x;
		float y;

	}POS;

	class cKinectTracking
	{
	private:

		// キネクトハンドル
		HRESULT hrKinect;

		// ユーザーの骨格情報
		NUI_SKELETON_FRAME Skeleton;

		// わからん
		INuiSensor* Sensor;

		HANDLE hSkeletonEvent;

		HANDLE hEvents[1];

		POS fPos[20];

		// 3dモデル関係変数
		int ModelHandle;
		int FrameNum;

	public:


		void Connect();
		void GetData();
		void ResetColorPoint();
		void DebugPrint();
		void KinectShutdown();
		void DrawPos() {
			for (int i = 0; i < 20; i++) {
				// DrawFormatString(0, i * 20, 0xFFFFFF, "%f,%f", fPos[i].x, fPos[i].y);
			}
		}
		void Draw3DModel() {

			if (ModelHandle == NULL)
				ModelHandle = MV1LoadModel("Model/あいえるたん.pmx");

			if (FrameNum == NULL) {
				FrameNum = MV1GetFrameNum(ModelHandle);
				
				// MV1SetFrameUserLocalMatrix(ModelHandle, 0, MGetTranslate(VGet(0.f, 100.f, 0.f)));
			}

			DrawFormatString(320, 260, 0xffffff, "%s", MV1GetFrameName(ModelHandle, 1));

			MV1DrawModel(ModelHandle);

			MV1SetFrameUserLocalMatrix(ModelHandle, 1, MGetTranslate(VGet(fPos[0].x, fPos[0].y, 0.f)));

			DrawFormatString(320, 240, 0xffffff, "%d", FrameNum);
		}

		// 変数参照関数
		POS GetPos(eBody b) { return fPos[b]; }
	};

	class CColor {
	private:
		unsigned int iColor[20];
	public:
		CColor() {
			iColor[Head] = 0xFF0000;
			iColor[Hand_L] = 0x00FFFF;
			iColor[Hand_R] = 0xFF00FF;
			iColor[Foot_L] = 0x0000FF;
			iColor[Foot_R] = 0x00FF00;
		}
		unsigned int GetMarkColor(eBody b)
		{
			return iColor[(int)b];
		}
		eBody	GetBody(int num) {
			switch (num) {
			case 0:
				return Head;
				break;
			case 1:
				return Foot_L;
				break;
			case 2:
				return Foot_R;
				break;
			case 3:
				return Hand_L;
				break;
			case 4:
				return Hand_R;
				break;
			default:
				return Error;
				break;
			}
		}

	};

	class CMarker {
	private:
		POS		fPos;
		eBody	Body;
		unsigned int iColor[20];
		float	fSizeR;
		CColor *Col;

	public:
		CMarker(){
			fPos	= { (float)GetRand(WinX), (float)GetRand(WinY / 2) + 100 };
			fSizeR	= 30.f + (float)GetRand(20);
			Col		= new CColor();
			Body	= Col->GetBody(GetRand(4));

			iColor[Head] = 0xFF0000;
			iColor[Hand_L] = 0x00FFFF;
			iColor[Hand_R] = 0xFF00FF;
			iColor[Foot_L] = 0x0000FF;
			iColor[Foot_R] = 0x00FF00;
		}
		~CMarker() {
			delete Col;
			Col = nullptr;
		}
		void	DrawMarker() {
			DrawCircleAA(fPos.x, fPos.y, fSizeR, 20, iColor[Body], true);
			// DrawFormatString(fPos.x, fPos.y, 0x000000, "%d", (int)Body);
		}
		bool	Collision(eBody b, float x, float y) {
			if (fPos.x + fSizeR > x && fPos.x - fSizeR < x &&
				fPos.y + fSizeR > y && fPos.y - fSizeR < y) {
				if (b == Body) return true;
				
			}

			/*if (((fPos.x - x) * (fPos.x - x)) + ((fPos.y - y) * (fPos.y - y)) < (fSizeR + 20.f) * (fSizeR + 20.f))
			{
				if (b == Body)
				{
					return true;
				}
			}*/
			return false;
		}
		POS GetPos() { return fPos; }
	};

	class CGame {
	private:
		int iTurn;
		int iTurnMax;
		int iObjNum;
		int iScore;
		bool isClear;
		CMarker *Marker[ObjMax];
		cKinectTracking *k;
	public:
		// コロンは変数を引数内で初期化するということ
		CGame(int _iTurnMax)
		: iTurnMax(_iTurnMax)
		{
			iTurn = 0;
			k = new cKinectTracking();
			k->Connect();
			SetMarker(1 + GetRand(ObjMax - 1));
			isClear = false;

		}
		~CGame() {
			k->KinectShutdown();
			delete k;
			k = nullptr;
			DeleteMarker();
		}
		void	Update() {

			k->GetData();
			DrawMarker();
			int Touch = CollisionMarker();
			if (Touch != -1)
			{
				delete Marker[Touch];
				Marker[Touch] = nullptr;
			}
			if (LiveMarker() == 0) {
				// finish = true;
				iTurn++;
				if (iTurn >= iTurnMax) {
					// kuria
					//isClear = true;
					//mode = ModeFinish;
					finish = true;
				}
				else {
					DeleteMarker();
					SetMarker(GetRand(4));
				}
			}

			for (int i = 0; i < ObjMax; i++) {
				// if (Marker[i] != nullptr) DrawFormatString(0, i * 20, 0xFFFFFF, "%f,%f", Marker[i]->GetPos().x, Marker[i]->GetPos().y);
			}
			k->Draw3DModel();
		}
		void	DeleteMarker() {
			for (int i = 0; i < ObjMax; i++) {
				delete Marker[i];
				Marker[i] = nullptr;
			}
		}
		int LiveMarker() {
			int count = 0;
			for (int i = 0; i < ObjMax; i++) {
				if (Marker[i] != nullptr) {
					count++;
				}
			}
			return count;
		}
		void	SetMarker(int num) {
			for (int i = 0; i < num; i++) {
				if (Marker[i] == nullptr) {
					Marker[i] = new CMarker();
				}
			}
		}
		int	CollisionMarker() {
			CColor c;
			for (int i = 0; i < ObjMax; i++)
			{

				if (Marker[0] != nullptr) {
					bool a = Marker[0]->Collision(c.GetBody(i), k->GetPos(c.GetBody(i)).x, k->GetPos(c.GetBody(i)).y);
					if (a) {
						delete Marker[0];
						Marker[0] = nullptr;
						PlaySoundMem(GoodSE, DX_PLAYTYPE_BACK, TRUE);
					}
				}
				if (Marker[1] != nullptr) {
					bool a = Marker[1]->Collision(c.GetBody(i), k->GetPos(c.GetBody(i)).x, k->GetPos(c.GetBody(i)).y);
					if (a) {
						delete Marker[1];
						Marker[1] = nullptr;
						PlaySoundMem(GoodSE, DX_PLAYTYPE_BACK, TRUE);
					}
				}
				if (Marker[2] != nullptr) {
					bool a = Marker[2]->Collision(c.GetBody(i), k->GetPos(c.GetBody(i)).x, k->GetPos(c.GetBody(i)).y);
					if (a) {
						delete Marker[2];
						Marker[2] = nullptr;
						PlaySoundMem(GoodSE, DX_PLAYTYPE_BACK, TRUE);
					}
				}
				if (Marker[3] != nullptr) {
					bool a = Marker[3]->Collision(c.GetBody(i), k->GetPos(c.GetBody(i)).x, k->GetPos(c.GetBody(i)).y);
					if (a) {
						delete Marker[3];
						Marker[3] = nullptr;
						PlaySoundMem(GoodSE, DX_PLAYTYPE_BACK, TRUE);
					}
				}
				if (Marker[4] != nullptr) {
					bool a = Marker[4]->Collision(c.GetBody(i), k->GetPos(c.GetBody(i)).x, k->GetPos(c.GetBody(i)).y);
					if (a) {
						delete Marker[4];
						Marker[4] = nullptr;
						PlaySoundMem(GoodSE, DX_PLAYTYPE_BACK, TRUE);
					}
				}
			
	
			}
			return -1;
		}
		void	DrawMarker() {
			for (int i = 0; i < ObjMax; i++) {
				if (Marker[i] != nullptr) {
					Marker[i]->DrawMarker();
				}
			}
		}
	};

	
}

extern void Init();
extern void Updata();