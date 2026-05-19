#include <iostream>
#include "miniaudio.h"

int main() {
  std::cout << "pulse-player\n";
  std::cout << "miniaudio version: " << ma_version_string() << "\n";
  return 0;
}
