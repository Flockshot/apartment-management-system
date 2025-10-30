/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include <iostream>

#include "Agency.h"

int inputBuildingID(Agency& agency);
void addBuilding(Agency& agency, Building** buildings, int& buildingsCreated);
void addApartmentToBuilding(Agency& agency);
int calculateRent(Agency& agency);


int main()
{
    Agency agency("Manchester Comfort Apartments");
    Building** buildings = new Building * [30];
    int buildingsCreated = 0;

    std::cout << "!!!Welcome to Agency Management System!!!\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "Please select an operation\n";
    std::cout << "1. Add a new building to the agency\n";

    std::cout << "2. Add a new apartment (monthly or daily rental) to a building\n";
    std::cout << "3. List all buildings\n";
    std::cout << "4. List all apartments available for the agency\n";
    std::cout << "5. List all apartments that have the specified number of rooms\n";
    std::cout << "6. List all apartments which are bigger than the specified apartment size\n";
    std::cout << "7. List all apartments which are cheaper than the specified price in a specified number of days\n";
    std::cout << "8. List all apartments that are either daily or monthly rental\n";
    std::cout << "9. Calculate the price of a specific apartment in a specified number of days\n";
    std::cout << "0. Exit\n";

    int selection;
    do
    {
        std::cout << "---------------------------------------------\n";
        std::cout << "Your selection: ";
        std::cin >> selection;
        
        switch (selection)
        {
            case 1:
                addBuilding(agency, buildings, buildingsCreated);
                break;

            case 2:
                addApartmentToBuilding(agency);
                break;

            case 3:
                std::cout << "Buildings:\n";
                agency.printBuildings();
                break;

            case 4:
                std::cout << "In Building: \n";
                agency.printBuildingsWithApartments();
                break;

            case 5:
                int rooms;
                std::cout << "Enter the specified room number: ";
                std::cin >> rooms;

                agency.printBuildingsWithRoom(rooms);
                break;

            case 6:
                int size;
                std::cout << "Enter minimum size: ";
                std::cin >> size;

                agency.printBuildingsBiggerThan(size);
                break;

            case 7:
                int price, days;
                std::cout << "Enter the price (GBP): ";
                std::cin >> price;
                std::cout << "Enter the days: ";
                std::cin >> days;

                agency.printBuildingsCheaperThan(price, days);
                break;

            case 8:
                int aptType;
                do
                {
                    std::cout << "Enter Daily/Monthly Rental (0/1): ";
                    std::cin >> aptType;
                }
                while (!(aptType == 0 || aptType == 1));
                
                agency.printBuildingsWithApartments(apartCostType(++aptType));
                break;

            case 9:
                std::cout << "The rent for your stay is " << calculateRent(agency) << " GBP!\n";               
         
        }
    }
    while (selection != 0);

    std::cout << "Thanks for choosing Agency Management System!\n";
    std::cout << "---------------------------------------------\n";

    return 0;
}

int inputBuildingID(Agency& agency)
{
    int buildingID;
    std::cout << "Available Buildings:\n";

    agency.printBuildings();

    std::cout << "Building id: ";
    std::cin >> buildingID;

    return buildingID;
}

void addBuilding(Agency& agency, Building** buildings, int& buildingsCreated)
{
    char* address = new char[100];
    std::cout << "What is the address of your building: "<<std::endl;
    std::cin.ignore();
    std::cin.getline(address, 100);

    buildings[buildingsCreated] = new Building(buildingsCreated, address);
    agency.addBuilding(buildings[buildingsCreated]);

    std::cout << "The building is created with the id number " << buildingsCreated++ << ".\n";
    delete[] address;
}

void addApartmentToBuilding(Agency& agency)
{
    std::cout << "Which building you want to add apartment into ?\n";

    agency.addApartmentToBuilding(inputBuildingID(agency));

    std::cout << "Apartment successfully added!\n";
}

int calculateRent(Agency& agency)
{
    int roomNo;
    int days;
    int buildingID = inputBuildingID(agency);
    agency.printBuildingsApartmentsOnly(buildingID);

    std::cout << "Enter Room No: ";
    std::cin >> roomNo;
    std::cout << "Enter Number of Days: ";
    std::cin >> days;

    return agency.calculateRentalPriceByAptID(buildingID, roomNo, days);
}
