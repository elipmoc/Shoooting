#include "Barrage.hpp"
#include "Bullet.hpp"
#include <algorithm>

namespace game {

	Barrage::Barrage(size_t size)
	{
		//�O�����ă��������m�ۂ��āA��������}��
		bullets.reserve(size);
	}

	Barrage::~Barrage()
	{
	}

	void Barrage::AddBullet(const Bullet& bullet)
	{
		//bullet�̃��X�g�ɐV����bullet��ǉ�����
		bullets.emplace_back(bullet);
	}

	void Barrage::Update()
	{
		//�폜����bullet�����X�g�̌��Ƀ\�[�g����
		//itr�ł��̍폜����bullet�B�̐擪�̃C�e���[�^�𓾂�
		auto itr = 
			std::remove_if(bullets.begin(), bullets.end(), [](Bullet& b) {return b.IsDelete(); });

		//itr���烊�X�g�̖����܂ō폜����
		//�������邱�Ƃō폜�Ώۂ�bullet���폜�ł���
		bullets.erase(itr, bullets.end());

		//���̂悤�Ɉ�xremove_if�ō폜�Ώۂ��\�[�g���Ă���
		//erase�Ŏ��ۂɍ폜����e�N�j�b�N��
		//erase-remove�C�f�B�I���Ƃ�����
		//�����悭�폜�ł����



		//range based for�Ń��X�g����
		for (auto& bullet : bullets) {
			bullet.Update();
		}



	}



}