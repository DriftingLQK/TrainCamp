#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


vector<string> RestoreIpAddresses(string s)
{
	vector<string>ipPath;           //存储IP地址
	if (s.length()<4 || s.length()>12)      //当输入字符过短或者过长 则不满足IP地址格式
	{
		return ipPath;
	}
	/*if (s[0]=='0')
	{
	ipPath.push_back(0);
	return ipPath;
	}*/
	string FristFeature, SecondFeature, ThirdFeature, RemindFeature;
	int FristNumber, SecondNumber, ThirdNumber, RemindNumber;
	string IpTemp;     //存储IP地址的字符串
	int NowIpLen, flag = 0;
	int remindlen;
	int TypeWide_1 = 4;
	int TypeWide_2 = 4;
	int TypeWide_3 = 4;
	int TypeWide_4 = 4;
	for (int a = 1; a < TypeWide_1; a++)       //第一栏的个数
	{
		for (int b = 1; b < TypeWide_2; b++)      //第二栏的个数
		{
			for (int c = 1; c < TypeWide_3; c++)      //第三栏的个数
			{
				for (int d = 1; d < 4; d++)     //第四栏的个数
				{
					NowIpLen = a + b + c + d;  //计算当前长度
					if (NowIpLen == s.length())    //判断是否占用所有字符串
					{
						FristFeature = s.substr(0, a);//第一栏的信息						
						FristNumber = stoi(FristFeature, 0, 10);
						SecondFeature = s.substr(a, b);//第二栏的信息
						SecondNumber = stoi(SecondFeature, 0, 10);
						ThirdFeature = s.substr(a + b, c);//第三栏的信息	
						ThirdNumber = stoi(ThirdFeature, 0, 10);
						RemindFeature = s.substr(a + b + c); //剩余的信息

						RemindNumber = stoi(RemindFeature, 0, 10);
						if (FristFeature == "0")   //判断第一个段的数是否为0
						{
							TypeWide_1 = 1;
							if (SecondFeature == "0")
							{
								TypeWide_2 = 1;
								if (ThirdFeature == "0")
								{
									TypeWide_3 = 1;
									if (RemindFeature.size() > 1 && RemindFeature[0] == '0')
									{
										return ipPath;
									}
								}
							}
							else if (ThirdFeature.size() > 1 && ThirdFeature[0] == '0'||RemindFeature.size() > 1 && RemindFeature[0] == '0')//第三栏的信息
							{
								continue;
							}
							
						}
						else//第一栏不为0
						{
							if (ThirdFeature.size() > 1 && ThirdFeature[0] == '0' || SecondFeature.size() > 1 && SecondFeature[0] == '0' || RemindFeature.size() > 1 && RemindFeature[0] == '0')//第三栏的信息
							{
								continue;
							}
						}




						if (FristNumber <= 255 && SecondNumber <= 255 && ThirdNumber <= 255 && RemindNumber <= 255)
						{
							IpTemp = to_string(FristNumber) + "." + to_string(SecondNumber) + "." + to_string(ThirdNumber) + "." + to_string(RemindNumber);
							for (unsigned int i = 0; i < ipPath.size(); i++)
							{
								if (IpTemp == ipPath[i])
								{
									flag = 1;
									break;
								}
							}
							if (flag == 0)  //如果数组中不存在当前IP，则保存
							{
								ipPath.push_back(IpTemp);
								flag = 0;
							}
						}
					}  //判断长度
					RemindFeature.clear();
				}// for 第四栏
			}  // for 第三栏
		}  // for 第二栏
	}  // for 第一栏

	return ipPath;
}