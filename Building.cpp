/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "Building.h"



Building::Building() : Building(0, "Not Provided")
{
}

Building::Building(int id, char* address)
{
	this->apartments = new Apartment*[MAX_APARTMENTS];

	setID(id);
	//Memory allocation in setAddress;
	setAddress(address);
}

Building::Building(const Building& building) : Building(building.getID(), building.getAddress())
{
	for (int i = 0; i < building.getNoOfApartments(); i++)
		getApartments()[i] = building.getApartments()[i]->clone();
}

Building Building::operator=(const Building& building)
{
	if (this == &building)
		return *this;

	this->apartments = new Apartment * [MAX_APARTMENTS];

	setID(building.getID());
	setAddress(building.getAddress());

	for (int i = 0; i < building.getNoOfApartments(); i++)
		getApartments()[i] = building.getApartments()[i]->clone();

	return *this;
}

void Building::printApartmentsWithRoom(int rooms)
{
	for (int i = ApartCostTypeFirst; i < ApartCostTypeLast; i++)
	{
		std::cout << apartCostTypeInText(i) << " Rental Apartments:\n";
		bool found = false;

		for (int j = 0; j < getNoOfApartments(); j++)
		{
			if (getApartments()[j]->getApartmentCostType() != i)
				continue;

			if (getApartments()[j]->getNoOfRooms() == rooms)
			{
				found = true;
				getApartments()[j]->printInformation();
			}
		}
		if (!found)
			std::cout << "Not Found\n";
	}
}

void Building::printApartmentsBiggerThan(int size)
{
	for (int i = ApartCostTypeFirst; i < ApartCostTypeLast; i++)
	{
		std::cout << apartCostTypeInText(i) << " Rental Apartments:\n";
		bool found = false;

		for (int j = 0; j < getNoOfApartments(); j++)
		{
			if (getApartments()[j]->getApartmentCostType() != i)
				continue;
			
			if (getApartments()[j]->getAptSize() >= size)
			{
				found = true;
				getApartments()[j]->printInformation();
			}
		}
		if (!found)
			std::cout << "Not Found\n";
	}
}

void Building::printApartmentsCheaperThan(int price, int days)
{
	for (int i = ApartCostTypeFirst; i < ApartCostTypeLast; i++)
	{
		std::cout << apartCostTypeInText(i) << " Rental Apartments:\n";
		bool found = false;

		for (int j = 0; j < getNoOfApartments(); j++)
		{
			if (getApartments()[j]->getApartmentCostType() != i)
				continue;
			
			if (getApartments()[j]->calculateRentalPrice(days) <= price)
			{
				found = true;
				getApartments()[j]->printInformation();
			}
		}
		if (!found)
			std::cout << "Not Found\n";
	}
}


void Building::printApartments()
{
	for (int i = ApartCostTypeFirst; i < ApartCostTypeLast; i++)
	{
		std::cout << apartCostTypeInText(i) << " Rental Apartments:\n";
		printApartments(apartCostType(i));
	}
}

void Building::printApartments(apartCostType type)
{
	bool found = false;

	for (int j = 0; j < getNoOfApartments(); j++)
	{
		if (getApartments()[j]->getApartmentCostType() != type)
			continue;

		found = true;
		getApartments()[j]->printInformation();
	}
	if (!found)
		std::cout << "Not Found\n";
}


int Building::calculateRentalPriceByAptID(int id, int days)
{
	for (int j = 0; j < getNoOfApartments(); j++)
	{
		if (getApartments()[j]->getApartmentID() == id)
			return getApartments()[j]->calculateRentalPrice(days);
	}
	
	return -1;
}

void Building::printInformation()
{
	std::cout << "ID: " << getID() << ", ";
	std::cout << "Address: " << getAddress() << std::endl;
}

void Building::printInformationWithApartments()
{
	printInformation();
	printApartments();
}

Building::~Building()
{
	for(int i=0; i< getNoOfApartments(); i++)
		delete apartments[i];
	delete[] apartments;

	delete[] address;
}


void Building::addApartment()
{
	if (getNoOfApartments() < MAX_APARTMENTS)
	{
		int selection;
		do
		{
			std::cout << "What is the type of the apartment?\n";
			std::cout << "1. Daily Rental Apartment\n";
			std::cout << "2. Monthly Rental Apartment\n\n";
			std::cout << "Type: ";
			std::cin >> selection;
		}
		while (!(selection == 1 || selection == 2));

		Apartment* apartment;
		int roomNo;
		int noOfRooms;
		int rent;
		int size;		

		std::cout << "Enter room number: ";
		std::cin >> roomNo;
		std::cout << "Enter number of rooms: ";
		std::cin >> noOfRooms;
		std::cout << "Enter rent (GBP): ";
		std::cin >> rent;
		std::cout << "Enter size (m2): ";
		std::cin >> size;

		if(selection==1)
			apartment = createDailyApartment(roomNo, noOfRooms, rent, size);
		else
			apartment = createMonthlyApartment(roomNo, noOfRooms, rent, size);


		getApartments()[getNoOfApartments()] = apartment;
		setNoOfApartments(getNoOfApartments() + 1);
	}
	else
		std::cout << "Building is full, apartment limit reached.\n";
}

Apartment* Building::createDailyApartment(int roomNo, int noOfRooms, int rent, int size)
{
	int decorationStyle;
	do
	{
		std::cout << "Decoration Style:\n";
		std::cout << "1. Minimalist\n";
		std::cout << "2. Modern\n";
		std::cout << "3. Classic\n";
		std::cout << "Your selection: ";
		std::cin >> decorationStyle;
	}
	while (!(decorationStyle >= 1 && decorationStyle <= 3));

	Apartment* apartment = new DailyRentalApartment(roomNo, noOfRooms, rent, size, apartType(--decorationStyle));

	return apartment;
}

Apartment* Building::createMonthlyApartment(int roomNo, int noOfRooms, int rent, int size)
{
	bool furnished;

	std::cout << "Furnished (Yes(1) / No (0)): ";
	std::cin >> furnished;

	Apartment* apartment = new MonthlyRentalApartment(roomNo, noOfRooms, rent, size, furnished);

	return apartment;
}




int Building::getID() const{
	return id;
}
void Building::setID(int id) {
	this->id = id;
}

char* Building::getAddress() const {
	return address;
}
void Building::setAddress(const char* address)
{
	delete this->address;
	this->address = new char[100];
	strcpy(this->address, address);
}

int Building::getNoOfApartments() const {
	return noOfApartments;
}
void Building::setNoOfApartments(int noOfApartments) {
	this->noOfApartments = noOfApartments;
}

Apartment** Building::getApartments() const {
	return apartments;
}


