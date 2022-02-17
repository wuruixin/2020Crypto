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
	ZZ a[140], b[100], sum;
	sum = to_ZZ("355790296288503583646169352003925718345053247793");
	//cout << sum << endl;
	char x[10];
	//读取文件到数组中
	ifstream fin("input140.txt");
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
	for (int i = 100; i < 140; i++) {
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> x[0];
		fin >> a[i];
	}
	int r[40];
	mat_ZZ B;
	int k;
	B.SetDims(101, 101);
	srand(time(0));
	ZZ n;







	for (int number = 0; number < 50; number++) {

		//构造随机数组
		for (int i = 0; i < 40; i++) {
			r[i] = rand() % 120;
			for (int j = 0; j < i; j++) {
				if (r[i] == r[j]) {
					r[i] = rand() % 120;
					for (int j1 = 0; j1 < i; j1++) {
						if (r[i] == r[j1]) {
							r[i] = rand() % 140;
							for (int j2 = 0; j2 < i; j2++) {
								if (r[i] == r[j2]) {
									r[i] = rand() % 120;
								}
							}
						}
					}
				}
			}
			cout << r[i] << " ";
		}



		cout << endl;
		//创建新数组
		k = 0;
		for (int i = 0; i < 140; i++) {
			int flag = 0;
			for (int j = 0; j < 40; j++) {
				if (i == r[j]) {
					k++; flag = 1;
					break;
				}
			}
			//cout << i << " " << k << " " << i - k << endl;
			if (flag == 0) {
				b[i - k] = a[i];
			}
			else {
				flag = 0;
			}
		}
		for (int i = 0; i < 100; i++) {
			//cout << b[i] << " " << endl;
		}

		//构造数组
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				B[i][j] = 0;
			}
		}
		k = 0;
		for (int i = 0; i < 100; i++) {
			B[i - k][i - k] = 1;
			B[i - k][100] = 0 - 100000 * b[i];
		}
		B[100][100] = 100000 * sum;
		//cout << B << endl;
		BKZ_FP(B, 0.99,30,15);
		//cout << B[0] << endl;



		for (int i = 0; i < 100; i++) {
			n = 0;
			for (int j = 0; j < 100; j++) {
				n = n + B[i][j] * b[j];
			}
			n = n + sum;
			//cout << i << ' ' << n << endl;
			if (n == 0) {
				cout << i << B[i] << "\n";
			}
			n = n -2 * sum;
			if (n == 0) {
				cout << i << B[i] << "\n";
			}
		}
		cout << B[0] << "\n";

















	}
}

