//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Umut Tölek
//---Student Number: 150190724
//--------------------------//
#include <iostream>
#include "Robot.h"
using namespace std;
class Crew{
	private:
		int maxExplorers;
		int maxMiners;
		int crewManufactureCost;
		float crewMaintenanceCost;
		static int explorerCrewSize;
		static int minerCrewSize;
		static Explorer **ExplorerCrew;
		static Miner **MinerCrew;
	public:
		friend class CommandCenter;
		Crew(int crewMaxExplorer, int crewMaxMiner, int explorerCrewSizes, int minerCrewSizes){
			this->crewManufactureCost = 0;
			this->crewMaintenanceCost = 0;

			if(!((crewMaxExplorer >= 1) && (crewMaxExplorer <= 5))){ this->maxExplorers = 2; }
			else{ this->maxExplorers = crewMaxExplorer;	}

			if(!((crewMaxMiner >= 1) && (crewMaxMiner <= 5))){ this->maxMiners = 2; }
			else{ this->maxMiners = crewMaxMiner; }

			if(explorerCrewSizes > this->maxExplorers){ explorerCrewSize = this->maxExplorers; } 
			else if(explorerCrewSizes < 0){ explorerCrewSize = this->maxExplorers; }
			else {explorerCrewSize = explorerCrewSizes; };

			if(minerCrewSizes > this->maxMiners){ minerCrewSize = this->maxMiners; }
			else if(minerCrewSizes < 0){ minerCrewSize = this->maxMiners; }
			else {minerCrewSize = minerCrewSizes; };

			ExplorerCrew = new Explorer*[this->maxExplorers];
			MinerCrew = new Miner*[this->maxMiners];

			for(int m = 0; m < this->explorerCrewSize; m++){
				Explorer* returnExp = dynamic_cast<Explorer*>(manufactureRobot("explorer"));
				crewManufactureCost += returnExp->getManufactureCost();
				ExplorerCrew[m] = returnExp;
			}
			for(int i = 0 ; i < this->minerCrewSize; i++){
				Miner* returnMin = dynamic_cast<Miner*>(manufactureRobot("miner"));
				crewManufactureCost += returnMin->getManufactureCost();
				MinerCrew[i] = returnMin;
			}
		}
		Robot* manufactureRobot(string RobotType) {
			if(RobotType == "explorer"){
				int durability = 1 + (rand() % 5);
				float speed = 1.5 + (static_cast<float>(rand()) / RAND_MAX);  
				Explorer* newRobot = new Explorer(RobotType, speed, durability);
				newRobot->setCanMove(true);
				string name = "exp-" + to_string(Robot::getUnqID());
				Robot::incrementUnqID();
				newRobot->setRobotName(name);
				return newRobot;
			}
			else if(RobotType == "miner"){
				int durability = 1 + (rand() % 5);
				float speed = 1 + (static_cast<float>(rand()) / RAND_MAX) * (1.5 - 1);
				Miner* newRobot = new Miner(RobotType, speed, durability);
				newRobot->setCanMove(true);
				string name = "mnr-" + to_string(Robot::getUnqID());
				Robot::incrementUnqID();
				newRobot->setRobotName(name);
				return newRobot;
			}
			return NULL;
		};
		Robot* manufactureRobot();
		// -----------------------GETTERS --------------------------
		static Explorer** getExplorers() { return ExplorerCrew; };
		static Miner** getMiners() { return MinerCrew; };	
		static int getMinerCrewSize() { return minerCrewSize; };
		static int getExplorerCrewSize() { return explorerCrewSize; };
		float getCrewMaintenanceCost() const { return this->crewMaintenanceCost; };
		int	getCrewManufactureCost() const { return this->crewManufactureCost; };
		int getMaxExplorers() const { return this->maxExplorers; };

		//----------------------------------------------------------

		//------------------------SETTERS---------------------------
		void setCrewMaintenanceCost(float crewMaintenanceCost) { this->crewMaintenanceCost = crewMaintenanceCost; };
		void setCrewManufactureCost(int crewManufactureCost) { this->crewManufactureCost = crewManufactureCost; };

		void initMovement() { 
			for(int exp = 0; exp < this->getExplorerCrewSize(); exp++){
				getExplorers()[exp]->setCanMove(true);
			}
			for(int min = 0; min < this->getMinerCrewSize(); min++){
				getMiners()[min]->setCanMove(true);
			}
		};
		void updateDurability() {
			cout << "Explorer durability is being updated" << endl;
			for(int exp = 0; exp < explorerCrewSize; exp++){
				if(getExplorers()[exp]->getDurability() != 0){
					getExplorers()[exp]->setDurability(1);
					if(getExplorers()[exp]->getDurability() == 0){
						cout << getExplorers()[exp]->getName() << "'s durability=0" << endl;
						cout << getExplorers()[exp]->getName() << ": Goodbye" << endl;
						if(explorerCrewSize != 1){ 
							removeRobot(getExplorers()[exp]->getName());
						}	
					}
				}
			}
			cout << "Miner durability is being updated" << endl;
			for(int mnr = 0; mnr < minerCrewSize; mnr++){
				if(getMiners()[mnr]->getDurability() != 0){
					getMiners()[mnr]->setDurability(1);
					if(getMiners()[mnr]->getDurability() == 0){
						cout << getMiners()[mnr]->getName() << "'s durability=0" << endl;
						cout << getMiners()[mnr]->getName() << ": Goodbye" << endl;
						if(minerCrewSize != 1){ 
							removeRobot(getMiners()[mnr]->getName());
						}	
					}
				}
			}
		}
		
