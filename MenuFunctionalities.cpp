#include "MenuFunctionalities.h"
#include "newRatingCalculator.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>

#define STUDENT_MAX 1000

void intro()
{
  std::cout << "\n\n\n                          Hello.  Welcome to Pawnstorm!" << std::endl
       << "                        Copyright Clifford Richardson 2017" << std::endl << std::endl;
}


void menu(int& studentCount, StudentData studentArray[])
{
  char input;
  std::string newl = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";


  do{
    intro();
    std::cout << "\n\nHow may I help you?\n\n"
              << "1:  Record Result\n"
              << "2:  Register Student\n"
              << "3:  Add New Student\n"
              << "4:  See Stats\n"
              << "5:  See Current Results\n"
              << "6:  Exit\n\n"
              << "d:  Edit Data \n\n|<<  ";

    std::cin >> input;

    switch(input)
    {
      case '1':
        recordResult(studentCount, studentArray);
        update(studentCount, studentArray);

        break;
      case '2':
        registerStudent(studentCount, studentArray);
        std::cout << newl;
        break;
      case '3':
        addNewStudent(studentCount, studentArray);
        update(studentCount, studentArray);
        std::cout << newl;
        break;
      case '4':
        seeStats();
        std::cout << newl;
        break;
      case '5':
        seeCurrentResults(studentCount, studentArray);
        std::cout << newl;
        break;
      case '6':
        return;
      case 'd':
        edit(studentCount, studentArray);
        update(studentCount, studentArray);
        std::cout << newl;
        break;
      default:
        std::cout << newl;
        std::cout << "\n\nThe entered value is not valid.  Please enter a number 1 - 6, or valid letter.";
    }
  }while(true);


}

// 1

void recordResult(int studentCount, StudentData studentArray[])
{
  int indexOne = 0;
  int indexTwo = 0;

  char input = NULL;

  bool promptUser = false;

  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

  std::cout << "Game Record Format -- <PLAYER 1> defeats <PLAYER 2>\n\n";

  std::cout << "PLAYER 1:  ";

  indexOne = searchForStudent(studentCount, studentArray, promptUser);

  std::cout << "    defeats  " << "\nPLAYER 2:  ";

  indexTwo = searchForStudent(studentCount, studentArray, promptUser);

  std::cout << "\n\nConfirm Result:  \n";

  std::cout << studentArray[indexOne].getFirstName() << " "
            << studentArray[indexOne].getLastName() << "  defeats  "
            << studentArray[indexTwo].getFirstName() << " "
            << studentArray[indexTwo].getLastName();

  if(studentArray[indexOne].getRegistered() == false)
  {
    std::cout << "\n\nWARNING:  "  << studentArray[indexOne].getFirstName() << " "
              << studentArray[indexOne].getLastName() << " is NOT registered!";
  }

  if(studentArray[indexTwo].getRegistered() ==false)
  {
    std::cout << "\n\nWARNING:  "  << studentArray[indexTwo].getFirstName() << " "
              << studentArray[indexTwo].getLastName() << " is NOT registered!";
  }


  std::cin.get();

  std::cout << "\n\nEnter y to confirm results (e = exit)...   ";

  while(true)
  {
    std::cin >> input;
    if(input == 'y')
    {
      calculate(studentArray[indexOne], studentArray[indexTwo], false);
      std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
      std::cout << "New Ratings: \ns" << std::endl;
      std::cout << studentArray[indexOne].getFirstName() << " "
                << studentArray[indexOne].getLastName() << " "
                <<"- (" << studentArray[indexOne].getRating() << ")"
                << std::endl << studentArray[indexTwo].getFirstName() << " "
                << studentArray[indexTwo].getLastName() << " - ("
                << studentArray[indexTwo].getRating() << ")";
      return;
    }
    if(input == 'e')
    {
      return;
    }
  }




}

// 2

