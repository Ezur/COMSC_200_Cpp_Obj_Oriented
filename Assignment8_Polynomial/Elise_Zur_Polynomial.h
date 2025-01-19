//  Polynomial.hpp
//  Class Specification File

#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <iostream>
using namespace std;

const int MAX = 100;

class Polynomial
{
private:
  int coefficients[MAX];
  int exponents[MAX];
  int term;
  int numTerms;
  
public:
  Polynomial();
  ~Polynomial();
  void enterTerms();
  void printPolynomial() const;
  
  int getNumTerms();
  int getExponent(int);
  int getCoefficient(int);
  void setCoefficient(int, int);
  
  Polynomial operator+(const Polynomial&) const;
  Polynomial operator-(const Polynomial&) const;
  Polynomial operator*(const Polynomial&) const;
  
  Polynomial &operator=(const Polynomial&);
  Polynomial &operator+=(const Polynomial&);
  Polynomial &operator-=(const Polynomial&);
  Polynomial &operator*=(const Polynomial&);
  static void combine(Polynomial &);
};

#endif /* Polynomial_hpp */
