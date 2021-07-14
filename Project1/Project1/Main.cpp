#include <stdio.h>
#include <string>
#include <random>

//��\��
//float Distance(float num1, float num2)
//{
//	return num1 - num2;
//}

//��\���
struct Card
{
public:
	int GetCardNum() { return cardNum; }
	int SetCardNum(int n) { return cardNum = n; }

	std::string GetStr() { return str; }
	std::string SetStr(std::string s) { return str = s; }

	//�J�[�h���ݒ�
	void cardList(Card cardList[])
	{

		for (int i = 0; i < 13; i++)
		{
			cardList[i + 0].str = "�X�y�[�h��";
			cardList[i + 13].str = "�n�[�g��";
			cardList[i + 26].str = "�_�C�A��";
			cardList[i + 39].str = "�N���u��";
			cardList[52].str = "�W���[�J�[";

			cardList[i + 0].cardNum = i + 1;
			cardList[i + 13].cardNum = i + 1;
			cardList[i + 26].cardNum = i + 1;
			cardList[i + 39].cardNum = i + 1;
			cardList[52].cardNum = NULL;

		}

	}

	//�����̃J�[�h�J��
	int openCard(Card n[])
	{
		for (int i = 0; i < 53; i++)
		{
			if (n[i].str == "�W���[�J�[")
			{
				printf("%s\n", n[i].str.c_str());
			}
			else 
			{
				printf("%s%d\n", n[i].str.c_str(), n[i].cardNum);
			}
		}

		return 0;
	}

	//�V���b�t��
	void shuffle(Card n[])
	{
		std::random_device std;

		for (int i = 0; i < 53; i++)
		{
			int j = std() % 53;
			Card t = n[i];
			n[i] = n[j];
			n[j] = t;
		}
	}

private:
	std::string str;
	int cardNum = 0;
};


int main(void) 
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
	//��ɋL��	

	//��\���

	Card card[53];
	
	card->cardList(card);
	card->shuffle(card);
	card->openCard(card);

}

