#include<iostream>
#include<vector>
using namespace std;

/*****************************第十六题
[要求]
颠倒给定的 32 位无符号整数的二进制位。
[提高]
如果多次调用这个函数，你将如何优化你的算法？
*************************************************************/

unsigned int ReverseBits(unsigned int n)
{
	vector<int> Bits;
	for (int i = 0; i<32; i++)   //依次将二进制数的末位放到容器中的尾部
	{
		Bits.push_back(n % 2);
		n /= 2;
	}
	//vector 中完成了二进制数反转
	unsigned int savebit = 0;

	for (int i = 0; i<32; i++)  // 将反转的二进制数转化为十进制数
	{
		savebit = 2 * savebit + Bits[i];
	}
	return savebit;
}


//unsigned int ReverseBits(unsigned int n)   //移位加法，加到末位
//{
//	unsigned int m = 0, temp, remd;
//		for (int i = 0; i < 32; i++)
//		{
//		temp = m << 1;
//		remd = n % 2;
//		m = temp + remd;
//		n /= 2;
//		}
//		return m;
//}
