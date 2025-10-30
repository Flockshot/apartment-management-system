/* Muhammad Somaan 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "Agency.h"

Agency::Agency() : Agency("Not Provided")
{
}

Agency::Agency(char* name)
{
	this->name = new char[100];
	this->buildings = new Building * [MAX_BUILDINGS];
	setName(name);

}

Agency::Agency(char* name, Building** buildings, int noOfBuildings) : Agency(name)
{
	for (int i = 0; i < noOfBuildings; i++)
	{
		addBuilding(buildings[i]);
	}
}

Agency::Agency(const Agency& agency) : Agency(name)
{
}

Agency& Agency::operator=(const Agency& agency)
{
	if (this == &agency)
		return *this;
	setName(agency.getName());

	return *this;
}


void Agency::printBuildings()
{
	for (int i = 0; i < getNoOfBuildings(); i++)
		getBuildings()[i]->printInformation();
}

void Agency::printBuildingsWithRoom(int rooms)
{
	for (int i = 0; i < getNoOfBuildings(); i++)
		getBuildings()[i]->printApartmentsWithRoom(rooms);
}

void Agency::printBuildingsBiggerThan(int size)
{
	for (int i = 0; i < getNoOfBuildings(); i++)
		getBuildings()[i]->printApartmentsBiggerThan(size);
}

void Agency::printBuildingsCheaperThan(int price, int days)
{
	for (int i = 0; i < getNoOfBuildings(); i++)
		getBuildings()[i]->printApartmentsCheaperThan(price, days);
}

void Agency::printBuildingsWithApartments()
{
	for (int i = 0; i < getNoOfBuildings(); i++)
		getBuildings()[i]->printInformationWithApartments();
}

void Agency::printBuildingsApartmentsOnly()
{
	for (int i = 0; i < getNoOfBuildings(); i++)
		getBuildings()[i]->printApartments();
}

void Agency::printBuildingsApartmentsOnly(int buildingID) {
	getBuildingWithID(buildingID)->printApartments();
}

void Agency::printBuildingsWithApartments(apartCostType type)
{
	for (int i = 0; i < getNoOfBuildings(); i++)
	{
		getBuildings()[i]->printInformation();
		getBuildings()[i]->printApartments(type);
	}		
}


int Agency::calculateRentalPriceByAptID(int buildingID, int aptID, int days) {	
	return getBuildingWithID(buildingID)->calculateRentalPriceByAptID(aptID, days);
}


void Agency::addBuilding(Building* building)
{
	if (getNoOfBuildings() < MAX_BUILDINGS)
	{
		getBuildings()[getNoOfBuildings()] = building;
		setNoOfBuildings(getNoOfBuildings() + 1);
	}
	else
		std::cout << "Agency building capacity is full.\n";
}

void Agency::addApartmentToBuilding(int buildingID) {
	getBuildingWithID(buildingID)->addApartment();
}

Building* Agency::getBuildingWithID(int buildingID)
{
	for (int j = 0; j < getNoOfBuildings(); j++)
		if (getBuildings()[j]->getID() == buildingID)
			return getBuildings()[j];
}


Agency::~Agency() {
	delete[] name;
}




char* Agency::getName() const {
	return name;
}
void Agency::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[100];
	strcpy(this->name, name);
}

Building** Agency::getBuildings() const {
	return buildings;
}

int Agency::getNoOfBuildings() const {
	return noOfBuildings;
}
void Agency::setNoOfBuildings(int noOfBuildings) {
	this->noOfBuildings = noOfBuildings;
}


