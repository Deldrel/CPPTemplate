#include "Libraries.h"
#include "Core.h"

int main() {

    try {
        Core core;
        assert(core.init());
        core.run();
    }
    catch (std::exception& e) {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
