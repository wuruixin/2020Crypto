#include<iostream>
#include<fstream>
#include <NTL/ZZ.h>
#include <NTL/vec_ZZ.h>
#include <NTL/mat_ZZ.h>
#include <NTL/LLL.h>
NTL_CLIENT
//背包问题->svp格上最短向量问题->LLL算法进行格基规约后，取其最短向量

int main() {
    //创建变量
    ZZ a[181], b[180], c[180], x1[50000], x2[50000], sum;
    sum = to_ZZ("757680399933334153634722410993690867586002859113929552263090603594409");
    char x[10];
    ifstream fin("input180.txt");
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
    for (int i = 100; i < 180; i++) {
        fin >> x[0];
        fin >> x[0];
        fin >> x[0];
        fin >> x[0];
        fin >> x[0];
        fin >> a[i];
    }
    fin.close();

    //读取数组到矩阵B[]中
    mat_ZZ B;
    cout << B << endl;
    B.SetDims(181, 181);
    cout << B << endl;
    for (int i = 0; i < 180; i++) {
        B[i][i] = 1;
        B[i][180] = 0 - 1000000 * a[i];
    }
    B[180][180] = 1000000 * sum;

    //将这个矩阵进行LLL规约

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
    //验证
    ZZ n;
    for (int i = 0; i < 180; i++) {
        n = 0;
        for (int j = 0; j < 180; j++) {
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