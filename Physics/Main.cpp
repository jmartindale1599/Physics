
#include <iostream>

#include <include/SDL.h>

#include <glm/glm.hpp>

#include "../Physics/Engine/Graphics.h"

#include "../Physics/Engine/Random.h"

#include "../Physics/Tests/ParticleTest.h"

#include "../Physics/Tests/ForceTest.h"

#include "../Physics/Tests/JointTest.h"

int main(int argc, char* argv[]) {

    Test* test = new JointTest();
     
    test->Initialize();

    while (!test->IsQuit()){

        test->Run();

    }

    delete test;

    return 0;

}
