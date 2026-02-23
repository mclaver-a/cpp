#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbPath) {
    std::ifstream file(dbPath.c_str());
    if (!file.is_open()) throw std::runtime_error("could not open database.");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t sep = line.find(',');
        if (sep != std::string::npos) {
            _data[line.substr(0, sep)] = (float)std::atof(line.substr(sep + 1).c_str());
        }
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) this->_data = other._data;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::_isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;
    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());
    if (y < 2008 || m < 1 || m > 12 || d < 1 || d > 31) return false;
    if (m == 2) {
        bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        if (d > (leap ? 29 : 28)) return false;
    }
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
    return true;
}

void BitcoinExchange::processInput(const std::string& inputPath) {
    std::ifstream file(inputPath.c_str());
    if (!file.is_open()) { std::cerr << "Error: could not open file." << std::endl; return; }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t sep = line.find(" | ");
        if (sep == std::string::npos) { std::cerr << "Error: bad input => " << line << std::endl; continue; }
        std::string date = line.substr(0, sep);
        std::string valStr = line.substr(sep + 3);
        if (!_isValidDate(date)) { std::cerr << "Error: bad input => " << date << std::endl; continue; }
        float val = (float)std::atof(valStr.c_str());
        if (val < 0) std::cerr << "Error: not a positive number." << std::endl;
        else if (val > 1000) std::cerr << "Error: too large a number." << std::endl;
        else {
            std::map<std::string, float>::iterator it = _data.lower_bound(date);
            if (it != _data.begin() && it->first != date) --it;
            std::cout << date << " => " << valStr << " = " << val * it->second << std::endl;
        }
    }
}
