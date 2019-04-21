#include <iostream>
#include<cstdlib>//生成随机数
#include<ctime>//与随机数的生成配套使用
using namespace std;
class Card
{
private:
	int NUM[5];//每人最多五张牌
	int number;//一共发了多少张牌
	int nWin;//赢的局数
	int nLose;//输的局数
	int nDraw;//平局数
public:
	Card();
	void FirstTwocard();
	int GetNumber();
	int GetValue();
	void DisplayValue();
	void DisplayValue(int);//除了第一张，依次全部牌面点数值（向电脑展示）
	void TurnPlay();//出一张牌
	void Win();//赢
	void Lose();//输
	void Draw();//平局
	void DisplayInformation();//展示一些信息
	int GetCurrentCard();//返回牌点数
};
struct User
{
	char uesername[12];
	char password[12];
};
//构造一个函数并且完成初始化
Card::Card()
{
	number = 0;
	for (int i = 0; i < 5; i++)
	{
		NUM[i] = 0;
	}
	nWin = 0;
	nLose = 0;
	nDraw = 0;
}

//最初每人俩张牌
void Card::FirstTwocard()
{
	NUM[0] = rand() % 10 + 1;
	NUM[1] = rand() % 10 + 1;
	number = 2;
}
//返回牌数(牌的张数）
int Card::GetNumber()
{

	return number;
}
//返回牌的数值
int Card::GetValue()
{
	int nvalue=0;
	for (int i = 0; i < number; i++)
	{
		if (NUM[i] >= 10)
		{
			nvalue += 10;
		}
		else
			nvalue += NUM[i];
	}
	return nvalue;
}
//显示全部牌面
void Card::DisplayValue()//依次显示牌点数
{
	for (int i = 0; i < number; i++)
		cout<< NUM[i] << "\t";
	cout << endl;
}
//除了第一张，依次全部牌面点数值（向电脑展示）
void Card::DisplayValue(int)
{
	cout << "[*]" <<'\t';//不显示第一张牌
	for (int i = 1; i < number; i++)
		cout << NUM[i] << '\t';
	cout << endl;
}
//出一张牌
void Card::TurnPlay()
{
	number++;
	NUM[number - 1] = rand() % 10 + 1;
}
//赢
void Card::Win()
{
	nWin++;
	cout << "赢家牌面：";
	DisplayValue();
	cout << "牌面点数：" << GetValue() << endl;
	cout << "赢了" << nWin << "次" << "输了" << nLose << "次" << "平局" << nDraw << "次" << endl;
}
//输
void Card::Lose()
{
	nLose++;
	cout << "输家牌面:";
	DisplayValue();
	if (GetValue() > 21)
		cout << "爆了！" << endl;
	else
		cout << "牌面点数：" << GetValue() << endl;
	cout << "赢了" << nWin << "次" << "输了" << nLose << "次" << "平局" << nDraw << "次" << endl;
	cout << endl << endl;
}
//平局
void Card::Draw()
{
	nDraw++;
	cout << "平局牌面:";
	DisplayValue();
	if (GetValue() > 21)
		cout << "爆了! \n";
	else
		cout << "牌面点数：" << GetValue() << endl;
	cout << " 赢了" << nWin << "次" << "输了" << nLose << "次 " << "平局 " << nDraw << "次 " << endl;
}
//展示一些信息
void Card::DisplayInformation()
{
	cout << "您一共玩了" << nWin + nLose + nDraw << "局," << "赢了" << nWin << "局," << "输了" << nLose << "局，" << "平局" << nDraw << "局" << endl;
}

