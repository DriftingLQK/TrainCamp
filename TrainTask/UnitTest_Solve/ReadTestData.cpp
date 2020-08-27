//#include<iostream>
//#include <string>
//#include <atlstr.h>   //关键头文件
#include "stdafx.h"


CString ReadTestData(CString InputTiltle, CString InputKey, int MAXSIZE ,CString FilePath)
{
	//CString StrTital, StrKey, StrValue;   //写入
	//StrTital = "Student";
	//StrKey = "Name";
	//StrValue = "jacky";
	//WritePrivateProfileString(StrTital, StrKey, StrValue,FILEPATH);

	CString DataTital, DataKey, OutValue;         //读取
	DataTital = InputTiltle;
	DataKey = InputKey;
	GetPrivateProfileString(DataTital, DataKey, "DefaultName", OutValue.GetBuffer(MAXSIZE), MAXSIZE, FilePath);
	return OutValue;
}


