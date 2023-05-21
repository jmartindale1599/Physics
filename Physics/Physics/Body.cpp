#include "Body.h"

#include "Integrator.h"

#include "World.h"

#include "../Physics/Shapes/CircleShape.h"

void Body::Step(float dt){

	if (type != Dynamic) return;

	//gravity

	ApplyForce(World::gravity * gravityScale * mass);

	Integrator::SemiImplicitEuler(*this, dt);

	ClearForce();
	
	// damping
	
	velocity *= (1.0f / (1.0f + (damping * dt)));

}

void Body::Draw(Graphics* m_graphics){

	shape->Draw(m_graphics, position);

}

void Body::ApplyForce(const glm::vec2& force){

	this->force += force;

}

bool Body::Intersects(Body* body){

	glm::vec2 direction = body->position - position;
	
	float distance = glm::length(direction);
	
	float radius = dynamic_cast<CircleShape*>(shape)->radius + dynamic_cast<CircleShape*>(body->shape)->radius;

	return distance <= radius;

}
