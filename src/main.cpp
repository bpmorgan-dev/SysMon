#include <iostream>
#include "ncurses_display.h"
#include "system.h"
#include "linux_parser.h"

int main() {
  try{
  	System system;
  	NCursesDisplay::Display(system);
  }catch(std::exception& ex){
    std::cerr << "Exception thrown: " << ex.what() << std::endl;
  }
}