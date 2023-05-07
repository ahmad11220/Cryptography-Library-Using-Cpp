#pragma once
#include<iostream>
#include <string>
using namespace std;
class VigenereRepeating
{
public:
	void textToUpper(string& text);
	string Encrypt(string plainText, string key);
	string Decrypt(string cipherText, string key);
	string Analyse(string plainText, string cipherText);
	string Repeatingkeystream(string PlainTEXT, string Key);

	int mod(int k, int n);

};