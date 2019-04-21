#include <iostream>
#include<cstdlib>//���������
#include<ctime>//�����������������ʹ��
using namespace std;
class Card
{
private:
	int NUM[5];//ÿ�����������
	int number;//һ�����˶�������
	int nWin;//Ӯ�ľ���
	int nLose;//��ľ���
	int nDraw;//ƽ����
public:
	Card();
	void FirstTwocard();
	int GetNumber();
	int GetValue();
	void DisplayValue();
	void DisplayValue(int);//���˵�һ�ţ�����ȫ���������ֵ�������չʾ��
	void TurnPlay();//��һ����
	void Win();//Ӯ
	void Lose();//��
	void Draw();//ƽ��
	void DisplayInformation();//չʾһЩ��Ϣ
	int GetCurrentCard();//�����Ƶ���
};
struct User
{
	char uesername[12];
	char password[12];
};
//����һ������������ɳ�ʼ��
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

//���ÿ��������
void Card::FirstTwocard()
{
	NUM[0] = rand() % 10 + 1;
	NUM[1] = rand() % 10 + 1;
	number = 2;
}
//��������(�Ƶ�������
int Card::GetNumber()
{

	return number;
}
//�����Ƶ���ֵ
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
//��ʾȫ������
void Card::DisplayValue()//������ʾ�Ƶ���
{
	for (int i = 0; i < number; i++)
		cout<< NUM[i] << "\t";
	cout << endl;
}
//���˵�һ�ţ�����ȫ���������ֵ�������չʾ��
void Card::DisplayValue(int)
{
	cout << "[*]" <<'\t';//����ʾ��һ����
	for (int i = 1; i < number; i++)
		cout << NUM[i] << '\t';
	cout << endl;
}
//��һ����
void Card::TurnPlay()
{
	number++;
	NUM[number - 1] = rand() % 10 + 1;
}
//Ӯ
void Card::Win()
{
	nWin++;
	cout << "Ӯ�����棺";
	DisplayValue();
	cout << "���������" << GetValue() << endl;
	cout << "Ӯ��" << nWin << "��" << "����" << nLose << "��" << "ƽ��" << nDraw << "��" << endl;
}
//��
void Card::Lose()
{
	nLose++;
	cout << "�������:";
	DisplayValue();
	if (GetValue() > 21)
		cout << "���ˣ�" << endl;
	else
		cout << "���������" << GetValue() << endl;
	cout << "Ӯ��" << nWin << "��" << "����" << nLose << "��" << "ƽ��" << nDraw << "��" << endl;
	cout << endl << endl;
}
//ƽ��
void Card::Draw()
{
	nDraw++;
	cout << "ƽ������:";
	DisplayValue();
	if (GetValue() > 21)
		cout << "����! \n";
	else
		cout << "���������" << GetValue() << endl;
	cout << " Ӯ��" << nWin << "��" << "����" << nLose << "�� " << "ƽ�� " << nDraw << "�� " << endl;
}
//չʾһЩ��Ϣ
void Card::DisplayInformation()
{
	cout << "��һ������" << nWin + nLose + nDraw << "��," << "Ӯ��" << nWin << "��," << "����" << nLose << "�֣�" << "ƽ��" << nDraw << "��" << endl;
}

