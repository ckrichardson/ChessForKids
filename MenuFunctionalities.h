#ifndef MENU_FUNCTIONALITIES
#define MENU_FUNCTIONALITIES

#include "StudentData.h"

void intro();
void menu(int& studentCount, StudentData studentArray[]);
void recordResult( int studentCount, StudentData studentArray[] );
void registerStudent(int& studentCount, StudentData studentArray[]);
void addNewStudent(int& studentCount, StudentData studentArray[]);
void seeStats();
void seeCurrentResults(int studentCount, StudentData studentArray[]);
void edit(int studentCount, StudentData studentArray[]);

int searchForStudent(int studentCount, StudentData studentArray[], bool promptUser);
bool wayToSort(StudentData studentOne, StudentData studentTwo);

void update(int studentCount, StudentData studentArray[]);
void newVersionUpdater(int studentCount, StudentData studentArray);



#endif
