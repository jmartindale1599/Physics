
#include <iostream>

#include <include/SDL.h>

#include <glm/glm.hpp>

#include "../Physics/Engine/Graphics.h"

#include "../Physics/Engine/Random.h"

#include "../Physics/Tests/ParticleTest.h"

#include "../Physics/Tests/ForceTest.h"

#include "../Physics/Tests/JointTest.h"

#include "../Physics/Tests/CollisionTest.h"

int main(int argc, char* argv[]) {

    Test* test = new CollisionTest();
     
    test->Initialize();

    while (!test->IsQuit()){

        test->Run();

    }

    delete test;

    return 0;

}
