#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


vector<string> RestoreIpAddresses(string s)
{
	vector<string>ipPath;           //�洢IP��ַ
	if (s.length()<4 || s.length()>12)      //�������ַ����̻��߹��� ������IP��ַ��ʽ
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
	string IpTemp;     //�洢IP��ַ���ַ���
	int NowIpLen, flag = 0;
	int remindlen;
	int TypeWide_1 = 4;
	int TypeWide_2 = 4;
	int TypeWide_3 = 4;
	int TypeWide_4 = 4;
	for (int a = 1; a < TypeWide_1; a++)       //��һ���ĸ���
	{
		for (int b = 1; b < TypeWide_2; b++)      //�ڶ����ĸ���
		{
			for (int c = 1; c < TypeWide_3; c++)      //�������ĸ���
			{
				for (int d = 1; d < 4; d++)     //�������ĸ���
				{
					NowIpLen = a + b + c + d;  //���㵱ǰ����
					if (NowIpLen == s.length())    //�ж��Ƿ�ռ�������ַ���
					{
						FristFeature = s.substr(0, a);//��һ������Ϣ						
						FristNumber = stoi(FristFeature, 0, 10);
						SecondFeature = s.substr(a, b);//�ڶ�������Ϣ
						SecondNumber = stoi(SecondFeature, 0, 10);
						ThirdFeature = s.substr(a + b, c);//����������Ϣ	
						ThirdNumber = stoi(ThirdFeature, 0, 10);
						RemindFeature = s.substr(a + b + c); //ʣ�����Ϣ

						RemindNumber = stoi(RemindFeature, 0, 10);
						if (FristFeature == "0")   //�жϵ�һ���ε����Ƿ�Ϊ0
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
							else if (ThirdFeature.size() > 1 && ThirdFeature[0] == '0'||RemindFeature.size() > 1 && RemindFeature[0] == '0')//����������Ϣ
							{
								continue;
							}
							
						}
						else//��һ����Ϊ0
						{
							if (ThirdFeature.size() > 1 && ThirdFeature[0] == '0' || SecondFeature.size() > 1 && SecondFeature[0] == '0' || RemindFeature.size() > 1 && RemindFeature[0] == '0')//����������Ϣ
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
							if (flag == 0)  //��������в����ڵ�ǰIP���򱣴�
							{
								ipPath.push_back(IpTemp);
								flag = 0;
							}
						}
					}  //�жϳ���
					RemindFeature.clear();
				}// for ������
			}  // for ������
		}  // for �ڶ���
	}  // for ��һ��

	return ipPath;
}