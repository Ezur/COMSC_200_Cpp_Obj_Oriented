// Array class definition with overloaded operators.
#ifndef ELISE_ZUR_ARRAY_H
#define ELISE_ZUR_ARRAY_H

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class Array
{
  // COMMENT ONE: operator<< is made a friend function of Array
  // class in order for it to be able to have access to the class's
  // private and protected members.
  template <typename U>
  friend std::ostream &operator<<( std::ostream &, const Array<U> & );
  
  // COMMENT TWO: operator<< is made a friend function of Array
  // class in order for it to be able to have access to the class's
  // private and protected members.
  template <typename U>
  friend std::istream &operator>>( std::istream &, Array<U> & );

public:
  explicit Array( size_t arraySize = 10 ); // default constructor
  Array( const Array<T> & ); // copy constructor
  ~Array(); // destructor
  size_t getSize() const; // return size

  const Array &operator=( const Array<T>& ); // assignment operator
  bool operator==( const Array<T> & ) const; // equality operator

  // inequality operator; returns opposite of == operator
  bool operator!=( const Array<T> &right ) const
  {
    return ! ( *this == right ); // invokes Array::operator==
  }

  // subscript operator for non-const objects returns modifiable lvalue
  T &operator[]( int );

  // subscript operator for const objects returns rvalue
  T operator[]( int ) const;
  
private:
  size_t size; // pointer-based array size
  T *ptr; // pointer to first element of pointer-based array
  
};

// ************************
//    IMPLEMENTATION
// ************************

// COMMENT THREE: here is the default constructor for the
// Array class. it initializes size, a private member
// variable. this function also provides input validation.
// the size will depend on what number the program uses
// as a parameter in Array.cpp / main.cpp
template <typename T>
Array<T>::Array( size_t arraySize )
   : size( arraySize > 0 ? arraySize :
        throw invalid_argument( "Array size must be greater than 0" ) ),
     ptr( new T[ size ] )
{

//  cout << "INSIDE (int) CONSTRUCTOR...\n\n";

//   for ( size_t i = 0; i < size; ++i )
//      ptr[ i ] = 0; // set pointer-based array element
}


// COMMENT FOUR: here is the copy constructor for the
// Array class.
// - this function allows us to use the
//   functionality of copying an object, specific
//   for an array of type T().
// - it must receive a reference to an array.
template <typename T>
Array<T>::Array( const Array<T> &arrayToCopy )
   : size( arrayToCopy.size ),
     ptr( new T[ size ] )
{
//  cout << "INSIDE COPY CONSTRUCTOR...\n\n";

  for ( size_t i = 0; i < size; ++i )
    ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object
}

// COMMENT FOUR: here is the destructor for the
// Array class.
// - this function will delete the pointer which
//   deallocates the memory it held onto.
template <typename T>
Array<T>::~Array()
{
//  cout << "INSIDE DESTRUCTOR...\n\n";
  delete [] ptr; // release pointer-based array space
}

// COMMENT FIVE: the getSize() function
// - this function will return the number
//   elements in the Array
// - using a getter style member function,
//   we cannot alter the host's value,
//   we can only read it and print it out.
template <typename T>
size_t Array<T>::getSize() const
{
   return size; // number of elements in Array
}


// COMMENT SIX: here is the overloaded assignment
// operator for the Array class.
// - this function allows us to use the
//   functionality of assigning an array the
//   value of another array
// - const return avoids: ( a1 = a2 ) = a3
template <typename T>
const Array<T>& Array<T>::operator=( const Array &right )
{

//  cout << "INSIDE ASSIGNMENT OPERATOR...\n\n";

  if (&right != this) // avoid self-assignment
  {
    cout << "NO SELF ASSIGNMENT\n\n";

    // for Arrays of different sizes, deallocate original
    // left-side Array, then allocate new left-side Array
    if (size != right.size)
    {
      delete[] ptr; // release space
      size = right.size; // resize this object
      ptr = new T[size]; // create space for Array copy
    }

    for (size_t i = 0; i < size; ++i)
      ptr[i] = right.ptr[i]; // copy array into object
  }

  else
    cout << "SELF ASSIGNMENT WAS ATTEMPTED!\n\n";

   return *this; // enables x = y = z, for example
}

// COMMENT SEVEN: here is the overloaded ==
// operator for the Array class.
// - this function allows us to use the
//   behavior of looking to see if 2 arrays
//   are equal
// - it will return true if 2 arrays are equal,
//   otherwise return false.
template <typename T>
bool Array<T>::operator==( const Array &right ) const
{
   if ( size != right.size )
      return false; // arrays of different number of elements

   for ( size_t i = 0; i < size; ++i )
      if ( ptr[ i ] != right.ptr[ i ] )
         return false; // Array contents are not equal

   return true; // Arrays are equal
}

// COMMENT EIGHT: here is the overloaded []
// operator for the Array class.
// - this function allows us to work with
//   NON-CONST arrays
// - it will return a REFERENCE which creates
//   a value that can be modified
template <typename T>
T &Array<T>::operator[]( int subscript )
{
//  cout << "INSIDE OF NON-CONST OPERATOR[]\n\n";

  // check for subscript out-of-range error
  if ( subscript < 0 || subscript >= size )
    throw out_of_range( "Subscript out of range" );

  return ptr[ subscript ]; // reference return
}

// COMMENT NINE: here is the overloaded []
// operator for the Array class.
// - this function allows us to work with
//   CONST arrays
// - it will return a COPY which creates
//   an r-value
template <typename T>
T Array<T>::operator[]( int subscript ) const
{
//  cout << "INSIDE OF CONST OPERATOR[]\n\n";

   // check for subscript out-of-range error
   if ( subscript < 0 || subscript >= size )
      throw out_of_range( "Subscript out of range" );

   return ptr[ subscript ]; // returns copy of this element
}

// COMMENT TEN: here is the overloaded >>
// operator for the Array class.
// - this function allows us to replace the
//   normal behavior, and use the input operator
//   to input the values for an entire array!
template <typename T>
istream &operator>>( istream &input, Array<T> &a )
{
   for ( size_t i = 0; i < a.size; ++i )
      input >> a.ptr[ i ];

   return input; // enables cin >> x >> y;
}

// COMMENT ELEVEN: here is the overloaded <<
// operator for the Array class.
// - this function allows us to replace the
//   normal behavior, and use the output operator
//   to output the values for an entire array!
template <typename T>
ostream &operator<<( ostream &output, const Array<T> &a )
{
   // output private ptr-based array
   for ( size_t i = 0; i < a.size; ++i )
   {
      output << setw( 12 ) << a.ptr[ i ];

      if ( ( i + 1 ) % 5 == 0 ) // 4 numbers per row of output
         output << endl;
   }

   if ( a.size % 4 != 0 ) // end last line of output
      output << endl;

   return output; // enables cout << x << y;
}

#endif

