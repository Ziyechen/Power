#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stdlib.h>
#include "Power.h"
using namespace std;

void TestPower()
{
	double ret1 = Power(7.0, 1);
	double ret2 = Power(7.0, 2);
	double ret3 = Power(7.0, 0);
	double ret4 = Power(0.0, -1);

	cout << "ret1 = " << ret1 << endl;
	cout << "ret2 = " << ret2 << endl;
	cout << "ret3 = " << ret3 << endl;
	cout << "ret4 = " << ret4 << endl;

}

int main()
{
	TestPower();

	system("pause");
	return 0;
}
