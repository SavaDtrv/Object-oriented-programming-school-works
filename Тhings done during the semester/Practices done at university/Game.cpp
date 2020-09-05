#include <iostream>
#include "Inventory.h"
#include "Hero.h"
#include "NPC.h"
using namespace std;


void testInventory() {
	while (true) {
		Inventory inv;
	}
}

void testTemplate() {
	Shapeshifter<IntellectBuff> shapeshift("", 100, 1, 0, 5, 5, 5, 5); //shablonite se kompilirat kogato zadadem tip na shablona

}

int main() {
	//Hero ThirdSlot;
	//Hero FirstSlot("Clementia", 1200, 1, 0, 250, 60, 10);
	////Hero SecondSlot("Alythai", 800, 1, 0, 10, 60, 250);

	//Hero hero(ThirdSlot);

	//FirstSlot.heroDescription();
	////SecondSlot.heroDescription();
	//ThirdSlot.heroDescription();

		//Dynamic memory
	//double *array = new double; // delete array;
	//double *array1 = new double[4]; //delete[] array1;
	//double sum = 0;

	//for (int i = 0; i < 4; i++)
	//{
	//	cin >> array1[i];
	//	sum += array1[i];
	//}

	//cout << sum / 4 << '\n';
	//delete[] array1;

	//double **matrix = new double*[10]; // ** shows that we will have an array of pointers.
	//for (int i = 0; i < 10; i++)
	//{
	//	matrix[i] = new double[10];
	//}

	 //Operator " = ", predef.

	//testInventory();
	//testTemplate();
	
	 //Test stuff
	NPC npc;

	Attackable att;
	//att.printName();

	Lootable loot;
	//loot.printName();

	NPC* pn = &npc;
	NPC* pa = &att;
	NPC* p1 = &loot;

	pn->printName();
	pa->printName();
	p1->printName();

	// //checking Boss
	//Boss boss;
	//cout << boss;

	//THe Big Four - only when using dynamic memory!!
	system("pause");
	return 0;
}



class Field {
public:
	virtual void getThrough()= 0;
};

class BossFight : public Field {
	Boss boss;

public:
	void getThrough() {

	}
};