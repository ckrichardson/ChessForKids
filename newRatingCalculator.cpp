#include "newRatingCalculator.h"
#include <cmath>
#include "StudentData.h"
#include <iostream>


//THIS ASSUMES THAT PLAYER ONE WINS!!!
void calculate(StudentData& playerOne, StudentData& playerTwo, bool draw)
{
  int playerOneScore = 1;
  int playerTwoScore = 0;

  //Rating volatility (too high and will change too much, too low and wont change)
  int ratingVolatility = 32;

  //transformed ratings
  float playerOneTransformed = 0;
  float playerTwoTransformed = 0;

  //win probabilites of individual players
  float estVictoryOne = 0;
  float estVictoryTwo = 0;

  //Resultant ratings of players
  float newRatingOne = 0;
  float newRatingTwo = 0;


  playerOneTransformed = pow(10, playerOne.getRating()/400);
  playerTwoTransformed = pow(10, playerTwo.getRating()/400);

  std::cout << "Transofrmed:  " << playerOneTransformed << " " << playerTwoTransformed;
  std::cout << "\nratings: " << playerOne.getRating() << "  " << playerTwo.getRating();

  estVictoryOne = playerOneTransformed/(playerOneTransformed + playerTwoTransformed);
  estVictoryTwo = playerTwoTransformed/(playerOneTransformed + playerTwoTransformed);

  if(draw == true)
  {
    playerOneScore = 0.5;
    playerTwoScore = 0.5;
  }

  newRatingOne = playerOne.getRating() + ratingVolatility * (playerOneScore - estVictoryOne);
  newRatingTwo = playerTwo.getRating() + ratingVolatility * (playerTwoScore - estVictoryTwo);



  playerOne.setLastRating(playerOne.getRating());
  playerTwo.setLastRating(playerTwo.getRating());

  playerOne.setRating(newRatingOne);
  playerTwo.setRating(newRatingTwo);

  





}
