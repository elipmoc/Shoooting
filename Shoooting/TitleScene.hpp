#pragma once

//�{���A�w�b�_�ɃC���N���[�h����̂͂��߂���
//�p������ꍇ�͖h���Ȃ�
//���ꂪ�p���̂��߂ȂƂ���
#include"Scene.hpp"

namespace game {
	//�^�C�g����ʂ̃V�[��
	class TitleScene:public Scene{
	public:
		//Update���I�[�o�[���C�h����
		//override�͕t���Ȃ��Ă�������
		//�t�����ق�����������
		//���R��https://www.google.co.jp���Q��
		virtual void Update()final override;
	};
}