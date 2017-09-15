#include "Central.hpp"
#include "Scene.hpp"

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
		m_nowScene = std::move(newScene);
	}

	//�V�[���X�V����
	bool Central::Update()
	{
		if(m_nowScene!=nullptr)
			m_nowScene->Update();

		return m_endFlag==false;
	}


}