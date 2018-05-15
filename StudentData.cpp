#include "StudentData.h"
#include <iostream>






StudentData::StudentData(){

}

StudentData::StudentData(std::string firstName, std::string lastName, float rating)
{
  m_firstName = firstName;
  m_lastName = lastName;
  m_rating = rating;
  m_lastRating = 0;
  m_entryRating = 0;

}

//controls user first name, last name

std::string StudentData::getFirstName(){
  return m_firstName;
}

void StudentData::setFirstName(std::string firstName){
  m_firstName = firstName;
}

std::string StudentData::getLastName(){
  return m_lastName;
}

void StudentData::setLastName(std::string lastName){
  m_lastName = lastName;
}



//controls rating variables

float StudentData::getRating(){
  return m_rating;
}

void StudentData::setRating(float rating){
  m_rating = rating;
}

float StudentData::getLastRating(){
  return m_lastRating;
}

void StudentData::setLastRating(float lastRating){
  m_lastRating = lastRating;
}

float StudentData::getEntryRating(){
  return m_entryRating;
}

void StudentData::setEntryRating(float entryRating){
  m_entryRating = entryRating;
}

int StudentData::getRemainingSessions(){
  return m_remainingSessions;
}

void StudentData::setRemainingSessions(int remainingSessions){
  m_remainingSessions = remainingSessions;
}

bool StudentData::getRegistered()
{
  return m_registered;
}

void StudentData::setRegistered(bool registered)
{
  m_registered = registered;
}

int StudentData::getRatingDifference()
{
  return m_ratingDifference;
}

void StudentData::setRatingDifference(int ratingDifference)
{
  m_ratingDifference = ratingDifference;
}

void StudentData::operator=(StudentData student)
{
  this->setFirstName(student.getFirstName());
  this->setLastName(student.getLastName());
  this->setRating(student.getRating());
  this->setLastRating(student.getLastRating());
  this->setEntryRating(student.getEntryRating());
  this->setRemainingSessions(student.getEntryRating());
  this->setRegistered(student.getRegistered());
  this->setRatingDifference(student.getRatingDifference());
}
