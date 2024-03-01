#include "Window.h"

#include "Graphics/GraphicsContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Nebula
{
	std::string Window::GetTitle() const
	{
		return glfwGetWindowTitle(GetNativeWindow());
	}

	void Window::SwapBuffers() const
	{
		glfwSwapBuffers(GetNativeWindow());
	}

	void Window::Close()
	{
		glfwSetWindowShouldClose(m_NativeWindow, true);
	}

	bool Window::IsPendingClose() const
	{
		return glfwWindowShouldClose(GetNativeWindow());
	}

	Window* Window::CreateWindow(const std::string& Title, int Width, int Height, EWindowFlags Flags)
	{
		Window* ReturnValue = new Window();

		glfwDefaultWindowHints();

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

		//Initialize Flags
		glfwWindowHint(GLFW_MAXIMIZED, Flags & WindowFlag_Maximized);

		ReturnValue->m_NativeWindow = glfwCreateWindow(Width, Height, Title.c_str(), nullptr, nullptr);
		
		glfwMakeContextCurrent(ReturnValue->GetNativeWindow());
		glfwSetWindowUserPointer(ReturnValue->GetNativeWindow(), ReturnValue);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			delete ReturnValue;
			return nullptr;
		}

		GraphicsContext::RegisterWindow(ReturnValue);
		return ReturnValue;
	}

	Window::~Window()
	{
		glfwDestroyWindow(GetNativeWindow());
		GraphicsContext::UnregisterWindow(this);
	}
}
