#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

char* CIGARETE_TYPE = "Cigaretes";
char* ALCOHOL_TYPE = "Alcohol";
const int MAX_AMOUNT_PRODUCTS = 100;
const int MAX_NICOTIN = 15;
const int MAX_ALCOHOL = 70; //Abscent = 70%
const int MAX_LENGTH_CIG_ALC_NAME = 20;

class Product {
protected:
	double price;

public:
	Product() :price(0) {}
	Product(double _price) :price(_price) {}

	virtual char* kindOfProduct() = 0;
	virtual void characteristics() = 0;
};

class Cigaretes :public Product {
	char name[MAX_LENGTH_CIG_ALC_NAME];
	int nicotin;

public:
	Cigaretes(double _price, char _name[MAX_LENGTH_CIG_ALC_NAME], int _nicotin) :Product(_price), nicotin(_nicotin) {
		strcpy(name, _name);
	}
	
	const char* getName() const { return this->name; }
	int getNicotin() { return this->nicotin; }
	double getPrice() const { return this->price; }

	char* kindOfProduct() {
		return CIGARETE_TYPE;
	}

	void characteristics() {
		cout << "Name: " << name
			<< " Nicotin: " << nicotin 
			<< " Price: " << price << "(value of the country)" << '\n';
	}
};

class Alcohol : public Product {
	char name[MAX_LENGTH_CIG_ALC_NAME];
	int alcohol;

public:
	Alcohol(double _price, char _name[MAX_LENGTH_CIG_ALC_NAME], int _alcohol) : Product(_price), alcohol(_alcohol) {
		strcpy(name, _name);
	}

	int getAlcohol() { return this->alcohol; }
	const char* getName() const { return this->name; }
	double getPrice() const { return this->price; }

	char* kindOfProduct() {
		return ALCOHOL_TYPE;
	}

	void characteristics() {
		cout << "Name: " << name 
			<< " Alcohol: " << alcohol << "%"
			<< " Price: " << price << "(value of the country)" <<'\n';
	}
};

class Store {
	Product** products;
	int current;
public:
	Store() {
		current = 0;
		products = new Product*[MAX_AMOUNT_PRODUCTS];
	}

	~Store() {
		delete products;
		products = nullptr;
	}


	Store& operator+=(Product& newProduct) {
		if (current == MAX_AMOUNT_PRODUCTS - 1) {
			cout << "The store is full. No more space for products left." << '\n';
			return *this;
		}

		products[current] = &newProduct;
		current++;
	}

	Store& operator-=(Product* soldProduct) 
	{
		for (int i = 0; i < current; i++)
		{
			if (strcmp(products[i]->kindOfProduct(), soldProduct->kindOfProduct()) == 0) 
			{

				if (strcmp(products[i]->kindOfProduct(), CIGARETE_TYPE) == 0)
				{

					Cigaretes* soldCig = dynamic_cast<Cigaretes*>(soldProduct);
					Cigaretes* inProdCig = dynamic_cast<Cigaretes*>(products[i]);
					
					if (strcmp(soldCig->getName(), inProdCig->getName()) == 0) 
					{
						products[i] = products[current];
						current--;

						return *this;
					}
				}
				else 
				{
					Alcohol* soldAlc = dynamic_cast<Alcohol*>(soldProduct);
					Alcohol* inProdAlc = dynamic_cast<Alcohol*>(products[i]);

					if (strcmp(soldAlc->getName(), inProdAlc->getName()) == 0) 
					{
						products[i] = products[current];
						current--;
						return *this;
					}
				}
			}
		}
	}

	void calculateSoldOut() {

		double soldOutMoney;

		for (int i = 0; i < current; i++)
		{
			//soldOutMoney += products[i]->getPrice();
			if (strcmp(products[i]->kindOfProduct(), CIGARETE_TYPE) == 0)
			{
				Cigaretes* inProdCig = dynamic_cast<Cigaretes*>(products[i]);
				soldOutMoney += inProdCig->getPrice();
			}
			else
			{
				Alcohol* inProdAlc = dynamic_cast<Alcohol*>(products[i]);
				soldOutMoney += inProdAlc->getPrice();
			}
		}

		cout << "Soldout money: " << soldOutMoney << '\n';
	}

	void findLowestNicotinCig() {
		int tmpNicotin = MAX_NICOTIN;
		const char* tmpCigName = "";

		for (int i = 0; i < current; i++)
		{
			if (strcmp(products[i]->kindOfProduct(), CIGARETE_TYPE) == 0)
			{
				Cigaretes* inProdCig = dynamic_cast<Cigaretes*>(products[i]);
				if (inProdCig->getNicotin() < tmpNicotin)
				{
					tmpNicotin = inProdCig->getNicotin();
					tmpCigName = inProdCig->getName();
				}
			}
		}

		cout << "Lowest nicotin cigaretes are: " << tmpCigName << '\n';
	}

	void findByLowestAlc() {
		int tmpAlcohol = MAX_ALCOHOL;
		const char* tmpAlcName = "";

		for (int i = 0; i < current; i++)
		{
			if(strcmp(products[i]->kindOfProduct(), ALCOHOL_TYPE) == 0)
			{
				Alcohol* inProdAlc = dynamic_cast<Alcohol*>(products[i]);
				
				if (inProdAlc->getAlcohol() < tmpAlcohol)
				{
					tmpAlcohol = inProdAlc->getAlcohol();
					tmpAlcName = inProdAlc->getName();
				}
			}
		}

		cout << "Lowest type of alcohol in alcohol % is: " << tmpAlcName << '\n';
	}
};


//void testDynamic() {
//
//	while (true) {
//		Store str;
//	}
//}

int main() {

	Store str;

	Cigaretes cigs(5, "No name", 7);
	Alcohol alc(10, "Abscent", 70);

	/*Product* c = &cigs;
	Product* a = &alc;

	c->characteristics();
	a->characteristics();*/


	str += cigs;
	str += alc;

	str.findLowestNicotinCig();
	str.findByLowestAlc();

	system("pause");
	return 0;
}