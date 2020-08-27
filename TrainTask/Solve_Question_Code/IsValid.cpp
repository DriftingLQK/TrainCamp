#include<iostream>
#include<vector>
using namespace std;

/****************************第十二题***************************************************** /
[要求]
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
**********************************************/////
bool IsValid(string str)
{
	// 判断是否是空字符或者字符串为奇数
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
		case 1:    //左括号 ，存入容器
			ValidSave.push_back(str[i]);
			break;

		case 2://左括号 ，存入容器
			ValidSave.push_back(str[i]);
			break;
		case 3: //左括号 ，存入容器
			ValidSave.push_back(str[i]);
			break;
		case 4: //右小括号，判断数组最后是否是
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
