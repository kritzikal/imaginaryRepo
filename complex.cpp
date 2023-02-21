/**
 * Implementation for the complex class
 * @author William Duncan, YOUR NAME
 * <pre>
 * Date: LAST DATE MODIFIED
 * File: complex.cpp
 * Course: csc 1254 Section 1
 * Project #: 1
 * Instructor: Dr. Duncan
 * </pre>
 */

#include <cmath>
#include <cstdlib>
#include "complex.h"


/* SOME FUNCTION HAVE BEEN IMPLEMENTED FOR YOU. IMPLEMENT
   ALL OTHER FUNCTIONS DESCRIBED ON THE PROJECT HANDOUT.
   WHOSE PROTOTYPES APPEAR IN THE CLASS.
*/

Complex::Complex()
{
   real = 0.0;
   imag = 0.0;
}

Complex::Complex(double r)
{
    real = r;

    imag = 0;
}

Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}


double Complex::getReal() const
{
   return real;
}

double Complex::getImag() const
{
    return imag;
}

Complex Complex::conjugate() const
{
   return Complex(real,-imag);
}

double Complex::modulus() const
{
    return sqrt(real * real + imag * imag);
}

double Complex::argument() const
{
    if (imag == 0 && real == 0)
    {
        throw - 2;
    }
    return atan2(imag, real);
}


Complex operator+(const Complex& z1, const Complex& z2)
{
   return Complex(z1.real+z2.real,z1.imag+z2.imag);
}

Complex operator-(const Complex& z1, const Complex& z2)
{
    return Complex(z1.real - z2.real, z1.imag - z2.imag);
}

Complex operator*(const Complex& z1, const Complex& z2)
{
    return Complex((z1.real * z2.real - z1.imag * z2.imag), (z1.real * z2.imag + z2.real * z1.imag));
}

Complex operator/(const Complex& z1, const Complex& z2)
{
    if (z2.real == 0 && z2.imag == 0)
    {
        throw - 1;
    }

    if (z2.imag == 0)
    {
        return Complex(z1.real / z2.real, z1.imag / z2.real);
    }
    else
    {
        Complex z2_c(z2.real, -z2.imag);
        Complex num = z1 * z2_c;

        double denom = z2.real * z2.real + z2.imag * z2.imag;

        double r = num.real / denom;
        double i = num.imag / denom;

        return Complex(r, i);
    }
}

Complex pow(const Complex& z, int n)
{
    double magnitude = pow(z.modulus(), n);
    double angle = z.argument() * n;
    double real = magnitude * cos(angle);
    double imag = magnitude * sin(angle);

    return Complex(real, imag);
}


ostream& operator<<(ostream& out, const Complex& z)
{
   if (z.real == 0 && z.imag == 0)
   {
      out<<"0";
      return out;
   }
   if (z.real == 0)
   {
      if (z.imag < 0)
      {
         if (z.imag != -1)
            out<<z.imag<<"i";
         else
            out<<"-i";
      }
      else
      {
         if (z.imag != 1)
            out<<z.imag<<"i";
         else
            out<<"i";
      }
      return out;
   }
   if (z.imag == 0)
   {
      out<<z.real;
      return out;
   }
   out <<z.real;
   if (z.imag < 0)
   {
      if (z.imag != -1)
         out<<z.imag<<"i";
      else
         out<<"-i";
   }
   else
   {
      if (z.imag != 1)
         out<<"+"<<z.imag<<"i";
      else
         out<<"+i";
   }
   return out;
}
