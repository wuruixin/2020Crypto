#include<iostream>
#include<fstream>
#include <NTL/ZZ.h>
#include <NTL/vec_ZZ.h>
#include <NTL/mat_ZZ.h>
#include <NTL/LLL.h>
NTL_CLIENT

//��������->svp���������������->LLL�㷨���и����Լ��ȡ���������

void main() {
	//��������
	ZZ a[40], b[40], c[40], x1[50000], x2[50000], sum,det2;
	sum = to_ZZ("2038015735279982");
	//cout << sum << endl;
	char x[10];
	int num1 = 0, num2 = 0;
	int n1, n2, n3, n4, n5;
	int z1, z2, z3, z4, z5;
	//��ȡ�ļ���������
	ifstream fin("input40.txt");
	for (int i = 0; i < 10; i++) {
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> a[i];
	}
	for (int i = 10; i < 40; i++) {
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> a[i];
	}
	//��ȡ���鵽����B[]��
	mat_ZZ B;
	cout << B << endl;
	B.SetDims(41, 41);
	cout << B << endl;
	for (int i = 0; i < 40; i++) {
		B[i][i] = 1;
		B[i][40] = 0-10000*a[i];
	}
	B[40][40] = 10000*sum;

	//������������LLL��Լ

	cout << B << endl;
	BKZ_FP(B);
	cout << B << "\n";

	//��֤
	ZZ n;
	for (int i = 0; i < 40; i++) {
		n = 0;
		for (int j = 0; j < 40; j++) {
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