#include "../Tests/ParticleTest.h"

#include "../Physics/Body.h"

#include "../Physics/Shapes/CircleShape.h"

void ParticleTest::Initialize(){

	Test::Initialize();

}

void ParticleTest::Update(){

	Test::Update();

	if (m_input->GetMouseButton(0)) {

		glm::vec2 velocity = { randomUnitCircle() * randomf(100, 200) };

		auto body = new Body(new CircleShape(random(60), { random(0,255), random(0,255), random(0,255), random(0,255) }), (m_input->GetMousePosition(), velocity));

		m_world->AddBodyObject(body);

	}

}

void ParticleTest::FixedUpdate(){//changing this changed my particles placement highly. 

	m_world->Step(m_time->GetFixedDeltaTime()); 

}

void ParticleTest::Render(){ 

	m_world->Draw(m_graphics); 

	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 }); 

}
