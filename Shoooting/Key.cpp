#include "Key.hpp"
#include "UseDxLib.hpp"

namespace game{

	//���̐���
	Key Key::instance;

	void Key::UpdateKey()
	{
		char GetHitkey[256];
		DxLib::GetHitKeyStateAll(GetHitkey);

		//�Ώۂ̃L�[��������Ă�����1���Z
		//������Ă��Ȃ�������0�ɂ���
		//�Ⴆ��keys[0]�ɂ�����L�[��
		//60�t���[�������������
		//keys[0]��60�ɂȂ�
		for (size_t i = 0;i<KEY_MAX;i++) {
			if (GetHitkey[i] == 1)
				keys[i]++;
			else              
				keys[i] = 0;
		}
	}
}


