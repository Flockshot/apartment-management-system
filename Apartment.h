/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#pragma once
#ifndef APARTMENT_H
#define APARTMENT_H
#include <iostream>

#include "apartCostType.h"

class Apartment
{
private:
    int apartmentID;
    int noOfRooms;
    int price;
    int aptSize;
    apartCostType type;

    void setApartmentID(int ID);
    void setNoOfRooms(int noOfRooms);
    void setPrice(int price);
    void setAptSize(int aptSize);    

protected:
    void setApartmentCostType(apartCostType type);

public:
    Apartment(int apartmentID, int noOfRooms, int price, int aptSize);
    Apartment();
    Apartment(const Apartment& apartment);

    virtual int calculateRentalPrice(int days) = 0;
    virtual Apartment* clone() = 0;

    virtual void printInformation();

    apartCostType getApartmentCostType();
    int getPrice();
    int getApartmentID();
    int getNoOfRooms();
    int getAptSize();

};
#endif // APARTMENT_H


