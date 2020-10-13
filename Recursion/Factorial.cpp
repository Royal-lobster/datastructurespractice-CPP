#include <iostream>
using namespace std;

// function declaration
int factorial(int n);

// Main function
int main()
{
    int n;
    cout << "Input number for factorial: ";
    cin >> n;

    cout << "Factorial of " << n << " = " << factorial(n);
}

//function
int factorial(int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}