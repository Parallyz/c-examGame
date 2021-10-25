#include <string>
#include <list>
#include <algorithm>
#include <ctime>
#include "classes.h"

class PlayerManager
{
	std::list<Player> PlayerList;

public:
	void ShowPlayerInfo(int  id)
	{
		for (auto player : PlayerList)
		{
			if (player.GetId() == id)
			{
				std::cout
					<< "\tName: " << player.GetName()
					<< "\tRank: " << player.GetRank() << std::endl;
			}

		}
	}
	void  DeletePlayer(int  pos)
	{
		std::list<Player>::iterator iterator = PlayerList.begin();
		std::advance(iterator, pos);
		PlayerList.erase(iterator);
	}
	void  CreatePlayer(int  id, std::string name, int rank)
	{
		Player new_player(id, name, rank);
		PlayerList.push_back(new_player);
	}
	Player* GetPlayerByName(std::string name)
	{
		for (auto player : PlayerList)
		{
			if (player.GetName() == name)
				return &player;
		}
		return nullptr;
	}

	Player* GetPlayerById(int id)
	{
		for (auto player : PlayerList)
		{
			if (player.GetId() == id)
				return &player;
		}
		return nullptr;
	}
};


class HeroManager
{
	std::list<Hero> HeroList;

public:
	void ShowHeroInfo(int  id)
	{
		for (auto hero : HeroList)
		{
			if (hero.GetId() == id)
			{
				std::cout 
					<< "\tName: " << hero.GetName()
					<< "\tHP: " << hero.GetHP()
					<< "\tDamage: " << hero.GetDamage() << std::endl;
			}

		}
	}
	void  DeleteHero(int  pos)
	{
		std::list<Hero>::iterator iterator = HeroList.begin();
		std::advance(iterator, pos);
		HeroList.erase(iterator);
	}
	void  CreateHero(int  id, std::string name, int hp, int damage)
	{
		Hero new_hero(id, name, hp, damage);
		HeroList.push_back(new_hero);
	}
	Hero* GetHeroByName(std::string name)
	{
		for (auto hero : HeroList)
		{
			if (hero.GetName() == name)
				return &hero;
		}
		return nullptr;
	}

	Hero* GetHeroById(int id)
	{
		for (auto hero : HeroList)
		{
			if (hero.GetId() == id)
				return &hero;
		}
		return nullptr;
	}
};

class TeamManager {
	void GenerateNewTeam() {}
	void GetTeamInfo() {}
};

class Session {
	time_t StartTime;
	Team TeamOne;
	Team TeamTwo;
	Team Winner;
	void CalculateWinner() {}
};

class GameManager {
	std::list<Session> GameSessions;

	void PerformGameSession() {};
};