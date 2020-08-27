#include<iostream>
#include<string>
using namespace std;



/********************第十三题***********************************
实现一个 atoi 函数，使其能将字符串转换成整数。
首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：
如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
提示：本题中的空白字符只包括空格字符 ' ' 。
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为[-2^31, 2^31-1]。如果数值超过这个范围，请返回  INT_MAX(2^31-1) 或 INT_MIN(-2^31) 。

[说明]
假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。
在任何情况下，若函数不能进行有效的转换时，请返回 0 。
**************************************************************/

int myAtoi(string str)
{


	int len = str.size();
	if (len <= 0)
	{
		return 0;
	}

	int start = str.find_first_not_of(' ', 0);
	if (start == string::npos)   //如果找到不全是空格
	{
		return 0;
	}

	//确定数字的正负
	int flag;        //标定符号
	if (str[start] == '+' || isdigit(str[start]) || str[start] == '-')
	{
		if (str[start] == '+' || isdigit(str[start]))
		{
			if (str[start] == '+')
			{
				flag = 1;
				start++;
			}
			else
				flag = 1;
		}
		else
		{
			flag = -1;
			start++;
		}
	}
	else
	{
		return 0;
	}

	int temp = NULL;
	long long value = NULL;       //转化的数值
	while (start < len && isdigit(str[start]))
	{
		temp = (str[start] - '0');
		value = value * 10 + temp;
		temp = NULL;
		start++;
		if (value > INT_MAX)    //如果所计算的数值大于最大值，则判断当前是正数还是负数
		{
			if (flag == -1)
			{
				return INT_MIN;
			}
			else
			{
				return INT_MAX;
			}
		}
	}
	int result = value*flag;
	return result;
}
