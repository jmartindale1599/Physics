
#include "../Tests/ForceTest.h"

#include "../Physics/Body.h"

#include "../Physics/Shapes/CircleShape.h"

#include "../Physics/Forces/GravitationalForce.h"

#include "../Physics/Forces/PointForce.h"

#include "../Physics/Forces/AreaForce.h"

#include "../Physics/Forces/DragForce.h"

#define POINT_FORCE

//#define AREA_FORCE

//#define DRAG_FORCE

void ForceTest::Initialize() {

	Test::Initialize();

	/*auto forceGenerator = new GravitationalForce(400);

	m_world->AddForceGenerator(forceGenerator);*/

#if defined(POINT_FORCE)

	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::Static);

	ForceGenerator* forceGenerator = new PointForce(body, 2000);

	m_world->AddForceGenerator(forceGenerator);

#elif defined(AREA_FORCE)

	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::Static);

	ForceGenerator* forceGenerator = new AreaForce(body, 2000, -90);
	
	m_world->AddForceGenerator(forceGenerator);

#elif defined(DRAG_FORCE)

	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::Static);

	ForceGenerator* forceGenerator = new DragForce(body, 0.5f);
	
	m_world->AddForceGenerator(forceGenerator);

#endif

}

void ForceTest::Update() {

	Test::Update();

	if (m_input->GetMouseButton(0)) {

		glm::vec2 velocity = { randomUnitCircle() * randomf(100, 200) };

		float size = randomf(2, 9) * 3;

		auto body = new Body(new CircleShape(size, { random(0,255), random(0,255), random(0,255), random(0,255) }),m_input->GetMousePosition(), velocity, size);

		body->gravityScale = 30;

		m_world->AddBodyObject(body);

	}

}

void ForceTest::FixedUpdate() {

	m_world->Step(m_time->GetFixedDeltaTime());

}

void ForceTest::Render() {

	m_world->Draw(m_graphics);

	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });

}

