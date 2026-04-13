#include "FoodComponent.h"

#include "AvatarComponent.h"
#include "ColliderComponent.h"
#include "EventQueue.h"
#include "GameObject.h"
#include "PhysicsComponent.h"
#include "ServiceLocator.h"
#include "SoundSystem.h"
#include "SpriteComponent.h"
#include "Timer.h"

float FoodComponent::m_SpriteScale{ 4 };
arche::SpriteDataPreset FoodComponent::m_GreenScore100{ false, 3, 2, 1.f, 2, 0 };
arche::SpriteDataPreset FoodComponent::m_GreenScore200{ false, 3, 2, 1.f, 3, 0 };
arche::SpriteDataPreset FoodComponent::m_BlueScore100{ false, 3, 2, 1.f, 4, 4 };
arche::SpriteDataPreset FoodComponent::m_BlueScore200{ false, 3, 2, 1.f, 5, 0 };

FoodComponent::~FoodComponent()
{
	arche::EventQueue::GetInstance().SendEvent(arche::Event{"FoodCompDestroyed"});
}

void FoodComponent::Initialize()
{
	arche::ColliderComponent* myColl = m_pOwner->GetComponent<arche::ColliderComponent>();
	if (myColl)
	{
		myColl->SetOverlapFunction([this](arche::GameObject* overlappingActor)
			{
				if (m_CurrState == State::Points)
					return;

				//if its a player
				AvatarComponent* avatarComp = overlappingActor->GetComponent<AvatarComponent>();
				arche::SpriteComponent* spriteComp = m_pOwner->GetComponent<arche::SpriteComponent>();
				arche::PhysicsComponent* physComp = m_pOwner->GetComponent<arche::PhysicsComponent>();
				if (avatarComp && spriteComp && physComp)
				{
					avatarComp->PickedUpFood(m_MyType);
					m_CurrState = State::Points;
					arche::ServiceLocator::GetSoundSystem().PlaySound("../Data/Sound/PickupFood.wav", 100, 0);
					//Set sprite variables
					switch(m_MyType)
					{
					case FoodType::Fries:
					{
						if (avatarComp->GetColor() == AvatarComponent::AvatarColor::green)
							spriteComp->SetAnimVariables(m_GreenScore200);
						else
							spriteComp->SetAnimVariables(m_BlueScore200);
						break;
					}
					case FoodType::Melon:
					{
						if (avatarComp->GetColor() == AvatarComponent::AvatarColor::green)
							spriteComp->SetAnimVariables(m_GreenScore100);
						else
							spriteComp->SetAnimVariables(m_BlueScore100);
						break;
					}
					}
					spriteComp->Scale(m_SpriteScale);
					spriteComp->Pause(true);

					physComp->SetPhysicsSettings(false, false, false);
				}
			});
	}
}

void FoodComponent::Update()
{
	switch(m_CurrState)
	{
	case State::Food:
	{
		break;
	}
	case State::Points:
	{
		if (m_Timer >= 1.f)
		{
			m_pOwner->Destroy();
			return;
		}

		float deltaTime = arche::Time::GetInstance().GetDelta();
		m_Timer += deltaTime;

		m_pOwner->GetTransform()->Translate(glm::vec2(0, -deltaTime * 100.f));

		break;
	}
	}
}

void FoodComponent::SetFoodType(FoodType type)
{
	m_MyType = type;
}
