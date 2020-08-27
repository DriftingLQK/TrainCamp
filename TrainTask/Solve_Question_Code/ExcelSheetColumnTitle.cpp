#include<iostream>
#include<string>

using namespace std;

string ExcelSheetColumnTitle(int n)
{
	string  flag = "";
	if (n <= 0)
	{
		return flag;
	}
	else
	{
		do
		{
			n--;
			int a = n % 26;
			flag = (char)('A' + a) + flag;
			n /= 26;
		} while (n != 0);
		return flag;
	}
}

//int main()
//{
//	int n = 78;
//	string title = ExcelSheetColumnTitle(n);
//	cout << title << endl;
//	getchar();
//	return 0;
//}
//