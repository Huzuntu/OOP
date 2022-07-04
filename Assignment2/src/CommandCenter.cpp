//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Umut Tölek
//---Student Number: 150190724
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------//
#include "CommandCenter.h"
#include "Robot.h"
#include <iostream>
using namespace std;
/*
****************
BEGIN: CREW CLASS FUNCTION DECLARATIONS 
****************
*/

Robot* Crew::manufactureRobot(){
    string RobotType;
    cout << "Type:" << endl;
    cin >> RobotType;
    
    if(RobotType == "explorer"){
        int durability = 1 + (rand() % 5);
        float speed = 1.5 + (static_cast<float>(rand()) / RAND_MAX);  
        Explorer* newRobot = new Explorer(RobotType, speed, durability);
        string name = "exp-" + to_string(Robot::getUnqID());
        newRobot->setRobotName(name);
        Robot::incrementUnqID();
        if(!(explorerCrewSize + 1 > maxExplorers)){
            crewManufactureCost += newRobot->getManufactureCost();
            return newRobot;
        }
        else{
            delete newRobot;
            cout << "This robot cannot be added, check maximum size of the crew" << endl;
        }
    }
    else if(RobotType == "miner"){
        int durability = 1 + (rand() % 5);
        float speed = 1 + (static_cast<float>(rand()) / RAND_MAX) * (1.5 - 1);
        Miner* newRobot = new Miner(RobotType, speed, durability);
        string name = "mnr-" + to_string(Robot::getUnqID());
        newRobot->setRobotName(name);
        Robot::incrementUnqID();
        if(!(minerCrewSize + 1 > maxMiners)){
            crewManufactureCost += newRobot->getManufactureCost();
            return newRobot;
        }
        else{
            delete newRobot;
            cout << "This robot cannot be added, check maximum size of the crew" << endl;
        }

    }
    else{
        cout << "You have entered wrong type of Robot" << endl;
    }
    return NULL;
}



/*
****************
END: CREW CLASS FUNCTION DECLARATIONS 
****************
*/
Miner** Crew::MinerCrew;
Explorer** Crew::ExplorerCrew;
int Crew::explorerCrewSize;
int Crew::minerCrewSize;
/*
****************
BEGIN: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/
//float CommandCenter::searchArea;
/*
****************
END: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/