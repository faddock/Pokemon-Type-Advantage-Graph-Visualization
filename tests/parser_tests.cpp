#include "../cs225/catch/catch.hpp"
#include "../graphUtil/data_parser.h"

#include <iostream>

TEST_CASE("Get correct number of rows and columns in the .csv file", "[parser]") {
    DataParser parser = DataParser("data/pokemon.csv");
    std::vector<std::vector<std::string>> grid = parser.getGrid();
    
    // Check the number of rows
    REQUIRE(grid.size() == 802);

    // Check the number of columns in each row
    for (size_t i = 0; i < grid.size(); i++) {
        REQUIRE(grid[i].size() == 41);
    }
}

TEST_CASE("Test specific values within the grid", "[parser]") {
    DataParser parser = DataParser("data/pokemon.csv");
    std::vector<std::vector<std::string>> grid = parser.getGrid();
    
    // Gets the category name
    REQUIRE(grid[0][3] == "against_dragon");

    // Remember that the first index is the actual Pokemon number
    REQUIRE(grid[801][0] == "['Soul-Heart']");

    // Abilities of Bulbasaur, Ivysaur, and Venosaur
    REQUIRE(grid[1][0] == "\"['Overgrow', 'Chlorophyll']\"");
    REQUIRE(grid[2][0] == "\"['Overgrow', 'Chlorophyll']\"");
    REQUIRE(grid[3][0] == "\"['Overgrow', 'Chlorophyll']\"");

    // Abilities of Pidgey, Pidgeotto, and Pidgeot
    REQUIRE(grid[16][0] == "\"['Keen Eye', 'Tangled Feet', 'Big Pecks']\"");
    REQUIRE(grid[17][0] == "\"['Keen Eye', 'Tangled Feet', 'Big Pecks']\"");
    REQUIRE(grid[18][0] == "\"['Keen Eye', 'Tangled Feet', 'Big Pecks']\"");

    // Abilities of Rattata and Ratticate
    REQUIRE(grid[19][0] == "\"['Run Away', 'Guts', 'Hustle', 'Gluttony', 'Hustle', 'Thick Fat']\"");
    REQUIRE(grid[20][0] == "\"['Run Away', 'Guts', 'Hustle', 'Gluttony', 'Hustle', 'Thick Fat']\"");
}

TEST_CASE("Get Pokemon names using their Pokedex number", "[parser]") {
    DataParser parser = DataParser("data/pokemon.csv");
    std::vector<std::vector<std::string>> grid = parser.getGrid();
    
    // Test 1st generation Pokemon
    REQUIRE(parser.getPokemonName(1) == "Bulbasaur");
    REQUIRE(parser.getPokemonName(25) == "Pikachu");
    REQUIRE(parser.getPokemonName(150) == "Mewtwo");

    // Test 5th generation Pokemon
    REQUIRE(parser.getPokemonName(643) == "Reshiram");
    REQUIRE(parser.getPokemonName(644) == "Zekrom");

    // Test invalid Pokedex numbers
    REQUIRE(parser.getPokemonName(-400) == "N/A");
    REQUIRE(parser.getPokemonName(1000) == "N/A");
}

TEST_CASE("Get the Pokemon types using a Pokemon's Pokedex number", "[parser]") {
    DataParser parser = DataParser("data/pokemon.csv");
    std::vector<std::vector<std::string>> grid = parser.getGrid();
    
    std::vector<std::string> types;

    // Bulbasaur: Primary -> Grass, Secondary -> Poison
    types = parser.getPokemonTypes(1);
    REQUIRE(types[0] == "grass");
    REQUIRE(types[1] == "poison");

    // Pikachu: Primary -> Electric, Secondary -> Electric
    types = parser.getPokemonTypes(25);
    REQUIRE(types[0] == "electric");
    REQUIRE(types[1] == "electric");

    // Mewtwo: Primary -> Psychic, Secondary -> Psychic
    types = parser.getPokemonTypes(150);
    REQUIRE(types[0] == "psychic");
    REQUIRE(types[1] == "psychic");

    // Reshiram: Primary -> Dragon, Secondary -> Fire
    types = parser.getPokemonTypes(643);
    REQUIRE(types[0] == "dragon");
    REQUIRE(types[1] == "fire");

    // Test invalid Pokedex numbers
    types = parser.getPokemonTypes(-123);
    types = parser.getPokemonTypes(803);
}

TEST_CASE("Get correct type effectiveness against a Pokemon", "[parser]") {
    DataParser parser = DataParser("data/pokemon.csv");
    std::vector<std::vector<std::string>> grid = parser.getGrid();
    
    // Grass should be 0.25x effective against Bulbasaur
    REQUIRE(parser.getTypeEffectiveness(1, "grass") == 0.25);

    // Ground should be 2x effective against Pikachu, and steel should be 0.5x effective
    REQUIRE(parser.getTypeEffectiveness(25, "ground") == 2);
    REQUIRE(parser.getTypeEffectiveness(25, "steel") == 0.5);

    // Dark should be 2x effective against MewTwo, and normal should be 1x effective
    REQUIRE(parser.getTypeEffectiveness(150, "dark") == 2);
    REQUIRE(parser.getTypeEffectiveness(150, "normal") == 1);

    // Test invalid type inputs
    REQUIRE(parser.getTypeEffectiveness(1, "") == -1);
    REQUIRE(parser.getTypeEffectiveness(150, "asdf") == -1);

    // Test invalid Pokedex numbers
    REQUIRE(parser.getTypeEffectiveness(0, "grass") == -1);
    REQUIRE(parser.getTypeEffectiveness(1002, "psychic") == -1);

}