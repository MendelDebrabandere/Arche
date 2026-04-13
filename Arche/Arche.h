#pragma once
#include <functional>
#include <mutex>
#include <queue>
#include <string>

namespace arche
{
	class SceneManager;

	class Arche final
	{
	public:
		explicit Arche(const std::string& dataPath);
		~Arche();

		Arche(const Arche& other) = delete;
		Arche(Arche&& other) = delete;
		Arche& operator=(const Arche& other) = delete;
		Arche& operator=(Arche&& other) = delete;

		SceneManager* GetSceneManager() const;

		void Run();

		static void LockMutex() { s_LoopMutex.lock(); }
		static void UnlockMutex() { s_LoopMutex.unlock(); }

		static void AddTask(const std::function<void()> func) { s_Tasks.push(func); }

		static void SetRandomSeed(unsigned int seed){ std::srand(seed); }
	private:
		SceneManager* mpSceneManager;

		inline static std::mutex s_LoopMutex{};
		inline static std::queue<std::function<void()>> s_Tasks{};

		unsigned int m_RandomSeed{};
	};
}