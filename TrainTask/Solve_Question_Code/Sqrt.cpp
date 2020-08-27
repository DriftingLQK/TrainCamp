#include<iostream>
#include<cmath>
using namespace std;

/*********************************************第十九题**********************
[要求]
实现 int sqrt(int x) 函数，计算并返回 x 的平方根，其中 x 是非负整数。由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
[提高]
要求不使用现成的函数

本方法使用牛顿迭代进行计算
************************************************************************************/


int Sqrt(int y)  //x为非负整数
{
	if (y < 2)
		return y;
	double x0 = y;                    // 构建函数方程  f(x) = x^2-y ，f'(x) = 2*x
	double x1 = (x0 + y / x0) / 2.0;  // x1 = x0-f(x0)/f'(x0)
	int count = 0;
	double delta = x1 - x0;
	while (abs(delta) >= 0.5)        // 采用牛顿迭代方式进行迭代计算，当两个解之间的偏差值小于0.5 ，则结束迭代
	{
		//count++;                  //迭代次数统计
		x0 = x1;
		x1 = (x0 + y / x0) / 2.0;
		delta = x1 - x0;
	}
	//cout << count << endl;
	return (int)x1;

	//int result;
	//result = sqrt(y);
	//return result;
}