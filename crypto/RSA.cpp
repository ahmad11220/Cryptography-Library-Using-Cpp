#include "RSA.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include<numeric>
#include<math.h>

using namespace std;

int RSA::Encrypt(int p, int q, int M, int e)
{
    for (int i = p; i > 0; i--)
    {
        if (p % i == 0)
        {
            if (i == p || i == 1)
            {
                continue;
            }
            cout << "p is not prime";
            return 0;
        }
    }
    for (int i = q; i > 0; i--)
    {
        if (q % i == 0)
        {
            if (i == q || i == 1)
            {
                continue;
            }
            cout << "q is not prime";
            return 0;
        }
    }

    int n = p * q;
    int quotient = (p - 1) * (q - 1);
    if (gcd1(e, quotient) != 1)
    {
       
        cout << " GCD is not equal to 1";
        return 0;
    }

    double C = modulo(M, e, n);
    cout << C << endl;
    return C;
}
int RSA::Decrypt(int p, int q, int C, int e)
{
    for (int i = p; i > 0; i--)
    {
        if (p % i == 0)
        {
            if (i == p || i == 1)
            {
                continue;
            }
            cout << "p is not prime";
            return 0;
        }
    }
    for (int i = q; i > 0; i--)
    {
        if (q % i == 0)
        {
            if (i == q || i == 1)
            {
                continue;
            }
            cout << "q is not prime";
            return 0;
        }
    }
    int n = p * q;
    int quotient = (p - 1) * (q - 1);

    if (gcd1(e, quotient) != 1)
    {
        cout << " GCD is not equal to 1";
        return 0;
    }
    int d = modulusinvesre(e, quotient);

    double M = modulo(C, d, n);
    cout << M << endl;
    return M;
}
int RSA::gcd1(int a, int b)
{
    if (b == 0)
        return a;
    return gcd1(b, a % b);
}
int RSA::modulusinvesre(int num, int quotient)
{
    for (int i = 0; i < quotient; i++)
    {
        if ((i * num % quotient) == 1)
        {
            return i;
        }
    }
}
int RSA::modulo(int a, int b, int n) {
    long long x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y) % n;
        }
        y = (y * y) % n;
        b /= 2;
    }
    return x % n;
}