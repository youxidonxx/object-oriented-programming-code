/************************************************************************/
/* class Deck:poker of 52 cards,public interface":sendCard,freshCard,
compareCard,showCard
         太慢....                                                        */
/************************************************************************/
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;
#define		POKERNUM	13
#define		POKERSTYLE	4
class	Player{
private:
	int*	CardInHand ;
	int*	CardStyle;
	int*	startInHand ;			//作为保留起始地址的指针
	int*	startStyle ;

public:
	void	setCardNum(int& num);
	void	setCardStyle(int& style);
	bool	cmpCard(Player pl2);
	int*	getCardNum();
	int*	getCardStyle();
	void	initial(){
		CardInHand= new int[POKERNUM];
		CardStyle = new int[POKERNUM];
		startInHand = CardInHand;
		startStyle = CardStyle;
	}
	Player(){initial();}
	~Player();
};
Player::~Player(){
	delete	[] CardInHand;
	delete	[]	CardStyle;
}
int*		Player::getCardNum()
{
	return	 startInHand;
}
int*		Player::getCardStyle()
{
	return	startStyle;
}
bool	Player::cmpCard(Player pl2)
{

	return	true;
}
void	Player::setCardNum(int& num)
{
	*CardInHand = num;
	*CardInHand++;
}
void	Player::setCardStyle(int& style)
{
	*CardStyle = style;
	*CardStyle++;
}
class	Deck{
private:
	char	card[POKERSTYLE][POKERNUM];
	static	int total ;
//	const char* cardStyle={3,4,5,6};
	string	haveSent;
	string	sentCard;
public:
	static char  cardOri[POKERNUM];
	Deck(){freshCard();}
 	void	sendCard(int times,Player& pl);
	void	freshCard();
	void	sendCard(Player& pl);
};
char	Deck::cardOri[POKERNUM]={'3','4','5','6','7','8','9','10','J','Q','K','A','2'};
int		Deck::total= 52;
void	Deck::freshCard()
{
	for (int i=0;i<POKERSTYLE;i++)
	{
		for (int j=0;j<POKERNUM;j++)
		{
			card[i][j]=cardOri[j];
		}
	}
}
void	Deck::sendCard(int times,Player& pl)
{
	int i=0;
	for (;i<times;i++)
	{
	srand(time(0));
	int vertical=rand()%13;
	int horizon = rand()%4;
		if (0==card[horizon][vertical])			//当遇到重复发牌时
		{
			i--;
		}
		else
		{
	//		*(Player::CardInHand)	=	vertical;
	//		*(Player::CardStyle)	=	horizon;
			pl.setCardNum(vertical);
			pl.setCardStyle(horizon);
			card[horizon][vertical]	=	0;
		}
	}
}/*
void	Deck::sendCard(Player& pl)
{
	srand(time(0));

}
int main()
{
	int i=0,l;
	l=13;
	char  a[4] = {3,4,5,6};
	Deck	ck;
 	Player pl1,pl2;
	ck.sendCard(l,pl1);
  	ck.sendCard(l,pl2);
//	int* play1 ,*play2 ;
//	*play1 = 4;//
	int*	 play1 = pl1.getCardNum();
 	int*	 play2 = pl1.getCardStyle();
	int*		play3	= pl2.getCardNum();
	int*	play4 = pl2.getCardStyle();
	for (;i<l;i++)
	{
		cout<<ck.cardOri[*play1++]<<a[*play2++]<<"::"<<ck.cardOri[*play3++]<<a[*play4++]<<endl;
	}
	return 0;
}
*/