int Card::GetCurrentCard()
{
	return NUM[number-1];
}
//չʾ����
void DisplayRule(void)
{
	cout << "\t��ӭ����21����Ϸ���磡"<<endl;
	cout << "\t��Ϸ����"<<endl;
	cout << "\t1.���������Ҫ5���ƣ�"<<endl;
	cout << "\t2.����Ƶ����������21�򱬵㣬�Զ����䣻"<<endl;
	cout << "\t3.����������Ƶ���ڵ���16ʱ����Ҫ�ơ�"<<endl;//���Զ�Ҫ�Ƶ��ж�
	cout << "\t4.ף������!"<<endl;
	cout << endl << endl;
}
//�ж���Ӯ
void Judge(Card &cpu, Card &player)
{
	cout << endl;
	if ((cpu.GetValue() > 21 || player.GetValue() > 21) || cpu.GetValue() == player.GetValue())
	{
		cout << "\n\n���ź���������"<<endl;
		cout << "��������ݣ�\t";
		cpu.DisplayValue();
		cout << "���������" << cpu.GetValue() << endl;
		cout << "\n��������\t";
		player.Lose();
		cout << endl;
	}
	else if ((cpu.GetValue() > 21) || (player.GetValue() > cpu.GetValue() && player.GetValue() <= 21))
	{
		cout << "\n\n��ϲ������Ӯ�ˣ�\n";
		cout << "��������ݣ�\t";
		cpu.DisplayValue();//����������ֵ
		cout << "���������" << cpu.GetValue() << endl;
		cout << "\n��������\t";
		player.Win();
		cout << endl;

	}
	else
	{
		cout << "\n\nƽ��"<<endl;
		cout << "��������ݣ�\t";
		cpu.DisplayValue();
		cout << "���������" << cpu.GetValue() << endl;
		cout << "\n��������\t";
		player.Draw();
		cout << endl;

	}

}
void PlayTurn(Card &cpu, Card &player)//��һ��
{
	char chChoice;
	int blCpu = 1, blPlayer = 1;//�ж��Ƿ�Ҫ��
	cpu.FirstTwocard();//���Ե�������
	player.FirstTwocard();//����Լ���������
	do
	{
		cout << "�����Ƶ㣺\t"<<endl;
		player.DisplayValue();
		cout << "������Ƶ㣺\t";
		cpu.DisplayValue(1);
		cout << "�����Ƶ����ǣ�" << player.GetValue() << endl;
		if (blPlayer)
		{
			cout << "\n\n���Ƿ����Ҫ�ƣ�Y/N)";
			cin >> chChoice;
			if ((chChoice == 'Y' || chChoice == 'y'))//Y��y������yes
			{
				if (player.GetNumber() < 5)
				{
					player.TurnPlay();
					cout << "��������Ҫ����:" << player.GetCurrentCard() << endl;
					if (player.GetValue() > 21)
						blPlayer = 0;
				}
				else
				{
					cout << "�Բ������Ѿ�Ҫ��5�����ˣ�������Ҫ���ˣ�";
					blPlayer = 0;
				}
			}
		}

		if ((chChoice == 'N') || (chChoice == 'n'))//N��n������no
		{
			blPlayer = 0;
		}

		if (cpu.GetValue() < 16 && cpu.GetNumber() < 5)
		{
			cpu.TurnPlay();
			cout << "�����Ҫ�ƣ��Ƶ��ǣ�" << cpu.GetCurrentCard() << endl;
		}
		else
			blCpu = 0;

		if (blCpu&&player.GetNumber() < 5 && player.GetValue() < 21)
			blPlayer = 1;

	}
	while (blCpu || blPlayer);
	//�ж���Ӯ
	Judge(cpu, player);
	return;
}
int main()
{
	srand((unsigned)time(NULL));//��ʼ�����������
	Card cpu, player;//���ԣ������
	DisplayRule();//��ӡ����
	int userage=0;
	cin >> userage;
	if (userage < 18) 
	{
		cout << "�����С����Ҫ�Ӵ�������Ϸ����úö���" << endl;
	}
	else
	{
		cout << "����Կ�ʼ�����Ϸ��" << endl;
	}
	char chChoice;
	cout << "�Ƿ�ʼ��Ϸ��Y/N��?";
	cin >> chChoice;//ѡ��
	while(chChoice=='Y'||chChoice=='y')
	{
		PlayTurn(cpu, player);
		cout << "�Ƿ����21����Ϸ��Y/N��?\n";
		cin >> chChoice;
	}
	cout << "��ӭ�ٴ�ʹ�ñ�����"<<endl;

}
