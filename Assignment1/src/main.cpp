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
#include <fstream>


#include "pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---// 
// 
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---// 
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);
    

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: "; 
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
  
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};

string* readEnemyNames(const char* argv){
    ifstream file_obj; //object to read file
    file_obj.open(argv,ifstream::in);
    if (!file_obj.is_open()) {
        file_obj.open(argv,ifstream::in);
        if (!file_obj.is_open()) {
            cerr << "Could not open the file" << endl;
            exit(1);
        }
    }
    string first_line;
    getline(file_obj, first_line);
    string* line = new string[stoi(first_line)];
    int line_number = 0;
    
    while(getline(file_obj, line[line_number])){                                                                                                                                              
        line_number++;    
    }
    file_obj.close();
    return line;
};

//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readPokemonNames(const char* argv){
    ifstream file_obj; //object to read file
    file_obj.open(argv,ifstream::in);
    if (!file_obj.is_open()) {
        file_obj.open(argv,ifstream::in);
        if (!file_obj.is_open()) {
            cerr << "Could not open the file" << endl;
            exit(1);
        }
    }
    string first_line;
    getline(file_obj, first_line);
    string* line = new string[stoi(first_line)];
    
    int line_number = 0;
    while(getline(file_obj, line[line_number])){                                                                                                                                              
        line_number++;    
    }
    file_obj.close();
    
    return line;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice){
    if (pokemonChoice == 1){
        pokemon newPokemon("Bulbasaur", PLAYER_POKEMON_ATTACK);
        player newPlayer = player(playerName, newPokemon);
        return newPlayer;
    }
    else if (pokemonChoice == 2){
        pokemon newPokemon("Charmender", PLAYER_POKEMON_ATTACK);
        player newPlayer = player(playerName, newPokemon);
        return newPlayer;
    }
    else{
        pokemon newPokemon("Squirtle", PLAYER_POKEMON_ATTACK);
        player newPlayer = player(playerName, newPokemon);
        return newPlayer;
    }
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){

    pokemon enemyPokemon(pokemonNames[POK_COUNTER], ENEMY_POKEMON_ATTACK);
    POK_COUNTER++;
    if(!(newPlayer->playerPokedex.isContains(enemyPokemon))){
        
        enemy enemyPlayer(enemyNames[NAME_COUNTER], enemyPokemon);
        NAME_COUNTER++;
        string enemyName = enemyPlayer.getName();
        string enemyPokemonName = enemyPlayer.getPokemon().get_name();
        
        pokemon playerPokemon = newPlayer->getPokemon();

        cout << "You encounter with " << enemyName << " and his/hers pokemon " << enemyPokemonName << endl; 
        cout << enemyPokemonName << " Health: " << enemyPokemon.get_hpValue() << " Attack: " << enemyPokemon.get_atkValue() << endl;
        cout << endl;
        newPlayer->playerPokedex.updatePokedex(enemyPokemon);
        

        bool fight_keeps_going = ((playerPokemon.get_hpValue() != 0) && (enemyPokemon.get_hpValue() != 0));
        while(fight_keeps_going){
            cout << "1- Fight" << endl;
            cout << "2- Runaway" << endl;
            int choice;
            cout << "Choice: "; 
            cin >> choice;
            switch(choice){
                case 1:
                    playerPokemon.set_hpValue(enemyPokemon.get_atkValue());
                    enemyPokemon.set_hpValue(playerPokemon.get_atkValue());
                    if(enemyPokemon.get_hpValue() == 0){
                        cout << "Your Pokemons Health: " << playerPokemon.get_hpValue() << endl;
                        cout << enemyName << " Pokemons Health: " << enemyPokemon.get_hpValue() << endl;
                        cout << "You Won!" << endl;
                        newPlayer->battleWon();
                        fight_keeps_going = false;
                        break;
                    }
                    else if(playerPokemon.get_hpValue() == 0){
                        cout << "You Lost!" << endl;
                        break;
                    }
                    else{
                        cout << "Your Pokemons Health: " << playerPokemon.get_hpValue() << endl;
                        cout << enemyName << " Pokemons Health: " << enemyPokemon.get_hpValue() << endl;
                        cout << endl;
                        break;
                    }
                case 2:
                    fight_keeps_going = false;
                    break;
            }
            
        }
    }
    else{
        cout << "You already encountered with " << enemyPokemon.get_name() << endl;
    }
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player* newPlayer, string* pokemonNames){
    
    pokemon newPokemon(pokemonNames[POK_COUNTER], ENEMY_POKEMON_ATTACK);
    POK_COUNTER++;
    if(!(newPlayer->playerPokedex.isContains(newPokemon))){
        
        newPlayer->playerPokedex.updatePokedex(newPokemon);
        cout << "You encounter with " << newPokemon.get_name() << " Health: " << newPokemon.get_hpValue() << " Attack: " << newPokemon.get_atkValue() << endl;

        cout << "1- Catch" << endl;
        cout << "2- Runaway" << endl;
        int choice;
        cout << "Choice: "; 
        cin >> choice;
        cout << choice << endl;
        switch(choice){
            case 1:
                cout << "You catch " << newPokemon.get_name() << endl;
                newPlayer->catchPokemon();
                break;
            case 2:
                break;
        } 
    }
    else{
        cout << "You already encountered with " << newPokemon.get_name() << endl;
    }
};
