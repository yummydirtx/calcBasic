#include <iostream>
#include <sstream>
#include "random.hpp"
 
// get base random alias which is auto seeded and has static API and internal state
using Random = effolkronium::random_static;

int main(int argc, char *argv[]) {
    int maxNumber{1000};
    int iterations{1000};
    int tries{0};
    long long int guess{0};
    int lowestNumber{100000000};
    if (argc == 3) {
        std::stringstream convert1{argv[1]};
        std::stringstream convert2{argv[2]};
        int first;
        convert1 >> first;
        int second;
        convert2 >> second;
        maxNumber = int(first);
        iterations = int(second);
    } else {
        std::cout << "Tip: to skip this beginning part use two parameters from the command line to define the max number and the number of iterations" << '\n';
        std::cout << "Example: calcBasic 100 10" << '\n';
        std::cout << "What should be the max number the random number generator should chose? ";
        std::cin >> maxNumber;
        std::cout << '\n' << "";
    }
    for (int i{0}; i < iterations; i++) {
        guess = 0;
        tries = 0;
        while (!(guess == maxNumber)) {
            guess = Random::get(0, maxNumber + 1);
            std::cout << guess << std::endl;
            tries++;
        }
        std::cout << "This took " << tries << " tries!" << '\n';
        if (tries < lowestNumber) {
            lowestNumber = tries;
        }
    }
    std::cout << "The lowest number of tries was " << lowestNumber << '\n';
    return 0;
}