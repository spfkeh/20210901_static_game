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
	cout << "������ �湮�Ͽ����ϴ�" << endl;
	cout << "[coin : " << coin << "]" << endl << endl;
	cout << "[1] ���ݷ����� : 150\t[2] ü�� ���� : 50" << endl;
	char s = _getch();
	if (s == '1')
	{
		if (coin >= 150)
		{
			cout << "[�ŷ� ����]" << endl;
			playerdamage += 10;
			coin -= 150;
		}
		
	}
	else if (s == '2')
	{
		if (coin >= 50)
		{
			cout << "[�ŷ� ����]" << endl;
			Hpp += 3;
			coin -= 50;
		}
	}
}
void Game::Die()
{
	life--;
	cout << "**������ 1�����Ͽ� " << life << "�� �Ǿ����ϴ�" << endl << endl;
	
}
double Game::Damage()
{
	double damaged = 0;
	if (energy > 0)
	{
		damaged += rand() % 20;
		energy -= damaged;
		cout << "�������� " << damaged << "�����Ͽ� " << energy << "�� �Ǿ����ϴ�" << endl;
		if (energy < 0)
		{
			life--;
			energy = 100;
			cout << "**������ 1�����Ͽ� " << life << "�� �Ǿ����ϴ�" << endl << endl;
		}
	}
	return energy;
}
int Game::Start()
{
	int m = rand() % 3 + 1;
	if (m == 1)
	{
		cout << "���� �������ϴ�!" << endl;
		
		choice();
		return 1;
	}
	else if (m == 2)
	{
		cout << "������ ã�ҽ��ϴ�" << endl;
		market();
	}
	else
	{
		cout << "�ƹ��ϵ� �Ͼ�� �ʾҽ��ϴ�" << endl;
		return 0;
	}
	
}
Game::Game()
{
	cout << "�� ������ ���۵Ǿ����ϴ�!" << endl;
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
		cout << "[1] ����\t[2] ����" << endl;
		char ch = _getch();
		if (ch == '1')
		{
			cout << "������ ����!\n������" << playerdamage << "��ŭ �������� �־����ϴ�" << endl;
			enemy -= playerdamage;
		}
		else if (ch == '2')
		{
			
			system("cls");
			cout << "[����]" << endl << endl;
			if (Hpp != 0)
			{
				cout << "[1] Hp���� : " << Hpp << endl;;
				char b = _getch();
				if (b == '1')
				{
					cout << "Hp�� 50 ȸ���߽��ϴ�" << endl;
					Hpp--;
					energy += 50;
					Sleep(1000);
				}
			}
			
		}
		if (enemy <= 0)
		{
			system("cls");
			cout << "���� ���񷶽��ϴ�!" << endl;
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