void registerStudent(int& studentCount, StudentData studentArray[])
{

//Use search to obtain desired index.
bool promptUser = false;
std::string confirmation;
int index = 0;

std::cout << "Search for:  ";

index  = searchForStudent(studentCount, studentArray, promptUser);

  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

  std::cout << "Confirm entry of " << studentArray[index].getFirstName() << " "
            << studentArray[index].getLastName() << "?  "
            << "(enter y/n, e to exit)" << std::endl;



    while(true)
    {
          std::cout << "|<< ";
          std::cin >> confirmation;
          std::cout << std::endl;
      if(confirmation == "y" || confirmation == "Y")
      {
          studentArray[index].setRegistered(true);
          return;
      }
      else if(confirmation == "n" || confirmation == "N")
      {
          std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          std::cout << "\n\n\n" << "Search Again -- Search for:  ";
          promptUser = true;
          index = searchForStudent(studentCount, studentArray, promptUser);
          if(index == NULL)
          {
            std::cout << "\n\nNo results for keyword found.";
            return;
          }
          std::cout << "Confirm entry of " << studentArray[index].getFirstName() << " "
                    << studentArray[index].getLastName() << "?  "
                    << "(enter y/n, e to exit)" << std::endl;
    }
    else if(confirmation == "e" || confirmation == "E")
    {
      return;
    }
    else{
      std::cout << "Invalid value.  Y or N or E only!" << std::endl;
    }




    }









}

// 3

void addNewStudent(int& studentCount, StudentData studentArray[])
{
  if(studentCount == STUDENT_MAX)
  {
    std::cout << "\n\nNo more space available!  Please contact Developer.\n\n";
    return;
  }

  std::string firstName;
  std::string lastName;
  float rating = 0;
  int remainingSessions = 0;


  std::cout << "\n\nPlease enter first name:  ";
  std::cin >> firstName;

  std::cout << "\n\nPlease enter last name:  ";
  std::cin >> lastName;

  std::cout << "\n\nPlease enter rating (existing or new):  ";
  std::cin >> rating;

  std::cout << "\n\nPlease enter remaining sessions available:  ";
  std::cin >> remainingSessions;

  studentArray[studentCount].setFirstName(firstName);
  studentArray[studentCount].setLastName(lastName);
  studentArray[studentCount].setRating(rating);
  studentArray[studentCount].setRemainingSessions(remainingSessions);

  std::cout << studentArray[studentCount].getFirstName();
  std::cout << studentArray[studentCount].getLastName();
  std::cout << studentArray[studentCount].getRating();
  std::cout << studentArray[studentCount].getRemainingSessions();

  studentCount++;







}

// 4

void seeStats()
{

}

// 5

void seeCurrentResults(int studentCount, StudentData studentArray[])
{
  int fieldWidth = 50;
  int innerFieldWidth = 25;
  int tracker = 0;
  int totalLength = 0;
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

  std::cout << "                               -Current Rankings-\n\n\n";

  StudentData studentArrayCopy[studentCount];

  for(int i  = 0; i < studentCount; i++)
  {
    if(studentArray[i].getRegistered() == true)
    {
      studentArrayCopy[tracker] = studentArray[i];

      tracker++;
    }
  }

  std::sort(studentArrayCopy, studentArrayCopy + tracker, wayToSort);

  for(int i = 0; i < tracker; i++)
  {
    totalLength = studentArrayCopy[i].getLastName().length() + 1;

    if(i <= 3)
    {
      if(i == 0)
      std::cout <<"||__xX 1ST PLACE:\t";
      if(i == 1)
      std::cout <<"       2nd Place:\t";
      if(i == 2)
      std::cout <<"       3rd Place:\t";
      if(i == 3)
      std::cout << "\n\n";
    }
    if( i >= 3)
    {
      std::cout << i + 1 << ". ";

    }


    std::cout << studentArrayCopy[i].getLastName() << std::setw(innerFieldWidth - totalLength);

    std::cout << studentArrayCopy[i].getFirstName()
              << std::setw(15)
              << studentArrayCopy[i].getRating()
              << std::setw(5)
              << "(";



    studentArrayCopy[i].setRatingDifference(studentArrayCopy[i].getRating() - studentArrayCopy[i].getEntryRating());

    if(studentArrayCopy[i].getRatingDifference() >= 0)
    {
      std::cout << "+";
    }


    std::cout << studentArrayCopy[i].getRatingDifference() << ")";

    if(i == 0)
    std::cout << " Xx__||";

    std::cout << std::endl;

    if(i < 3)
    {

      std::cout << std::endl;
      if(i == 0)
      std::cout << std::endl;

    }
  }


}

