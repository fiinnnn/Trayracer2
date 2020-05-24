#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "core/core.h"

namespace Trayracer2 {

class Texture2D {
public:
	virtual ~Texture2D() = default;

	static Ref<Texture2D> create(unsigned int width, unsigned int height);

	[[nodiscard]] virtual unsigned int getWidth() const { return m_width; };
	[[nodiscard]] virtual unsigned int getHeight() const { return m_height; };

	[[nodiscard]] virtual unsigned int getID() const = 0;

	virtual void update(void* buffer) = 0;

protected:
	Texture2D(unsigned int width, unsigned int height);

protected:
	unsigned int m_width, m_height;
};

}

#endif //TEXTURE2D_H
