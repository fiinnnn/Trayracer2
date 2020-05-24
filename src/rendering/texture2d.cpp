#include "texture2d.h"

#include "core/core.h"
#include "renderer_api.h"
#include "platform/opengl/opengl_texture2d.h"

namespace Trayracer2 {

Ref<Texture2D> Texture2D::create(unsigned int width, unsigned int height)
{
	switch (RendererAPI::getAPI()) {
		case RendererAPI::API::None:
			ASSERT(false, "RendererAPI::None is not supported");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return createRef<OpenGLTexture2D>(width, height);
	}
}

Texture2D::Texture2D(unsigned int width, unsigned int height) : m_width(width), m_height(height)
{}

}
