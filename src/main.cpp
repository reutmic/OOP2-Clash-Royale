#include "Window.h"
#include <vector>
#include <cstdlib>
#include <ctime>

int main() try
{
    unsigned seed = std::time(nullptr);
    std::srand(seed);

    Window window;
    window.run();

    return 0;
}

catch (std::exception& ex)
{
    std::cerr << "Exception: " << ex.what() << '\n';
    return EXIT_FAILURE;
}
catch (...)
{
    std::cerr << "ERROR: Unknown exception\n";
    return EXIT_FAILURE;
}
