#include "Component.h"
#include "GameObject.h"

arche::GameObject* arche::Component::GetOwner() const
{
	return m_pOwner;
}

void arche::Component::SetOwner(GameObject* pParent)
{
	m_pOwner = pParent;
}