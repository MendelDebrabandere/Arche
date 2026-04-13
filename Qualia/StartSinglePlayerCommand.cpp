#include "StartSinglePlayerCommand.h"

#include <SDL_keycode.h>


#include "Avatar.h"
#include "HUD.h"
#include "InputManager.h"
#include "LevelLoader.h"
#include "SceneManager.h"
#include "SceneSwapper.h"
#include "ServiceLocator.h"
#include "SoundSystem.h"
#include "AvatarComponent.h"
#include "ToggleSoundSysCommand.h"

void StartSinglePlayerCommand::Execute()
{
	auto& sceneManager = arche::SceneManager::GetInstance();
	auto scene = sceneManager.GetActiveScene();

	arche::InputManager::GetInstance().RemoveAllInputs();
	arche::InputManager::GetInstance().AddKeyboardCommand(SDLK_F2, arche::InputManager::InputType::OnDown, std::make_unique<ToggleSoundSysCommand>());

	scene->RemoveAll();
	LevelLoader::LoadLevel(scene, 1);
	scene->SetName("1");

	auto avatar = Avatar::CreateAvatar(sceneManager.GetActiveScene(), glm::vec2{100,700}, true, false);

	HUD::CreateHUD(scene, avatar->GetComponent<AvatarComponent>());


	SceneSwapper::GetInstance().m_State = SceneSwapper::GameState::SinglePlayer;

	//Start playing the in game music
	arche::ServiceLocator::GetSoundSystem().PlayMusic("../Data/Sound/MainTheme.mp3", 100, -1);
	arche::ServiceLocator::GetSoundSystem().ToggleMusic(true);
}
