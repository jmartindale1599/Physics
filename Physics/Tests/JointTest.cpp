#include "../Tests/JointTest.h"

#include "../Physics/Shapes/CircleShape.h"

#include "../Physics/World.h"

#include "../Physics/Body.h"

#include "../Physics/Constraints/Joint.h"

#define SPRING_STIFFNESS 120

#define SPRING_LENGTH 45

#define BODY_DAMPING 10

#define CHAIN_SIZE 6

void JointTest::Initialize(){

	Test::Initialize();

	m_anchor = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 100 }, { 0, 0 }, 0, Body::Kinematic);
	
	m_world->AddBodyObject(m_anchor);

	auto prevBody = m_anchor;

	//chain -> for

	auto body = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 }, { 0, 0 }, 1, Body::Dynamic);

	body->damping = BODY_DAMPING;
	
	m_world->AddBodyObject(body);

	auto joint = new Joint(m_anchor, body, SPRING_STIFFNESS, SPRING_LENGTH);
	
	m_world->AddJoint(joint);

	prevBody = body;

	body = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 }, { 0, 0 }, 1, Body::Dynamic); 

	body->gravityScale = 250; 
	
	body->damping = BODY_DAMPING; 

	m_world->AddBodyObject(body); 

	joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH); 

	m_world->AddJoint(joint); 

}

void JointTest::Update(){

	Test::Update();
	
	m_anchor->position = m_input->GetMousePosition();

}

void JointTest::FixedUpdate(){

	m_world->Step(m_time->GetFixedDeltaTime());

}

void JointTest::Render(){

	m_world->Draw(m_graphics);
	
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });

}
