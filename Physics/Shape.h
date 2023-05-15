#pragma once

#include <glm/glm.hpp>

#include "Graphics.h"

class Shape{

public:

	Shape() {}

	Shape(const glm::vec4& color) : color{ color } {}

	virtual void Draw(class Graphics* graphics, const glm::vec2& position) = 0;

public:

	float size = 0;

	glm::vec4 color{ 1,1,1,1 };

};
