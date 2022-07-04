//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Umut Tölek
//---Student Number: 150190724
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;

bool pokedex::isContains(const pokemon newPokemon){ 
    if(this->value == 0){
        return false;
    }
    else{
        for(int i = 0; i < value; i++){
            if(pokedexArray[i].get_name() != newPokemon.get_name()){
                if(((i+1) == value) && (pokedexArray[value].get_name() == newPokemon.get_name())){
                    return true;
                }
                else if(((i+1) == value) && (pokedexArray[value].get_name() != newPokemon.get_name())){
                    return false;
                }
            }
            else{
                return true;
            }
        }
        return false;
    }
}
