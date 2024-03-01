#include "GraphicsContext.h"

#include "Core/Application.h"
#include "Core/NebulaEngine.h"
#include "Debug/Logger.h"

namespace Nebula
{
	void GraphicsContext::RegisterWindow(Window* NewWindow)
	{
		NewWindow->m_ID = static_cast<uint32_t>(m_Windows.size()) + 1;
		m_Windows.emplace(static_cast<uint32_t>(m_Windows.size()) + 1, NewWindow);

		GEngine->GetApplication()->m_Windows.push_back(NewWindow);

		NEBULA_LOG(ELogSeverity::Neutral, "Window with title \"{}\" registered with ID: {}.", NewWindow->GetTitle(), NewWindow->GetID())
	}

	void GraphicsContext::UnregisterWindow(Window* RegisteredWindow)
	{
		if(RegisteredWindow)
		{
			if(m_Windows.contains(RegisteredWindow->GetID()))
			{
				RegisteredWindow->m_ID = 0;

				std::vector<Window*>& AppWindows = GEngine->GetApplication()->m_Windows;

				for(int i = 0; i < AppWindows.size(); i++)
				{
					if(AppWindows[i]->GetID() == RegisteredWindow->GetID())
					{
						AppWindows.erase(AppWindows.begin() + i);
						break;
					}
				}

				m_Windows.erase(RegisteredWindow->GetID());
			}
		}
	}
}
