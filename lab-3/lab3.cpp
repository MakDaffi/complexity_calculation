#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> T (vector<vector<int>> &a) {
    vector<vector<int>> b (a[0].size(), vector<int> (a.size()));

    for(int i = 0; i < b.size(); ++i) {
        for(int j = 0; j < b[i].size(); ++j) {
            b[i][j] = a[j][i];
        }
    }

    return b;
}

int main(void) {
    setlocale(LC_ALL, "rus");
    int col, row;
    cout << "Введите размерности матрицы: ";
    cin >> col >> row;
    cout << "Введите исходную матрицу:\n";
    vector<vector<int>> a (col, vector<int> (row));

    for(int i = 0; i < col; ++i) {
        for(int j = 0; j < row; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> b = T(a);

    cout << "Транспонированная матрица:\n";
    for(int i = 0; i < b.size(); ++i) {
        for(int j = 0; j < b[i].size(); ++j) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}