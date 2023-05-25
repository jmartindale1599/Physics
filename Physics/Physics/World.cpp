#include "World.h"

#include "../Physics/Forces/ForceGenerator.h"

#include "../Physics/Constraints/Joint.h"

#include "../../Physics/Collision/Contact.h"

#include "../../Physics/Collision/Collision.h"

#include <vector>

glm::vec2 World::gravity{ 0, -9.8f };

World::~World(){

	for(Body* body : m_bodys){
	
		delete body;
	
	}

}

void World::Step(float dt){

	//apply joints

	for (auto joints : m_joints) joints->Step(dt);

	//apply force gens force

	std::vector<Body*> bodies(m_bodys.begin(), m_bodys.end());

	if (m_bodys.empty() == false && m_forceGenerators.empty() == false){

		for (auto forceGenerator : m_forceGenerators) {

			forceGenerator->Apply(bodies);

		}

	}

	//bodys

	for (Body* body : m_bodys) {

		body->Step(dt);

	}

	//collision

	std::vector<Contact> contacts;

	Collision::createContacts(bodies, contacts);

	Collision::seperateContacts(contacts);

	Collision::resolveContacts(contacts);

}

void World::Draw(Graphics* graphics){

	for (auto joints : m_joints) joints->Draw(graphics);

	for (auto forceGenerator : m_forceGenerators) forceGenerator->Draw(graphics);

	for (Body* body : m_bodys) {

		body->Draw(graphics);

	}

}

void World::AddBodyObject(Body* body){

	m_bodys.push_back(body);

}

void World::RemoveBodyObject(Body* body){

	m_bodys.remove(body);

}

void World::AddJoint(Joint* joint){

	m_joints.push_back(joint);

}

void World::RemoveJoint(Joint* joint){

	m_joints.remove(joint);

}

void World::AddForceGenerator(ForceGenerator* forceGen){

	m_forceGenerators.push_back(forceGen);

}
