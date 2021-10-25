#include <string>

class Player {

	int Id;
	std::string Name;
	int Rank;

public:

	int GetId() { return Id; }
	std::string GetName() { return Name; }
	int GetRank() { return Rank; }

	Player(int id,std::string name,int rank)
		:Id(id),Name(name),Rank(rank){}
	Player() {}
};

class Hero {

	int Id;
	std::string Name;
	int HP;
	int Damage;

public:

	int GetId() { return Id; }
	std::string GetName() { return Name; }
	int GetHP() { return HP; }
	int GetDamage() { return Damage; }

	int setHP(int hp) { this->HP = hp; }



	Hero(int id, std::string name, int hp,int damage) 
		:Id(id), Name(name), HP(hp),Damage(damage) {}
	Hero() {}
};



class Team {

public:
	std::string Name;
	Hero HeroList [5];
	Player PlayerList[5];
	Team(std::string name):Name(name) {}
	Team(){}
};