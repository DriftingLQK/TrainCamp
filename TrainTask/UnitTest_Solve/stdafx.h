// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//
#pragma once
#include "targetver.h"
#include "CppUnitTest.h"// 用于 CppUnitTest 的头文件

// TODO:  在此处引用程序需要的其他头文件
#include<iostream>
#include <vector>
#include <stdlib.h> 
#include <string>
#include <atlstr.h>  // 读取ini文件时使用,关键头文件  
#include <math.h>    //字符串分割
#include"..//Solve_Question_Code//Solve_Question_Code.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


#define FILEPATH "..//TestData.ini"   //测试文件地址
#define TestTitle1  "Test1"			  //测试题目节名
#define TestTitle2  "Test2"			  //测试题目节名
#define TestTitle3  "Test3"			  //测试题目节名
#define TestTitle4  "Test4"			  //测试题目节名
#define TestTitle5  "Test5"			  //测试题目节名
#define TestTitle6  "Test6"			  //测试题目节名
#define TestTitle7  "Test7"			  //测试题目节名
#define TestTitle8  "Test8"			  //测试题目节名
#define TestTitle9  "Test9"			  //测试题目节名
#define TestTitle10  "Test10"		  //测试题目节名
#define TestTitle11  "Test11"		  //测试题目节名
#define TestTitle12  "Test12"		  //测试题目节名
#define TestTitle13  "Test13"		  //测试题目节名
#define TestTitle14  "Test14"		  //测试题目节名
#define TestTitle15  "Test15"		  //测试题目节名
#define TestTitle16  "Test16"		  //测试题目节名
#define TestTitle17  "Test17"		  //测试题目节名
#define TestTitle18  "Test18"		  //测试题目节名
#define TestTitle19  "Test19"		  //测试题目节名
#define TestTitle20  "Test20"		  //测试题目节名
#define TestTitle21  "Test21"		  //测试题目节名
#define TestTitle22  "Test22"		  //测试题目节名
#define TestTitle23  "Test23"		  //测试题目节名
#define TestTitle24  "Test24"		  //测试题目节名
#define TestTitle25  "Test25"		  //测试题目节名
#define TestNumKey  "Num"			  //测试题目数据个数键名
#define TestInputArray  "Array"		  //测试数据-输入数据键名1
#define TestInputKey  "Key"           //测试数据-输入数据键名2
#define TestInputKey_Input  "Input"   //测试数据-输入数据键名3
//#define TestInputKey_4  "Key"       //测试数据-输入数据键名4
#define TestOutputKey  "Output"       //测试数据-输出数据键名1
//#define TestOutputKey_2  "Output"   //测试数据-输出数据键名2
#define GET_INI_MAXSIZE  70000          //读取ini文件数值及字符串缓存区大小
#define GET_INI_BOOL  20              //读取ini文件中布尔量缓存区大小
#define DATASUM_BUFFER  100           //字符串转换样例数大小


int Str_To_Int(string str, int *ResuleData, int *CheckData, int numberbuffer); //字符串分割函数
int StrToInt_New(char *InputData, int len, vector<int>&nums, vector<int>&flags);
TreeNode *CreateBTree(TreeNode *node, vector<int>&nums, vector<int>&flags, int n, int& index);            //创建一个二叉树--层次结构
TreeNode *CreateBTree2(TreeNode *node, int *num, int *check, int& index);                  //创建一个二叉树--前序结构

void Test1(CString c);   //题目1_单元测试
void Test2(CString c);   //题目2_单元测试
void Test3(CString c);   //题目3_单元测试
void Test4(CString c);   //题目4_单元测试
void Test5(CString c);   //题目5_单元测试
void Test6(CString c);   //题目6_单元测试
void Test7(CString c);   //题目7_单元测试
void Test8(CString c);   //题目8_单元测试
void Test9(CString c);   //题目9_单元测试
void Test10(CString c);  //题目10_单元测试
void Test11(CString c);  //题目10_单元测试
void Test12(CString c);  //题目12_单元测试
void Test13(CString c);  //题目13_单元测试
void Test14(CString c);  //题目14_单元测试
void Test15(CString c);  //题目15_单元测试
void Test16(CString c);  //题目16_单元测试
void Test17(CString c);  //题目17_单元测试
void Test18(CString c);  //题目18_单元测试
void Test19(CString c);  //题目19_单元测试
void Test20(CString c);  //题目20_单元测试
void Test21(CString c);  //题目21_单元测试
void Test22(CString c);  //题目22_单元测试
void Test23(CString c);  //题目23_单元测试
void Test24(CString c);  //题目24_单元测试
void Test25(CString c);  //题目25_单元测试
