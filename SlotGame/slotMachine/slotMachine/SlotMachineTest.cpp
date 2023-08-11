#include <iostream>
#include <Windows.h>
#include <vector>
#include <string.h>
#include <random>
#include <ctime>
#include <limits>
#include <cstddef>
#include <sstream>

#undef max
std::vector<char> LReel = { 'A','C','A','A','C','G','G','G','F','C','F','F','D','E','E','E','D','D','D','K','K','K' };
std::vector<char> CReel = { 'K','K','E','K','E','F','F','F','G','E','G','G','D','C','C','C','D','D','D','A','A','A' };
std::vector<char> RReel = { 'D','D','F','D','F','F','E','E','G','E','G','G','D','K','K','K','A','A','A','C','C','C' };
int choice;
void insertCredits();
int credits;
void menuCredits();
int win;
void spinOne();
void spinTwo();
void spinThree();
void spinFour();
void spin(int);
//bool IsNumber;
using namespace std;

bool IsNumber(string W)
{
	for (int i = 0; i < W.length(); i++)
	{
		if (isdigit(W[i] == false)) {
			return false;
		}
		return true;
	}
	// 재시작할때 넘버가 들어오는지 아닌지를 체크하는 용도
}

void menuCredits()
{
	bool correctChoice = false;
	while (!correctChoice) {
		cout << "당신의 크레딧은 현재 " << credits << " 개 입니다." << endl;
		cout << "얼마를 베팅하시겠습니까?" << endl;
		cout << "1)50" << endl;
		cout << "2)100" << endl;
		cout << "3)150" << endl;
		cout << "4)200" << endl;
		bool WhileNotANumber = false;
		while (!WhileNotANumber)
		{
			// 이곳에서 루프가 돌면서 제대로 된 답이 넘어올때까진 시작이 안되게끔 조절
			//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
			cin >> choice;
			if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n'))
			{
				// 이곳이 제대로 실행되면 choice가 생성되면서 밑에 스위치문으로 진행할 수 있게됨
				//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				WhileNotANumber = true;
			}
			else
			{
				// 제대로 된 숫자가 입력이 안되면 여기를 계속 수행
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cout << "1~4의 숫자만 입력해주세요" << std::endl;
			}
		}
		switch (choice) {
			// correctChoice를 true로 만들어줌으로써 이 루프를 탈출시키고 각자의 행동에 맞는 작동을 하게끔 유도할 수 있음
		case 1:
			system("cls");
			correctChoice = true;
			credits -= 50;
			//spinOne();
			spin(50);
			//PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
			break;
		case 2:
			system("cls");
			correctChoice = true;
			credits -= 100;
			spin(100);
			//spinTwo();
			//PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
			break;
		case 3:
			system("cls");
			correctChoice = true;
			credits -= 150;
			spin(150);
			//spinThree();
			//PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
			break;
		case 4:
			system("cls");
			correctChoice = true;
			credits -= 200;
			spin(200);
			//spinFour();
			//PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
			break;
		default:
			cout << "에러! 1부터 4까지의 숫자만 입력해주십시요" << endl;
			correctChoice = false;
			break;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	insertCredits();
	menuCredits();
	system("Pause");
	return 0;
}

void insertCredits()
{
	bool WhileNotANumber = false;
	cout << "크레딧을 원하는 만큼 입력하세요" << endl;
	cout << "50보다는 크거나 같아야 합니다." << endl;
	while (!WhileNotANumber)
	{
		cin >> credits;
		if (credits < 50)
		{
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "50보다 크거나 같은 수를 입력하세요" << std::endl;
			cin >> credits;
		}
		if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n'))
		{
			WhileNotANumber = true;
			//bool SlotWin = PlaySound(TEXT("InsertCoin.wav"), NULL, SND_ASYNC);
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "50보다 크거나 같은 수를 입력하세요" << std::endl;
			cin >> credits;
		}
	}
}

void spin(int num)
{
	bool Play = true;
	std::mt19937 generator(std::random_device{}());
	std::mt19937 generator2(std::random_device{}());
	std::mt19937 generator3(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, LReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution2(0, CReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution3(0, RReel.size() - 1);
	// 완전한 랜덤화를 위해서 이렇게 진행
	//방식은 한번 더 알아볼 필요가 존재함

	do
	{
		cout << "당신의 크레딧은 현재 " << credits << "개 입니다." << endl;
		if (credits -= num)
		{
			//bool SlotWin1 = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
		}
		int mini = rand() % 101;
		int minor = rand() % 151;
		int major = rand() % 201;
		cout << "미니 보너스 카운트는 " << mini << endl;
		cout << "마이너 보너스 카운트는 " << minor << endl;
		cout << "메이저 보너스 카운트는 " << major << endl;
		if (mini >= 100)
		{
			cout << "미니 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 10000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 10000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		else if (minor >= 150)
		{
			cout << "마이너 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 100000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 100000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		else if (major >= 200)
		{
			cout << "메이져 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 1000000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 1000000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		std::size_t number = distribution(generator);
		std::size_t number2 = distribution(generator2);
		std::size_t number3 = distribution(generator3);
		std::cout << LReel[number] << CReel[number2] << RReel[number3] << std::endl;
		// 곱하기 배수의 문제가 있긴함 뒤로 갈수록 2배 3배 이렇게 하기에는 밋밋해서 해보긴함
		int multiplication = 1;
		switch (num) {
		case 50:
			multiplication = 1;
			break;
		case 100:
			multiplication = 2 * 1.25;
			break;
		case 150:
			multiplication = 3 * 1.25;
			break;
		case 200:
			multiplication = 4 * 1.25;
			break;
		}
		if (LReel[number] == 'D' && CReel[number2] == 'D' && RReel[number3] == 'D')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(75 * multiplication);
			cout << (int)(75 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'F')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(10 * multiplication);;
			cout << (int)(10 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(2000 * multiplication);
			cout << (int)(2000 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'G')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(1750 * multiplication);
			cout << (int)(1750 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'E')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(50 * multiplication);
			cout << (int)(50 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(1550 * multiplication);
			cout << (int)(1550 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'C')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(75 * multiplication);
			cout << (int)(75 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(1500 * multiplication);
			cout << (int)(1550 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'E')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 10;
			cout << "10개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(75 * multiplication);
			cout << (int)(75 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'F')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(75 * multiplication);
			cout << (int)(75 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(75 * multiplication);
			cout << (int)(75 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'C')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(1000 * multiplication);
			cout << (int)(1000 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'D')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += (int)(75 * multiplication);
			cout << (int)(75 * multiplication) << "개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}

		if (Play)
		{
			bool PressedChoice = false;
			while (!PressedChoice)
			{
				string yesOrNo = "";
				cout << "다시 하시겠습니까? y/n? y나 n을 입력해주십시요" << endl;
				cin >> yesOrNo;
				if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
				{
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					PressedChoice = true;
				}
				else
				{
					// 그만한다 해도 다시한번 물어보는용도
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cout << " y 혹은 n을 입력하세요" << std::endl;
					cin >> yesOrNo;
					if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
					{
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
						PressedChoice = true;
					}
					if (yesOrNo == "y") {
						Play = true;
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
					else if (yesOrNo == "n")
					{
						Play = false;
						PressedChoice = true;
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
				}
				if (yesOrNo == "y") {
					Play = true;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				else if (yesOrNo == "n")
				{
					Play = false;
					PressedChoice = true;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				if (credits <= 0)
				{
					cout << "크레딧이 더 없습니다!! " << endl;
					Play = false;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
			}
		}
	} while (Play);
}

void spinOne()
{
	bool Play = true;
	std::mt19937 generator(std::random_device{}());
	std::mt19937 generator2(std::random_device{}());
	std::mt19937 generator3(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, LReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution2(0, CReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution3(0, RReel.size() - 1);
	// 완전한 랜덤화를 위해서 이렇게 진행
	//방식은 한번 더 알아볼 필요가 존재함

	do
	{
		cout << "당신의 크레딧은 현재 " << credits << "개 입니다." << endl;
		if (credits -= 50)
		{
			//bool SlotWin1 = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
		}
		int mini = rand() % 101;
		int minor = rand() % 151;
		int major = rand() % 201;
		cout << "미니 보너스 카운트는 " << mini << endl;
		cout << "마이너 보너스 카운트는 " << minor << endl;
		cout << "메이저 보너스 카운트는 " << major << endl;
		if (mini >= 100)
		{
			cout << "미니 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 10000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 10000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		else if (minor >= 150)
		{
			cout << "마이너 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 100000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 100000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		else if (major >= 200)
		{
			cout << "메이져 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 1000000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 1000000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		std::size_t number = distribution(generator);
		std::size_t number2 = distribution(generator2);
		std::size_t number3 = distribution(generator3);
		std::cout << LReel[number] << CReel[number2] << RReel[number3] << std::endl;
		if (LReel[number] == 'D' && CReel[number2] == 'D' && RReel[number3] == 'D')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 75;
			cout << "75개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'F')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 10;
			cout << "10개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 2000;
			cout << "2000개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'G')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 1750;
			cout << "1750개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'E')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 25;
			cout << "25개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 1550;
			cout << "1550개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'C')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 75;
			cout << "75개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 1500;
			cout << "1500개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'E')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 10;
			cout << "10개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 50;
			cout << "50개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'F')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 50;
			cout << "50개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 50;
			cout << "50개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'C')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 1000;
			cout << "1000개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'D')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 50;
			cout << "50개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}

		if (Play)
		{
			bool PressedChoice = false;
			while (!PressedChoice)
			{
				string yesOrNo = "";
				cout << "다시 하시겠습니까? y/n? y나 n을 입력해주십시요" << endl;
				cin >> yesOrNo;
				if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
				{
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					PressedChoice = true;
				}
				else
				{
					// 그만한다 해도 다시한번 물어보는용도
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cout << " y 혹은 n을 입력하세요" << std::endl;
					cin >> yesOrNo;
					if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
					{
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
						PressedChoice = true;
					}
					if (yesOrNo == "y") {
						Play = true;
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
					else if (yesOrNo == "n")
					{
						Play = false;
						PressedChoice = true;
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
				}
				if (yesOrNo == "y") {
					Play = true;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				else if (yesOrNo == "n")
				{
					Play = false;
					PressedChoice = true;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				if (credits <= 0)
				{
					cout << "크레딧이 더 없습니다!! " << endl;
					Play = false;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
			}
		}
	} while (Play);
}

void spinTwo()
{
	bool Play = true;
	std::mt19937 generator(std::random_device{}());
	std::mt19937 generator2(std::random_device{}());
	std::mt19937 generator3(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, LReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution2(0, CReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution3(0, RReel.size() - 1);
	// 완전한 랜덤화를 위해서 이렇게 진행
	//방식은 한번 더 알아볼 필요가 존재함

	do
	{
		cout << "당신의 크레딧은 현재 " << credits << "개 입니다." << endl;
		if (credits -= 100)
		{
			//bool SlotWin1 = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
		}
		int mini = rand() % 101;
		int minor = rand() % 151;
		int major = rand() % 201;
		cout << "미니 보너스 카운트는 " << mini << endl;
		cout << "마이너 보너스 카운트는 " << minor << endl;
		cout << "메이저 보너스 카운트는 " << major << endl;
		if (mini >= 100)
		{
			cout << "미니 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 10000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 10000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		else if (minor >= 150)
		{
			cout << "마이너 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 100000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 100000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		else if (major >= 200)
		{
			cout << "메이져 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 1000000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 1000000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		std::size_t number = distribution(generator);
		std::size_t number2 = distribution(generator2);
		std::size_t number3 = distribution(generator3);
		std::cout << LReel[number] << CReel[number2] << RReel[number3] << std::endl;
		if (LReel[number] == 'D' && CReel[number2] == 'D' && RReel[number3] == 'D')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 175;
			cout << "175개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'F')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 50;
			cout << "50개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 3000;
			cout << "3000개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'G')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 2750;
			cout << "2750개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'E')
		{
			//	bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 125;
			cout << "125개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 1550;
			cout << "1550개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'C')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 175;
			cout << "175개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'E')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 110;
			cout << "110개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 2500;
			cout << "2500개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'F')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'C')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 2000;
			cout << "2000개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'D')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}

		if (Play)
		{
			bool PressedChoice = false;
			while (!PressedChoice)
			{
				string yesOrNo = "";
				cout << "다시 하시겠습니까? y/n? y나 n을 입력해주십시요" << endl;
				cin >> yesOrNo;
				if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
				{
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					PressedChoice = true;
				}
				else
				{
					// 그만한다 해도 다시한번 물어보는용도
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cout << " y 혹은 n을 입력하세요" << std::endl;
					cin >> yesOrNo;
					if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
					{
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
						PressedChoice = true;
					}
					if (yesOrNo == "y") {
						Play = true;
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
					else if (yesOrNo == "n")
					{
						Play = false;
						PressedChoice = true;
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
				}
				if (yesOrNo == "y") {
					Play = true;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				else if (yesOrNo == "n")
				{
					Play = false;
					PressedChoice = true;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				if (credits <= 0)
				{
					cout << "크레딧이 더 없습니다!! " << endl;
					Play = false;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
			}
		}
	} while (Play);
}

void spinThree()
{
	bool Play = true;
	std::mt19937 generator(std::random_device{}());
	std::mt19937 generator2(std::random_device{}());
	std::mt19937 generator3(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, LReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution2(0, CReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution3(0, RReel.size() - 1);
	// 완전한 랜덤화를 위해서 이렇게 진행
	//방식은 한번 더 알아볼 필요가 존재함

	do
	{
		cout << "당신의 크레딧은 현재 " << credits << "개 입니다." << endl;
		if (credits -= 150)
		{
			//bool SlotWin1 = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
		}
		int mini = rand() % 101;
		int minor = rand() % 151;
		int major = rand() % 201;
		cout << "미니 보너스 카운트는 " << mini << endl;
		cout << "마이너 보너스 카운트는 " << minor << endl;
		cout << "메이저 보너스 카운트는 " << major << endl;
		if (mini >= 100)
		{
			cout << "미니 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 10000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 10000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		else if (minor >= 150)
		{
			cout << "마이너 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 100000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 100000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		else if (major >= 200)
		{
			cout << "메이져 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 1000000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 1000000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		std::size_t number = distribution(generator);
		std::size_t number2 = distribution(generator2);
		std::size_t number3 = distribution(generator3);
		std::cout << LReel[number] << CReel[number2] << RReel[number3] << std::endl;
		if (LReel[number] == 'D' && CReel[number2] == 'D' && RReel[number3] == 'D')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 190;
			cout << "190개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'F')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 50;
			cout << "50개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 3000;
			cout << "3000개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'G')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 2750;
			cout << "2750개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'E')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 125;
			cout << "125개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 1550;
			cout << "1550개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'C')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 175;
			cout << "175개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 2500;
			cout << "2500개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'E')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 110;
			cout << "110개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 2500;
			cout << "2500개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'F')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'C')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 2000;
			cout << "2000개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'D')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}

		if (Play)
		{
			bool PressedChoice = false;
			while (!PressedChoice)
			{
				string yesOrNo = "";
				cout << "다시 하시겠습니까? y/n? y나 n을 입력해주십시요" << endl;
				cin >> yesOrNo;
				if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
				{
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					PressedChoice = true;
				}
				else
				{
					// 그만한다 해도 다시한번 물어보는용도
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cout << " y 혹은 n을 입력하세요" << std::endl;
					cin >> yesOrNo;
					if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
					{
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
						PressedChoice = true;
					}
					if (yesOrNo == "y") {
						Play = true;
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
					else if (yesOrNo == "n")
					{
						Play = false;
						PressedChoice = true;
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
				}
				if (yesOrNo == "y") {
					Play = true;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				else if (yesOrNo == "n")
				{
					Play = false;
					PressedChoice = true;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				if (credits <= 0)
				{
					cout << "크레딧이 더 없습니다!! " << endl;
					Play = false;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
			}
		}
	} while (Play);
}

void spinFour()
{
	bool Play = true;
	std::mt19937 generator(std::random_device{}());
	std::mt19937 generator2(std::random_device{}());
	std::mt19937 generator3(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, LReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution2(0, CReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution3(0, RReel.size() - 1);
	// 완전한 랜덤화를 위해서 이렇게 진행
	//방식은 한번 더 알아볼 필요가 존재함

	do
	{
		cout << "당신의 크레딧은 현재 " << credits << "개 입니다." << endl;
		if (credits -= 150)
		{
			//bool SlotWin1 = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
		}
		int mini = rand() % 101;
		int minor = rand() % 151;
		int major = rand() % 201;
		cout << "미니 보너스 카운트는 " << mini << endl;
		cout << "마이너 보너스 카운트는 " << minor << endl;
		cout << "메이저 보너스 카운트는 " << major << endl;
		if (mini >= 100)
		{
			cout << "미니 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 10000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 10000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		else if (minor >= 150)
		{
			cout << "마이너 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 100000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 100000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		else if (major >= 200)
		{
			cout << "메이져 보너스에 당첨되셨습니다!!!" << endl;
			cout << "당첨 보상으로 크레딧 1000000개를 획득하셨습니다!" << endl;
			//bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 1000000;
			cout << "현재 크레딧의 갯수는 " << credits << "개 입니다." << endl;
		}
		std::size_t number = distribution(generator);
		std::size_t number2 = distribution(generator2);
		std::size_t number3 = distribution(generator3);
		std::cout << LReel[number] << CReel[number2] << RReel[number3] << std::endl;
		if (LReel[number] == 'D' && CReel[number2] == 'D' && RReel[number3] == 'D')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 275;
			cout << "275개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'F')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 20;
			cout << "20개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 3500;
			cout << "3500개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'G')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 3000;
			cout << "3000개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'E')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 125;
			cout << "125개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 2550;
			cout << "2550개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'C')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 175;
			cout << "175개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 3000;
			cout << "3000개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'E')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 110;
			cout << "110개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'K')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 2500;
			cout << "2500개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'F')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'A')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'C')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 2000;
			cout << "2000개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'D')
		{
			//bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			cout << "이겼습니다!!!" << endl;
			credits += 150;
			cout << "150개를 획득하였습니다. 지금 크레딧은 " << credits << "개 입니다." << endl;
		}

		if (Play)
		{
			bool PressedChoice = false;
			while (!PressedChoice)
			{
				string yesOrNo = "";
				cout << "다시 하시겠습니까? y/n? y나 n을 입력해주십시요" << endl;
				cin >> yesOrNo;
				if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
				{
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					PressedChoice = true;
				}
				else
				{
					// 그만한다 해도 다시한번 물어보는용도
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cout << " y 혹은 n을 입력하세요" << std::endl;
					cin >> yesOrNo;
					if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
					{
						//	bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
						PressedChoice = true;
					}
					if (yesOrNo == "y") {
						Play = true;
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
					else if (yesOrNo == "n")
					{
						Play = false;
						PressedChoice = true;
						//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
				}
				if (yesOrNo == "y") {
					Play = true;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				else if (yesOrNo == "n")
				{
					Play = false;
					PressedChoice = true;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				if (credits <= 0)
				{
					cout << "크레딧이 더 없습니다!! " << endl;
					Play = false;
					//bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
			}
		}
	} while (Play);
}