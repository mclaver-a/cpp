#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, float> _data;
    bool _isValidDate(const std::string& date);
    bool _isValidValue(const std::string& valStr, float& value);

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& dbPath);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void processInput(const std::string& inputPath);
};

#endif
