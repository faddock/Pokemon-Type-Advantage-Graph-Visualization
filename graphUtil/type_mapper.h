#pragma once

#include <map>
#include <string>

using std::iterator;
using std::string;
using std::map;

class TypeMapper{
    public:
        /**
         * Constructor for type mapping
         * 
         */
        TypeMapper();

        /**
         * Takes a type and finds its index
         * 
         * @param type the string representation of the type
         * @return index of the type passed in
         */
        int typeToIndex(string type);

        /**
         * Takes an index and finds its associated type
         * 
         * @param i the integer representation of the type
         * @return string of the type passed in
         */
        string indexToType(int i);

        /**
         * Finds the end of the map
         * 
         * @return map<string, int>::iterator of the map storing the values
         */
        map<string, int>::iterator end();

        /**
         * Finds a given type in the map
         * 
         * @param type the string representation of the type 
         * @return map<string, int>::iterator for the specified type
         */
        map<string, int>::iterator find(string type);

    private:
        map<string, int> typeToIndex_;

        string indexToType_[18] = {
            "bug", "dark", "dragon", 
            "electric", "fairy", "fighting", 
            "fire", "flying", "ghost", 
            "grass", "ground", "ice", 
            "normal", "poison", "psychic", 
            "rock", "steel", "water"
        };
};