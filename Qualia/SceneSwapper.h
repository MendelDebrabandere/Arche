#pragma once
#include "EventListener.h"
#include "Singleton.h"


class SceneSwapper final : public arche::Singleton<SceneSwapper>,
							public arche::EventListener
{
public:
	enum class GameState
	{
		Menu,
		SinglePlayer,
		Coop,
		Versus,
	};

	~SceneSwapper() override = default;
	SceneSwapper(const SceneSwapper& other) = delete;
	SceneSwapper operator=(const SceneSwapper& rhs) = delete;
	SceneSwapper(SceneSwapper&& other) = delete;
	SceneSwapper operator=(SceneSwapper&& rhs) = delete;

	void Init();
	void SkipLevel();

	void OnEvent(const arche::Event& e) override;

	GameState m_State{ GameState::Menu };
private:
	friend class Singleton<SceneSwapper>;
	SceneSwapper() = default;

};


