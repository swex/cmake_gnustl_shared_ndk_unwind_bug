#include "lib1.h"
#include <exception>
#include <stdexcept>
#include <string>

void lib1_iThrow()
{
    throw std::runtime_error("i throw");
}
