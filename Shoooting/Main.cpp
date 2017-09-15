#include "UseDxLib.hpp"
#include "Central.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	//�E�C���h�E�Ƃ��̏�����
	DxLib::SetMainWindowText("�����V���[�e�B���O c++��");
	DxLib::SetGraphMode(500, 480, 16);
	DxLib::ChangeWindowMode(true), DxLib::DxLib_Init(), DxLib::SetDrawScreen(DX_SCREEN_BACK);

	//�g�p����t�H���g�̐ݒ�
	DxLib::ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	//���C�����[�v
	//Central()�Ŏ��ۂ̃Q�[���̏������s���Ă��
	while (
		DxLib::ScreenFlip() == 0 &&
		DxLib::ProcessMessage() == 0 &&
		DxLib::ClearDrawScreen() == 0 && 
		game::Central::GetInstance().Update());

	DxLib::DxLib_End(); // DX���C�u�����I������
	return 0;
}