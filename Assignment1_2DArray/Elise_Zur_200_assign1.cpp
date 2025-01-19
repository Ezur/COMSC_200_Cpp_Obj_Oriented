// Programmer's Name: Elise Zur
// Course: COMSC 200
// Assignment: PA 1

#include <iostream>
using namespace std;

const int COLS = 5;

int getTotal(int [][COLS], int);
double getAverage(int [][COLS], int);
int getRowTotal(int [][COLS], int);
int getColumnTotal(int [][COLS], int, int);
int getHighestInRow(int [][COLS], int);
int getLowestInRow(int [][COLS], int);

int main()
{
  const int ROWS = 4;
  
  int testArray[ROWS][COLS] =
          { { 63, 24, 39, 13, 32 },
          {   12, 53, 64, 27, 55 },
          {   29, 69, 57, 51, 17 },
          {   19, 44, 73, 23, 72 } };
     
  cout << "The total of the array elements is "
     << getTotal(testArray, ROWS)
     << endl;
   

  cout << "The average value of an element is "
     << getAverage(testArray, ROWS)
     << endl;


  cout << "The total of row 0 is "
     << getRowTotal(testArray, 0)
     << endl;


  // COMMENT ONE
  // the second parameter inside the function call
  // is the specified value that intentionally
  // sets the array's column's index. this will
  // allow the program to calculate the column
  // total.
  cout << "The total of col 2 is "
     << getColumnTotal(testArray, 2, ROWS)
     << endl;


  cout << "The highest value in row 2 is "
     << getHighestInRow(testArray, 2)
     << endl;


  cout << "The lowest value in row 2 is "
    << getLowestInRow(testArray, 2)
    << endl << endl;
  
  return 0;
}

// COMMENT TWO
// getTotal() accept a two-dimensional array and integer
// that relates back to the constant value of the number
// of rows. the function will return the total value
// of all numbers added together, back to main
int getTotal(int array[][COLS], int rows)
{
  int total = 0;
  
  // COMMENT THREE
  // this nested for loop will read the values of each
  // array index-- each element has an ongoing counter
  // variable (total) which will be the integer
  // that will be returned at the end of the function
  for (int r = 0; r < rows; r++)
    for (int c = 0; c < COLS; c++)
      total += array[r][c];
  return total;
}

// COMMENT FOUR
// getAverage() accepts a two-dimensional array and integer
// for the number of rows. the function will return the
// average of all numbers in the array. it is a double
// to account for any decimal values when calculating.
double getAverage(int array[][COLS], int rows)
{
  double sum = 0;
  int num_of_values = 0;
  
  // COMMENT FIVE
  // this nested for loop starts at the first row and
  // steps into the inner for loop to read each element.
  // each step through the inner for loop, the function
  // adds all numbers together and increments the counter
  // variable that calculates the number of elements in
  // the entire array. this will allow the function to
  // calculate the average below.
  for (int r = 0; r < rows; r++)
    for (int c = 0; c < COLS; c++)
    {
      sum += array[r][c];
      num_of_values++;
    }
  
  return sum / num_of_values;
}

// COMMENT SIX
// getRowTotal() function receives a two-dimensional array
// and integer that represenets which row the function
// will be calculating the total of (rowToTotal).
// this allows the user to call the function multiple times
// and get the row total for different rows.
int getRowTotal(int array[][COLS], int rowToTotal)
{
  int total = 0;
  
  for (int c = 0; c < COLS; c++)
    total += array[rowToTotal][c];
  
  return total;
}

// COMMENT SEVEN
// getColumnTotal() function receives a two-dimensional array,
// an integer that represents which column the function should
// calculate the total of (colToTotal), and the int that
// represents the number of rows. the function will step
// through each element in the specified column
// and find the total value.
int getColumnTotal(int array[][COLS], int colToTotal, int rows)
{
  int total = 0;
  
  for (int r = 0; r < rows; r++)
    total += array[r][colToTotal];
  
  return total;
}

// COMMENT EIGHT
// getHighestInRow() function receives a two-dimensional array,
// and an integer that represents which row the function will
// calculate from (rowToSearch). this will allow the user
// to find the highest value in the row.
int getHighestInRow(int array[][COLS], int rowToSearch)
{
  // COMMENT NINE
  // the variable--highest-- is set to the value of the first
  // element in the array. this allows the function to
  // compare whether or not each value has a lower or higher
  // value
  int highest = 0;
  highest = array[rowToSearch][0];
  
  // COMMENT TEN
  // the for loop is set to run through an entire row and return
  // the highest element found. rowToSearch remains the same value
  // while the column index will go from 0 to the max # of columns.
  // the if statement verifies, if the value of highest is less
  // then the current index's value- then that current value is
  // labeled as the highest element. this continues until all
  // elements in the row are compared.
  for (int c = 0; c < COLS; c++)
    if (highest < array[rowToSearch][c]) highest = array[rowToSearch][c];
  
  return highest;
}

// COMMENT ELEVEN
// getLowestInRow() function receives a two-dimensional array,
// and an integer that represents which row the function
// will search (rowToSearch) for the lowest value.
// the for loop will go through the entire row and return
// the lowest value found by comparing the current value
// that is in the variable- lowest, vs the value
// of the current index.
int getLowestInRow(int array[][COLS], int rowToSearch)
{
  int lowest = array[rowToSearch][0];
  
  for (int c = 0; c < COLS; c++)
    if (lowest > array[rowToSearch][c]) lowest = array[rowToSearch][c];
  
  return lowest;
}

