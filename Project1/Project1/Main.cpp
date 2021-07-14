#include <stdio.h>
#include <string>
#include <random>
#include <math.h>

#define CARDNUM 53

//第十問
struct Vector2
{
public:
	float Getvec_x() { return vec_x; }
	float Setvec_x(float n) { return vec_x = n; }

	float Getvec_y() { return vec_y; }
	float Setvec_y(float n) { return vec_y = n; }

	Vector2(float n1,float n2)
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
	float answer = sqrt( (vec2.Getvec_x() - vec1.Getvec_x()) * ((vec2.Getvec_x() - vec1.Getvec_x()) + ((vec2.Getvec_y() - vec1.Getvec_y()) * ((vec2.Getvec_y() - vec1.Getvec_y())))));
	printf("%f\n", answer);

	return answer;
}


//第十一問
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
	//カード情報設定
	Deck(Card cardList[CARDNUM])
	{
		for (int i = 0; i < CARDNUM; i++)
		{
			c[i] = cardList[i];
		}

		for (int i = 0; i < 13; i++)
		{
			c[i + 0].SetStr("スペードの");
			c[i + 13].SetStr("ハートの");
			c[i + 26].SetStr("ダイアの");
			c[i + 39].SetStr("クラブの");
			c[52].SetStr("ジョーカー");

			c[i + 0].SetCardNum(i + 1);
			c[i + 13].SetCardNum(i + 1);
			c[i + 26].SetCardNum(i + 1);
			c[i + 39].SetCardNum(i + 1);
			c[52].SetCardNum(NULL);

		}

	}

	//カード開示
	int openCard()
	{
		for (int i = 0; i < CARDNUM; i++)
		{
			if (c[i].GetStr() == "ジョーカー")
			{
				printf("%s\n", c[i].GetStr().c_str());
			}
			else
			{
				printf("%s%d\n", c[i].GetStr().c_str(), c[i].GetCardNum());
			}
		}

		return 0;
	}

	//シャッフル
	void shuffle()
	{
		std::random_device std;

		for (int i = 0; i < CARDNUM; i++)
		{
			int j = std() % CARDNUM;
			Card t = c[i];
			c[i] = c[j];
			c[j] = t;
		}
	}

private:
	Card c[CARDNUM];
};


int main(void) 
{
	//第一問
	//printf("%d\n", 0b1011 + 0b0101);
	//printf("%d\n", 0b110100 + 0b11011);
	//printf("%d\n", 0b1011 + 0b110011);

	//第二問
	//printf("%d\n", 0xFF + 0xFF);
	//printf("%d\n", 0xed + 0x10);
	//printf("%d\n", 0x563 + 0xcd);

	//第三問
	//charは1バイト
	//intは4バイト
	//floatは4バイト
	//doubleは8バイト

	//第四問
	//①が処理される

	//第五問
	//34回

	//第六問
	//20回

	//第七問
	//80バイト

	//第八問
	//20

	//第九問
	//intが正しい

	//第十問
	//Vector2 ve1(5,2);
	//Vector2 ve2(34,5);
	//Distance(ve1, ve2);
	 
	//第十一問
	Card card[CARDNUM];

	Deck deck(card);
	deck.shuffle();
	deck.openCard();

}

