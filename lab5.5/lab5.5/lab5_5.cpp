#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <iostream>

using namespace std;
  
int getLength(long long value) {
    if (value == 0) {
        return 0;
    }
    else {
        return getLength(value / 10) + 1;
    }
}

long long multiply(long long x, long long y) {
    int xLength = getLength(x);
    int yLength = getLength(y);

    // ��������� �� ���� ������
    int N = (int)(fmax(xLength, yLength));

    // ���� ����������� ������� ������ ��������, ������ ������ ����������� ��� �����
    if (N < 10)
        return x * y;


    N = (N / 2) + (N % 2);
    // ���� ��� ��������� ������� ��������
    long long multiplier = pow(10, N);

    long long b = x / multiplier;
    long long a = x - (b * multiplier);
    long long d = y / multiplier;
    long long c = y - (d * multiplier);

    long long d0 = multiply(a, c);
    long long d1 = multiply(a + b, c + d);
    long long d2 = multiply(b, d);

    // ������� �(t)
    return d0 + ((d1 - d0 - d2) * multiplier) + (d2 * (long long)(pow(10, 2 * N)));

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    long long a, b, c, d;

    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "c: "; cin >> c;
    cout << "d: "; cin >> d;

    cout << "r = " << (a * c - b * d) << endl;
    cout << "s = " << (a * d + b * c) << "i" << endl;
}