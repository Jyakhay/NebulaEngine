#pragma once

#include <string>

struct GLFWwindow;

namespace Nebula
{

	typedef int EWindowFlags;

	enum EWindowFlags_
	{
		WindowFlag_None = 0 << 0,
		WindowFlag_Maximized = 1 << 1
	};

	class Window
	{

	public:

		std::string GetTitle() const;

		void SwapBuffers() const;

		void Close();
		bool IsPendingClose() const;

		uint32_t GetID() const { return m_ID; }
		GLFWwindow* GetNativeWindow() const { return m_NativeWindow; }


		//--- Static Constructors ---//

		static Window* CreateWindow(const std::string& Title, int Width, int Height, EWindowFlags Flags);

	private:

		Window() = default;
		~Window();

		GLFWwindow* m_NativeWindow;
		uint32_t m_ID = 0;

		friend struct GraphicsContext;
		friend class Application;

	};

}
