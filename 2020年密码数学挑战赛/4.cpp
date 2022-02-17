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
	ZZ a[100], sum;
	sum = to_ZZ("214326896127070329471158810547025670819");
	//cout << sum << endl;
	char x[10];
	//读取文件到数组中
	ifstream fin("input100.txt");
	for (int i = 0; i < 10; i++) {
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> a[i];
	}
	for (int i = 10; i < 100; i++) {
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> a[i];
	}
	//读取数组到矩阵B[]中
	mat_ZZ B;
	cout << B << endl;
	B.SetDims(101, 101);
	cout << B << endl;
	for (int i = 0; i < 100; i++) {
		B[i][i] = 1;
		B[i][100] = 0 - a[i];
	}
	/*
	for (int i = 0; i < 80; i++) {
		B[80][i] = 0.1;
	}*/
	B[100][100] = sum;

	//将这个矩阵进行LLL规约

	cout << B << endl;
	clock_t stop;
	BKZ_FP(B, 0.99,25);
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
	for (int i = 0; i < 100; i++) {
		n = 0;
		for (int j = 0; j < 100; j++) {
			n = n + B[i][j] * a[j];
		}
		n = n + sum;
		cout << i << ' ' << n << endl;
		if (n == 0) {
			cout << B[i] << "\n";

		}
	}
	cout << "time = " << stop / CLOCKS_PER_SEC << "s" << endl;

	cout << B[0] << "\n";
}