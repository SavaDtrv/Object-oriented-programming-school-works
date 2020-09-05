#include <iostream>
#include "BattleField.h"
#include <random>
#include <ctime>

using namespace std;

const int STARTING_LIFE_POINT = 4000;

void playGame() {
//suzdavame si pole
	Battlefield battleField;
//tazi promenliva kazva koi trugva purvi
	int playerOnMove = rand() % 2 + 1;
//shte suzdadem tochkite na dva geroq, naprimer te shte budat po 4000
	int player1 = STARTING_LIFE_POINT; //igrata produljava dokato ediniq
	int player2 = STARTING_LIFE_POINT; //ot tqh ne stigne 0 tochki

	while ((player1 != 0 && player2 != 0) && 
		(battleField.getCurrentDeck1() != 0 && battleField.getCurrentDeck2() != 0)) {
		//Kogato ediniq ot igrachite stigne 0 tochki igrata shte svurshi
		//ili ako v testeto na ediniq ima 0 karti

	//Na vsqko vurtene shte ni vika nova karta, kato sled vseki dve 
	//iteracii intervala shte se skasqva s 1ca
		int i = 0; //tova s koeto shte namalqme intervala
		int iter = 1; //broi iteraciite
		int getRandomCard = rand() % 29 + 0 - i;
	
		/*Ot tuk natatuk purvo vikame metoda addCardToHand(<parametri>), koito
	shte izpolzva getRandomCard kato index za karta i shte q dobavi v rukata
	na igracha i shte q premahne ot testeto. Sled koeto shte proverim na koq iteraciq
	sme i ako sme na iteraciq >1, togava shte proverim dali ima protivnikovo
	chudovishte na poleto i ako ima shte izvikame metoda battleField.monsterFigth(<parametri>)
	i t.n. Ako tekushtiq igrach nqma chudovishta, shte proverim dali imame karta kapan i shte q
	izpolzvame chrez battleField.useTrap(<parametri>). Sushtoto i na za magicheska karta
	(battleField.useMagic(<parametri>)), kato shte primem che imame metod, koito pita igracha dali iska 
	da q polzva sega ili prosto da q pribavi kum rukata mu. Kogato tekushtata iteraciq svurshi shte 
	proverqvame dali e chetna i ako e shte uvelichavame promenlivata i s 1ca(promqnata na intervala), 
	i sled koeto shte uvelichim	samata promenliva za iteraciq. Predi vseki vrushta na proverkata pri while() 
	cikula shte proverqvame	dali ima pobeditel, ako ima takuv igrata prikliuchva i se provuzglasqva pobeditelq.*/
	
	}

}

int main()
{
	
	playGame();
/*
	Ideqta mi za igrata e, nakratko opisana, takava. Sujalqvam che ne uspqh da q zavursha do samiq krai
	s celiq cikul na igra i mojebi sum zabravil nqkoi metod v classovete, kakto i navqrno ima dosta
	greshni neshta, no do tolkova uspqh za jalost. Blagodarq za vnimanieto
*/

	system("pause");
	return 0;
}