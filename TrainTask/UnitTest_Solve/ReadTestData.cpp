//#include<iostream>
//#include <string>
//#include <atlstr.h>   //�ؼ�ͷ�ļ�
#include "stdafx.h"


CString ReadTestData(CString InputTiltle, CString InputKey, int MAXSIZE ,CString FilePath)
{
	//CString StrTital, StrKey, StrValue;   //д��
	//StrTital = "Student";
	//StrKey = "Name";
	//StrValue = "jacky";
	//WritePrivateProfileString(StrTital, StrKey, StrValue,FILEPATH);

	CString DataTital, DataKey, OutValue;         //��ȡ
	DataTital = InputTiltle;
	DataKey = InputKey;
	GetPrivateProfileString(DataTital, DataKey, "DefaultName", OutValue.GetBuffer(MAXSIZE), MAXSIZE, FilePath);
	return OutValue;
}


