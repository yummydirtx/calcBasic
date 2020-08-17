#include <iostream>
#include <sstream>
#include "random.hpp"

// this program was written by Alex Frutkin in 2020

// it is a lot of fun to play around with
// it will generate random numbers until the number 1 is generated
// this takes a long time and it will print the number of attempts it took to find it
// the user can define the range of numbers to be chose from
// they can also define the number of times it should be repeated
// have fun!

// get base random alias which is auto seeded and has static API and internal state
using Random = effolkronium::random_static;

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    int numberOfLowest{1};
    int maxNumber{1000};
    long long int iterations{1000};
    long long int tries{0};
    long long int guess{0};
    long long int lowestNumber{100000000000000};
    if (argc == 3) {
        std::stringstream convert1{argv[1]};
        std::stringstream convert2{argv[2]};
        int first;
        convert1 >> first;
        int second;
        convert2 >> second;
        maxNumber = int(first);
        iterations = int(second);
    } else if (argc > 3) {
        std::cout << "Error: too many arguments" << '\n';
        std::cout << "Usage: calcbasic [Maximum number to generate] [Number of times to run]" << '\n';
        return 1;
    } else {
        std::cout << "Tip: to skip this beginning part use two parameters from the command line to define the max number and the number of iterations" << '\n';
        std::cout << "Example: calcBasic 100 10" << '\n';
        std::cout << "What should be the max number the random number generator should chose? ";
        std::cin >> maxNumber;
        std::cout << "The max number will be " << maxNumber << '\n';
        std::cout << "How many times should the computer try to guess? (more tries will yeild better attempt numbers but will take longer) ";
        std::cin >> iterations;
        std::cout << '\n';
    }
    for (int i{0}; i < iterations; i++) {
        guess = 0;
        tries = 0;
        while (!(guess == 1)) {
            guess = Random::get(0, maxNumber + 1);
            // uncomment this next line to show each guess, signifigant slowdown will occur however
            //std::cout << guess << std::endl;
            tries++;
        }
        std::cout << "This took " << tries << " tries!" << '\n';
        if (tries < lowestNumber) {
            lowestNumber = tries;
            numberOfLowest = 1;
        } else if (tries == lowestNumber) {
            numberOfLowest++;
        }
    }
    std::cout << "The lowest number of tries was " << lowestNumber << '\n';
    std::cout << "That number appeared in that many tries " << numberOfLowest;
    if (numberOfLowest == 1) {
        std::cout << " time." << '\n';
    } else {
        std::cout << " times." << '\n';
    }
    return 0;
}
