/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "MonthlyRentalApartment.h"


MonthlyRentalApartment::MonthlyRentalApartment() {
	setHasFurniture(false);
}

MonthlyRentalApartment::MonthlyRentalApartment(int apartmentID, int noOfRooms, int price, int aptSize, bool furniture):Apartment(apartmentID, noOfRooms, price, aptSize)
{
	setHasFurniture(furniture);
	setApartmentCostType(Monthly);
}

void MonthlyRentalApartment::printInformation()
{
	Apartment::printInformation();
	std::cout << "Furnished: " <<  getBoolInText(getHasFurniture()) << "\n";
}

int MonthlyRentalApartment::calculateRentalPrice(int days) {	
	return std::ceil(days / 30.0) * getPrice();
}


const char* MonthlyRentalApartment::getBoolInText(bool val)
{
	if (val)
		return "Yes";
	return "No";
}


Apartment* MonthlyRentalApartment::clone()
{
	Apartment* apart = new MonthlyRentalApartment(getApartmentID(), getNoOfRooms(), getPrice(), getAptSize(), getHasFurniture());	
	return apart;
}


bool MonthlyRentalApartment::getHasFurniture() {
	return hasFurniture;
}
void MonthlyRentalApartment::setHasFurniture(bool furniture) {
	hasFurniture = furniture;
}


