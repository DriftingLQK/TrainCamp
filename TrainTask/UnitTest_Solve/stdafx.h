// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//
#pragma once
#include "targetver.h"
#include "CppUnitTest.h"// ���� CppUnitTest ��ͷ�ļ�

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include<iostream>
#include <vector>
#include <stdlib.h> 
#include <string>
#include <atlstr.h>  // ��ȡini�ļ�ʱʹ��,�ؼ�ͷ�ļ�  
#include <math.h>    //�ַ����ָ�
#include"..//Solve_Question_Code//Solve_Question_Code.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


#define FILEPATH "..//TestData.ini"   //�����ļ���ַ
#define TestTitle1  "Test1"			  //������Ŀ����
#define TestTitle2  "Test2"			  //������Ŀ����
#define TestTitle3  "Test3"			  //������Ŀ����
#define TestTitle4  "Test4"			  //������Ŀ����
#define TestTitle5  "Test5"			  //������Ŀ����
#define TestTitle6  "Test6"			  //������Ŀ����
#define TestTitle7  "Test7"			  //������Ŀ����
#define TestTitle8  "Test8"			  //������Ŀ����
#define TestTitle9  "Test9"			  //������Ŀ����
#define TestTitle10  "Test10"		  //������Ŀ����
#define TestTitle11  "Test11"		  //������Ŀ����
#define TestTitle12  "Test12"		  //������Ŀ����
#define TestTitle13  "Test13"		  //������Ŀ����
#define TestTitle14  "Test14"		  //������Ŀ����
#define TestTitle15  "Test15"		  //������Ŀ����
#define TestTitle16  "Test16"		  //������Ŀ����
#define TestTitle17  "Test17"		  //������Ŀ����
#define TestTitle18  "Test18"		  //������Ŀ����
#define TestTitle19  "Test19"		  //������Ŀ����
#define TestTitle20  "Test20"		  //������Ŀ����
#define TestTitle21  "Test21"		  //������Ŀ����
#define TestTitle22  "Test22"		  //������Ŀ����
#define TestTitle23  "Test23"		  //������Ŀ����
#define TestTitle24  "Test24"		  //������Ŀ����
#define TestTitle25  "Test25"		  //������Ŀ����
#define TestNumKey  "Num"			  //������Ŀ���ݸ�������
#define TestInputArray  "Array"		  //��������-�������ݼ���1
#define TestInputKey  "Key"           //��������-�������ݼ���2
#define TestInputKey_Input  "Input"   //��������-�������ݼ���3
//#define TestInputKey_4  "Key"       //��������-�������ݼ���4
#define TestOutputKey  "Output"       //��������-������ݼ���1
//#define TestOutputKey_2  "Output"   //��������-������ݼ���2
#define GET_INI_MAXSIZE  70000          //��ȡini�ļ���ֵ���ַ�����������С
#define GET_INI_BOOL  20              //��ȡini�ļ��в�������������С
#define DATASUM_BUFFER  100           //�ַ���ת����������С


int Str_To_Int(string str, int *ResuleData, int *CheckData, int numberbuffer); //�ַ����ָ��
int StrToInt_New(char *InputData, int len, vector<int>&nums, vector<int>&flags);
TreeNode *CreateBTree(TreeNode *node, vector<int>&nums, vector<int>&flags, int n, int& index);            //����һ��������--��νṹ
TreeNode *CreateBTree2(TreeNode *node, int *num, int *check, int& index);                  //����һ��������--ǰ��ṹ

void Test1(CString c);   //��Ŀ1_��Ԫ����
void Test2(CString c);   //��Ŀ2_��Ԫ����
void Test3(CString c);   //��Ŀ3_��Ԫ����
void Test4(CString c);   //��Ŀ4_��Ԫ����
void Test5(CString c);   //��Ŀ5_��Ԫ����
void Test6(CString c);   //��Ŀ6_��Ԫ����
void Test7(CString c);   //��Ŀ7_��Ԫ����
void Test8(CString c);   //��Ŀ8_��Ԫ����
void Test9(CString c);   //��Ŀ9_��Ԫ����
void Test10(CString c);  //��Ŀ10_��Ԫ����
void Test11(CString c);  //��Ŀ10_��Ԫ����
void Test12(CString c);  //��Ŀ12_��Ԫ����
void Test13(CString c);  //��Ŀ13_��Ԫ����
void Test14(CString c);  //��Ŀ14_��Ԫ����
void Test15(CString c);  //��Ŀ15_��Ԫ����
void Test16(CString c);  //��Ŀ16_��Ԫ����
void Test17(CString c);  //��Ŀ17_��Ԫ����
void Test18(CString c);  //��Ŀ18_��Ԫ����
void Test19(CString c);  //��Ŀ19_��Ԫ����
void Test20(CString c);  //��Ŀ20_��Ԫ����
void Test21(CString c);  //��Ŀ21_��Ԫ����
void Test22(CString c);  //��Ŀ22_��Ԫ����
void Test23(CString c);  //��Ŀ23_��Ԫ����
void Test24(CString c);  //��Ŀ24_��Ԫ����
void Test25(CString c);  //��Ŀ25_��Ԫ����
