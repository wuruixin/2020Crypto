#include<iostream>
#include<fstream>
#include <NTL/ZZ.h>
#include <NTL/vec_ZZ.h>
#include <NTL/mat_ZZ.h>
#include <NTL/LLL.h>
#include <time.h>
NTL_CLIENT

//背包问题->svp格上最短向量问题->LLL算法进行格基规约后，取其最短向量

using namespace std;
void main() {
	//创建变量
	ZZ a[120], sum;
	sum = to_ZZ("8987566925476668532408205296222718456099890634");
	//cout << sum << endl;
	char x[10];
	//读取文件到数组中
	ifstream fin("input120.txt");
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
	for (int i = 100; i < 120; i++) {
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> a[i];
	}
	for (int i = 0; i < 120; i++) {
		//cout << i << " " << a[i] << endl;
	}
	//读取数组到矩阵B[]中
	mat_ZZ B;
	//cout << B << endl;
	B.SetDims(121, 121);
	//cout << B << endl;

	ZZ P;
	P = 1000000;
	for (int i = 0; i < 120; i++) {
		B[i][i] = 1;
		B[i][120] = 0 - P * a[i];
	}
	/*
	for (int i = 0; i < 80; i++) {
		B[80][i] = 0.1;
	}*/
	B[120][120] = P * sum;

	//将这个矩阵进行LLL规约

	cout << B << endl;
	clock_t stop;
	//BKZ_FP(B, 0.99, 30, 10);
	BKZ_FP(B, 0.99,35,10);
	stop = clock();
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
	for (int i = 0; i < 120; i++) {
		n = 0;
		for (int j = 0; j < 120; j++) {
			n = n + B[i][j] * a[j];
		}
		n = n - sum;
		cout << i << ' ' << n << endl;
		if (n == 0) {
			cout << B[i] << "\n";

		}
	}
	cout << "time = " << stop / CLOCKS_PER_SEC << "s" << endl;

	cout << B[0] << "\n";
	n = 0;
	ZZ nn;
	nn = 0;
	for (int i = 0; i < 120; i++) {
		n = n + B[119][i] * a[i];
		cout << i << " " << n << endl;
		nn = nn + B[119][i] * B[119][i];
	}
	cout << B[119] << endl;
	cout << nn << endl;

}



//BKZ_FP(B, 0.99,30,10);
//[1 - 2 - 1 0 - 2 - 1 0 1 - 2 2 0 0 - 2 - 1 1 0 1 1 1 1 0 - 1 2 0 1 1 - 1 1 0 - 1 1 0 0 1 0 - 1 0 1 1 1 2 1 1 2 0 0 - 1 0 - 1 - 2 0 0 1 1 0 0 0 1 0 - 1 0 0 0 0 - 1 2 - 1 1 - 2 - 1 3 0 1 - 1 - 1 - 1 2 1 - 1 1 0 0 - 1 - 1 1 0 0 0 0 0 0 - 1 1 1 0 - 1 - 3 0 0 0 0 0 0 0 - 1 - 1 2 2 0 0 0 2 0 - 1 0 - 1 0 0 0 - 1 0]

