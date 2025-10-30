/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "Apartment.h"


Apartment::Apartment() : Apartment(0, 0, 0, 0)
{
}

Apartment::Apartment(const Apartment& apartment) {
    *this = apartment;
}

Apartment::Apartment(int apartmentID, int noOfRooms, int price, int aptSize)
{
    setApartmentID(apartmentID);
    setNoOfRooms(noOfRooms);
    setPrice(price);
    setAptSize(aptSize);

    setApartmentCostType(Base);
}


void Apartment::printInformation()
{
    std::cout << "Room No:" << getApartmentID() << ", ";
    std::cout << "Number of Rooms:" << getNoOfRooms() << ", ";
    std::cout << "Rent:" << getPrice() << " GBP, ";
    std::cout << "Size:" << getAptSize() << " ";
}


int Apartment::getApartmentID() {
    return apartmentID;
}
void Apartment::setApartmentID(int ID) {
    apartmentID = ID;
}

int Apartment::getNoOfRooms() {
    return noOfRooms;
}
void Apartment::setNoOfRooms(int noOfRooms) {
    this->noOfRooms = noOfRooms;
}

int Apartment::getPrice() {
    return price;
}
void Apartment::setPrice(int price) {
    this->price = price;
}

int Apartment::getAptSize() {
    return aptSize;
}
void Apartment::setAptSize(int aptSize) {
    this->aptSize = aptSize;
}

apartCostType Apartment::getApartmentCostType() {
    return type;
}
void Apartment::setApartmentCostType(apartCostType type) {
    this->type = type;
}
