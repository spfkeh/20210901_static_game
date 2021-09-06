#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Game
{
private:
	double energy = 100;
	static int life;
	static int playerdamage;
	static int enemy;
	static int coin;
	int Hpp = 3;
public:
	void choice();
	Game();
	double Damage();
	static void Die();
	int Start();
	int war();
	void market();
};
int Game::life = 10;
int Game::playerdamage = 10;
int Game::enemy = 100;
int Game::coin = 200;
void Game::market()
{
	system("cls");
	cout << "상점에 방문하였습니다" << endl;
	cout << "[coin : " << coin << "]" << endl << endl;
	cout << "[1] 공격력증가 : 150\t[2] 체력 포션 : 50" << endl;
	char s = _getch();
	if (s == '1')
	{
		if (coin >= 150)
		{
			cout << "[거래 성공]" << endl;
			playerdamage += 10;
			coin -= 150;
		}
		
	}
	else if (s == '2')
	{
		if (coin >= 50)
		{
			cout << "[거래 성공]" << endl;
			Hpp += 3;
			coin -= 50;
		}
	}
}
void Game::Die()
{
	life--;
	cout << "**생명이 1감소하여 " << life << "이 되었습니다" << endl << endl;
	
}
double Game::Damage()
{
	double damaged = 0;
	if (energy > 0)
	{
		damaged += rand() % 20;
		energy -= damaged;
		cout << "에너지가 " << damaged << "감소하여 " << energy << "이 되었습니다" << endl;
		if (energy < 0)
		{
			life--;
			energy = 100;
			cout << "**생명이 1감소하여 " << life << "이 되었습니다" << endl << endl;
		}
	}
	return energy;
}
int Game::Start()
{
	int m = rand() % 3 + 1;
	if (m == 1)
	{
		cout << "적을 만났습니다!" << endl;
		
		choice();
		return 1;
	}
	else if (m == 2)
	{
		cout << "상점을 찾았습니다" << endl;
		market();
	}
	else
	{
		cout << "아무일도 일어나지 않았습니다" << endl;
		return 0;
	}
	
}
Game::Game()
{
	cout << "자 모험이 시작되었습니다!" << endl;
}
void Game::choice()
{
	cout << "asd";
	enemy = 100;
	while (enemy > 0)
	{
		system("cls");
		cout << "[Hp : " << energy << "]" << endl;
		cout << "\t\t[enemy : " << enemy << "]" << endl;
		cout << "[1] 공격\t[2] 가방" << endl;
		char ch = _getch();
		if (ch == '1')
		{
			cout << "적에게 공격!\n적에게" << playerdamage << "만큼 데미지를 넣었습니다" << endl;
			enemy -= playerdamage;
		}
		else if (ch == '2')
		{
			
			system("cls");
			cout << "[가방]" << endl << endl;
			if (Hpp != 0)
			{
				cout << "[1] Hp포션 : " << Hpp << endl;;
				char b = _getch();
				if (b == '1')
				{
					cout << "Hp를 50 회복했습니다" << endl;
					Hpp--;
					energy += 50;
					Sleep(1000);
				}
			}
			
		}
		if (enemy <= 0)
		{
			system("cls");
			cout << "적을 무찔렀습니다!" << endl;
			Sleep(1000);
		}
		else
		{
			Damage();
		}
		
		Sleep(1200);
		
	}
	
}
int main()
{
	srand((unsigned)time(NULL));
	Game c1;
	int i=4;
	while (1)
	{
		char a;
		a = _getch();
		c1.Start();
		
	}
	
	
	return 0;
}