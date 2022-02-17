#include<iostream>
#include<fstream>
#include <NTL/ZZ.h>
#include <NTL/vec_ZZ.h>
#include <NTL/mat_ZZ.h>
#include <NTL/LLL.h>
#include <time.h>
NTL_CLIENT
//背包问题->svp格上最短向量问题->LLL算法进行格基规约后，取其最短向量

void main() {
	//创建变量
	#include <time.h>
	ZZ a[80], b[80], c[80], x1[50000], x2[50000], sum;
	sum = to_ZZ("3808748539414823520119275163007");
	//cout << sum << endl;
	char x[10];
	int num1 = 0, num2 = 0;
	int n1, n2, n3, n4, n5;
	int z1, z2, z3, z4, z5;
	//读取文件到数组中
	ifstream fin("input80.txt");
	for (int i = 0; i < 10; i++) {
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> a[i];
	}
	for (int i = 10; i < 80; i++) {
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> a[i];
	}
	//读取数组到矩阵B[]中
	mat_ZZ B;
	cout << B << endl;
	B.SetDims(81, 81);
	cout << B << endl;
	for (int i = 0; i < 80; i++) {
		B[i][i] = 1;
		B[i][80] = 0-10000*a[i];
	}
	/*
	for (int i = 0; i < 80; i++) {
		B[80][i] = 0.1;
	}*/
	B[80][80] =10000*sum;

	//将这个矩阵进行LLL规约

	cout << B << endl;
	clock_t stop;
	BKZ_FP(B, 0.99, 20);
	stop = clock();
	cout << "time = " << stop / CLOCKS_PER_SEC << "s" << endl;
	//BKZ_XD(B);
	cout << B << "\n";
	/*
	B[80][80] = 0;
	for (int i = 0; i < 60; i++) {
		B[80][80] += a[i];
	}
	B[80][80] - sum;

	cout << B << endl;
	LLL_QP(B);
	cout << B << "\n";*/
	//验证
	ZZ n;
	for (int i = 0; i <80; i++) {
		n = 0;
		for (int j = 0; j < 80; j++) {
			n = n + B[i][j] * a[j];
		}
		//n = n + sum;
		cout << i << ' ' << n << endl;
		if (n == 0) {
			cout << B[i] << "\n";
		
		}
	}

	cout << B[0] << "\n";
}