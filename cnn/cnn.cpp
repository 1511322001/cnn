// cnn.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<opencv2\opencv.hpp>
#include"Filter.h"
#include"Activator.h"
#include"commom.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Filter M(5, 5, 5);
	//Activator a;
	//test
	//cout<<a.forward(-5);
	//cout << a.back(2);
	system("pause");
	array3 a;
	a=resize(a, 10, 10, 10);
	a = init_matrix_random(a);
	a=padding(a,2);
	print_matrxi(a);
	system("pause");

	
	
}

