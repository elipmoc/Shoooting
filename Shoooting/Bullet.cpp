#include "Bullet.hpp"
#include "CollisionCircle.hpp"
#include "define.hpp"
#include "UseDxLib.hpp"


namespace game {

	void Bullet::Update()
	{
		//�Փ˂����I�u�W�F�N�g�̏���
		m_collision->GetColliBuf(
			[this] (CollisionID id){
			//��l���̒e�Ȃ�A�G�ƏՓ˂��Ă���A�폜����
			if (m_collision->GetCollisionID() == CollisionID::PlayerBulletID) {
				if (id == CollisionID::TekiID)
					Delete();
			}
			//�G�̒e�Ȃ�A���@�ƏՓ˂��Ă���A�폜����
			if (m_collision->GetCollisionID() == CollisionID::TekiBulletID) {
				if (id == CollisionID::PlayerID)
					Delete();
			}
		}
		);

		//�G���A�͈͊O�`�F�b�N
		AreaCheck();

		//���W�X�V
		SetPos(GetPos() + GetAddPos());

		//�e�����\��
		DxLib::DrawString(GetPos().x, GetPos().y, "�e", DxLib::GetColor(255, 255, 255));

	}

	void Bullet::AreaCheck()
	{
		//�e���͈͊O�ɏo�������
		if (
			GetPos().x > WINDOW_W ||
			GetPos().x <-16 ||
			GetPos().y > WINDOW_H ||
			GetPos().y < -16
			)
			Delete();
	}

	Bullet & Bullet::operator=(Bullet &&) = default;

	Bullet::Bullet(Bullet &&) = default;

	Bullet::Bullet(CollisionID id)
		:m_collision(std::make_unique<CollisionCircle>(GetRefPos()))
	{
		m_collision->SetCollisionID(id);
		m_collision->SetOffsetPos(Vec2(8, 8));
		m_collision->SetR(7);

	}
	Bullet::~Bullet()
	{
	}
}