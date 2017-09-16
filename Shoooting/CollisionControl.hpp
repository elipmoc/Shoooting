#pragma once
#include <memory>
#include <vector>
namespace game {

	//�N���X�O���錾
	class CollisionData;

	//�����蔻��Ǘ��N���X
	//�V���O���g���ɂ���

	class CollisionControl {
		CollisionControl()=default;
		~CollisionControl();
		static CollisionControl m_instance;

		//�����蔻��̃��X�g
		std::vector<std::unique_ptr<CollisionData>> m_collisions;
	public:
		

		static CollisionControl& GetInstance()noexcept { return m_instance; }

		void PushCollisionData(CollisionData& colliData);

		void Update();

	};
}