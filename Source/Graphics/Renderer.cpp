#include "Renderer.h"

#include <glad/glad.h>

namespace Nebula
{

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::SetClearColor(const Color& ClearColor)
	{
		glClearColor(ClearColor.R, ClearColor.G, ClearColor.B, ClearColor.A);
	}

}
