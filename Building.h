/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#pragma once
#ifndef BUILDING_H
#define BUILDING_H
#define MAX_APARTMENTS 30

#include<string.h>

#include "MonthlyRentalApartment.h"


class Building
{
private:
	int id;
	char* address;
	Apartment** apartments;
	int noOfApartments;
	
	void setID(int id);	
	void setAddress(const char* address);	
	void setNoOfApartments(int noOfApartments);

	Apartment* createDailyApartment(int roomNo, int noOfRooms, int rent, int size);
	Apartment* createMonthlyApartment(int roomNo, int noOfRooms, int rent, int size);

	Apartment** getApartments() const;

public:
	Building();
	Building(int id, char* address);
	Building(const Building& building);
	Building operator=(const Building& building);

	void addApartment();
	
	int getID() const;
	char* getAddress() const;
	int getNoOfApartments() const;

	void printApartments();
	void printApartments(apartCostType type);
	void printApartmentsWithRoom(int rooms);
	void printApartmentsBiggerThan(int size);
	void printApartmentsCheaperThan(int price, int days);

	int calculateRentalPriceByAptID(int id, int days);

	void printInformation();
	void printInformationWithApartments();
	~Building();

};
#endif