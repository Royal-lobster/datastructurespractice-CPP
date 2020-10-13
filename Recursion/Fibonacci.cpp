#include <iostream>
using namespace std;

//fuction declarations
void fib(int);

int main()
{
    int n;
    cout << "enter number of elements: ";
    cin >> n;
    cout << "Fibonacci series is as follows: \n";
    cout << "0 1 ";
    fib(n);
    return 0;
}

void fib(int n)
{
    static int n1 = 0, n2 = 1, n3;
    if (n > 0)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        cout << n3 << " ";
        fib(n - 1);
    }
}