#include "../cs225/catch/catch.hpp"
#include "../graphUtil/type_mapper.h"

TEST_CASE("Values stored correctly", "[mapper]") {

    TypeMapper tm;
    string types[18] = {
        "bug", "dark", "dragon", 
        "electric", "fairy", "fighting", 
        "fire", "flying", "ghost", 
        "grass", "ground", "ice", 
        "normal", "poison", "psychic", 
        "rock", "steel", "water"
    };

    SECTION("typeToIndex works correctly") {
        for(int i = 0; i < 18; i++) {
            REQUIRE(tm.typeToIndex(types[i]) == i+1);
        }
    }

    SECTION("indexToType works correctly") {
        for(int i = 0; i < 18; i++) {
            REQUIRE(tm.indexToType(i) == types[i]);
        }
    }

}