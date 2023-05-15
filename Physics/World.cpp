#include "World.h"

#include "ForceGenerator.h"

glm::vec2 World::gravity{ 0, 9.8f };

World::~World(){

	for(Body* body : m_bodys){
	
		delete body;
	
	}

}

void World::Step(float dt){

	if (m_bodys.empty() == false && m_forceGenerators.empty() == false){

		std::vector<Body*> bodies(m_bodys.begin(), m_bodys.end());

		for (auto forceGenerator : m_forceGenerators) {

			forceGenerator->Apply(bodies);

		}

	}

	for (Body* body : m_bodys) {

		body->Step(dt);

	}

}

void World::Draw(Graphics* graphics){

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

void World::AddForceGenerator(ForceGenerator* forceGen){

	m_forceGenerators.push_back(forceGen);

}
