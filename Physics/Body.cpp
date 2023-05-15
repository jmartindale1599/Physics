#include "Body.h"

#include "Integrator.h"

#include "World.h"

#include "Shape.h"

void Body::Step(float dt){

	if (type != Dynamic) return;

	//gravity

	ApplyForce(World::gravity * gravityScale * mass);

	float damping = 2;

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
