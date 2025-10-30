/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#pragma once
#ifndef DAILYRENTALAPARTMENT_H
#define DAILYRENTALAPARTMENT_H

#include "Apartment.h"
#include "apartType.h"


class DailyRentalApartment : public Apartment
{
private:
    apartType decorationStyle;

    apartType getDecorationStyle();
    void setDecorationStyle(apartType style);

public:
    DailyRentalApartment(int apartmentID, int noOfRooms, int price, int aptSize, apartType style);
    DailyRentalApartment();

    void printInformation();
    Apartment* clone();

    int calculateRentalPrice(int days);

};
#endif // DAILYRENTALAPARTMENT_H
