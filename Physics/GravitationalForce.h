#pragma once

#include "ForceGenerator.h"

class GravitationalForce : public ForceGenerator{

public:

	GravitationalForce(float strenght) : m_strength{ strenght } {}

	void Apply(std::vector<class Body*> bodies) override;

private:

	float m_strength{ 0 };

};


