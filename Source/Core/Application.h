#pragma once
#include <string>
#include <vector>

#include "Window.h"

namespace Nebula
{

	class Application
	{

	public:

		virtual void Initialize();
		virtual void Update(float DeltaTime);
		virtual void Render(float DeltaTime);
		virtual void Shutdown();

		virtual bool IsRunning() const;

		std::string GetName() const { return m_Name; }
		void SetName(const std::string& NewName) { m_Name = NewName; }

	private:

		std::string m_Name = "NebulaEngine";
		std::vector<Window*> m_Windows;

		Application();
		~Application();

		//Only allow engine class to access constructor and destructor.
		friend class NebulaEngine;
		friend struct GraphicsContext;

	};
	
}
