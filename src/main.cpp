#include <iostream>
#include "box.hpp"
#include "box.cpp"
#include "window.cpp"


int main( int argc, char *argv[] ) {
  // get the count of boxes from the command line
  if (argc != 2) {
    std::cerr << "Incorrect Usage. Usage:" << std::endl;
    std::cerr << "  Usage: " << argv[0] << " <count>" << std::endl;
    return 1;
  }

  int count = atoi(argv[1]);

  WindowManager window(devflr(640.0f * 2, BOX_SIZE), devflr(480.0f * 2, BOX_SIZE), "BouncyBoxes", count);
  window.start_loop();
  return 0;
}