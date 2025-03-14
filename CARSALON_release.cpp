
#include <algorithm>
#include <vector>

#include <iostream>
#include <string>
using namespace std;

struct Car
{

	string name;
	int year;
	int price;
	double volume_engine;



	Car(string name, int year, int price, double volume_engine) : name(name), year(year), price(price), volume_engine(volume_engine) {}
};

class CarSalon
{
private:
	vector <Car> cars;
public:
	CarSalon() {};

	void add()
	{
		string name;
		int year;
		int price;
		double volume_engine;
		cout << "Name: "; cin >> name;
		cout << "Year: "; cin >> year;
		cout << "Price: "; cin >> price;
		cout << "Volume engine: "; cin >> volume_engine;
		cars.push_back(Car(name, year, price, volume_engine));
	}

	void Delete(int index) { cars.erase(cars.begin() + index); }

	void DeleteLast() { cars.pop_back(); }

	void DeleteAll() { cars.clear(); }

	void show() {
		for (int i = 0; i < cars.size(); i++)
		{
			cout << "---------" << endl;
			cout << "Name: " << cars[i].name << endl;
			cout << "Year: " << cars[i].year << endl;
			cout << "Price: " << cars[i].price << endl;
			cout << "Volume engine: " << cars[i].volume_engine << endl;
			cout << "---------" << endl;
		}
	}


	void operator()(int index) {
		cout << "Name: " << cars[index].name << endl;
		cout << "Year: " << cars[index].year << endl;
		cout << "Price: " << cars[index].price << endl;
		cout << "Volume engine: " << cars[index].volume_engine << endl;
	}


	void SortByName() {
		sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
			return a.name < b.name;
			});
	}

	void SortByYear() {
		sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
			return a.year < b.year;
			});
	}

	void SortByPrice() {
		sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
			return a.price < b.price;
			});
	}

	void SortByVolumeEngine() {
		sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
			return a.volume_engine < b.volume_engine;
			});
	}

	int FindByName() {
		string name;
		cin >> name;
		for (int i = 0; i < cars.size(); i++)
		{
			if (cars[i].name == name)
				return i;
		}
		return -1;
	}

	int FindByYear() {
		int year;
		cin >> year;
		for (int i = 0; i < cars.size(); i++)
		{
			if (cars[i].year == year)
				return i;
		}
		return -1;
	}

	int FindByPrice() {
		int price;
		cin >> price;
		for (int i = 0; i < cars.size(); i++)
		{
			if (cars[i].price == price)
				return i;
		}
		return -1;
	}

	int FindByVolumeEngine() {
		double volume_engine;
		cin >> volume_engine;
		for (int i = 0; i < cars.size(); i++)
		{
			if (cars[i].volume_engine == volume_engine)
				return i;
		}
		return -1;
	}

	void operator()() {
		int choice;
		int index;
		cout << "============================" << endl;
		cout << "Choose action: " << endl;
		cout << "1. Add car" << endl;
		cout << "2. Delete car" << endl;
		cout << "3. Delete last car" << endl;
		cout << "4. Delete all cars" << endl;
		cout << "5. Sort by name" << endl;
		cout << "6. Sort by year" << endl;
		cout << "7. Sort by price" << endl;
		cout << "8. Sort by volume engine" << endl;
		cout << "9. Find by name" << endl;
		cout << "10. Find by year" << endl;
		cout << "11. Find by price" << endl;
		cout << "12. Find by volume engine" << endl;
		cout << "13. Show all cars" << endl;
		cout << "0. Exit" << endl;
		cout << "============================" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			add();
			break;
		case 2:

			cin >> index;
			Delete(index);
			break;
		case 3:
			DeleteLast();
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			SortByName();
			break;
		case 6:
			SortByYear();
			break;
		case 7:
			SortByPrice();
			break;
		case 8:
			SortByVolumeEngine();
			break;
		case 9:
			index = FindByName();
			if (index == -1)
				cout << "Car not found" << endl;
			else
				(*this)(index);
			break;
		case 10:
			index = FindByYear();
			if (index == -1)
				cout << "Car not found" << endl;
			else
				(*this)(index);
			break;
		case 11:
			index = FindByPrice();
			if (index == -1)
				cout << "Car not found" << endl;
			else
				(*this)(index);
			break;
		case 12:
			index = FindByVolumeEngine();
			if (index == -1)
				cout << "Car not found" << endl;
			else
				(*this)(index);
			break;
		case 13:
			show();
			break;
		case 0:
			exit(0);
			break;

		default:
			break;
		}

	}

};

int main()
{
	CarSalon salon;

	while (true) {
		salon();
	}



}

