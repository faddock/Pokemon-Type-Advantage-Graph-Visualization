#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "type_mapper.h"

using namespace std;

class DataParser {
    public:
        /**
         * Constructor for the DataParser.
         * 
         * @param filename the name of the .csv file
         */ 
        DataParser(const std::string& filename);

        /**
         * Gets the name of the Pokemon given its Pokedex number. 
         * The Pokedex number starts at 1.
         * 
         * @param number the Pokedex number
         * 
         * @return the name of the Pokemon, or "N/A" if the number is invalid
         */
        std::string getPokemonName(int number);

        /**
         * Gets the 2 types that a Pokemon has. If the Pokemon only has 1 type, the
         * second type will be the same as the first type. The Pokedex number starts at 1.
         * 
         * @param number the Pokedex number
         * @return the types the Pokemon has, or an empty vector if the number is invalid
         */
        std::vector<std::string> getPokemonTypes(int number);

        /**
         * Gets the effectiveness of the type against the Pokemon. The Pokedex number
         * starts at 1, and the type must be valid.
         * 
         * @param number the Pokedex number
         * @param the type used against the Pokemon
         * 
         * @return a double value indicating type effectiveness, or -1 if 
         * the number of the type name is invalid
         */
        double getTypeEffectiveness(int number, std::string type);

        /**
         * A helper method that returns the .csv file as a 2D vector. This function
         * should only be used when testing.
         * 
         * @return a 2D vector that represents the data in the .csv file
         */
        std::vector<std::vector<std::string>> getGrid();

    private:
        std::vector<std::vector<std::string>> grid_;
        TypeMapper types_values_;
};