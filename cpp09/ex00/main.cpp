#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        // Initialize the exchange with the database
        BitcoinExchange be("data.csv");
        // Process the input file
        be.processInput(argv[1]);
    } catch (const std::exception &e) {
        // If the database is missing or corrupt
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
