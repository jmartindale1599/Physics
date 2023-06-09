#pragma once

#include "../Engine/Time.h"

#include "../Physics/Body.h"

namespace Integrator {

	void ExplicitEuler(Body& body, float dt) {//dt is delta time

		body.position = body.position + body.velocity * dt;

		body.velocity = body.velocity + (body.force * body.invMass) * dt;

	}

	void SemiImplicitEuler(Body& body, float dt){
		
		body.velocity = body.velocity + (body.force * body.invMass) * dt;

		body.position = body.position + body.velocity * dt;

	}

}
