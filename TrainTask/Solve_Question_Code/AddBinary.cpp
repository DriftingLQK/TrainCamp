#include<iostream>
#include<string>
using namespace std;
/**************************��9�⣺*********************************************************
[Ҫ��]
���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����
����Ϊ�ǿ��ַ�����ֻ�������� 1 �� 0��
��ʾ��ÿ���ַ��������ַ� '0' �� '1' ��ɡ�
         1 <= a.length, b.length <= 10^4
         �ַ���������� "0" ���Ͷ�����ǰ���㡣
************************* *******************************************/

string AddBinary(string a, string b) {
	int len1 = a.size();
	int len2 = b.size();
	int lenmax, lenmin;
	if (len1 >= len2)
	{
		lenmax = len1;  //�ж������������ַ�������󳤶�
	    lenmin = len2;
	}
		
	else
	{
		lenmax = len2;
		lenmin = len1;
	}
		
		if (lenmax>10000 || lenmin<1)
	{
		return "�������";
	}
	string value;
	int carry = 0;
	while (carry | len1 | len2)
	{
		if (len1)
		{
			--len1;
			carry += a[len1] - '0';       //���ַ������һλת����������
		}
		if (len2)
		{
			--len2;
			carry += b[len2] - '0';        //���ַ������һλת����������
		}
		value.push_back(carry % 2 + '0');  // push_back����string��������һ���ַ���


		carry >>= 1;                       //��������޸�
	}
	reverse(value.begin(), value.end());   //  �ַ�����ת
	return value;
}
