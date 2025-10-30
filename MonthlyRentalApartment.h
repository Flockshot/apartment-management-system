/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#pragma once
#ifndef MONTHLYRENTALAPARTMENT_H
#define MONTHLYRENTALAPARTMENT_H

#include "DailyRentalApartment.h"


class MonthlyRentalApartment : public Apartment
{
private:
    bool hasFurniture;

    bool getHasFurniture();
    void setHasFurniture(bool furniture);

    const char* getBoolInText(bool val);

public:
    MonthlyRentalApartment(int apartmentID, int noOfRooms, int price, int aptSize, bool hasFurniture);
    MonthlyRentalApartment();

    void printInformation();
    Apartment* clone();

    int calculateRentalPrice(int days);

};
#endif // MONTHLYRENTALAPARTMENT_H
