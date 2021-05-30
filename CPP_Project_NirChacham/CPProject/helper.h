
#pragma once
#ifndef _HELPER_H
#define _HELPER_H
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <time.h>       /* time_t, time, ctime */
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
const int NAME_LENGTH = 50;// change to 20
const int PASSWORD_LENGTH = 16;
const int NOT_FOUND = -1;
const int REVIEW_LENGTH = 500;
const int NUM_OF_OPTIONS = 14;
const int MIN_LETTERS = 2;
const int ZERO = 0;
const int TEN_MILLION = 10000000;


class Helper
{
public:
	Helper();
	~Helper();
	static int getString(const string& title, string& s, int min, int max);
	static int getLineString(const string& title, string& s, int min, int max);
	static int getInt(const string& title, int * s, int min, int max);
 };

#endif // _HELPER_H
