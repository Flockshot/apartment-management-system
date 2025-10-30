/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#pragma once
#ifndef AGENCY_H
#define AGENCY_H
#define MAX_BUILDINGS 30

#include "Building.h"

class Agency
{
private:
	char* name;
	Building** buildings;
	int noOfBuildings;

	void setNoOfBuildings(int noOfBuildings);
	char* getName() const;
	void setName(const char* name);

	Building** getBuildings() const;

	Building* getBuildingWithID(int buildingID);

public:
	Agency();
	Agency(char* name);
	Agency(char* name, Building** buildings, int noOfBuildings);
	Agency(const Agency &agency);

	Agency& operator=(const Agency& agency);

	int getNoOfBuildings() const;

	void addBuilding(Building* building);
	void addApartmentToBuilding(int buildingID);

	void printBuildings();
	void printBuildingsWithRoom(int rooms);
	void printBuildingsBiggerThan(int size);
	void printBuildingsCheaperThan(int price, int days);
	void printBuildingsWithApartments();
	void printBuildingsApartmentsOnly();
	void printBuildingsApartmentsOnly(int buildingID);
	void printBuildingsWithApartments(apartCostType type);

	int calculateRentalPriceByAptID(int buildingID, int aptID, int days);

	~Agency();

};
#endif