bool wayToSort(StudentData studentOne, StudentData studentTwo)
{
  return studentOne.getRating() - studentOne.getEntryRating() >  studentTwo.getRating() - studentTwo.getEntryRating();
}


void edit(int studentCount, StudentData studentArray[])
{
  char input;
  std::string newName;
  int newVal = 0;
  int index = 0;


  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

  std::cout << "Please enter name of student:  ";

  index = searchForStudent(studentCount, studentArray, false);

  std::cout << "Loading Data for " << studentArray[index].getFirstName() << " "
            << studentArray[index].getLastName() << "...\n\n";
  std::cout << "Please select the data to edit: " << std::endl << std::endl;


    while(true)
    {

        std::cout << "A:  First Name\n"
                  << "B:  Last Name\n"
                  << "C:  Rating\n"
                  << "D:  Remaining Sessions\n"
                  << "E:  Exit\n\n|<<  ";

      std::cin >> input;
      switch(input)
      {

        case 'a':  case 'A':
          std::cout << "\n\nEnter new first name:  ";
          std::cin >> newName;
          studentArray[index].setFirstName(newName);

          break;
        case 'b':  case 'B':
          std::cout << "\n\nEnter new lastname:  ";
          std::cin >> newName;
          studentArray[index].setLastName(newName);
          break;
        case 'c':  case 'C':
          std::cout << "\n\nEnter new rating:  ";
          std::cin >> newVal;
          studentArray[index].setRating(newVal);
          break;
        case 'd':  case 'D':
          std::cout << "\n\nEnter new Remainign Sessions:  ";
          std::cin >> newVal;
          studentArray[index].setRemainingSessions(newVal);
          break;
        case 'e':  case 'E':
          return;
        default:
          std::cout << "\n\n\n\n\nValue entered is not valid.  Please try again.";


      }
    }
}


//updates data file
void update(int studentCount, StudentData studentArray[])
{
  std::ofstream outfile;
  outfile.open("Student_Data.txt");

  //Output new data once more at the end of the program.

  outfile << studentCount << std::endl;

  for(int i = 0; i < studentCount; i++)
  {
    outfile << studentArray[i].getFirstName() << " ";
    outfile << studentArray[i].getLastName() << " ";
    outfile << studentArray[i].getRating() << " ";
    outfile << studentArray[i].getRemainingSessions() << " ";
    /*
    cout << studentArray[i].getFirstName() << " ";
    cout << studentArray[i].getLastName() << " ";
    cout << studentArray[i].getRating() << " ";
    cout << studentArray[i].getRemainingSessions() << " ";
    cout << endl;
    */
    outfile << std::endl;
  }

  outfile.close();

}

void newVersionUpdater(int studentCount, StudentData studentArray[])
{
  update(studentCount, studentArray);
}

