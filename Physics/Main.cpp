
#include <iostream>

#include <include/SDL.h>

#include <glm/glm.hpp>

#include "Graphics.h"

#include "Random.h"

#include "ParticleTest.h"

#include "ForceTest.h"

int main(int argc, char* argv[]) {

    Test* test = new ForceTest();
     
    test->Initialize();

    while (!test->IsQuit()){

        test->Run();

    }

    delete test;

    return 0;

}
