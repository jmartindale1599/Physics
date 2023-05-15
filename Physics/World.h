#pragma once

#include "Body.h"

#include <list>

#include <glm/glm.hpp>

#include <vector>

class World{

public:
	
	~World();
	
	void Step(float dt);
	
	void Draw(class Graphics* graphics);
	
	void AddBodyObject(Body* body);
	
	void RemoveBodyObject(Body* body);

	void AddForceGenerator(class ForceGenerator* forceGen);

	static glm::vec2 gravity;

private:

	std::list<Body*> m_bodys;

	std::vector<class ForceGenerator*> m_forceGenerators;

};
