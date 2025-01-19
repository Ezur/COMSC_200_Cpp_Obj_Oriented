//  Polynomial.cpp
//  Class Implementation File

#include <iostream>
#include "Polynomial.h"
using namespace std;

// COMMENT ONE: the constructor for a Polynomial object
// initializes the coefficients and exponents arrays.
// it also sets the number of terms to zero.
Polynomial::Polynomial()
{
  for (int i = 0; i < MAX; i++)
  {
    coefficients[i] = 0;
    exponents[i] = 0;
  }
  numTerms = 0;
}

// destructor
Polynomial::~Polynomial() {
}

// get number of terms func
int Polynomial::getNumTerms()
{
    return numTerms;
}

// get exponenet func
int Polynomial::getExponent(int term)
{
    return exponents[term];
}

// get coefficient func
int Polynomial::getCoefficient(int term)
{
    return coefficients[term];
}

void Polynomial::setCoefficient(int term, int coefficient)
{
   if (coefficients[term] == 0) // no term @ location
      cout << "Error: No term at this location." << endl;
   else
      coefficients[term] = coefficient;
}

// COMMENT TWO: the enterTerms() function will call for
// many actions for the user to take. it will first
// ask the user to enter the number of polynomials
// and then the user will enter the specific
// number of terms which includes entering
// the coefficient and exponent.
void Polynomial::enterTerms()
{
  bool foundTerm = false;
  int coeff, exp, term;

  cout << "\nEnter number of polynomial terms: ";
  cin >> numTerms;

  for (int i = 0; i < numTerms && i < MAX; ++i)
  {
     cout << "\nEnter coefficient: "; cin >> coeff;
     cout << "Enter exponent: "; cin >> exp;

     if (coeff != 0)
     {
        if (exp == 0)
        {
           coefficients[ 0 ] += coeff;
           continue;
        }

        for (term = 1; (term < MAX) && (coefficients[term] != 0); ++term)

           if (exp == exponents[term])
           {
             // existing exponent is updated
              coefficients[term] += coeff;
              exponents[term] = exp;
              foundTerm = true;
           }

        if (!foundTerm) // adds ter,
        {
           coefficients[term] += coeff;
           exponents[term] = exp;
        }
     }
    
  }
}

// COMMENT THREE: the print function will not change any
// polynomial's value but will only output it to the console.
// there are many factors that will decide how to print
// each term and whether it is positive or negative.
void Polynomial::printPolynomial() const
{
  int print_index;

  if (coefficients[0]) // output constants
  {
    cout << coefficients[0];
    print_index = 1;
  }
  else
  {
     if (coefficients[1])
     {
        cout << coefficients[1] << 'x';
        if ((exponents[1] != 0 ) && (exponents[1] != 1))
          cout << '^' << exponents[1];
     }
    print_index = 2;
  }

  // output remaining polynomial terms
  for (int x = print_index; x < MAX; ++x)
  {
     if (coefficients[x] != 0)
     {
       if (coefficients[x] < 0)
         cout << coefficients[x] << 'x';
       else if (coefficients[x] > 0)
         cout << '+' << coefficients[x] << 'x';

       if ((exponents[x] != 0) && (exponents[x] != 1))
         cout << '^' << exponents[x];
     }
  }
  cout << endl;
}

// COMMENT FOUR: this is an overloaded operator + function.
// it will allow us to use our Polynomial class object's
// plus sign to add two objects together.
Polynomial Polynomial::operator+(const Polynomial &num) const
{
  Polynomial tempObj;
  bool foundExponent;
  int x;

  // element with a zero exponent
  tempObj.coefficients[0] = coefficients[0] + num.coefficients[0];

  // COMMENT FIVE: this for loop will copy arrays
  // into tempObj object; x will be used to keep
  // track of the first open coefficient element
  for (x = 1; (x < MAX) && (num.exponents[x] != 0); ++x)
  {
     tempObj.coefficients[x] = num.coefficients[x];
     tempObj.exponents[x] = num.exponents[x];
  }

  for (int y = 1; y < MAX; ++y)
  {
     foundExponent = false;

     for (int z = 1; (z < MAX) && (!foundExponent); ++z)
        if (exponents[y] == tempObj.exponents[z])
        {
           tempObj.coefficients[z] += coefficients[y];
           foundExponent = true;  // exponents found
        }

     // exponents was not found, insert into tempObj
     if (!foundExponent)
     {
        tempObj.exponents[x] = exponents[y];
        tempObj.coefficients[x] += coefficients[y];
        ++x;
     }
  }
  return tempObj;
}

