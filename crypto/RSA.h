#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class RSA
{


public:
	int modulo(int a, int b, int n);
	int Encrypt(int p, int q, int M, int e);
	int gcd1(int a, int b);
	int modulusinvesre(int num, int quotient);
	int Decrypt(int p, int q, int C, int e);
};

