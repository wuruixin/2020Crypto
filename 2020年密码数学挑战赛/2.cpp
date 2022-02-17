#include<iostream>
#include<fstream>
#include <NTL/ZZ.h>
#include <NTL/vec_ZZ.h>
#include <NTL/mat_ZZ.h>
#include <NTL/LLL.h>
NTL_CLIENT
//背包问题->svp格上最短向量问题->LLL算法进行格基规约后，取其最短向量

void main() {
	//创建变量
	ZZ a[60], b[60], c[60], x1[50000], x2[50000], sum;
	sum = to_ZZ("133588376232103627614352");
	//cout << sum << endl;
	char x[10];
	int num1 = 0, num2 = 0;
	int n1, n2, n3, n4, n5;
	int z1, z2, z3, z4, z5;
	//读取文件到数组中
	ifstream fin("input60.txt");
	for (int i = 0; i < 10; i++) {
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> a[i];
	}
	for (int i = 10; i < 60; i++) {
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> a[i];
	}
	//读取数组到矩阵B[]中
	mat_ZZ B;
	cout << B << endl;
	B.SetDims(61, 61);
	cout << B << endl;
	for (int i = 0; i < 60; i++) {
		B[i][i] = 1;
		B[i][60] = 10000*a[i];
	}
	for (int i = 0; i < 60; i++) {
		B[60][i] = 0.5;
	}
	B[60][60] = 10000*sum;

	//将这个矩阵进行LLL规约

	cout << B << endl;
	BKZ_QP(B);
	cout << B << "\n";
	/*
	B[60][60] = 0;
	for (int i = 0; i < 60; i++) {
		B[60][60] += a[i];
	}
	B[60][60] - sum;

	cout << B << endl;
	LLL_QP(B);
	cout << B << "\n";*/
	//验证
	ZZ n;
	for (int i = 0; i < 60; i++) {
		n = 0;
		for (int j = 0; j < 60; j++) {
			n = n + B[i][j] * a[j];
		}
		n = n - sum;
		cout << i << ' ' << n << endl;
		if (n == 0) {
			cout << B[i] << "\n";
		}
	}
	cout << B[0] << "\n";
}