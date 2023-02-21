/**
 * public interface for the complex number class.
 * @author Jason Phan, YOUR NAME
 * <pre>
 * File: complex.h
 * Date: 2/20/23
 * Course: csc 1254 section 1
 * Project #: 1
 * Instructor: Dr. Duncan
 * </pre>
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

/* YOUR TASK HERE IS TO GIVE THE COMPLETE DEFINITION OF
   THE class Complex AS DESCRIBED IN THE PRJECT HANDOUT.
   BE SURE TO INCLUDE A DESCRIPTION OF EACH OF THE FUNCTIONS.
   YOU WILL PROVIDE ONLY THE PUBLIC INTERFACE OF THE MEMBER
   AND FRIEND FUNCTIONS, NOT THEIR DEFINITIONS.
   THE MEMBER AND FRIEND FUNCTIONS WILL BE DEFINED IN THE
   IMPLEMENTATION FILE.

   DEFINE THE CLASS BELOW.
*/

/**
* A class that models a complex number in the form of z = x+iy and performs various operations with complex numbers.
*/
class Complex {
private:
	/**
	* The real component of the imaginary number in the form of x.
	*/
	double real;
	/**
	* The imaginary component of the imaginary number in the form of iy.
	*/
	double imag;

public:
	/**
	* Default constructor that sets both real and imag to 0.
	*/
	Complex();

	/**
	*Constructor that creates a complex number using the specified parameter and sets imag to 0.
	* @param r - real component
	*/
	Complex(double r);

	/**
	*Constructor that creates a complex number using the specified parameters.
	* @param r - real component
	* @param i - imaginary component
	*/
	Complex(double r, double i);

	/**
	* Overloaded + operator
	* @z1 - constant reference to a Complex object
	* @z2 - constant reference to a Complex object
	* @return a Complex object representing the sum of two Complex numbers.
	*/
	friend Complex operator+(const Complex& z1, const Complex& z2);

	/**
	* Overloaded - operator
	* @z1 - constant reference to a Complex object
	* @z2 - constant reference to a Complex object
	* @return a Complex object representing the difference of two Complex numbers.
	*/
	friend Complex operator-(const Complex& z1, const Complex& z2);

	/**
	* Overloaded * operator
	* @z1 - constant reference to a Complex object
	* @z2 - constant reference to a Complex object
	* @return a Complex object representing the product of two Complex numbers.
	*/
	friend Complex operator*(const Complex& z1, const Complex& z2);

	/**
	* Overloaded / operator
	* @z1 - constant reference to a Complex object of form x1 +iy1.
	* @z2 - constant reference to a Complex object of form x2+iy2.
	* @returns a Complex object representing division of two Complex numbers.
	* The object is undefined if both x2 and y2 are zero.
	* If y2 = 0, then z1/z2 = (x1/x2)+i(y1/x2).
	* z2bar = z2's conjugate
	* If y2 doesnt = 0, then z1/z2 = (z1*z2bar)/(z2*z2bar).
	*/
	friend Complex operator/(const Complex& z1, const Complex& z2);

	/**
	* Overloaded << operator
	* @out - constant reference to an outstream object for output.
	* @z - constant reference to a Complex object.
	* @return a reference to the outstream object out.
	*/
	friend ostream& operator<<(ostream& out, const Complex& z);

	/**
	* Gives the real component.
	* @returns the real component of the imaginary number.
	*/
	double getReal() const;

	/**
	* Gives the imaginary component.
	* @returns the imaginary component of the imaginary number.
	*/
	double getImag() const;

	/**
	* Creates a complex number with its conjugate form.
	* @returns the conjugate form of x-iy, where the original form is x+iy.
	*/
	Complex conjugate() const;

	/**
	* Computes the magnitude of the complex number.
	* @returns the square root of the the sum of the squares of the real and imaginary part.
	*/
	double modulus() const;

	/**
	* Computes the polar angle of the complex angle.
	* @returns the arctan(y/x) of z = x+iy where an exception of -2 is thrown if both y and x are 0.
	*/
	double argument() const;

	/**
	* Creates a new Complex object equal to z^n;
	* @returns a new Complex object where the complex object z is raised to the power of n.
	*/
	friend Complex pow(const Complex& z, int n);



};





#endif
