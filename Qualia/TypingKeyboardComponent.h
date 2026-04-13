#pragma once
#include "Component.h"
#include "EventListener.h"

namespace arche
{
	class TextComponent;
}

class TypingKeyboardComponent final : public arche::Component,
										public arche::EventListener
{
public:
	TypingKeyboardComponent();
	~TypingKeyboardComponent() override;

	TypingKeyboardComponent(const TypingKeyboardComponent& other) = delete;
	TypingKeyboardComponent(TypingKeyboardComponent&& other) = delete;
	TypingKeyboardComponent& operator=(const TypingKeyboardComponent& other) = delete;
	TypingKeyboardComponent& operator=(TypingKeyboardComponent&& other) = delete;

	void OnEvent(const arche::Event& event) override;

	const std::string& GetInput() const;

private:
	std::string m_TextString{};

	arche::TextComponent* m_pText{};
};

