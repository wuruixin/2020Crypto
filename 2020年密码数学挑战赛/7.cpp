#include<iostream>
#include<fstream>
#include <NTL/ZZ.h>
#include <NTL/vec_ZZ.h>
#include <NTL/mat_ZZ.h>
#include <NTL/LLL.h>
NTL_CLIENT
//��������->svp���������������->LLL�㷨���и����Լ��ȡ���������

int main() {
    //��������
    ZZ a[161], b[160], c[160], x1[50000], x2[50000], sum;
    sum = to_ZZ("17296503075579279351567257704798756537293794806478152345509691");
    char x[10];
    ifstream fin("input160.txt");
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
    for (int i = 100; i < 160; i++) {
        fin >> x[0];
        fin >> x[0];
        fin >> x[0];
        fin >> x[0];
        fin >> x[0];
        fin >> a[i];
    }
    fin.close();

    //��ȡ���鵽����B[]��
    mat_ZZ B;
    cout << B << endl;
    B.SetDims(161, 161);
    cout << B << endl;
    for (int i = 0; i < 160; i++) {
        B[i][i] = 1;
        B[i][160] = 0 - 1000000 * a[i];
    }
    B[160][160] = 1000000 * sum;

    //������������LLL��Լ

    cout << B << endl;
    BKZ_FP(B);
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
    //��֤
    ZZ n;
    for (int i = 0; i < 160; i++) {
        n = 0;
        for (int j = 0; j < 160; j++) {
            n = n + B[i][j] * a[j];
        }
        n = n - sum;
        cout << i << ' ' << n << endl;
        if (n == 0) {
            cout << B[i] << "\n";
        }
    }
    cout << B[0] << "\n";

    return 0;
}