int searchForStudent(int studentCount, StudentData studentArray[], bool promptUser)
{
  int indecies[50] = {0};
  std::string name;
  std::string arrayName;
  StudentData save;
  int found = 0;
  int alphabet[26] = {0};
  int hits[26] = {0};
  int matches = 0;
  int count = 0;
  int greatest = 0;
  int searchSelection = 0;


    std:: cin >> name;





  //Lots of switches to look and count all the letters that exist in both the
  //input and the stored data.


  for(int j = 0; j < name.size(); j++)
  {
    switch(name[j])
    {
      case 'a':  case 'A':
        alphabet[0]++;
        break;
      case 'b':  case 'B':
        alphabet[1]++;
        break;
      case 'c':  case 'C':
        alphabet[2]++;
        break;
      case 'd':  case 'D':
        alphabet[3]++;
        break;
      case 'e':  case 'E':
        alphabet[4]++;
        break;
      case 'f':  case 'F':
        alphabet[5]++;
        break;
      case 'g':  case 'G':
        alphabet[6]++;
        break;
      case 'h':  case 'H':
        alphabet[7]++;
        break;
      case 'i':  case 'I':
        alphabet[8]++;
        break;
      case 'j':  case 'J':
        alphabet[9]++;
        break;
      case 'k':  case 'K':
        alphabet[10]++;
        break;
      case 'l':  case 'L':
        alphabet[11]++;
        break;
      case 'm':  case 'M':
        alphabet[12]++;
        break;
      case 'n':  case 'N':
        alphabet[13]++;
        break;
      case 'o':  case 'O':
        alphabet[14]++;
        break;
      case 'p': case 'P':
        alphabet[15]++;
        break;
      case 'q':  case 'Q':
        alphabet[16]++;
        break;
      case 'r':  case'R':
        alphabet[17]++;
        break;
      case 's':  case 'S':
        alphabet[18]++;
        break;
      case 't':  case 'T':
        alphabet[19]++;
        break;
      case 'u':  case 'U':
        alphabet[20]++;
        break;
      case 'v':  case 'V':
        alphabet[21]++;
        break;
      case 'w':  case 'W':
        alphabet[22]++;
        break;
      case 'x':  case 'X':
        alphabet[23]++;
        break;
      case 'y':  case 'Y':
        alphabet[24]++;
        break;
      case 'z':  case 'Z':
        alphabet[25]++;
        break;
      default:
        break;

    }
  }



  for(int i = 0; i < studentCount; i++, studentArray++)
  {
    matches = 0;


    for(int j = 0; j < studentArray->getFirstName().size(); j++)
    {
      arrayName = studentArray->getFirstName();

      switch(arrayName[j])
      {
        case 'a':  case 'A':
          hits[0]++;
          break;
        case 'b':  case 'B':
          hits[1]++;
          break;
        case 'c':  case 'C':
          hits[2]++;
          break;
        case 'd':  case 'D':
          hits[3]++;
          break;
        case 'e':  case 'E':
          hits[4]++;
          break;
        case 'f':  case 'F':
          hits[5]++;
          break;
        case 'g':  case 'G':
          hits[6]++;
          break;
        case 'h':  case 'H':
          hits[7]++;
          break;
        case 'i':  case 'I':
          hits[8]++;
          break;
        case 'j':  case 'J':
          hits[9]++;
          break;
        case 'k':  case 'K':
          hits[10]++;
          break;
        case 'l':  case 'L':
          hits[11]++;
          break;
        case 'm':  case 'M':
          hits[12]++;
          break;
        case 'n':  case 'N':
          hits[13]++;
          break;
        case 'o':  case 'O':
          hits[14]++;
          break;
        case 'p': case 'P':
          hits[15]++;
          break;
        case 'q':  case 'Q':
          hits[16]++;
          break;
        case 'r':  case'R':
          hits[17]++;
          break;
        case 's':  case 'S':
          hits[18]++;
          break;
        case 't':  case 'T':
          hits[19]++;
          break;
        case 'u':  case 'U':
          hits[20]++;
          break;
        case 'v':  case 'V':
          hits[21]++;
          break;
        case 'w':  case 'W':
          hits[22]++;
          break;
        case 'x':  case 'X':
          hits[23]++;
          break;
        case 'y':  case 'Y':
          hits[24]++;
          break;
        case 'z':  case 'Z':
          hits[25]++;
          break;
        default:
          break;

      }


      arrayName = studentArray->getLastName();

      switch(arrayName[j])
      {
        case 'a':  case 'A':
          hits[0]++;
          break;
        case 'b':  case 'B':
          hits[1]++;
          break;
        case 'c':  case 'C':
          hits[2]++;
          break;
        case 'd':  case 'D':
          hits[3]++;
          break;
        case 'e':  case 'E':
          hits[4]++;
          break;
        case 'f':  case 'F':
          hits[5]++;
          break;
        case 'g':  case 'G':
          hits[6]++;
          break;
        case 'h':  case 'H':
          hits[7]++;
          break;
        case 'i':  case 'I':
          hits[8]++;
          break;
        case 'j':  case 'J':
          hits[9]++;
          break;
        case 'k':  case 'K':
          hits[10]++;
          break;
        case 'l':  case 'L':
          hits[11]++;
          break;
        case 'm':  case 'M':
          hits[12]++;
          break;
        case 'n':  case 'N':
          hits[13]++;
          break;
        case 'o':  case 'O':
          hits[14]++;
          break;
        case 'p': case 'P':
          hits[15]++;
          break;
        case 'q':  case 'Q':
          hits[16]++;
          break;
        case 'r':  case'R':
          hits[17]++;
          break;
        case 's':  case 'S':
          hits[18]++;
          break;
        case 't':  case 'T':
          hits[19]++;
          break;
        case 'u':  case 'U':
          hits[20]++;
          break;
        case 'v':  case 'V':
          hits[21]++;
          break;
        case 'w':  case 'W':
          hits[22]++;
          break;
        case 'x':  case 'X':
          hits[23]++;
          break;
        case 'y':  case 'Y':
          hits[24]++;
          break;
        case 'z':  case 'Z':
          hits[25]++;
          break;
        default:
          break;

      }
    }

    //Search for whether there are sequential matches in the string.  Any
    //matches found will be recorded, by length of the found string, into
    //matches.

    std::string tempArrayName;
    tempArrayName = studentArray->getFirstName();

    for(int i = 0; i < name.length(); i++)
    {
      if(name[i] <= 90)
      {
        name[i] += 32;
      }
    }

    for(int i = 0; i < tempArrayName.length(); i++)
    {
      if(tempArrayName[i] <= 90)
      {
        tempArrayName[i] += 32;
      }
    }

    // debugging test code to make sure data transfer is correct
    // std::cout << "\n\n" << tempArrayName << '\n' << name;

    if(tempArrayName.find(name) != std::string::npos)
    {
        matches += name.length();
    }

    tempArrayName = studentArray->getLastName();

    for(int i = 0; i < arrayName.length(); i++)
    {
      if(tempArrayName[i] <= 90)
      {
        tempArrayName[i] += 32;
      }
    }


    if(tempArrayName.find(name) != std::string::npos)
    {
      matches += name.length();
    }


    //Add to match score if there are the same letters.  If the same number of
    //Letters do not exist, then the number of letters in the searched string
    //is added into matches.
    for(int l = 0; l < 26; l++)
    {
      //std::cout << hits[l] << ".";

      //std::cout << alphabet[l] << "-";
        if(alphabet[l] == hits[l] && (alphabet[l] != 0 && hits[l] != 0) || hits[l] < alphabet[l])
        {
          matches += hits[l];

        }

        if(alphabet[l] != 0 && hits[l] != 0 && hits[l] > alphabet[l])
        {
          matches += alphabet[l];
        }



      hits[l] -= hits[l];

    }




    //Indexes possible results by matches, including sequential matches.
    //Only the highest scores will be recorded to provide accurate results.




    if(matches >= greatest && matches != 0)
    {
      if(matches >= greatest)
      {
        indecies[count++] = i;
        found++;
      }


      greatest = matches;



      //std::cout << "MATCH: ";
    }

    /*
    if(matches >= greatest && matches != 0 && studentArray->getRegistered() == true)
    {
      greatest = matches;
    }
    */

    /*
    std::cout << studentArray->getFirstName();
    std::cout << std::endl << "Matches:  " << matches << " ";
    std::cout << std::endl << "greatest:  " << greatest << " ";
    std::cout << std::endl << "count:  " << count << " " << " ";
    std::cout << std::endl << "registered:  " << studentArray->getRegistered() << std::endl;
    */




  }




//For some reason the fucking studentArray can only be used as a pointer
studentArray -= studentCount;





//Display most likely results

int tracker = 0;

/*
std::cout << "Found:  " << found << std::endl;
std::cout << "Count:  " << count << std::endl;


for(int i = 0; i < count; i++)
{
  std::cout << indecies[i] << "-";
}
*/



// user manual selects choice when promptUser is true (used for registration)
// auto return highest match currently used for recording games



//std::cout << "Count is " << count;

  if(count != 0)
  {
    if(promptUser == 1)
    {
            std::cout << "                              -Search Results-\n\n\n\n";
            for(int i = count - 1; i >= 0; i--)
             {

               tracker++;
               //std::cout << "INDEX:  " << indecies[i] << std::endl;
               //std::cout << std::endl << "here" << studentArray->getLastName();

               std::cout << std::endl << tracker << ":  " << i << studentArray[indecies[i]].getLastName() << ", "
                         << studentArray[indecies[i]].getFirstName() << "  ||  " << studentArray[indecies[i]].getRating();


             }

             std::cout << "\n\n\nPlease enter desired selection (#)\n|<<   ";
             std::cin >> searchSelection;

             std::cout << indecies[count - searchSelection];

             return indecies[count - searchSelection];
    }






    return indecies[count - 1];
  }
  else
  {
    return NULL;
  }
//}
//else
//{
//  return count - 1;
//}





}
