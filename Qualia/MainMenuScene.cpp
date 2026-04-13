#include "MainMenuScene.h"

#include <SDL_keycode.h>

#include "FPSCounter.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "ServiceLocator.h"
#include "SoundSystem.h"
#include "StartSinglePlayerCommand.h"
#include "StartVersusCommand.h"
#include "TextComponent.h"
#include "Texture2D.h"
#include "ToggleSoundSysCommand.h"
#include "TextureComponent.h"

using namespace arche;

void MainMenuScene::Create()
{
	ServiceLocator::GetSoundSystem().ToggleMusic(false);

	auto& pSceneManager = SceneManager::GetInstance();
	auto* pGameScene = pSceneManager.GetActiveScene();

	InputManager::GetInstance().RemoveAllInputs();
	InputManager::GetInstance().AddKeyboardCommand(SDLK_F2, InputManager::InputType::OnDown, std::make_unique<ToggleSoundSysCommand>());

	if (pGameScene)
	{
		pGameScene->RemoveAll();
		pGameScene->SetName("MainMenu");
	}
	else
	{
		pGameScene = pSceneManager.CreateScene("MainMenu");
	}
	pSceneManager.SetActiveScene(pGameScene);


	//Add a commands to start the game
	InputManager::GetInstance().AddKeyboardCommand('1', InputManager::InputType::OnDown, std::make_unique<StartSinglePlayerCommand>());
	InputManager::GetInstance().AddKeyboardCommand('3', InputManager::InputType::OnDown, std::make_unique<StartVersusCommand>());

	const auto pFont{ ResourceManager::GetInstance().LoadFont("Retro.otf", 30) };

	// BubbleBobble logo
	const auto pBG = pGameScene->CreateGameObject();
	const auto pGameLogoTexture{ ResourceManager::GetInstance().LoadTexture("BubbleBobbleLogo.png") };
	pBG->AddComponent<TextureComponent>()->SetTexture(pGameLogoTexture);
	pBG->GetTransform()->SetWorldPosition(1280.f/2 - pGameLogoTexture->GetSize().x / 2, 20);

	// DAE LOGO
	const auto pLogo = pGameScene->CreateGameObject();
	const auto pLogoTexture{ ResourceManager::GetInstance().LoadTexture("logo.tga") };
	pLogo->AddComponent<TextureComponent>()->SetTexture(pLogoTexture);
	pLogo->AddComponent<FPSCounter>();
	pLogo->GetTransform()->SetWorldPosition(1280.f / 2 - pLogoTexture->GetSize().x / 2, 680);

	// made by text
	const auto pName = pGameScene->CreateGameObject();
	pName->AddComponent<TextureComponent>();
	pName->AddComponent<TextComponent>()->SetFont(pFont);
	pName->GetComponent<TextComponent>()->SetText("Made by Mendel Debrabandere");
	pName->GetComponent<TextComponent>()->Update();
	pName->GetTransform()->SetWorldPosition(1280.f / 2 - pName->GetComponent<TextureComponent>()->GetTextureSize().x / 2, 750);

	// FPS COUNTER
	const auto pFPSCounter = pGameScene->CreateGameObject();
	pFPSCounter->AddComponent<TextureComponent>();
	pFPSCounter->AddComponent<FPSCounter>();
	pFPSCounter->AddComponent<TextComponent>()->SetFont(pFont);


	// SinglePlayer
	const auto pSinglePlayer = pGameScene->CreateGameObject();
	pSinglePlayer->AddComponent<TextureComponent>();
	pSinglePlayer->AddComponent<TextComponent>()->SetFont(pFont);
	pSinglePlayer->GetComponent<TextComponent>()->SetText("Press 1 to start SinglePlayer mode");
	pSinglePlayer->GetComponent<TextComponent>()->SetColor(120, 250, 120);
	pSinglePlayer->GetComponent<TextComponent>()->Update();
	pSinglePlayer->GetTransform()->SetWorldPosition(1280.f / 2 - pSinglePlayer->GetComponent<TextureComponent>()->GetTextureSize().x / 2, 350);

	// Coop
	const auto pCoop = pGameScene->CreateGameObject();
	pCoop->AddComponent<TextureComponent>();
	pCoop->AddComponent<TextComponent>()->SetFont(pFont);
	pCoop->GetComponent<TextComponent>()->SetText("Press 2 to start Co-op mode");
	pCoop->GetComponent<TextComponent>()->SetColor(150, 150, 250);
	pCoop->GetComponent<TextComponent>()->Update();
	pCoop->GetTransform()->SetWorldPosition(1280.f / 2 - pCoop->GetComponent<TextureComponent>()->GetTextureSize().x / 2, 420);

	// versus
	const auto pVersus = pGameScene->CreateGameObject();
	pVersus->AddComponent<TextureComponent>();
	pVersus->AddComponent<TextComponent>()->SetFont(pFont);
	pVersus->GetComponent<TextComponent>()->SetText("Press 3 to start Versus mode");
	pVersus->GetComponent<TextComponent>()->SetColor(250, 150, 80);
	pVersus->GetComponent<TextComponent>()->Update();
	pVersus->GetTransform()->SetWorldPosition(1280.f / 2 - pVersus->GetComponent<TextureComponent>()->GetTextureSize().x / 2, 490);

	//==============================
	//CONTROLS
	const auto pKeyboard = pGameScene->CreateGameObject();
	pKeyboard->AddComponent<TextureComponent>();
	pKeyboard->AddComponent<TextComponent>()->SetFont(pFont);
	pKeyboard->GetComponent<TextComponent>()->SetText("Keyboard controls:");
	pKeyboard->GetComponent<TextComponent>()->SetColor(200, 200, 200);
	pKeyboard->GetComponent<TextComponent>()->Update();
	pKeyboard->GetTransform()->SetWorldPosition(890, 30);

	const auto pWASD = pGameScene->CreateGameObject();
	pWASD->AddComponent<TextureComponent>();
	pWASD->AddComponent<TextComponent>()->SetFont(pFont);
	pWASD->GetComponent<TextComponent>()->SetText("WASD and spacebar");
	pWASD->GetComponent<TextComponent>()->SetColor(200, 200, 200);
	pWASD->GetComponent<TextComponent>()->Update();
	pWASD->GetTransform()->SetWorldPosition(890, 70);

	const auto pController = pGameScene->CreateGameObject();
	pController->AddComponent<TextureComponent>();
	pController->AddComponent<TextComponent>()->SetFont(pFont);
	pController->GetComponent<TextComponent>()->SetText("Controller controls:");
	pController->GetComponent<TextComponent>()->SetColor(200, 200, 200);
	pController->GetComponent<TextComponent>()->Update();
	pController->GetTransform()->SetWorldPosition(890, 150);

	const auto pDPAD = pGameScene->CreateGameObject();
	pDPAD->AddComponent<TextureComponent>();
	pDPAD->AddComponent<TextComponent>()->SetFont(pFont);
	pDPAD->GetComponent<TextComponent>()->SetText("DPAD, A and B");
	pDPAD->GetComponent<TextComponent>()->SetColor(200, 200, 200);
	pDPAD->GetComponent<TextComponent>()->Update();
	pDPAD->GetTransform()->SetWorldPosition(890, 190);

}
