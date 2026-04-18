# Car-Parking-management-system-

## 📌 Project Title  
Car Parking Management System Using C Programming

## 🎯 Objective  
The objective of this project is to create a simple C program that manages parking slots for cars. It allows users to park and remove cars, search for parked vehicles, view all occupied slots, and undo the last operation. This project demonstrates basic C programming concepts such as dynamic memory allocation, linked lists, stack operations, decision-making, and clean output formatting.

## 📝 Project Description  
This program allows the user to:
- Enter the number of parking slots  
- Park a car in the first available slot  
- Remove a parked car using its car number  
- View all parked cars with slot numbers  
- Search for a car and display its slot  
- Undo the last operation (park/remove)  
- Exit the system  

The program uses a linked list to manage parking slots dynamically and a stack (linked list) to implement undo functionality. It does not rely on any external storage and is designed for learning purposes.

## 🛠️ Technologies Used  
- C Programming Language  
- GCC Compiler (or any standard C compiler)  
- Terminal / Command Line for input and output  

## ⚙️ How to Compile, Run, Sample Input & Output  
Use the following commands:

gcc parking_system.c -o parking_system  
./parking_system  

(For Windows, use parking_system.exe)

Sample Input:  
Enter number of slots: 3  
1  
CAR1  
1  
CAR2  
1  
CAR3  
1  
CAR4  
3  
4  
CAR2  
2  
CAR2  
3  
5  
3  
6  

Sample Output:  
Car CAR1 parked at slot 1  
Car CAR2 parked at slot 2  
Car CAR3 parked at slot 3  
Parking Full  

Slot 1: CAR1  
Slot 2: CAR2  
Slot 3: CAR3  

Car CAR2 found at slot 2  

Car CAR2 removed from slot 2  

Slot 1: CAR1  
Slot 3: CAR3  

Undo successful  

Slot 1: CAR1  
Slot 2: CAR2  
Slot 3: CAR3  

## 📸 Screenshots  
Screenshots of the program output are included in this repository for verification.

## ⚠️ Assumptions  
- Each car number is unique  
- Slots are assigned in order (first available)  
- Only the last operation can be undone  
- No data is stored after program exit  
- Console-based application
