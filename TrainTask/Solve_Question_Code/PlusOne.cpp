#include<iostream>
#include<vector>

using namespace std;
/****************************第十八题**************************
[要求]
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
**********************************************************/


vector<int> PlusOne(vector<int>& digits)
{
	reverse(digits.begin(), digits.end());//反转给定的数组
	vector<int>Result(digits);

	if (digits[0] < 9)        //如果最后一位小于九 ，则可以直接加
	{
		Result[0]++;
	}
	else                     //如果最后一位大于等于九 ，则需要进行进位处理
	{
		int oneplus = 0;         //定义一个相加后的变量
		int index = 0;
		unsigned int flag = 1;
		while (index < digits.size())
		{
			oneplus = digits[index] + flag; //给定的数组中的数与进位标志相加
			if (oneplus > 9)                //如果大于9 则有进位
			{
				Result[index] = 0;          //结果中的数字置零
				flag = 1;                   //进位标记置一
			}
			else                            //如果没有进位              
			{
				Result[index] = oneplus;    //直接将相加的结果存入
				flag = 0;
			}
			index++;
		}
		if (flag != 0)
		{
			Result.push_back(flag);
		}
	}
	reverse(Result.begin(), Result.end());//反转计算得到的数组
	return Result;
}
