/**
 * A program to test the complex class implementation
 * @author William Duncan, YOUR NAME
 * <pre>
 * File: complextester.cpp
 * Date: LAST DATE MODIFIED
 * Course: csc 1254 section 1
 * Project #: 1
 * Instructor: Dr. Duncan
 * </pre>
 */

#include <iostream>
#include "complex.h"
#include <cstdlib>


using namespace std;

int main(int argc, char **argv)
{
   Complex z0(3.6,4.8);
   Complex z1(4,-2);
   Complex z2(-4,2);
   Complex z3(-4,-3);
   Complex z4(3,-4);
   Complex z5;
   Complex z6;
   Complex z7;
   double ang;
   cout<<"z0 = "<<z0<<" and re(z0) = "<<z0.getReal()<<" and "
       <<"im(z0) = "<<z0.getImag()<<"."<<endl;
   cout<<"z1 = "<<z1<<endl;
   cout<<"z2 = "<<z2<<endl;
   cout<<"z3 = "<<z3<<endl;
   cout<<"z4 = "<<z4<<endl;

   cout<<"z2 x z3 = "<<z2*z3<<endl;
   cout<<"z1 + z2 = "<<z1+z2<<endl;

   cout<<"z3 = "<<z3<<endl;
   cout<<"z4 = "<<z4<<endl;
   cout<<"z3-z4 = "<<z3-z4<<endl;

   cout<<"((z2+z3)x(z3-z4)) = ";
   cout<<(z2+z3)*(z3-z4)<<endl;
   cout<<"z1^3 = "<<pow(z1,3)<<endl;
   cout<<"1/z2^2 = "<<pow(z2,-2)<<endl;
   cout<<"z3^0 = "<<pow(z3,0)<<endl;
   try
   {
      cout<<"((z2+z3)x(z3-z4))/z3 = ";
      z6 = ((z2+z3)*(z3-z4))/z3;
      cout<<z6<<endl;

      cout<<"z3 / z4 = "<<(z3/z4)<<endl;
      cout<<"Conj(z4) = "<<z4.conjugate()<<endl;

      cout<<"The real part of the conjugate of z4 is "<<(z4.conjugate()).getReal()<<endl;
      cout<<"The imaginary part of the conjugate of z4 is "<<(z4.conjugate()).getImag()<<endl;
      cout<<"The argument of the conjugate of z4 is "<<(z4.conjugate()).argument()<<"."<<endl;
      cout<<"The modulus of the conjugate of z4 is "<<(z4.conjugate()).modulus()<<"."<<endl;

      cout<<"(z3*conj(z4))/(z4*conj(z4))= ";


      cout<<(z3*z4.conjugate())/(z4*z4.conjugate())<<endl;

      /* Add statement here to compute ((z1-z2).(z3/z4))/(z4/z3)
         and print the result:*/
      cout << "((z1-z2).(z3/z4))/(z4/z3) = ";
      z7 = (((z1 - z2)*(z3 / z4)) / (z4 / z3));
      cout<<z7<<endl;

      ang = (z1+z2).argument();
	  cout<<"angle = "<<ang<<endl;
      /* Put a comment here explaining what happened and why?
		The sum of z1 and z2 results in a resultant z3 of 0 + 0i. Thus, the argument() function throws a exception of -2 since
		this is a condition where both and x and y represent zero where y represents the imaginary part and x represents the real part. Thus, x/y results in undefined.

      */
   }
   catch(int e)
   {
      if (e == -1)
         cerr<<"DivideByZero Exception in / operator"<<endl;
      else if (e == -2)
         cerr<<"DivideByZero Exception in argument function"<<endl;
   }
   return 0;
}
