
#include <iostream>
#include<vector>
#include <cmath>

using namespace std;

double f(double x)
{
   // The function to minimize
   return pow(x - 2, 2) + 1;
}

double variable_step_linear_search(double x0, double h, double eps)
{
   double fx0 = f(x0);
   double fh = f(x0 + h);
   double xh = x0 + h;
   double x1, fx1, h1;

   while (fh < fx0)
   {
      x1 = xh + h;
      fx1 = f(x1);

      if (fx1 >= fh)
      {
         h /= 2.0; // Decrease the step size
         xh = x1 - h;
         fh = f(xh);
      }
      else
      {
         h *= 2.0; // Increase the step size
         xh = x1;
         fh = fx1;
      }
   }

   return xh;
}

int main()
{
   // double x0, h, eps;

   // cout << "Enter initial guess for minimum: ";
   // cin >> x0;

   // cout << "Enter initial step size: ";
   // cin >> h;

   // cout << "Enter desired accuracy: ";
   // cin >> eps;

   // double xmin = variable_step_linear_search(x0, h, eps);

   // cout << "Minimum at x = " << xmin << ", f(x) = " << f(xmin) << endl;
   // int test=9^3;
   // cout<<(9^3);
   
cout<<701%26;
cout<<701/26;



   return 0;
}
