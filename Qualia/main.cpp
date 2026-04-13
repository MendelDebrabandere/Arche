#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Qualia.h"
#include "Arche.h"
#include "SDLSoundSystem.h"
#include "ServiceLocator.h"

using namespace arche;

int main(int, char* [])
{
	// Register the soundSystem
	ServiceLocator::InitDefault();

	Arche engine{ std::string("../Data/") };
	Qualia::Create();
	engine.Run();

	return 0;
}