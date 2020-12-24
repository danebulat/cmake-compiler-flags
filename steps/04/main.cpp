#include <iostream>
#include <vector>
#include "interpolate.h"

#include "config.h"

#ifdef OUTPUT_COMPILER_INFO
void output_compiler_info() {
    std::cout << "Compiler name: " << COMPILER_NAME << std::endl;
    std::cout << "Compiler ID: " << COMPILER_ID << std::endl;
    std::cout << "Compiler version: " << COMPILER_VERSION << std::endl;
    std::cout << "GCC compiler: " << COMPILER_IS_GNU << std::endl;
    std::cout << std::endl;
}
#endif

int main(int argc, char* argv[]) {
#ifdef OUTPUT_COMPILER_INFO
    output_compiler_info();
#endif

#ifdef NDEBUG
    std::cout << "NDEBUG Defined (Release)"
              << std::endl << std::endl;
#else
    std::cout << "NDEBUG Not Defined (Debug)"
              << std::endl << std::endl;
#endif

    std::cout << "Begin..." << std::endl;
    
    std::vector<float> results;
    float r1 = animation::easeInSine(0.0f, 1.0f, 9.0f, 10.0f);
    float r2 = animation::easeOutExpo(0.0f, 1.0f, 9.0f, 10.0f);
    float r3 = animation::linear(0.0f, 1.0f, 9.0f, 10.0f);
    
    results.push_back(r1);
    results.push_back(r2);
    results.push_back(r3);
    
    for (int i=0; i<3; ++i) {
        std::cout << "Result " << i << ": " << results.at(i) << std::endl;
    }

    std::cout << "Finished..." << std::endl;

    return 0;
}
