// AIM: to find minima of the given function using newton's method
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double evaluate(vector<double> coeffs, double x)
{
    double result = 0;
    int degree = coeffs.size() - 1;

    for (int i = degree; i >= 0; i--)
    {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

double evaluate_derivative(vector<double> coeffs, double x)
{
    double result = 0;
    int degree = coeffs.size() - 1;

    for (int i = degree; i > 0; i--)
    {
        result += i * coeffs[i] * pow(x, i - 1);
    }
    return result;
}

double newtons_method(vector<double> coeffs, double initial_guess, double tolerance)
{
    double x = initial_guess;
    double y = evaluate(coeffs, x);
    double dydx = evaluate_derivative(coeffs, x);
    int max_iterations = 100;
    int iteration = 0;
    while (abs(dydx) > tolerance && iteration < max_iterations)
    {
        x = x - y / dydx;
        y = evaluate(coeffs, x);
        dydx = evaluate_derivative(coeffs, x);
        iteration++;
    }
    return x;
}
int main()
{
    vector<double> coeffs; // vector to store coefficients

    cout << "Enter the degree of the polynomial: ";
    int degree;
    cin >> degree;
    // prompt user to enter coefficients

    for (int i = degree; i >= 0; i--)
    {
        double coeff;
        cout << "Enter the coefficient of x^" << i << ": ";
        cin >> coeff;
        coeffs.push_back(coeff);
    }

    double initial_guess;
    cout << "Enter an initial guess for the minima : ";
    cin >> initial_guess;

    double tolerance;
    cout << "Enter a tolerance value : ";
    cin >> tolerance;

    double minima = newtons_method(coeffs, initial_guess, tolerance);
    cout << "the minima of the polynomial function is : " << minima << endl;
    return 0;
}
