#include <exception>
#include <iostream>
#include <lib1.h>
#include <string>

void lib2_catch()
{
    try {
        lib1_iThrow();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
