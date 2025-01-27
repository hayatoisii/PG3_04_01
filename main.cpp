#include <Novice.h>
#include "GameManeger.h"

const char kWindowTitle[] = "LC1D_03_イシイハヤト_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//GameManegerクラスのインスタンスを作成する
	GameManager* gameManeger = new GameManager();

	//GameManegerクラスからメンバ関数Runを呼び出す
	gameManeger->Run();

	// ライブラリの終了
	Novice::Finalize();

	//GameManegerを解放
	delete gameManeger;

	return 0;
}
