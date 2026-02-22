#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
    // 1. Exact error message from subject
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        // 2. Initialize the exchange with the database
        BitcoinExchange be("data.csv");
        
        // 3. Process the input file
        be.processInput(argv[1]);
    } catch (const std::exception &e) {
        // If the database is missing or corrupt
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
