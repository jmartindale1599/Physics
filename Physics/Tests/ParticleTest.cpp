#include "../Tests/ParticleTest.h"

#include "../Physics/Body.h"

#include "../Physics/Shapes/CircleShape.h"

void ParticleTest::Initialize(){

	Test::Initialize();

}

void ParticleTest::Update(){

	Test::Update();

	if (m_input->GetMouseButton(0)) {

		glm::vec2 position = m_graphics->ScreenToWorld(m_input->GetMousePosition());

		glm::vec2 velocity = { 0,0 };//randomUnitCircle() * randomf(1, 3);

		float size = randomf(0.5f, 0.9f);

		auto body = new Body(new CircleShape(size, { randomf(), randomf(), randomf(), 1 }), position, velocity, size);

		m_world->AddBodyObject(body);

	}

}

void ParticleTest::FixedUpdate(){

	m_world->Step(m_time->GetFixedDeltaTime());

}

void ParticleTest::Render(){ 

	m_world->Draw(m_graphics);

	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 }); 

}
