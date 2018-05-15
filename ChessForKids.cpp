#include "StudentData.h"
#include "MenuFunctionalities.h"
#include <iostream>
#include <fstream>


#define STUDENT_MAX 1000

using namespace std;


int main()
{

  int studentCount = 0;

  ifstream infile;
  ofstream outfile;

  infile.open("Student_Data.txt");

  //Check whether data file exists.  If not, then create a file with necessary
  //initial data.
  if(!infile)
  {
    outfile.open("Student_Data.txt");
    outfile << "0";
    outfile.close();
  }


  //Initialize array of students
  StudentData studentArray[STUDENT_MAX];

  std::string first;
  std::string last;
  float rating = 0;
  int credit = 0;

  StudentData testStudent;


  //Input current available data

  infile >> studentCount;

  for(int i = 0; i < studentCount; i++)
  {
    infile >> first;
    infile >> last;
    infile >> rating;
    infile >> credit;
    studentArray[i].setFirstName(first);
    studentArray[i].setLastName(last);
    studentArray[i].setRating(rating);
    studentArray[i].setRemainingSessions(credit);
    studentArray[i].setEntryRating(studentArray[i].getRating());
  }

  infile.close();

  //Make sure data is up to date with version.  If new values for new features
  //do not exist, default values are assigned.
  update(studentCount, studentArray);

  //Goes to menu, in MenuFunctionalities
  menu(studentCount, studentArray);

  //Update one final time to make sure data is inputted
  update(studentCount, studentArray);




  /*
  StudentData newStudent("Clifford", "Richardson", 1387);
  cout << "First Name:  " << newStudent.getFirstName() << endl
       << "Last Name:  " << newStudent.getLastName() << endl
       << "Rating:  " << newStudent.getRating() << endl << endl;
  cout << "First Name:  " << studentArray[0].getFirstName() << endl
       << "Last Name:  " << studentArray[0].getLastName() << endl
       << "Rating:  " << studentArray[0].getRating() << endl << endl;

  */
  return 0;
}
