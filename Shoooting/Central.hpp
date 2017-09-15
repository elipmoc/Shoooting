#pragma once

//�����̍�����v���O�����̓I���W�i���̖��O��Ԃŕ�����I
//���O�Փ˂����Ȃ��Ȃ邼�I

namespace game {
	//�S�Ă̒��S�I�Ȋ����̃N���X
	//�����������邱�Ƃ͂Ȃ�����
	//�V���O���g���p�^�[���ɂ��Ă���
	//���܂�ǂ��Ȃ��Ƃ͌����Ă��邪
	//�ЂƂ������݂��Ȃ����Ƃ��ؖ��ł���̂͑f���炵�����Ƃ��Ǝv��
	class Central {

		//������̎��́iCentral.cpp�Ŏ��̂𐶐����Ă����j
		static Central instance;

		//�R���X�g���N�^��private�ɂ��ĊO�����琶���ł��Ȃ��悤�ɂ���
		Central()=default;

		bool m_endFlag = false;
	public:

		//���̂�n��
		static Central& GetInstance() {
			return instance;
		};

		//�V�[���X�V����
		//�Ԃ�l��while���[�v�𔲂��邩�ǂ����𐧌䂵�Ă�����
		bool Update();

		//�Q�[�����I��������
		void End()noexcept{ m_endFlag = true; }
	};
}