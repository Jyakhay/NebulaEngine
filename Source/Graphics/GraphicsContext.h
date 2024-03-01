#pragma once

#include "Core/Window.h"

#include <unordered_map>

namespace Nebula
{
	struct GraphicsContext
	{

	public:

		static void RegisterWindow(Window* NewWindow);
		static void UnregisterWindow(Window* RegisteredWindow);

	private:

		static inline std::unordered_map<uint32_t, Window*> m_Windows;
	};
}
