//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Umut Tölek
//---Student Number: 150190724
//--------------------------//
#include <iostream>
#ifndef _H
#define _H
using namespace std;
class Robot {
	private:
		friend class CommandCenter;
		friend class Explorer;
		friend class Miner;
		static int unqID;
		string RobotName;
		string RobotType;
		float speed; 
		int durability; 
		int manufactureCost; 
		float maintenanceCost;
		bool canMove;
	
	public:
		Robot(string RobotType, float speed, int durability, int manufactureCost, float maintenanceCost) 
			: RobotType(RobotType), speed(speed), durability(durability)
			, manufactureCost(manufactureCost), maintenanceCost(maintenanceCost)
		{
			this->canMove = false;
		}
		
		virtual ~Robot() {};
		// -----------------------GETTERS --------------------------
		string getRobotType() const  { return this->RobotType; };
		float getSpeed() const { return this->speed; }; 
		int getDurability() const { return this->durability; }; 
		int getManufactureCost() const { return this->manufactureCost; }; 
		float getMaintenanceCost() const { return this->maintenanceCost; };
		string getName() const { return this->RobotName; };
		static int getUnqID() { return unqID; };
		//----------------------------------------------------------

		//------------------------SETTERS---------------------------
		void setRobotName(string name) { this->RobotName = name; };
		static void incrementUnqID() { unqID += 1; };
		void setCanMove(bool expression){ this->canMove = expression; };
		void setDurability(int newDurability) { this->durability -= newDurability; };
		//----------------------------------------------------------

		Robot &operator=(const Robot &copyRobot){
				this->RobotName = copyRobot.RobotName;
				this->RobotType = copyRobot.RobotType;
				this->speed = copyRobot.speed;
				this->durability = copyRobot.durability;
				this->manufactureCost = copyRobot.manufactureCost;
				this->maintenanceCost = copyRobot.maintenanceCost;
				return *this;
		}
		
		void showInfo() {
			cout << "Name: " << this->RobotName << endl;
			cout << "Type: " << this->RobotType << endl;
			cout << "Speed: " << this->speed << endl;
			cout << "Durability: " << this->durability << endl;
			cout << "ManufactureCost: " << this->manufactureCost << endl;
			cout << "MaintenanceCost: " << this->maintenanceCost << endl;
			cout << "Can Move: " << this->canMove << endl;	
		};
}; 

class Explorer : public Robot{
	private:
		friend class CommandCenter;
		friend class Miner;
		static float totalExploredArea;
		static int totalNumberOfSeleniumArea;
		float exploredArea;
		bool detectedSelenium;
		
	public:
		Explorer(string RobotType, float speed, int durability) 
			: Robot(RobotType, speed, durability, 3000, (450/speed))
		{
			exploredArea = 0;
		}
		
		bool move(){
			return this->canMove;
		};

		void explore() {
			int rand_Number = rand() % 101;
			totalExploredArea += 1500;
			this->exploredArea = 1500;
			if(rand_Number >= 40){
				detectedSelenium = true;
				totalNumberOfSeleniumArea += 1;
			}
			else{
				detectedSelenium = false;
			}
		};
		
		Explorer &operator=(const Explorer &copyExplorer){
				this->RobotName = copyExplorer.RobotName;
				this->RobotType = copyExplorer.RobotType;
				this->speed = copyExplorer.speed;
				this->durability = copyExplorer.durability;
				this->manufactureCost = copyExplorer.manufactureCost;
				this->maintenanceCost = copyExplorer.maintenanceCost;
				this->detectedSelenium = copyExplorer.detectedSelenium;
				this->totalExploredArea = copyExplorer.totalExploredArea;
				this->totalNumberOfSeleniumArea = copyExplorer.totalNumberOfSeleniumArea;
				this->exploredArea = copyExplorer.exploredArea;
				return *this;
		}

		void showInfo() {
			Robot::showInfo();
			cout << "explored area: " << this->exploredArea << endl;
		};
		
		
};

class Miner : public Robot{
	private:
		friend class CommandCenter;
		static int totalGatheredSelenium;
		int gatheredSelenium;
	public:
		
		Miner(string RobotType, float speed, int durability)
			: Robot(RobotType, speed, durability, 5000, (750/speed))
		{

		};
		
		void mine() {
			int random_selenium = (int)(rand() % 91 + 10) * 5;
			setGatheredSelenium(random_selenium);
			totalGatheredSelenium += random_selenium ;

			if(Explorer::totalNumberOfSeleniumArea > 0){
				Explorer::totalNumberOfSeleniumArea--;
			}

		};
		bool move() { 
			if((Explorer::totalNumberOfSeleniumArea > 0) && (this->canMove)){
				return true;
			}
			else{
				return false;
			}
		};
		void setGatheredSelenium(int gatheredSelenium) { this->gatheredSelenium = gatheredSelenium; };
		
		Miner &operator=(const Miner &copyMiner) 
			{
				this->RobotName = copyMiner.RobotName;
				this->RobotType = copyMiner.RobotType;
				this->speed = copyMiner.speed;
				this->durability = copyMiner.durability;
				this->manufactureCost = copyMiner.manufactureCost;
				this->maintenanceCost = copyMiner.maintenanceCost;
				this->gatheredSelenium = copyMiner.gatheredSelenium;
				this->totalGatheredSelenium = copyMiner.totalGatheredSelenium;
				return *this;
		}

		void showInfo(){
			Robot::showInfo();
			cout << "# of gathered selenium: " << gatheredSelenium << endl; 
		}
};


#endif