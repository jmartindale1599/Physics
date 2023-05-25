#pragma once

#include <vector>

#include "../../Physics/Collision/Contact.h"

#include "../Body.h"

namespace Collision{

	Contact GenerateContact(Body* bodyA, Body* bodyB);

	void createContacts(std::vector<Body*> bodies, std::vector<Contact>& contacts);

	void seperateContacts(std::vector<Contact>& contacts);

	void resolveContacts(std::vector<Contact>& contacts);

}
