#include <iostream>
#include "random.hpp"
 
// get base random alias which is auto seeded and has static API and internal state
using Random = effolkronium::random_static;

int main() {
    int maxNumber{1000};
    int tries{0};
    long long int guess{0};
    int lowestNumber{100000000};
    for (int i{0}; i < 1000; i++) {
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
