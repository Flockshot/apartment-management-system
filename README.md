# Apartment Agency Management System (C++)

Built a C++ console application simulating an apartment rental agency's management system, designed to handle various property types and client queries efficiently.

This project is a deep dive into C++ Object-Oriented Programming (OOP) and manual memory management, built from the ground up without using standard library containers like `std::vector` or `std::string`.

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)

---

## 🏛️ Project Architecture

The system is built on a clear hierarchical structure, with each class managing its own dynamic resources.

* **`Agency`:** The top-level class. It holds a dynamic array of `Building*` pointers.
* **`Building`:** A mid-level class. It holds a dynamic array of `Apartment*` pointers.
* **`Apartment`:** An abstract base class that defines the common interface for all rental properties. It uses pure virtual functions for `calculateRentalPrice()` and `clone()`.
* **`DailyRentalApartment`:** A concrete class inheriting from `Apartment`. It calculates rent on a per-day basis.
* **`MonthlyRentalApartment`:** A concrete class inheriting from `Apartment`. It calculates rent by the 30-day month (pro-rated).

### UML Class Diagram


![](https://mermaid.ink/img/pako:eNrFVltr2zAY_StGY5CkTkjqXGpTCrlsLA_dRlsYjLyotmKL2ZKRZFia9b9PsmNZvmTLxmB5SPRJ-s7Rd46k6Ah8GiDgAT-GnG8wDBlMdsSSn7dvrQcUQ4Ep4RFOedG7DBHxDxYdDq0dGI9GzngHrFWG4wCT0PLkeMhQCAU6zddDg1rGMoVMJIgImbKmSUp5mVCN3P6QKRuI48ODDGFs5mxJhBgW3Tn3lIjo11m6xA1KEQlkTRhxixLrHcmSFupodGdBFa0pF0-HFEmsTK-4c4k6pTZd066V3CVArn2p7LHoU5-hH0E2sAhMkNFZKjoYWM-nJjeGsSQn9NN-1R67Kih6_XZXxWQOwiAoYXqaVrM2Zuran6hOUospp283ZkLK5JheY-_80BcsIg1dn-jD2M_kDkWF-J8Z9tHqsEzFdtNgti0VQzVSNAN44H3VMpQLkWZVpC2Qvt7MgyLrtTS0MFBv9WPDDhy0PJV6McRN33SN0leo6-0wdtkxeFVTHAe2VaM551Rb9r9UWjGek9VnSCbmh6QiVpMZpclHWiSqwh5kzIuQyTlFi-MX1K-O4qAFfDrs_wy6YWp1og1Xb2-Xz1ww6Iu7u4ZD2rrtpsO7fB2N_lSJ2UIRj3J1Rm_9-hHyyzzEteJLM1hVdM5hVP0ba3vay0HdzCs_pgT1ZHeXI8UW2pI9ZUn-v2HuoTccVburLKTXLqvfaUPnHXts6pODBMinLKd_FIfYlKkL5ELFbOMy5wr2cgm7FfxzAdX9tKnXJmH0sjplO_NPaAr3TGlsRZC_zxjBImOmYN3pF0uWQ-9L3P-j2AejMomhltSpVH0j1s66ehKgQnXzuK8gN7TK91YVnpQ7T3UxzT0mOIEx5sJEDxAjVZy_JrB_YgM2CBkOgCdYhmwgQROoQpDT7YCIkHxQAE82A8i-7cCOqJwUkq_SzDKN0SyMgLeHMZdRlgbqEi_eh3qKejmxNc2IAN7kepxjAO8IvstwMh3NZ87EWVxP3NmN_LbBAXjD2fXIXUyni-l4MnccZ-bOXm3wkvOOR-587Lru4mZ-M3MW7tixAQqwoOz-9EZVP68_AbScYqE?type=png)](https://mermaid.live/edit#pako:eNrFVltr2zAY_StGY5CkTkjqXGpTCrlsLA_dRlsYjLyotmKL2ZKRZFia9b9PsmNZvmTLxmB5SPRJ-s7Rd46k6Ah8GiDgAT-GnG8wDBlMdsSSn7dvrQcUQ4Ep4RFOedG7DBHxDxYdDq0dGI9GzngHrFWG4wCT0PLkeMhQCAU6zddDg1rGMoVMJIgImbKmSUp5mVCN3P6QKRuI48ODDGFs5mxJhBgW3Tn3lIjo11m6xA1KEQlkTRhxixLrHcmSFupodGdBFa0pF0-HFEmsTK-4c4k6pTZd066V3CVArn2p7LHoU5-hH0E2sAhMkNFZKjoYWM-nJjeGsSQn9NN-1R67Kih6_XZXxWQOwiAoYXqaVrM2Zuran6hOUospp283ZkLK5JheY-_80BcsIg1dn-jD2M_kDkWF-J8Z9tHqsEzFdtNgti0VQzVSNAN44H3VMpQLkWZVpC2Qvt7MgyLrtTS0MFBv9WPDDhy0PJV6McRN33SN0leo6-0wdtkxeFVTHAe2VaM551Rb9r9UWjGek9VnSCbmh6QiVpMZpclHWiSqwh5kzIuQyTlFi-MX1K-O4qAFfDrs_wy6YWp1og1Xb2-Xz1ww6Iu7u4ZD2rrtpsO7fB2N_lSJ2UIRj3J1Rm_9-hHyyzzEteJLM1hVdM5hVP0ba3vay0HdzCs_pgT1ZHeXI8UW2pI9ZUn-v2HuoTccVburLKTXLqvfaUPnHXts6pODBMinLKd_FIfYlKkL5ELFbOMy5wr2cgm7FfxzAdX9tKnXJmH0sjplO_NPaAr3TGlsRZC_zxjBImOmYN3pF0uWQ-9L3P-j2AejMomhltSpVH0j1s66ehKgQnXzuK8gN7TK91YVnpQ7T3UxzT0mOIEx5sJEDxAjVZy_JrB_YgM2CBkOgCdYhmwgQROoQpDT7YCIkHxQAE82A8i-7cCOqJwUkq_SzDKN0SyMgLeHMZdRlgbqEi_eh3qKejmxNc2IAN7kepxjAO8IvstwMh3NZ87EWVxP3NmN_LbBAXjD2fXIXUyni-l4MnccZ-bOXm3wkvOOR-587Lru4mZ-M3MW7tixAQqwoOz-9EZVP68_AbScYqE)

---

## 🚀 Core Concepts Demonstrated

This project was built to C-style specifications, providing a strong focus on core C++ mechanics.

* **Object-Oriented Programming:** A fully encapsulated system built on class hierarchies.
* **Inheritance & Polymorphism:** Used an abstract base class (`Apartment`) with pure virtual functions (`calculateRentalPrice`) to allow the `Agency` to manage different apartment types polymorphically.
* **Manual Memory Management:** All "strings" are C-style `char*` and all collections are C-style dynamic arrays of pointers (`Building**`, `Apartment**`). This required manual allocation with `new` and deallocation with `delete`/`delete[]`.
* **The Rule of Three (and Five):** To handle the manual memory, every class (`Agency`, `Building`, `Apartment`, etc.) correctly implements its own Destructor, Copy Constructor, and Copy Assignment Operator to ensure deep copying and prevent memory leaks or shallow-copy bugs.

---

## ✨ Features

The application runs as a command-line interface (CLI) that allows the user to:

* **Add New Buildings:** Dynamically add new buildings to the agency.
* **Add New Apartments:** Add new `DailyRentalApartment` or `MonthlyRentalApartment` objects to any building.
* **List All Properties:** Display all buildings and their corresponding apartments.
* **Complex Filtering:** List apartments based on specific criteria:
    * By number of rooms
    * By size (area in m²)
    * By rental type (Daily vs. Monthly)
    * By price (cheaper than a given amount for a specific duration)
* **Polymorphic Price Calculation:** Select any apartment by ID and calculate its exact rental price for a specified number of days, letting the object itself (daily or monthly) determine the correct cost.

---

## 💻 How to Compile and Run

This project consists of multiple `.cpp` and `.h` files. They must all be compiled and linked together.

### 1. Compile
Using a compiler like `g++`, you can compile all source files into a single executable:

```bash
g++ main.cpp Agency.cpp Building.cpp Apartment.cpp DailyRentalApartment.cpp MonthlyRentalApartment.cpp apartCostType.cpp apartType.cpp -o apartment_manager
```

### 2. Run
Execute the compiled program from your terminal:

```bash
./apartment_manager
```

---

## ⌨️ Example Usage (CLI)

The following is a sample run, demonstrating the system's functionality (based on the project specification appendix).



```bash
!!!Welcome to Agency Management System!!!
---------------------------------------------
Please select an operation
1. Add a new building to the agency
2. Add a new apartment (monthly or daily rental) to a building
3. List all buildings
4. List all apartments available for the agency
5. List all apartments that have the specified number of rooms
6. List all apartments which are bigger than the specified apartment size
7. List all apartments which are cheaper than the specified price in a specified number of days
8. List all apartments that are either daily or monthly rental
9. Calculate the price of a specific apartment in a specified number of days
0. Exit
---------------------------------------------
Your selection: 1
What is the address of your building:
Academia Apartments, 17 Warwick Rd, Old Trafford, Manchester M16 10XY
The building is created with the id number 0.
---------------------------------------------
Your selection: 2
Which building you want to add apartment into?
Available Buildings:
ID: 0, Address: Academia Apartments, 17 Warwick Rd, Old Trafford, Manchester M16 10XY
Building id: 0
What is the type of the apartment?
1. Daily Rental Apartment
2. Monthly Rental Apartment

Type: 1
Enter room number: 1
Enter number of rooms: 3
Enter rent (GBP): 86
Enter size (m2): 100
Decoration Style:
1. Minimalist
2. Modern
3. Classic
Your selection: 3
Apartment successfully added!
---------------------------------------------
Your selection: 2
Which building you want to add apartment into?
Available Buildings:
ID: 0, Address: Academia Apartments, 17 Warwick Rd, Old Trafford, Manchester M16 10XY
Building id: 0
What is the type of the apartment?
1. Daily Rental Apartment
2. Monthly Rental Apartment

Type: 2
Enter room number: 2
Enter number of rooms: 1
Enter rent (GBP): 1200
Enter size (m2): 70
Furnished (Yes(1) / No (0)): 1
Apartment successfully added!
---------------------------------------------
Your selection: 4
In Building: 
ID: 0, Address: Academia Apartments, 17 Warwick Rd, Old Trafford, Manchester M16 10XY
Daily Rental Apartments:
Room No:1, Number of Rooms:3, Rent:86 GBP, Size:100 Decoration Style: Classic
Monthly Rental Apartments:
Room No:2, Number of Rooms:1, Rent:1200 GBP, Size:70 Furnished: Yes
---------------------------------------------
Your selection: 9
Available Buildings:
ID: 0, Address: Academia Apartments, 17 Warwick Rd, Old Trafford, Manchester M16 10XY
Building id: 0
Room No:1, Number of Rooms:3, Rent:86 GBP, Size:100 Decoration Style: Classic
Room No:2, Number of Rooms:1, Rent:1200 GBP, Size:70 Furnished: Yes
Enter Room No: 2
Enter Number of Days: 80
The rent for your stay is 3600 GBP!
---------------------------------------------
Your selection: 0
Thanks for choosing Agency Management System!
---------------------------------------------
```