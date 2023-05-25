#include "Collision.h"

#include "../Shapes/CircleShape.h"

#include "../../Engine/Random.h"

namespace Collision {

	Contact Collision::GenerateContact(Body* bodyA, Body* bodyB) {

		Contact contact;

		contact.bodyA = bodyA;

		contact.bodyB = bodyB;

		glm::vec2 direction = bodyA->position - bodyB->position;

		float distance = glm::length(direction);

		if(distance == 0){
		
			direction = { randomf(0.03f, 0.07f), randomf(-0.03f, -0.07f) }; 
		
		}

		float radius = dynamic_cast<CircleShape*>(bodyA->shape)->radius + dynamic_cast<CircleShape*>(bodyB->shape)->radius; 

		contact.depth = radius - distance;

		contact.normal = glm::normalize(direction);
		
		contact.restitution = (bodyA->restitution + bodyB->restitution) * 0.5f;

		return contact;

	}

	void createContacts(std::vector<Body*> bodies, std::vector<Contact>& contacts){

		for (size_t i = 0; i < bodies.size() - 1; i++){

			for (size_t j = i + 1; j < bodies.size(); j++){

				Body* bodyA = bodies[i];

				Body* bodyB = bodies[j];

				// contact needs at least one dynamic body

				if (bodyA->type != Body::Dynamic && bodyB->type != Body::Dynamic) continue;

				// check for intersection between bodies

				if (bodyA->Intersects(bodyB)){

					// create contact

					Contact contact = Collision::GenerateContact(bodyA, bodyB); 

					contacts.push_back(contact);

				}

			}

		}

	}

	void seperateContacts(std::vector<Contact>& contacts){

		for(auto& contact : contacts){
		
			float totalInvMass = contact.bodyA->invMass + contact.bodyB->invMass;

			glm::vec2 seperation = contact.normal * (contact.depth / totalInvMass);

			contact.bodyA->position += seperation * contact.bodyA->invMass;

			contact.bodyB->position -= seperation * contact.bodyB->invMass;
		
		}

	}

	void resolveContacts(std::vector<Contact>& contacts){

		for (auto& contact : contacts) {

			glm::vec2 relativeVelocity = contact.bodyA->velocity - contact.bodyB->velocity;

			float normalVelocity = glm::dot(relativeVelocity, contact.normal);

			if (normalVelocity > 0) continue;

			float totalInvMass = contact.bodyA->invMass + contact.bodyB->invMass;

			float impulseMagnitutde = -(1.0f + contact.restitution) * normalVelocity / totalInvMass;

			glm::vec2 impulse = contact.normal * impulseMagnitutde;

			contact.bodyA->velocity += (impulse * contact.bodyA->invMass);

			contact.bodyB->velocity -= (impulse * contact.bodyB->invMass);

		}	

	}

}


