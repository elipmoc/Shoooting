#include "UseDxLib.hpp"
#include "Central.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	//ウインドウとかの初期化
	DxLib::SetMainWindowText("文字シューティング c++版");
	DxLib::SetGraphMode(500, 480, 16);
	DxLib::ChangeWindowMode(true), DxLib::DxLib_Init(), DxLib::SetDrawScreen(DX_SCREEN_BACK);

	//使用するフォントの設定
	DxLib::ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	//メインループ
	//Central()で実際のゲームの処理を行ってるよ
	while (
		DxLib::ScreenFlip() == 0 &&
		DxLib::ProcessMessage() == 0 &&
		DxLib::ClearDrawScreen() == 0 && 
		game::Central::GetInstance().Update());

	DxLib::DxLib_End(); // DXライブラリ終了処理
	return 0;
}