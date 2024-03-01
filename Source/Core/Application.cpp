#include "Application.h"

#include "Graphics/GraphicsContext.h"

namespace Nebula
{
	void Application::Initialize()
	{
	}

	void Application::Update(float DeltaTime)
	{
	}

	void Application::Render(float DeltaTime)
	{
		for (int i = static_cast<int>(m_Windows.size()) - 1; i >= 0 && !m_Windows.empty(); i--)
		{
			if (m_Windows[i]->IsPendingClose())
			{
				delete m_Windows[i];
				continue;
			}

			m_Windows[i]->SwapBuffers();
		}
	}

	void Application::Shutdown()
	{
	}

	bool Application::IsRunning() const
	{
		return m_Windows.size() > 0;
	}

	Application::Application()
	{
	}

	Application::~Application()
	{
	}
}
