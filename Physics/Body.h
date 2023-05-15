#pragma once

#include <glm/glm.hpp>

#include "Shape.h"

class Body {

public:

	enum Type{ Static, Kinematic, Dynamic};

	Body(Shape* shape, const glm::vec2& position, const glm::vec2& velocity = { 0, 0 }, float mass = 1, Type type = Type::Dynamic) : shape{ shape }, position { position }, velocity{ velocity }, mass{ mass }, type{ type } {
	
		if (type == Static) mass = 0;

		invMass = (mass == 0) ? 0 : 1 / mass; 
	
	};

	void Step(float dt);

	void Draw(class Graphics* m_graphics);

	void ApplyForce(const glm::vec2& force);

	void ClearForce() { force = glm::vec2{ 0,0 }; }

public:

	class Shape* shape{ nullptr };

	Type type{ Type::Dynamic };

	glm::vec2 position{ 0,0 };

	glm::vec2 velocity{ 0,0 };

	glm::vec2 force{ 0,0 };

	float gravityScale{ 1 };

	float mass{ 1 };

	float invMass{ 1 };

};
