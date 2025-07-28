#include <iostream>
#include <cmath>
using namespace std;

int countdigit(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
}

void armstrong(int num, int digit)
{
    int n = num, ans = 0, rem = 0;
    while (n > 0)
    {
        rem = n % 10;
        double po = pow(rem, digit);
        ans += po;
        n /= 10;
    }
    if (ans == num)
        cout << "Yes";
    else
        cout << "No";
}

int main()
{
    int num;
    cin >> num;
    int digit = countdigit(num);
    armstrong(num, digit);
    return 0;
}
