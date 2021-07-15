#include <stdio.h>
#include <string>
#include <random>
#include <math.h>

#define CARDNUM 53

//��\��
struct Vector2
{
public:
	float Getvec_x() { return vec_x; }
	float Setvec_x(float n) { return vec_x = n; }

	float Getvec_y() { return vec_y; }
	float Setvec_y(float n) { return vec_y = n; }

	Vector2(float n1, float n2)
	{
		Setvec_x(n1);
		Setvec_y(n2);
	}

private:
	float vec_x;
	float vec_y;
};

float Distance(Vector2 vec1, Vector2 vec2)
{
	float answer = sqrt((vec2.Getvec_x() - vec1.Getvec_x()) * ((vec2.Getvec_x() - vec1.Getvec_x()) + ((vec2.Getvec_y() - vec1.Getvec_y()) * ((vec2.Getvec_y() - vec1.Getvec_y())))));
	printf("%f\n", answer);

	return answer;
}


//��\���
struct Card
{
public:
	int GetCardNum() { return cardNum; }
	int SetCardNum(int n) { return cardNum = n; }

	std::string GetStr() { return str; }
	std::string SetStr(std::string s) { return str = s; }

private:
	std::string str;
	int cardNum = 0;
};

struct Deck
{
public:
	Deck()
	{
		CardSetting();
	}

	//�J�[�h���ݒ�
	void CardSetting()
	{
		for (int i = 0; i < 13; i++)
		{
			cardList[i + 0].SetStr("�X�y�[�h��");
			cardList[i + 13].SetStr("�n�[�g��");
			cardList[i + 26].SetStr("�_�C�A��");
			cardList[i + 39].SetStr("�N���u��");
			cardList[52].SetStr("�W���[�J�[");

			cardList[i + 0].SetCardNum(i + 1);
			cardList[i + 13].SetCardNum(i + 1);
			cardList[i + 26].SetCardNum(i + 1);
			cardList[i + 39].SetCardNum(i + 1);
			cardList[52].SetCardNum(NULL);

		}
	}

	//�J�[�h�J��
	void OpenCard()
	{
		for (int i = 0; i < CARDNUM; i++)
		{
			if (cardList[i].GetStr() == "�W���[�J�[")
			{
				printf("%s\n", cardList[i].GetStr().c_str());
			}
			else
			{
				printf("%s%d\n", cardList[i].GetStr().c_str(), cardList[i].GetCardNum());
			}
		}
	}

	//�V���b�t��
	void Shuffle()
	{
		std::random_device std;

		for (int i = 0; i < CARDNUM; i++)
		{
			int j = std() % CARDNUM;
			Card t = cardList[i];
			cardList[i] = cardList[j];
			cardList[j] = t;
		}
	}

private:
	Card cardList[CARDNUM];
};


int main()
{
	//����
	//printf("%d\n", 0b1011 + 0b0101);
	//printf("%d\n", 0b110100 + 0b11011);
	//printf("%d\n", 0b1011 + 0b110011);

	//����
	//printf("%d\n", 0xFF + 0xFF);
	//printf("%d\n", 0xed + 0x10);
	//printf("%d\n", 0x563 + 0xcd);

	//��O��
	//char��1�o�C�g
	//int��4�o�C�g
	//float��4�o�C�g
	//double��8�o�C�g

	//��l��
	//�@�����������

	//��ܖ�
	//34��

	//��Z��
	//20��

	//�掵��
	//80�o�C�g

	//�攪��
	//20

	//����
	//int��������

	//��\��
	//Vector2 ve1(5,2);
	//Vector2 ve2(34,5);
	//Distance(ve1, ve2);

	//��\���

	Deck deck;
	deck.Shuffle();
	deck.OpenCard();
}