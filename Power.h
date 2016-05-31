#pragma once

//实现函数double Power(double base, int exponent),求base的exponent次方。
//不得使用库函数，不用考虑大数问题

//InvalidInput用来检查返回0时是否非法
bool InvalidInput = false;

//浮点值与0的比较
bool equal(double num1, double num2)
{	
	if (num1 - num2 > 0.000001
		|| num1 - num2 < -0.000001)
		return true;
	else
		return false;
}

//double PowerWithUnsignedExponent(double base, unsigned int exponent)
//{
//	double ret = 1.0;
//
//	for (size_t i = 0; i < exponent; i++)
//	{
//		ret *= base;
//	}
//
//	return ret;
//}

//			a^(n/2) * a^(n/2)			,n为偶数
// a^n = {
//			a^((n-1)/2) * ((n-1)/2) * n	,n为奇数
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double ret = PowerWithUnsignedExponent(base, exponent >> 1);
	ret *= ret;

	if (exponent & 0x1 == 1)
		ret *= base;

	return ret;
}

double Power(double base, int exponent)
{
	InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0)
	{
		InvalidInput = true;
		return 0.0;//浮点值
	}

	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);

	double ret = PowerWithUnsignedExponent(base, absExponent);

	if (exponent < 0)
		ret = 1.0 / ret;

	return ret;
}