//10 0000 0000  BKZ_FP(B, 0.99);
//[-1 1 - 1 - 2 1 0 2 - 2 0 0 0 1 1 1 0 3 0 - 1 - 1 0 2 0 - 1 1 1 1 - 2 1 0 0 0 - 2 1 - 1 0 3 0 - 2 0 - 3 - 2 1 2 1 1 1 - 1 - 1 2 3 0 0 - 1 1 2 1 0 - 2 - 2 - 1 - 2 1 1 1 - 1 2 1 - 2 - 1 1 - 1 1 0 1 - 1 1 0 0 0 - 1 0 0 - 2 - 1 0 0 0 0 0 0 0 - 2 1 0 0 0 0 - 3 0 0 0 - 1 0 0 0 0 0 0 0 0 0 - 1 0 0 0 0 0 0 0 0 0]
//[-1 1 - 1 - 2 1 0 2 - 2 0 0 0 1 1 1 0 3 0 - 1 - 1 0 2 0 - 1 1 1 1 - 2 1 0 0 0 - 2 1 - 1 0 3 0 - 2 0 - 3 - 2 1 2 1 1 1 - 1 - 1 2 3 0 0 - 1 1 2 1 0 - 2 - 2 - 1 - 2 1 1 1 - 1 2 1 - 2 - 1 1 - 1 1 0 1 - 1 1 0 0 0 - 1 0 0 - 2 - 1 0 0 0 0 0 0 0 - 2 1 0 0 0 0 - 3 0 0 0 - 1 0 0 0 0 0 0 0 0 0 - 1 0 0 0 0 0 0 0 0 0]
//[-1 1 - 1 - 2 1 0 2 - 2 0 0 0 1 1 1 0 3 0 - 1 - 1 0 2 0 - 1 1 1 1 - 2 1 0 0 0 - 2 1 - 1 0 3 0 - 2 0 - 3 - 2 1 2 1 1 1 - 1 - 1 2 3 0 0 - 1 1 2 1 0 - 2 - 2 - 1 - 2 1 1 1 - 1 2 1 - 2 - 1 1 - 1 1 0 1 - 1 1 0 0 0 - 1 0 0 - 2 - 1 0 0 0 0 0 0 0 - 2 1 0 0 0 0 - 3 0 0 0 - 1 0 0 0 0 0 0 0 0 0 - 1 0 0 0 0 0 0 0 0 0]
//[-1 2 - 1 0 1 1 0 - 1 1 0 1 0 3 2 - 2 0 0 - 1 2 0 1 1 0 - 1 0 1 - 1 - 4 1 - 1 0 - 1 1 - 3 1 - 1 0 - 1 0 - 1 - 1 4 0 - 1 1 1 - 1 - 2 0 2 0 0 2 1 0 - 1 - 3 - 1 2 - 1 0 0 0 - 1 - 1 3 1 1 0 0 1 0 0 1 0 0 0 1 0 - 1 0 0 1 0 0 0 0 0 - 1 0 0 0 0 3 1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0]
//[1 1 2 2 1 1 0 0 1 - 3 0 4 - 1 3 0 - 2 - 1 2 0 - 1 1 1 - 2 1 1 - 2 - 1 2 - 2 - 3 0 4 0 0 - 1 - 1 2 0 2 0 3 0 - 2 - 2 1 1 1 1 - 3 4 - 1 0 - 1 - 1 - 1 1 0 - 1 1 0 1 - 1 - 1 - 1 0 2 0 0 - 1 - 2 0 1 2 0 0 0 0 1 1 - 1 0 0 0 0 1 0 0 0 - 1 0 0 0 0 0 0 0 0 - 1 0 0 0 0 0 0 0 0 0 0 0 0 0 - 2 0 0 0 0 0 0 0 0 0]
//[-1 1 - 1 - 2 1 0 2 - 2 0 0 0 1 1 1 0 3 0 - 1 - 1 0 2 0 - 1 1 1 1 - 2 1 0 0 0 - 2 1 - 1 0 3 0 - 2 0 - 3 - 2 1 2 1 1 1 - 1 - 1 2 3 0 0 - 1 1 2 1 0 - 2 - 2 - 1 - 2 1 1 1 - 1 2 1 - 2 - 1 1 - 1 1 0 1 - 1 1 0 0 0 - 1 0 0 - 2 - 1 0 0 0 0 0 0 0 - 2 1 0 0 0 0 - 3 0 0 0 - 1 0 0 0 0 0 0 0 0 0 - 1 0 0 0 0 0 0 0 0 0]

//10 0000 0000  BKZ_FP(B, 0.99, 30, 10);
//[1 - 2 - 1 0 - 2 - 1 0 1 - 2 2 0 0 - 2 - 1 1 0 1 1 1 1 0 - 1 2 0 1 1 - 1 1 0 - 1 1 0 0 1 0 - 1 0 1 1 1 2 1 1 2 0 0 - 1 0 - 1 - 2 0 0 1 1 0 0 0 1 0 - 1 0 0 0 0 - 1 2 - 1 1 - 2 - 1 3 0 1 - 1 - 1 - 1 2 1 - 1 1 0 0 - 1 - 1 1 0 0 0 0 0 0 - 1 1 1 0 - 1 - 3 0 0 0 0 0 0 0 - 1 - 1 2 2 0 0 0 2 0 - 1 0 - 1 0 0 0 - 1 0]


