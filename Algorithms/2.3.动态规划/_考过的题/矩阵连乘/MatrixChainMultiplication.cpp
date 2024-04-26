#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int A[N];
int m[N][N], s[N][N];

void matrixChain(int n) {
    int r, i, j, k;
    for (i = 0; i <= n;i++)
        m[i][i] = 0;
    for (r = 2; r <= n;r++) {
        for (i = 1; i < n - r; i++)
        {
            j = i + r - 1;
            m[i][j] = m[i][i] + m[i + 1][j] + A[i - 1] * A[i] * A[j];
            s[i][j] = i;
            for (k = i + 1; k < j; k++)
            {
                int t = m[i][k] + m[k + 1][j] + A[i - 1] * A[k] * A[j];
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }

    }
}

void traceback(int i, int j) {
    if (i == j)
        return;
    traceback(i, s[i][j]);
    traceback(s[i][j] + 1, j);
    cout << "Multiply A" << i << "," << s[i][j] << "and A" << s[i][j] + 1 << "," << j << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n;i++)
        cin >> A[i];
    matrixChain(n);
    traceback(1, n);
    return 0;
}