// COMMENT SIX: this is an overloaded operator - function.
// it will allow us to use our Polynomial class object's
// minus sign to subtract two objects and return a tempObj
// as the resulting polynomial.
Polynomial Polynomial::operator-(const Polynomial &num) const
{
  Polynomial tempObj;
  bool foundExponent;
  int x;

  // process element with a zero exponents
  tempObj.coefficients[0] = coefficients[0] - num.coefficients[0];

  // copy right arrays into tempObj object; s will be used to keep
  // track of first open coefficients element
  for (x = 1; (x < MAX) && (exponents[x] != 0); ++x)
  {
     tempObj.coefficients[x] = coefficients[x];
     tempObj.exponents[x] = exponents[x];
  }

  for (int y = 1; y < MAX; ++y)
  {
     foundExponent = false;

     for (int z = 1; (z < MAX) && (!foundExponent); ++z)
        if (num.exponents[y] == tempObj.exponents[z] )
        {
           tempObj.coefficients[z] -= num.coefficients[y];
           foundExponent = true;  // exponents found
        }

     // exponents was not found, insert into tempObj
     if (!foundExponent)
     {
        tempObj.exponents[x] = num.exponents[y];
        tempObj.coefficients[x] -= num.coefficients[y];
        ++x;
     }
  }
  return tempObj;
  
}

// COMMENT SEVEN: this is an overloaded operator * function.
// it will allow us to use our Polynomial class object's
// asterik sign to multiply two objects and return a tempObj
// as the resulting polynomial.
Polynomial Polynomial::operator*(const Polynomial &num) const
{
  Polynomial tempObj;
  int i = 1;

  for (int j = 0; (j < MAX) && (j == 0 || coefficients[j] != 0); ++j)
  {
    for (int k = 0; (k < MAX) && (k == 0 || num.coefficients[k] != 0); ++k)
    {
      if (coefficients[j] * num.coefficients[k])
      {
        if ((exponents[j] == 0) && (num.exponents[k] == 0))
           tempObj.coefficients[0] +=
              coefficients[j] * num.coefficients[k];
        else
        {
           tempObj.coefficients[i] =
              coefficients[j] * num.coefficients[k];
           tempObj.exponents[i] = exponents[j] + num.exponents[k];
           ++i;
        }
      }
    }
  }
  combine(tempObj); // combine common terms
  return tempObj;
}

// COMMENT EIGHT: this is an overloaded operator = function.
// it will allow us to use our Polynomial class object's
// equal sign to assign two objects and return a tempObj
// as the resulting polynomial.
Polynomial &Polynomial::operator=(const Polynomial &num)
{
  exponents[0] = num.exponents[0];
  coefficients[0] = num.coefficients[0];
  
  for (int i = 1; i < MAX; ++i)
  {
    if (num.exponents[i] != 0)
    {
      exponents[i] = num.exponents[i];
      coefficients[i] = num.coefficients[i];
    }
    else
    {
      if (exponents[i] == 0 )
         break;
      exponents[i] = 0;
      coefficients[i] = 0;
    }
  }
  return *this;
}

// COMMENT NINE: this is a overloaded += setter function
// and will allow us to add the right operand to the left
// operand and assign the result to left operand.
Polynomial &Polynomial::operator+=(const Polynomial &num)
{
  *this = *this + num;
  return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &num)
{
  *this = *this - num;
  return *this;
}

Polynomial &Polynomial::operator*=(const Polynomial &num)
{
  *this = *this * num;
  return *this;
}

// COMMENT TEN: this is the polynomial combining
// function which is used in the operator += function.
// it is used after the operation is done and will
// merge the two objects. 
void Polynomial::combine(Polynomial &index)
{
   Polynomial tempObj = index;
 
   for (int x = 0; x < MAX; ++x)
   {
     index.coefficients[x] = 0;
     index.exponents[x] = 0;
   }
 
   for (int x = 1; x < MAX; ++x)
   {
     for (int y = x + 1; y < MAX; ++y)
     {
       if (tempObj.exponents[x] == tempObj.exponents[y])
       {
          tempObj.coefficients[x] += tempObj.coefficients[y];
          tempObj.exponents[y] = 0;
          tempObj.coefficients[y] = 0;
       }
     }
   }
  index = tempObj;
}
