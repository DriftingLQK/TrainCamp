#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*******************************��ʮ����********************
[Ҫ��]
����һ�ֹ���pattern��һ���ַ���str���ж�str�Ƿ���ѭ��ͬ�Ĺ��ɡ�
�������ѭָ��ȫƥ�䡣
���磺pattern ���ÿ����ĸ���ַ��� str �е�ÿ���ǿյ���֮�������˫�����ӵĶ�Ӧ���ɡ�
****************************************************************/
bool WordPattern(string Pattern, string str)
{

	if (Pattern.empty() || str.empty())   //�����������ַ���Ϊ�գ������false
		return false;

	unordered_map <char, string> PtoW_map;   // �����뵥��ƥ���
	unordered_map <string, char> WtoP_map;   // ���ʱ����飩

	vector<string>StrWord;  //�洢������
#pragma region     �Ƚ��ַ����Կո�������洢��������
	int pos = 0;
	int index = 0;

	while (pos != -1) // ����find_first_of() �������ַ����е�1�����ֵ��ַ� ' '������ƥ���λ�á����û���ҵ����������� -1.
	{
		pos = str.find_first_of(' ', index);     //�ҵ��ո�����λ��   		
		StrWord.push_back(str.substr(index, pos - index));   // ����ַ���str�дӵ�iλ��ʼ�ĳ���Ϊpos - i���ַ���
		index = pos + 1;
	}
#pragma endregion  

	if (Pattern.size() != StrWord.size())     //�������͵��ʸ������Ƕ�Ӧ�ģ�ֱ�ӷ���Ϊ��
		return false;
	//
	for (unsigned int i = 0; i<Pattern.size(); i++)
	{
		if (PtoW_map.find(Pattern[i]) != PtoW_map.end())   //�����������ҵ���ǰ����
		{
			if (PtoW_map[Pattern[i]] == StrWord[i])        //  �жϵ�ǰ�����Ӧ�ĵ�����ԭλ�õĵ����Ƿ�ƥ��
				continue;
			else
				return false;
		}
		else      //�����������Ҳ�����ǰ���򣬽���Ӧ�����뵥�ʴ������
		{
			if (WtoP_map.find(StrWord[i]) != WtoP_map.end())   // ����Ҳ������򣬵��ǵ��ʱ��г����ˣ���ֱ�ӷ���false
				return false;

			PtoW_map[Pattern[i]] = StrWord[i];     //�����ʴ�����ж�Ӧ�Ĺ�����
			WtoP_map[StrWord[i]] = Pattern[i];     //�����ʴ��뵥�ʲ��ұ���
		}
	}
	return true;
}
