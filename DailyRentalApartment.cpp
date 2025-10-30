/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "DailyRentalApartment.h"


DailyRentalApartment::DailyRentalApartment() {
    setDecorationStyle(Minimalist);
}

DailyRentalApartment::DailyRentalApartment(int apartmentID, int noOfRooms, int price, int aptSize, apartType style) :Apartment(apartmentID, noOfRooms, price, aptSize)
{
    setDecorationStyle(style);
    setApartmentCostType(Daily);
}

void DailyRentalApartment::printInformation()
{
    Apartment::printInformation();
    std::cout << "Decoration Style: " << decorationStyleInText(getDecorationStyle()) << "\n";
}

Apartment* DailyRentalApartment::clone()
{
    Apartment *apart = new DailyRentalApartment(getApartmentID(), getNoOfRooms(), getPrice(), getAptSize(), getDecorationStyle());    
    return apart;
}

int DailyRentalApartment::calculateRentalPrice(int days) {
    return days * getPrice();
}



apartType DailyRentalApartment::getDecorationStyle() {
    return decorationStyle;
}
void DailyRentalApartment::setDecorationStyle(apartType style) {
    decorationStyle = style;
}
