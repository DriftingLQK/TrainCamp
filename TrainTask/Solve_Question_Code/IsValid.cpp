#include<iostream>
#include<vector>
using namespace std;

/****************************��ʮ����***************************************************** /
[Ҫ��]
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
��Ч�ַ��������㣺
�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����
**********************************************/////
bool IsValid(string str)
{
	// �ж��Ƿ��ǿ��ַ������ַ���Ϊ����
	int len = str.size();

	if (len % 2 != 0)
		return false;
	if (len==0 )
	{
		return true;
	}
	vector<char> ValidSave;
	ValidSave.clear();
	int span = NULL;
	char match = NULL;
	if (str[0] == ')' || str[0] == ']' || str[0] == '}')
	{
		return false;
	}
	if (str[len - 1] == '[' || str[len - 1] == '(' || str[len - 1] == '{')
	{
		return false;
	}

	for (int i = 0; i < len; i++)
	{

		if (str[i] == '(')
		{
			span = 1;
		}
		if (str[i] == '[')
		{
			span = 2;
		}
		if (str[i] == '{')
		{
			span = 3;
		}
		if (str[i] == ')')
		{
			span = 4;
		}
		if (str[i] == ']')
		{
			span = 5;
		}
		if (str[i] == '}')
		{
			span = 6;
		}
		switch (span)
		{
		case 1:    //������ ����������
			ValidSave.push_back(str[i]);
			break;

		case 2://������ ����������
			ValidSave.push_back(str[i]);
			break;
		case 3: //������ ����������
			ValidSave.push_back(str[i]);
			break;
		case 4: //��С���ţ��ж���������Ƿ���
			match = ValidSave.back();
			if (match == '(')
			{
				ValidSave.pop_back();
			}
			else
			{
				return false;
			}
			break;
		case 5:
			match = ValidSave.back();
			if (match == '[')
			{
				ValidSave.pop_back();
			}
			else
			{
				return false;
			}
			break;
		case 6:
			match = ValidSave.back();
			if (match == '{')
			{
				ValidSave.pop_back();
			}
			else
			{
				return false;
			}
			break;
		default:
			break;
		}
		span = NULL;
		match = NULL;
	}
	if (ValidSave.empty())
		return true;
	else
		return false;
}
