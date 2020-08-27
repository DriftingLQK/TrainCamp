#include<iostream>
#include<vector>
#include<string>
using namespace std;

/************************��ʮ����*****************
[Ҫ��]
����һ���ǿ��ַ���s��һ�������ǿյ����б���ֵ�wordDict��
�ж�s�Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ���
******************************************************/



//�����ֵ䵥���ж��ַ����Ƿ�ӵ�ǰλ��ƥ�䣬�жϿɲ�ֵ�λ�ã������жϿɲ��λ�õĺ����ַ����Ƿ�ƥ��
bool WordBreak(string str, vector<string>& wordDict)
{
	int len = str.size();
	if (len <= 0 || wordDict.size() == 0)
	{
		return false;
	}
	vector<bool> Check(len + 1, false);     //����һ��vector ��СΪlen+1��ֵȫΪfalse
	Check[0] = true;   //��ʾ����ʼλ�ÿ�ʼ���Խ���ƥ��

	for (int index = 0; index < len; index++)    //�����ַ����ĸ����ַ�
	{
		if (Check[index] == false)
			continue;
		for (string word : wordDict)     //�����ֵ��еĸ������� 
		{
			if (str.find(word, index) == index)   //�ж� �ֵ��еĸ����ַ����ܷ��ڵ�ǰλ���ҵ���Ӧ��
				Check[index + (int)word.size()] = true;
		}
	}
	return Check[len];
}

//bool WordBreak(string s, vector<string>& wordDict)   //�����ֵ䵥�ʳ����ж��ַ����Ƿ�ƥ��
//{
//	int len = s.size();
//	if (len <= 0 || wordDict.size() == 0)
//	{
//		return false;
//	}
//	vector<int>Check(len + 1, false);  //����һ������
//	Check[0] = true;
//	int wordstart = NULL;
//	string strword;
//	for (unsigned int i = 1; i < s.size() + 1; ++i)
//	{
//		for (string word : wordDict)
//		{
//			wordstart = i - word.size();                 //������ʼλ��
//			if (i >= word.size() && Check[wordstart])
//			{
//				strword = s.substr(wordstart, word.size());  //��ȡ�ַ����ж�Ӧ���ȵĵ���
//				if (word == strword)
//				{
//					Check[i] = true;
//					break;
//				}
//			}
//		}
//	}
//	return Check[len];
//	//return *Check.rbegin();   //rbegin() ָ����ĵ�һ��Ԫ��  end ָ���������һ��Ԫ��+1��λ��
//}