#include <iostream>
using namespace std;
long tailRecursiveFact(long n, long a)
{
    if (n == 0)
    {
        return a;
    }
    else
        return tailRecursiveFact(n - 1, a * n);
}
long normalFact(long n)
{
    if (n < 1)
    {
        return 1;
    }
    else
        return n * normalFact(n - 1);
}
int main()
{
    int n;
    cout << "Enter a number for factorial: ";
    cin >> n;
    cout << "factorial of " << n << " using normal method: ";
    cout << normalFact(n);
    cout << endl
         << "factorial of " << n << " using tail recursive method: ";
    cout << tailRecursiveFact(n, 1);
    cout << endl;
}