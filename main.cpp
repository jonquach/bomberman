#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <pthread.h>

#include "GameEngine.hpp"
#include "Exception.hpp"

int main()
{
  GameEngine engine;

  try {
    srand(time(NULL) + getpid());
    if (engine.initialize() == false)
      throw ErrorException("Error : GameEngine initialize failed.");
    while (engine.update() == true)
      engine.draw();
  }
  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
