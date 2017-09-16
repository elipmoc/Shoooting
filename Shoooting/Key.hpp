#pragma once
#include <array>

namespace game {

	//�L�[�̉����Ă邩�ǂ��������擾����N���X
	//�������V���O���g���N���X�ɂ���
	class Key {
		
		static Key instance;

		Key()=default;

	public:

		static Key& GetInstance(){return instance;}

		//�L�[�̐���萔�Œ�`���Ă���
		//�萔��constexpr���ō�
		static constexpr size_t KEY_MAX = 256;

	private:

		//�L�[�̔z��
		std::array<int, KEY_MAX> keys;

	public:

		//�L�[�̏����X�V
		void UpdateKey();

		//�L�[�̏�Ԃ��擾
		int GetKey(size_t keyCode)const noexcept {
			if (KEY_MAX <= keyCode)return -1;
			return keys[keyCode];
		}

	};
}