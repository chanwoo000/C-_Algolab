#include "MyComplex.h"
// Constructor
myComplex::myComplex(int real, int imag)
{
realPart = real;
imaginaryPart = imag;
}

// Copy constructor
myComplex::myComplex(const myComplex& number)
{
realPart = number.realPart;
imaginaryPart = number.imaginaryPart;
}

// Accessor functions
int myComplex::getRealPart() const
{
return realPart;
}
int myComplex::getImaginaryPart() const
{
return imaginaryPart;
}

// Mutator functions
void myComplex::setRealPart(int real)
{
realPart = real;
}
void myComplex::setImaginaryPart(int imag)
{
imaginaryPart = imag;
}
void myComplex::set(int real, int imag)
{
realPart = real;
imaginaryPart = imag;
}

// Overloaded binary operators
myComplex myComplex::operator +(const myComplex& number) const
{
int newReal = realPart + number.realPart;
int newImag = imaginaryPart + number.imaginaryPart;
return myComplex (newReal, newImag);
}
myComplex myComplex::operator +(int value) const
{
return myComplex(value) + (*this);
}

myComplex myComplex::operator -(const myComplex& number) const
{
int newReal = realPart - number.realPart;
int newImag = imaginaryPart - number.imaginaryPart;
return myComplex (newReal, newImag);
}
myComplex myComplex::operator -(int value) const
{
return (*this) - myComplex(value) ;
}

myComplex myComplex::operator *(const myComplex& number) const
{
int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
int newImag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
return myComplex (newReal, newImag);
}
myComplex myComplex::operator *(int value) const
{
return myComplex(value) * (*this);
}


// Assignment operators
myComplex& myComplex::operator =(const myComplex& number)
{
this->realPart = number.realPart;
this->imaginaryPart = number.imaginaryPart;
return *this;
}
myComplex& myComplex::operator =(int value)
{
realPart = value;
imaginaryPart = 0;
return *this;
}

myComplex& myComplex::operator+=(const myComplex& number)
{
this->realPart += number.realPart;
this->imaginaryPart += number.imaginaryPart;
return *this;
}
myComplex& myComplex::operator +=(int value)
{
realPart += value;
return *this;
}
myComplex& myComplex::operator -=(const myComplex& number)
{
this->realPart -= number.realPart;
this->imaginaryPart -= number.imaginaryPart;
return *this;
}
myComplex& myComplex::operator -=(int value)
{
realPart -= value;
return *this;
}
myComplex& myComplex::operator *=(const myComplex& number)
{
int r = realPart;
int i = imaginaryPart;
realPart = (r * number.realPart) - (i * number.imaginaryPart);
imaginaryPart = (r * number.imaginaryPart) + (number.realPart * i);
return *this;
}
myComplex& myComplex::operator *=(int value)
{
realPart *= value;
imaginaryPart *= value;
return *this;
}


// Overloading comparison operators
bool myComplex::operator ==(const myComplex& number) const
{
return (realPart == number.realPart) && (imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator !=(const myComplex& number) const
{
return (realPart != number.realPart) || (imaginaryPart != number.imaginaryPart);
}
bool myComplex::operator >(const myComplex& number) const
{
return norm() > number.norm();
}
bool myComplex::operator >=(const myComplex& number) const
{
return norm() >= number.norm();
}
bool myComplex::operator <(const myComplex& number) const
{
return norm() < number.norm();
}
bool myComplex::operator <=(const myComplex& number) const
{
return norm() <= number.norm();
}


// Overloaded unary operators
myComplex myComplex::operator -() // unary minus
{
return myComplex(-realPart, -imaginaryPart);
}
myComplex myComplex::operator ~() // unary minus
{
return myComplex(realPart, -imaginaryPart);
}
myComplex myComplex::operator ++() // unary minus
{
return myComplex(++realPart, imaginaryPart);
}
myComplex myComplex::operator --() // unary minus
{
return myComplex(--realPart, imaginaryPart);
}
myComplex myComplex::operator ++(int) // unary minus
{
    myComplex ret(realPart, imaginaryPart);
    ++(*this);
    return ret;
}
myComplex myComplex::operator --(int) // unary minus
{
    myComplex ret(realPart, imaginaryPart);
    --(*this);
    return ret;
}

// private function
int myComplex::norm() const
{
return realPart * realPart + imaginaryPart * imaginaryPart;
}

ostream &operator <<(ostream &outStream, const myComplex& number)
{
outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
return outStream;
}

istream &operator >>(istream &inStream, myComplex& number)
{
inStream >> number.realPart >> number.imaginaryPart;
return inStream;
}
myComplex operator+(int value, const myComplex & number) {
	return number + value;
}

myComplex operator-(int value, const myComplex & number) {
	return -(number - value);
}

myComplex operator*(int value, const myComplex & number) {
	return number * value;
}