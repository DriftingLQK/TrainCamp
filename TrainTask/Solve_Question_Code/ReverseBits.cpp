#include<iostream>
#include<vector>
using namespace std;

/*****************************��ʮ����
[Ҫ��]
�ߵ������� 32 λ�޷��������Ķ�����λ��
[���]
�����ε�������������㽫����Ż�����㷨��
*************************************************************/

unsigned int ReverseBits(unsigned int n)
{
	vector<int> Bits;
	for (int i = 0; i<32; i++)   //���ν�����������ĩλ�ŵ������е�β��
	{
		Bits.push_back(n % 2);
		n /= 2;
	}
	//vector ������˶���������ת
	unsigned int savebit = 0;

	for (int i = 0; i<32; i++)  // ����ת�Ķ�������ת��Ϊʮ������
	{
		savebit = 2 * savebit + Bits[i];
	}
	return savebit;
}


//unsigned int ReverseBits(unsigned int n)   //��λ�ӷ����ӵ�ĩλ
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
