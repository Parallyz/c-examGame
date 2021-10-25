#include <string>
#include <list>
#include <algorithm>
#include <ctime>
#include "classes.h"

 static  class PlayerManager
{
	static std::list<Player> PlayerList;

public:
	void  ShowPlayerInfo(Player  player)
	{

		std::cout
			<< "\tName: " << player.GetName()
			<< "\tRank: " << player.GetRank() << std::endl;

	}
	void  DeletePlayer(int  pos)
	{
		std::list<Player>::iterator iterator = PlayerList.begin();
		std::advance(iterator, pos);
		PlayerList.erase(iterator);
	}
	Player  CreatePlayer(int  id, std::string name, int rank)
	{
		Player new_player(id, name, rank);
		PlayerList.push_back(new_player);
		return new_player;
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


static class HeroManager
{
	static std::list<Hero> HeroList;

public:
	void static  ShowHeroInfo(Hero  hero)
	{
		std::cout
			<< "\tName: " << hero.GetName()
			<< "\tHP: " << hero.GetHP()
			<< "\tDamage: " << hero.GetDamage() << std::endl;

	}
	void  DeleteHero(int  pos)
	{
		std::list<Hero>::iterator iterator = HeroList.begin();
		std::advance(iterator, pos);
		HeroList.erase(iterator);
	}
	Hero  CreateHero(int  id, std::string name, int hp, int damage)
	{
		Hero new_hero(id, name, hp, damage);
		HeroList.push_back(new_hero);
		return new_hero;
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
	void GenerateNewTeam() {
		Team team("Team1");
		
	}
	void GetTeamInfo(Team team) {
		
		PlayerManager playermanager = PlayerManager();
		HeroManager heromanager = HeroManager();

		std::cout << "Team: " << team.Name<<std::endl;
		for (auto elem : team.PlayerList)
		{
			playermanager.ShowPlayerInfo(elem);
		}
		std::cout<<std::endl << "Heroes" << std::endl;
		for (auto elem : team.HeroList)
		{
			heromanager.ShowHeroInfo(elem);
		}
	}
};

class Session {
	time_t StartTime=time(0);
	Team TeamOne;
	Team TeamTwo;
	Team Winner;
	Team CalculateWinner() {

	}
};

class GameManager {
	std::list<Session> GameSessions;

	void PerformGameSession() {};
};