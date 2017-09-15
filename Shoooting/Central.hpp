#pragma once
//�W�����C�u�����̓w�b�_�ŃC���N���[�h���Ă��悢

//<memory>�̓X�}�[�g�|�C���^�n���g���Ƃ��̃w�b�_�����
#include<memory>

//�����̍�����v���O�����̓I���W�i���̖��O��Ԃŕ�����I
//���O�Փ˂����Ȃ��Ȃ邼�I

namespace game {

	//�O���錾
	class Scene;

	//�S�Ă̒��S�I�Ȋ����̃N���X
	//�����������邱�Ƃ͂Ȃ�����
	//�V���O���g���p�^�[���ɂ��Ă���
	//���܂�ǂ��Ȃ��Ƃ͌����Ă��邪
	//�ЂƂ������݂��Ȃ����Ƃ��ؖ��ł���̂͑f���炵�����Ƃ��Ǝv��
	class Central {

		//������̎��́iCentral.cpp�Ŏ��̂𐶐����Ă����j
		static Central instance;

		//�R���X�g���N�^��private�ɂ��ĊO�����琶���ł��Ȃ��悤�ɂ���
		//std::unique_ptr<Scene>�̂����Ŏ�����cpp�ɏ����Ȃ��Ă͂����Ȃ�
		//�����͏ȗ������Ă���iScene�̒�`�����̎��_�ł킩���Ă���΂��Ȃ��Ă��悢�j
		Central();
		~Central();

		//���݂̃V�[��������ϐ�
		//�X�}�[�g�|�C���^�ŕ��ł�̂�
		//�폜�͎����I�ɂ���Ă����
		std::unique_ptr<Scene> m_nowScene;

		//�Ȃ� m_ ��t���邩�H
		//member�ϐ��̂��Ƃ����Ӗ���
		bool m_endFlag = false;
	public:

		//���̂�n��
		static Central& GetInstance() {
			return instance;
		};

		void ChangeScene(std::unique_ptr<Scene>);

		//�V�[���X�V����
		//�Ԃ�l��while���[�v�𔲂��邩�ǂ����𐧌䂵�Ă�����
		bool Update();

		//�Q�[�����I��������
		//noexcept�͗�O��f���Ȃ��֐��ɕt���悤�I
		//�R���p�C�����œK�����₷���Ȃ邼���I
		void End()noexcept{ m_endFlag = true; }
	};
}