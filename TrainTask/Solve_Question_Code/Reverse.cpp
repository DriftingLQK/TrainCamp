#include<iostream>
#include<vector>

using namespace  std;

/**************************第二十一题**********************************
[要求]
给出一个32位的有符号整数，你需要将这个整数中每位上的数字进行反转。
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [-2^31,  2^31-1]。
请根据这个假设，如果反转后整数溢出那么就返回 0。
****************************************************************************/

int Reverse(int x)
{
	if (x > INT_MAX || x < INT_MIN || x == 0)  //判断输入数据的正确性
	{
		return 0;
	}
	int  flag;//判断数据的正负
	if (x < 0)
		flag = -1;
	else
		flag = 1;

	int saveinput;    //存储输入的数
	if (x == INT_MIN)  //如果是最小值-2147483648，	
	{
		saveinput = INT_MAX;  //取绝对值会溢出，用正最大值替代，尾数7与8对翻转影响不大
	}
	else
	{
		saveinput = abs(x);			
	}

	int  result;               //   防止反转后存储值超过int的最大范围
	int temp = saveinput, n = 0;
	while (temp)               //   将原数倒序表示
	{
		if (INT_MAX / 10 < n)      //  最大值的最后一位是 7 ，给定的最大数字首位不能大于2
		{
			return 0;
		}
		else
		{
			n = n * 10 + temp % 10;
			temp = temp / 10;
		}

	}
	result = flag * n;

	if (result > INT_MAX || result < INT_MIN)
	{
		return 0;
	}
	return (int)result;
}


