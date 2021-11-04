#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void create(int* a, const int n, const int l, const int h);
void max(int* a, int n, int& i_max, int& a_max, int i);
void min(int* a, int n, int& i_min, int& a_min, int i);
int sum(int a, int b);


int main() {
    srand((unsigned)time(NULL));

    const int n = 15;
    int a[n];

    int h = 20;
    int l = -20;
    int s;

    create(a, n, l, h);

    int a_max = a[0];
    int i_max = 0;

    int a_min = a[0];
    int i_min = 0;



    max(a, n, i_max, a_max, 0);
    min(a, n, i_min, a_min, 0);

    s = sum(i_max, i_min);

    for (int i = 0; i < n; i++) {
        cout << setw(3) << a[i] << " ";
    }
    cout << endl;

    cout << "a_max = " << setw(4) << a_max << "       " << "i_max = " << i_max << endl
        << "a_min = " << setw(4) << a_min << "       " << "i_min = " << i_min << endl
        << "sum = " << s;

    return 0;
}

void create(int* a, const int n, const int l, const int h)
{
    for (int i = 0; i < n; i++)
        a[i] = l + rand() % (h - l + 1);
}

void max(int* a, int n, int& i_max, int& a_max, int i) {
    if (a[i] > a_max) {
        a_max = a[i];
        i_max = i;
    }
    if (i + 1 < n) {
        max(a, n, i_max, a_max, i + 1);
    }
}

void min(int* a, int n, int& i_min, int& a_min, int i) {
    if (a[i] < a_min) {
        a_min = a[i];
        i_min = i;
    }
    if (i + 1 < n) {
        min(a, n, i_min, a_min, i+1);
    }
}

int sum(int a, int b) {
    return a + b;
}
