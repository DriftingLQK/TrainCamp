#include<iostream>
using namespace std;



/*************************第三题：
[要求]
编写一个程序判断给定的数是否为丑数。丑数就是只包含质因数 2, 3, 5 的正整数。
说明：
1. 1 是丑数。
2.输入不会超过 32 位有符号整数的范围-（2的31次方）---2的31次方 -1。
///思路一：首先除2，直到不能整除为止，然后除5到不能整除为止，然后除3直到不能整除为止。
//最终判断剩余的数字是否为1，如果是1则为丑数，否则不是丑数。
*********************************/

bool IsUgly(int num)
{
	/*int  Primefactor[] = { 2, 3, 5 };*/
	if (num <= 0)
	{
		return false;
	}
	else
	{
		while (num % 2 == 0)
			num /= 2;
		while (num % 5 == 0)
			num /= 5;
		while (num % 3 == 0)
			num /= 3;

		if (num == 1)
			return true;
		else
			return false;
	}  //	if (num <= 0)

}

