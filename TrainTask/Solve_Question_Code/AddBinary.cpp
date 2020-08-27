#include<iostream>
#include<string>
using namespace std;
/**************************第9题：*********************************************************
[要求]
给你两个二进制字符串，返回它们的和（用二进制表示）。
输入为非空字符串且只包含数字 1 和 0。
提示：每个字符串仅由字符 '0' 或 '1' 组成。
         1 <= a.length, b.length <= 10^4
         字符串如果不是 "0" ，就都不含前导零。
************************* *******************************************/

string AddBinary(string a, string b) {
	int len1 = a.size();
	int len2 = b.size();
	int lenmax, lenmin;
	if (len1 >= len2)
	{
		lenmax = len1;  //判断两个二进制字符串的最大长度
	    lenmin = len2;
	}
		
	else
	{
		lenmax = len2;
		lenmin = len1;
	}
		
		if (lenmax>10000 || lenmin<1)
	{
		return "输入错误！";
	}
	string value;
	int carry = 0;
	while (carry | len1 | len2)
	{
		if (len1)
		{
			--len1;
			carry += a[len1] - '0';       //将字符串最后一位转成整型数字
		}
		if (len2)
		{
			--len2;
			carry += b[len2] - '0';        //将字符串最后一位转成整型数字
		}
		value.push_back(carry % 2 + '0');  // push_back，在string中最后插入一个字符；


		carry >>= 1;                       //检查后程序修改
	}
	reverse(value.begin(), value.end());   //  字符串反转
	return value;
}
