#include <stdio.h>
#include <string>
#include <random>

//第十問
//float Distance(float num1, float num2)
//{
//	return num1 - num2;
//}

//第十一問
struct Card
{
public:
	int GetCardNum() { return cardNum; }
	int SetCardNum(int n) { return cardNum = n; }

	std::string GetStr() { return str; }
	std::string SetStr(std::string s) { return str = s; }

	//カード情報設定
	void cardList(Card cardList[])
	{

		for (int i = 0; i < 13; i++)
		{
			cardList[i + 0].str = "スペードの";
			cardList[i + 13].str = "ハートの";
			cardList[i + 26].str = "ダイアの";
			cardList[i + 39].str = "クラブの";
			cardList[52].str = "ジョーカー";

			cardList[i + 0].cardNum = i + 1;
			cardList[i + 13].cardNum = i + 1;
			cardList[i + 26].cardNum = i + 1;
			cardList[i + 39].cardNum = i + 1;
			cardList[52].cardNum = NULL;

		}

	}

	//自分のカード開示
	int openCard(Card n[])
	{
		for (int i = 0; i < 53; i++)
		{
			if (n[i].str == "ジョーカー")
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

	//シャッフル
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
	//上に記載	

	//第十一問

	Card card[53];
	
	card->cardList(card);
	card->shuffle(card);
	card->openCard(card);

}

