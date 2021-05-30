#include "helper.h"

Helper::Helper()
{
}

Helper::~Helper()
{
}
//func that gets a string with cin
int Helper::getString(const string& title, string& s, int min, int max) {
	bool ok = false;
	int len;
	while (!ok)
	{
		cout << "Please enter the " << title << "\n"; // check if name is valid
		cin >> s;
		len = s.length();
		if (len >= min && len <= max) {
			ok = true;
		}
		else {
			cout << "The " << title << " length mast be between " << min << " and " << max << "\n"; // check if name is valid
		}
	}
	return 1;
}
//func that gets a string with cin.getline
int Helper::getLineString(const string& title, string& s, int min, int maxLength) {
	bool ok = false;
	int len;

	while (!ok)
	{
		cout << "Please enter the " << title << "\n";
		getline(cin, s);

		len = s.length();
		if (len >= min && len <= maxLength) {
			ok = true;
		}
		else {
			cout << "The " << title << " length must be between " << min << " and " << maxLength << "\n";
		}
	}
	return 1;
}

//func that gets an integer and makes sure its and integer
inline bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}
//func that gets integer
int Helper::getInt(const string& title, int * s, int min, int max) {
	bool ok = false;
	string inputString;
	int temp;

	while (!ok)
	{
		cout << "Please enter the " << title << "\n";
		cin >> inputString;
		if (!isInteger(inputString)) {
			cout << "The " << title << " must be a number \n";
		}
		else {
			sscanf(inputString.c_str(), "%d", &temp);
			if (temp <= max && temp >= min) {
				ok = true;
				*s = temp;
			}
			else {
				cout << "The " << title << " must be between " << min << " and " << max << "\n";
			}

		}
	}
	return 1;
}


