#pragma once
namespace game {

	//�V�[���N���X����
	//�������p�����āA
	//GameScene�Ƃ�
	//TitleScene�Ƃ�������B
	class Scene {
	public:
		//���t���[���Ă΂��A�X�V�֐�
		virtual void Update() = 0;

		//�p�����Ďg���ꍇ
		//�f�X�g���N�^��virtual��t���悤
		//�������A�K�������t����̂������ł͂Ȃ��̂�
		//�ڂ����͒��ׂĂ�������
		virtual ~Scene() = default;//����default�̐����́E�E�E�ׂ̂Ƃ��ł���B
	};
}