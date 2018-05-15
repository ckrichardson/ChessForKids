#ifndef STUDENT_DATA
#define  STUDENT_DATA

#include <string>



class StudentData
{

public:
  StudentData();
  StudentData(std::string firstName, std::string lastName, float rating);
  std::string getFirstName();
  void setFirstName(std::string firstName);
  std::string getLastName();
  void setLastName(std::string lastName);

  float getRating();
  void setRating(float rating);
  float getLastRating();
  void setLastRating(float lastRating);
  float getEntryRating();
  void setEntryRating(float entryRating);
  int getRemainingSessions();
  void setRemainingSessions(int remainingSessions);
  bool getRegistered();
  void setRegistered(bool registered);
  int getRatingDifference();
  void setRatingDifference(int ratingDifference);

  void operator=(StudentData student);








private:
 std::string m_firstName;
 std::string m_lastName;

 float m_rating = 0;
 float m_lastRating = 0;
 float m_entryRating = 0;

 int m_remainingSessions = 0;

 bool m_registered = false;

 int m_ratingDifference = 0;





};



#endif
