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
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    // 2. Skip the header line ("date | value")
    if (!std::getline(file, line))
        return;

    // 3. Process each line
    while (std::getline(file, line)) {
        size_t sep = line.find(" | ");

        // Error: No separator found
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string valStr = line.substr(sep + 3);

        // 4. Validate Date
        if (!_isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        // 5. Validate Value
        // Check if valStr is empty or contains non-numeric garbage
        char* endPtr;
        float val = std::strtof(valStr.c_str(), &endPtr);

        if (*endPtr != '\0' && !isspace(*endPtr)) {
            std::cerr << "Error: bad input => " << valStr << std::endl;
            continue;
        }
        if (val < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (val > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // 6. Find the Exchange Rate in the Map
        // lower_bound returns the first element NOT LESS than 'date'
        std::map<std::string, float>::iterator it = _data.lower_bound(date);

        if (it != _data.end() && it->first == date) {
            // Case A: Exact match found
            std::cout << date << " => " << val << " = " << val * it->second << std::endl;
        }
        else if (it == _data.begin()) {
            // Case B: Date is earlier than our very first database entry.
            // Since there is no "lower date", we cannot perform the calculation.
            std::cerr << "Error: bad input => " << date << std::endl;
        }
        else {
            // Case C: Exact match not found, but a lower date exists.
            // We move the iterator back one position to get the closest past date.
            --it;
            std::cout << date << " => " << val << " = " << val * it->second << std::endl;
        }
    }
}
