#include "data_parser.h"

DataParser::DataParser(const std::string& filename): types_values_() {
    // Pushes all of the data into a 2D vector
    std::ifstream wordsFile(filename);
    std::string line;
    if (wordsFile.is_open()) {
        while (getline(wordsFile, line)) {
            // // This prints out the entire line
            // std::cout << line << std::endl;

            std::vector<string> tempVector;
            std::string tempString = "";
            size_t commaIndex = 0;
            while (!line.empty()) {
                commaIndex = line.find(',');
                if (commaIndex != string::npos && line.at(commaIndex + 1) != ' ') { // This deals the categories in the string
                    tempString += line.substr(0, commaIndex);
                    line = line.substr(commaIndex + 1, line.size());
                    tempVector.push_back(tempString);

                    // Reset the current string
                    tempString = "";
                }
                else if (!line.empty() && commaIndex == string::npos) { // This deals with the last category in the string
                    tempString = line;
                    tempVector.push_back(tempString);

                    // Clear the line so the while-loop stops, and reset the current string
                    line = "";
                    tempString = "";
                }
                else { // This deals with commas that may appear within a category
                    tempString += line.substr(0, commaIndex);
                    tempString += ",";
                    line = line.substr(commaIndex + 1, line.size());
                }
            }
            grid_.push_back(tempVector);
        }
    }
}

std::string DataParser::getPokemonName(int number) {
    if (number < 1 || size_t(number) > grid_.size()) { // If the index is out of bounds, say so and segfault
        std::cout << "The Pokedex entry is out of bounds!" << std::endl;
        return "N/A";
    }
    return grid_[number][30];
}

std::vector<std::string> DataParser::getPokemonTypes(int number) {
    std::vector<std::string> types;
    if (number < 1 || size_t(number) > grid_.size()) { // If the index is out of bounds, say so and segfault
        std::cout << "The Pokedex entry is out of bounds!" << std::endl;
        return types;
    }
    
    types.push_back(grid_[number][36]);
    if (!grid_[number][37].empty()) {
        types.push_back(grid_[number][37]);
    }
    else {
        types.push_back(grid_[number][36]); // Push back the type again if the Pokemon only has 1 type
    }
    return types;
}

double DataParser::getTypeEffectiveness(int number, std::string type) {
    std::map<std::string, int>::iterator itr = types_values_.find(type);
    if (itr == types_values_.end()) {
        std::cout << "The type is not valid!" << std::endl;
        return -1;
    }
    else if (number < 1 || size_t(number) > grid_.size()) {
        std::cout << "The Pokedex entry is out of bounds!" << std::endl;
        return -1;
    }

    return std::stod(grid_[number][types_values_.typeToIndex(type)]);
}

std::vector<std::vector<std::string>> DataParser::getGrid() {
    return grid_;
}