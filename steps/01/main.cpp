#include <iostream>
#include <vector>
#include "interpolate.h"

int main(int argc, char* argv[]) {
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
