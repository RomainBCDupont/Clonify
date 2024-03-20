#include "headers/Song.h"
#include <iostream>

int main() {

  Song *test = new Song(12);

  std::cout << test->getDuration() << std::endl;

  return 0;
}