int Card::GetCurrentCard()
{
	return NUM[number-1];
}
//展示规则
void DisplayRule(void)
{
	cout << "\t欢迎进入21点游戏世界！"<<endl;
	cout << "\t游戏规则："<<endl;
	cout << "\t1.玩家最多可以要5张牌；"<<endl;
	cout << "\t2.如果牌点的总数大于21则爆点，自动判输；"<<endl;
	cout << "\t3.计算机方在牌点大于等于16时不再要牌。"<<endl;//电脑对要牌的判断
	cout << "\t4.祝您好运!"<<endl;
	cout << endl << endl;
}
//判断输赢
void Judge(Card &cpu, Card &player)
{
	cout << endl;
	if ((cpu.GetValue() > 21 || player.GetValue() > 21) || cpu.GetValue() == player.GetValue())
	{
		cout << "\n\n很遗憾，您输了"<<endl;
		cout << "计算机数据：\t";
		cpu.DisplayValue();
		cout << "牌面点数：" << cpu.GetValue() << endl;
		cout << "\n您的数据\t";
		player.Lose();
		cout << endl;
	}
	else if ((cpu.GetValue() > 21) || (player.GetValue() > cpu.GetValue() && player.GetValue() <= 21))
	{
		cout << "\n\n恭喜您，您赢了！\n";
		cout << "计算机数据：\t";
		cpu.DisplayValue();//电脑牌面数值
		cout << "牌面点数：" << cpu.GetValue() << endl;
		cout << "\n您的数据\t";
		player.Win();
		cout << endl;

	}
	else
	{
		cout << "\n\n平局"<<endl;
		cout << "计算机数据：\t";
		cpu.DisplayValue();
		cout << "牌面点数：" << cpu.GetValue() << endl;
		cout << "\n您的数据\t";
		player.Draw();
		cout << endl;

	}

}
void PlayTurn(Card &cpu, Card &player)//玩一局
{
	char chChoice;
	int blCpu = 1, blPlayer = 1;//判断是否要牌
	cpu.FirstTwocard();//电脑的俩张牌
	player.FirstTwocard();//玩家自己的俩张牌
	do
	{
		cout << "您的牌点：\t"<<endl;
		player.DisplayValue();
		cout << "计算机牌点：\t";
		cpu.DisplayValue(1);
		cout << "您的牌点数是：" << player.GetValue() << endl;
		if (blPlayer)
		{
			cout << "\n\n您是否继续要牌（Y/N)";
			cin >> chChoice;
			if ((chChoice == 'Y' || chChoice == 'y'))//Y、y都代表yes
			{
				if (player.GetNumber() < 5)
				{
					player.TurnPlay();
					cout << "这是您想要的牌:" << player.GetCurrentCard() << endl;
					if (player.GetValue() > 21)
						blPlayer = 0;
				}
				else
				{
					cout << "对不起，您已经要了5张牌了，不能在要牌了！";
					blPlayer = 0;
				}
			}
		}

		if ((chChoice == 'N') || (chChoice == 'n'))//N、n都代表no
		{
			blPlayer = 0;
		}

		if (cpu.GetValue() < 16 && cpu.GetNumber() < 5)
		{
			cpu.TurnPlay();
			cout << "计算机要牌，牌点是：" << cpu.GetCurrentCard() << endl;
		}
		else
			blCpu = 0;

		if (blCpu&&player.GetNumber() < 5 && player.GetValue() < 21)
			blPlayer = 1;

	}
	while (blCpu || blPlayer);
	//判断输赢
	Judge(cpu, player);
	return;
}
int main()
{
	srand((unsigned)time(NULL));//初始化随机数种子
	Card cpu, player;//电脑，和玩家
	DisplayRule();//打印规则
	int userage=0;
	cin >> userage;
	if (userage < 18) 
	{
		cout << "年龄过小，不要接触此类游戏，请好好读书" << endl;
	}
	else
	{
		cout << "你可以开始你的游戏了" << endl;
	}
	char chChoice;
	cout << "是否开始游戏（Y/N）?";
	cin >> chChoice;//选择
	while(chChoice=='Y'||chChoice=='y')
	{
		PlayTurn(cpu, player);
		cout << "是否继续21点游戏（Y/N）?\n";
		cin >> chChoice;
	}
	cout << "欢迎再次使用本程序"<<endl;

}
