// Application Program File

#include <iostream>
#include <cstdlib>

using namespace std;

#include "Elise_Zur_Die.h"

// function prototypes
int user_input();
void score_calc(Die, int &);
void results(int, int);
void winner();
void loser();
void tie();

int main()
{
  srand(time(0));

  // COMMENT ONE
  // two different Die objects are created here
  // two six-sided dice are needed to play as
  // the player and computer share the same two dice
  Die dice1{6};
  Die dice2{6};
  
  int player_score = 0;
  int computer_score = 0;
  char choice = ' ';
  
  cout << "Let's play a game of 21!\n\n";
  cout << "-----------------------------\n";
  
  // COMMENT TWO
  // user input validation is implemented directly
  // into the code by using a while loop.
  // the loop validates that as long as the player's
  // score is less than or equal to 21, the loop
  // will continue.
  while (player_score <= 21)
  {
    // COMMENT THREE
    // here, the function user_input() is called
    // which will prompt the user to enter their
    // choice to either continue or stop.
    // the choice variable will be used to
    // verify the user's choice
   choice = user_input();
    
    // COMMENT FOUR
    // again, user input validation is embedded
    // directly into the code. using an if statement
    // the code is ensuring that as long as the
    // user enters Y/y, the program will continue
    // through this statement. if it is not entered
    // then it skips this chunk of code completely.
    if (choice == 'Y' or choice == 'y')
    {
      // COMMENT FIVE
      // inside the if statement, the program encounters
      // where the dice roll and score keeping will be
      // accomplished.
      // score_calc() is a versatile function that
      // will accept any dice and any user's score to
      // keep track of the value.
      
      // computer's turn
      score_calc(dice1, computer_score);
      
      // COMMENT SIX
      // the player's total score is revealed to the
      // console meanwhile the computer's score is
      // hidden throughout the game. not until the
      // user is done playing will the computer's
      // score be revealed.
      
      // player 1's turn
      score_calc(dice2, player_score);
      cout << "\n\tYou have " << player_score << " points.\n\n";

    }
    
    // COMMENT SEVEN
    // once the user finally enters N/n to
    // stop the loop of rolling the die and
    // adding to the score. when the user
    // enters N/n the if statement breaks out
    // of the control statement and will start
    // outputting the final statements.
    if (choice == 'N' or choice == 'n')
      break;
    
  }
  // COMMENT EIGHT
  // these output statements will print to the
  // console the final results statements.
  // it will output the computer's score
  // and below that, it will be the player's
  // score.
  cout << "\nThe computer had " << computer_score << " points.\n";
  cout << "You had " << player_score << " points.\n";
  
  // COMMENT NINE
  // the results() function accepts both user's
  // scores in as parameters and will
  // decide who is the winner through
  // different comparison statements.
  results(computer_score, player_score);

  cout << "-----------------------------\n";
  cout << "Game Over" << endl;
  
}
// function defintions:
int user_input()
{
  char choice = ' ';
  
  cout << "Would you like to roll the dice?\n";
  cout << "Enter Y for yes or N for no: ";
  cin >> choice;
  
  return choice;
}

void score_calc(Die dice, int &score)
{
  int dice_value = 0;
  
  dice.roll();
  dice_value = dice.getValue();
  score += dice_value;
  
}

// COMMENT TEN
// the results() function will accept both
// user's scores in and use an if and
// 9 else if statements to reveal who had
// the most points without going over
// 21. neither player will win if there is a
// tie of it both players go over 21.
// inside the if statements, depending on
// the outcome of the comparison, each
// qualifying statement will call a specific
// function to print out who won; using winner()
// loser() and tie().
void results(int computer, int player)
{
  if (computer > 21 && player > 21)
    tie();
  else if (computer == player)
    tie();
  else if (player < 21 && computer > 21)
    winner();
  else if (player == 21 && computer > 21)
    winner ();
  else if (player == 21 && computer < 21)
    winner();
  else if (player > 21 && computer < 21)
    loser();
  else if (player < 21 && computer == 21)
    loser();
  else if (player > 21 && computer == 21)
    loser();
  else if (player < 21 && computer < 21 && player > computer)
    winner();
  else if (player < 21 && computer < 21 && computer > player)
    loser();
  
  cout << endl;
}

void winner() {
  cout << "\nYou won! Congratulations!";
}

void loser() {
  cout << "\nComputer won! Better luck next time!";
}

void tie() {
  cout << "\nIt's a tie! Better luck next time!";
}