		Crew& operator+=(const Robot *copyRobot) {
			if(copyRobot != NULL){
				if(copyRobot->getRobotType() == "explorer"){
					Explorer *tempE = new Explorer(copyRobot->getRobotType(), copyRobot->getSpeed(), copyRobot->getDurability());
					tempE->setRobotName(copyRobot->getName());
					ExplorerCrew[getExplorerCrewSize()] = tempE;
					explorerCrewSize++;
				}
				else if(copyRobot->getRobotType() == "miner"){
					Miner *tempM = new Miner(copyRobot->getRobotType(), copyRobot->getSpeed(), copyRobot->getDurability());
					tempM->setRobotName(copyRobot->getName());
					MinerCrew[getMinerCrewSize()] = tempM;
					minerCrewSize++;
				}	
			}
			delete copyRobot;
			return *this;
		}
		
		void removeRobot(const string RobotName){
			if(RobotName[0] == 'e'){
				if(this->explorerCrewSize != 1){
					for(int i = 0; i < explorerCrewSize; i++){
						if(ExplorerCrew[i]->getName() == RobotName){
							delete ExplorerCrew[i];
							if(i == 0){
								for(int k = 0; k < maxExplorers; k++){
									ExplorerCrew[k] = ExplorerCrew[k+1];
								}
							}
							explorerCrewSize--;
						}
					}
				}
			}
			else if(RobotName[0] == 'm'){
				if(this->minerCrewSize != 1){
					for(int m = 0; m < minerCrewSize; m++){
						if(MinerCrew[m]->getName() == RobotName){
							delete MinerCrew[m];
							if(m == 0){
								for(int k = 0; k < maxMiners; k++){
									MinerCrew[k] = MinerCrew[k+1];
								}
							}
							minerCrewSize--;
						}
					}
				}
			}
		}
		Crew& operator-=(const string RobotName) {
			cout << RobotName << ": Goodbye" << endl;
			removeRobot(RobotName);
			return *this;
		}

		void showInfo() {
			cout << "explorerCrew Size:" << explorerCrewSize << endl;
			cout << "minerCrew Size:" << minerCrewSize << endl;
			
			for(int i = 0; i < explorerCrewSize + 1; i++){
				if(ExplorerCrew[i] != NULL){
					(ExplorerCrew[i])->showInfo();
				}	
			}
			for(int m = 0; m < minerCrewSize + 1; m++){
				if(MinerCrew[m] != NULL){
					(MinerCrew[m])->showInfo();
				}
			}
			
			cout << "Total manufacture cost: " << crewManufactureCost << endl;
			cout << "Total maintenance cost: " << crewMaintenanceCost << endl;
		}
};

class CommandCenter{
	private:
		int neededSelenium;
		float searchArea;
		int seleniumWorth;
		int turnCount;
		float totalCrewMaintenanceCost;
		float profit;
	public:
		CommandCenter() {
			this->neededSelenium = 0;
			this->searchArea = 0;
			this->seleniumWorth = 30;
			this->turnCount = 1;
			this->totalCrewMaintenanceCost = 0;
			this->profit = 0;
		}; 
		CommandCenter(int neededSelenium, float searchArea, int seleniumWorth)
			: neededSelenium(neededSelenium), searchArea(searchArea), seleniumWorth(seleniumWorth)
		{
			this->turnCount = 1;
			this->totalCrewMaintenanceCost = 0;
			this->profit = 0;
		}
		
		

		bool isGameEnded(){
			if(Explorer::totalExploredArea >= searchArea){
				cout << "Area has been fully explored." << endl;
				cout << "Aim: " << neededSelenium << " selenium." << endl;
				cout << "Collected: " << Miner::totalGatheredSelenium << endl;
				if(Miner::totalGatheredSelenium >= neededSelenium){
					cout << "Congrats!" << endl;
				}
				else{
					cout << "Mission Failed!" << endl;
				}
				for(int i = 0; i < Crew::explorerCrewSize; i++){
					delete Crew::ExplorerCrew[i];
				}
				for(int m = 0; m < Crew::minerCrewSize; m++){
					delete Crew::MinerCrew[m];
				}
			
				delete[] Crew::ExplorerCrew;
				delete[] Crew::MinerCrew;
				return true;
			}
			else{
				return false;
			}
		};

		void setProfit(float profit) { this->profit = profit; };
		float getProfit() const { return this->profit; };

		
		CommandCenter operator++() {
			CommandCenter temp;
			temp = *this;
			turnCount++;
			return temp;
		}
		
		
		void calculateProfit(Crew Crew){
			float sellSelenium = Miner::totalGatheredSelenium * seleniumWorth;
			float expenses = Crew.getCrewMaintenanceCost() + Crew.getCrewManufactureCost();
			setProfit(sellSelenium - expenses);
			cout << "Profit:" << this->profit << endl;
			cout << "Expenses:" << expenses << endl;
			cout << "Selenium Revenue:" << sellSelenium << endl;
		};

		void showInfo() {
			int exploredAreas = Explorer::totalExploredArea;
			int totalNumberOfSeleniumAreas = Explorer::totalNumberOfSeleniumArea;
			int collectedSelenium = Miner::totalGatheredSelenium;
			cout << "Current turn: " << turnCount << endl;
			cout << "Aim: " << neededSelenium << " selenium." << endl;
			cout << "Collected: " << collectedSelenium << endl;
			cout << "Total Search Area: " << searchArea << endl;
			cout << "Explored Area: " << exploredAreas << endl;
			cout << "Currently, there are " << totalNumberOfSeleniumAreas
				<< " area/s that include selenium." << endl; 
			if(totalNumberOfSeleniumAreas > 0){
				cout << "Mine these areas if miners have not finished their turn! If you cannot cope with mining, you can always add new miners!" << endl;
			}
			
		}
};



