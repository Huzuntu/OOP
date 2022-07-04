//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Umut Tölek
//---Student Number: 150190724
//--------------------------//

#ifndef _H
#define _H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//-------------Do Not Add Any New Class(es)-------------//

class pokemon{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        int hpValue;
        int atkValue;
    public:
        pokemon() { // Default Constructor
            this->name = "";
            this->atkValue = 0;
            this->hpValue = 0;
        };
        pokemon(const string name, const int atkValue){ // Second Constructor
            this->name = name;
            this->atkValue = atkValue;
            this->hpValue = 100;
        };
        pokemon(const pokemon& copyPokemon){ // Copy Constructor
            this->name = copyPokemon.name;
            this->hpValue = copyPokemon.hpValue;
            this->atkValue = copyPokemon.atkValue;
        };
        string get_name() const { return this->name;}; // Name and atkValue does not change so I used const 
        int get_atkValue() const { return this->atkValue;}; 
        int get_hpValue() { return this->hpValue;}; // Since hp can change in a fight ---> No Const
        void set_hpValue(const int damage) { this->hpValue = this->hpValue - damage;};

};

class pokedex{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        pokemon pokedexArray[100];
        int value;
    public:
        pokedex() { this->value = 0;};
        bool isContains(const pokemon); // Checks for duplicates
        void updatePokedex(const pokemon newPokemon){ 
            if(!(isContains(newPokemon))){
                this->pokedexArray[this->value] = newPokemon;
                this->value = this->value + 1; // Updates this value so we can keep track of the position
            }
        };
        void printPokedex(){
            for(int i = 0; i < this->value; i++){
                cout << this->pokedexArray[i].get_name() << endl;
            }
        };
};

class player{
    private:
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
        string name;
        int pokemonNumber;
        int pokeballNumber;
        int badgeNumber;
        pokemon playerPokemon;
    public:
        pokedex playerPokedex;
        player() { // Default Constructor
            this->name = "";
            this->badgeNumber = 0;
            this->pokeballNumber = 10;
            this->pokemonNumber = 0;
        };
        player(const string newName , const pokemon &pokemon){  // Second Constructor
            this->name = newName;
            this->playerPokemon = pokemon;
            this->badgeNumber = 0;
            this->pokeballNumber = 10;
            this->pokemonNumber = 0;
        };
        int showPokemonNumber() { return this->pokemonNumber; };
        int showPokeballNumber() { return this->pokeballNumber; };;
        int showBadgeNumber() { return this->badgeNumber; };
        pokemon getPokemon() const { return this->playerPokemon; };
        void battleWon() {
            this->badgeNumber = this->badgeNumber + 1;
            this->pokeballNumber = this->pokeballNumber + 3;
        };
        void catchPokemon() {
            this->pokemonNumber = this->pokemonNumber + 1;
            this->pokeballNumber = this->pokeballNumber - 1;
        };
};

class enemy{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        pokemon enemyPokemon;
    public:
        enemy() {this->name = "";};
        enemy(const string name, const pokemon enemyPokemon) {
            this->name = name;
            this->enemyPokemon = enemyPokemon;
        };
        pokemon getPokemon() { return this->enemyPokemon;};
        string getName() const { return this->name;};
};

#endif