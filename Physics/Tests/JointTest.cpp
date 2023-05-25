#include "../Tests/JointTest.h"

#include "../Physics/Shapes/CircleShape.h"

#include "../Physics/World.h"

#include "../Physics/Body.h"

#include "../Physics/Constraints/Joint.h"

#define SPRING_STIFFNESS 100

#define SPRING_LENGTH 1

#define BODY_DAMPING 10

#define CHAIN_SIZE 6

void JointTest::Initialize(){

	Test::Initialize();

	m_anchor = new Body(new CircleShape(1, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 0, Body::Kinematic);
	
	m_world->AddBodyObject(m_anchor);

	auto prevBody = m_anchor;

	//chain -> for

	auto body = new Body(new CircleShape(0.5f, { 1, 1, 1, 1 }), { 0, 0 });
	
	body->damping = BODY_DAMPING;
	
	m_world->AddBodyObject(body);

	auto joint = new Joint(m_anchor, body, SPRING_STIFFNESS, SPRING_LENGTH);
	
	m_world->AddJoint(joint);

	prevBody = body;

	body = new Body(new CircleShape(0.5f, { 1, 1, 1, 1 }), { 0, 0 }); 

	body->damping = BODY_DAMPING; 

	m_world->AddBodyObject(body); 

	joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH); 

	m_world->AddJoint(joint); 

}

void JointTest::Update(){

	Test::Update();
	
	m_anchor->position = m_graphics->ScreenToWorld(m_input->GetMousePosition());

}

void JointTest::FixedUpdate(){

	m_world->Step(m_time->GetFixedDeltaTime());

}

void JointTest::Render(){

	m_world->Draw(m_graphics);
	
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });

}
