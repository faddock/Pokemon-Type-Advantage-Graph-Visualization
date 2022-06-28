#include "type_mapper.h"

// Sets up the map from type effectiveness to row index
TypeMapper::TypeMapper():typeToIndex_() {
    typeToIndex_.insert(std::pair<std::string, int>("bug", 1));
    typeToIndex_.insert(std::pair<std::string, int>("dark", 2));
    typeToIndex_.insert(std::pair<std::string, int>("dragon", 3));
    typeToIndex_.insert(std::pair<std::string, int>("electric", 4));
    typeToIndex_.insert(std::pair<std::string, int>("fairy", 5));
    typeToIndex_.insert(std::pair<std::string, int>("fighting", 6));
    typeToIndex_.insert(std::pair<std::string, int>("fire", 7));
    typeToIndex_.insert(std::pair<std::string, int>("flying", 8));
    typeToIndex_.insert(std::pair<std::string, int>("ghost", 9));
    typeToIndex_.insert(std::pair<std::string, int>("grass", 10));
    typeToIndex_.insert(std::pair<std::string, int>("ground", 11));
    typeToIndex_.insert(std::pair<std::string, int>("ice", 12));
    typeToIndex_.insert(std::pair<std::string, int>("normal", 13));
    typeToIndex_.insert(std::pair<std::string, int>("poison", 14));
    typeToIndex_.insert(std::pair<std::string, int>("psychic", 15));
    typeToIndex_.insert(std::pair<std::string, int>("rock", 16));
    typeToIndex_.insert(std::pair<std::string, int>("steel", 17));
    typeToIndex_.insert(std::pair<std::string, int>("water", 18));
}

int TypeMapper::typeToIndex(string type) {
    return typeToIndex_.at(type);
}

string TypeMapper::indexToType(int i) {
    return indexToType_[i];
}
        
std::map<std::string, int>::iterator TypeMapper::end() {
    return typeToIndex_.end();
}

std::map<std::string, int>::iterator TypeMapper::find(string type) {
    return typeToIndex_.find(type);
}