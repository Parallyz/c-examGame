#include <string>
#include <list>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "classes.h"
#include <time.h>



std::string GetRandomHeroName(int random_number)
{
	switch (random_number)
	{
	case 0:return "Goblin";
	case 1: return "Orc";
	case 2: return "Dragon";
	case 3: return "Ogre";
	case 4: return "Skeleton";
	case 5: return "Troll";
	case 6: return "Vempire";
	case 7: return "Zombie";
	case 8: return "Human";
	case 9: return "Amplify";
	case 10: return "Urchin";
	case 11: return "Blaze";
	case 12: return "Cannonade";
	case 13: return "Kraken";
	case 14: return "Bulletproof";
	case 15: return "Fortitude";
	case 16: return "Tradewind";
	case 17: return "Apex";
	case 18: return "Tarantula";
	case 19: return "Chromium";
	case 20: return "Shockwave";
	}
	return"Error!";
}

std::string GetRandomPlayerName(int random_number)
{
	switch (random_number)
	{
	case 0:return "Adams";
	case 1: return "Baker";
	case 2: return "Clark";
	case 3: return "Davis";
	case 4: return "Evans";
	case 5: return "Ghosh";
	case 6: return "Frank";
	case 7: return "Hills";
	case 8: return "Irwin";
	case 9: return "Jones";
	case 10: return "Klein";
	case 11: return "Lopez";
	case 12: return "Mason";
	case 13: return "Nalty";
	case 14: return "Ochoa";
	case 15: return "Patel";
	case 16: return "Quinn";
	case 17: return "Reily";
	case 18: return "Smith";
	case 19: return "Trott";
	case 20: return "Usman";
	}
	return"Error!";
}
 
 class PlayerManager
{
public:
	bool isNameExist(Player playerlist[],int lenght, std::string name)
	{
		for (int i=0;i<lenght;i++)
		{
			if (playerlist[i].GetName() == name)
			{
				return true;
			}
		}
		return false;
	}
	void  ShowPlayerInfo(Player  player)
	{

		std::cout
			<< "\tName: " << player.GetName()
			<< "\tRank: " << player.GetRank() << std::endl;

	}
	Player*  DeletePlayer(Player playerlist[], int lenght,int pos)
	{
		Player* new_playerlist = new Player[lenght - 1];

		for (int i = 0; i < lenght - 1; i++)
		{
			if (pos >= i)
			{
				new_playerlist[i] = playerlist[i + 1];
				continue;
			}
			new_playerlist[i] = playerlist[i];

		}

		return new_playerlist;
	}
	Player CreatePlayer(Player *playerlist,int lenght)
	{	
		srand((unsigned)time(NULL));
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		int randplayerName = rand() % 20;
		int randplayerRank = rand() % 1001;
		int randId = rand() % 1001;

		std::string Name = GetRandomPlayerName(randplayerName);
		while (isNameExist(playerlist, lenght, Name))
		{
			Name = GetRandomPlayerName(randplayerName);
		}
		Player player(randId,Name,randplayerRank);

		return player;
	}
	Player* GetPlayerByName(Player playerlist[], int lenght,std::string name)
	{
		for (int i=0;i<lenght;i++)
		{
			if (playerlist[i].GetName() == name)
				return &playerlist[i];
		}
		return nullptr;
	}

	Player* GetPlayerById(Player playerlist[], int lenght,int id)
	{
		for (int i = 0; i < lenght; i++)
		{
			if (playerlist[i].GetId() == id)
				return &playerlist[i];
		}
		return nullptr;
	}
};


 class HeroManager
{


public:
	bool isNameExist(Hero herolist[], int lenght, std::string name)
	{
		for (int i = 0; i < lenght; i++)
		{
			if (herolist[i].GetName() == name)
			{
				return true;
			}
		}
		return false;
	}
	void static  ShowHeroInfo(Hero  hero)
	{
		std::cout
			<< "\tName: " << hero.GetName()
			<< "\tHP: " << hero.GetHP()
			<< "\tDamage: " << hero.GetDamage() << std::endl;

	}
	Hero*  DeleteHero(Hero herolist[], int lenght, int  pos)
	{
		Hero* new_herolist=new Hero[lenght - 1];

		for (int i = 0; i < lenght-1; i++)
		{
			if (pos>=i)
			{
				new_herolist[i] = herolist[i+1];
				continue;
			}
			new_herolist[i] = herolist[i];

		}

		return new_herolist;
	}
	Hero  CreateHero(Hero *herolist, int lenght)
	{		
		srand((unsigned)time(NULL));
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		int randHeroName = rand() % 20;
		int randHeroHP = rand() % 101;
		int randHeroDamage = rand() % 101;

		int randId = rand() % 1001;

		std::string Name = GetRandomHeroName(randHeroName);
		while (isNameExist(herolist, lenght, Name))
		{
			Name = GetRandomHeroName(randHeroName);
		}
		Hero hero(randId, Name, randHeroHP,randHeroDamage);

		return hero;
	}
	Hero* GetHeroByName(Hero herolist[], int lenght, std::string name)
	{
		for (int i=0;i<lenght;i++)
		{
			if (herolist[i].GetName() == name)
				return &herolist[i];
		}
		return nullptr;
	}

