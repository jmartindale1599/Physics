
#include "CollisionTest.h"

#include "../Physics/Body.h"

#include "../Physics/Shapes/CircleShape.h"

#include "../Physics/World.h"

void CollisionTest::Initialize(){

	Test::Initialize();

	m_user = new Body(new CircleShape(1, { 0, 0, 1, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::Kinematic);
	
	m_world->AddBodyObject(m_user);

	auto body = new Body(new CircleShape(200, glm::vec4{ 1.0f }), { 0, -207.5 }, { 0, 0 }, 1, Body::Static);
	
	m_world->AddBodyObject(body);

}

void CollisionTest::Update(){
	
	Test::Update();

	glm::vec2 position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
	
	m_user->velocity = position - m_user->position;

	m_user->position = position;

	if (m_input->GetMouseButton(0)){
		
		glm::vec2 velocity = { 0,0 };//randomUnitCircle() * randomf(1, 3);
		
		float size = randomf(0.5f, 0.9f);

		auto body = new Body(new CircleShape(size, { randomf(), randomf(), randomf(), 1 }), position, velocity, size);
		
		body->damping = 0.3f;
	
		body->gravityScale = 120;

		m_world->AddBodyObject(body);
	
	}

}

void CollisionTest::FixedUpdate(){
	
	m_world->Step(m_time->GetFixedDeltaTime());

}

void CollisionTest::Render(){

	m_world->Draw(m_graphics);

}


