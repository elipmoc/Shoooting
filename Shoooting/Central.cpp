#include "Central.hpp"
#include "Scene.hpp"
#include "Key.hpp"
#include "CollisionControl.hpp"

namespace game {
	//���̂𐶐�
	Central Central::instance;

	Central::Central()
	{
	}

	Central::~Central()
	{
	}

	//�V�[���ύX����
	void Central::ChangeScene(std::unique_ptr<Scene> newScene)
	{
		//���[�u�L���X�g���s��newScene�̏��L����m_nowScene�ɓn���ꂽ���Ƃ𖾎�����
		//���������l���������[�u�Z�}���e�B�N�X�ƌ����B�͂��B
		m_nextScene = std::move(newScene);
	}

	//�X�V����
	bool Central::Update()
	{
		//�L�[���X�V
		Key::GetInstance().UpdateKey();

		//�Փ˔���v�Z
		CollisionControl::GetInstance().Update();

		//�V�[���ύX
		if (m_nextScene != nullptr)
			m_nowScene = std::move(m_nextScene);

		//�V�[���X�V
		if(m_nowScene!=nullptr)
			m_nowScene->Update();

		return m_endFlag==false;
	}


}