	Hero* GetHeroById(Hero herolist[], int lenght, int id)
	{
		for (int i = 0; i < lenght; i++)
		{
			if (herolist[i].GetId() == id)
				return &herolist[i];
		}
		return nullptr;
	}
};

class TeamManager {
public:
	Team GenerateNewTeam(std::string TeamName) {

		PlayerManager playermanager = PlayerManager();
		HeroManager heromanager = HeroManager();


		Hero newHerolist[5];
		Player newPlayerlist[5];

		for (int i = 0; i < 5; i++)
		{
			newHerolist[i]=heromanager.CreateHero(newHerolist, 5);
			newPlayerlist[i] = playermanager.CreatePlayer(newPlayerlist, 5);
		}
		
		Team team(TeamName,newHerolist,newPlayerlist);
		return team;
		
	}
	void GetTeamInfo(Team &team) {
		
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
public:
	Team Winner;
	 Team TeamOne;
	 Team TeamTwo;
	void CalculateWinner() {

		int first_team_hp = GetTeamHP(TeamOne);
		int second_team_hp = GetTeamHP(TeamTwo);

		int first_team_damage = GetTeamDamage(TeamOne);
		int second_team_damage = GetTeamDamage(TeamTwo);

		if (second_team_hp - first_team_damage > first_team_hp - second_team_damage)
		{
			AddRank(TeamTwo);
			RemoveRank(TeamOne);

			Winner = TeamTwo;
		
		}
		else
		{

			AddRank(TeamOne);
			RemoveRank(TeamTwo);

			Winner = TeamOne;
			

		}
	}

	int GetTeamHP(Team& team)
	{
		int SumHp = 0;
		for (auto hero : team.HeroList)
		{
			SumHp+=hero.GetHP();
		}
		return SumHp;
	}
	int GetTeamDamage(Team& team)
	{
		int SumDamage = 0;
		for (auto hero : team.HeroList)
		{
			SumDamage += hero.GetDamage();
		}
		return SumDamage;
	}
	
	void AddRank( Team& winnerTeam)
	{
		for (auto &player : winnerTeam.PlayerList)
		{			
			player.SetRank(player.GetRank() + 25);
		}

		
	}

	void RemoveRank( Team& looserTeam)
	{
		for (auto &player : looserTeam.PlayerList)
		{
			player.SetRank(player.GetRank() - 25);
		}	
	}
};

class GameManager {
	std::list<Session> GameSessions;
public:
	void PerformGameSession() {
		TeamManager teamManager= TeamManager();
		Team team1 = teamManager.GenerateNewTeam("Dire");
		Team team2 = teamManager.GenerateNewTeam("Radiant");

		Session session=Session();
		session.TeamOne = team1;
		session.TeamTwo = team2;
		std::cout<<"Start Game" << std::endl;

		teamManager.GetTeamInfo(session.TeamOne);
		std::cout <<std:: endl;

		teamManager.GetTeamInfo(session.TeamTwo);
		std::cout << std::endl;

		session.CalculateWinner();
		std::cout << "Game Result" << std::endl;
		std::cout << "Winner" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		teamManager.GetTeamInfo(session.Winner);
		std::cout << std::endl;
		std::cout << std::endl;

		teamManager.GetTeamInfo(session.TeamOne);
		std::cout << std::endl;

		teamManager.GetTeamInfo(session.TeamTwo);
		std::cout << std::endl;


		GameSessions.push_back(session);
	};
};