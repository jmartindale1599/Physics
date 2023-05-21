#include "Joint.h"

#include "../Body.h"

#include "../../Engine/Graphics.h"

Joint::Joint(Body* bodyA, Body* bodyB, float stifness, float restLength) : m_bodyA{bodyA}, m_bodyB{bodyB}, m_stiffy{stifness}, m_restLength{restLength}{

	if (m_restLength == 0) m_restLength = glm::distance(bodyA->position, bodyB->position);

}

void Joint::Step(float dt){

	glm::vec2 direction = m_bodyA->position - m_bodyB->position;

	float length = glm::length(direction);

	//f = -k * x

	float x = length - m_restLength;

	if (x < 0) return;

	float f = -m_stiffy * x;

	glm::vec2 ndirection = glm::normalize(direction);

	m_bodyA->ApplyForce(ndirection * f);

	m_bodyB->ApplyForce(-ndirection * f);

}

void Joint::Draw(Graphics* graphics){

	graphics->DrawLine(m_bodyA->position, m_bodyB->position, glm::vec4{ 1 });

}
