#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<string>> Hamilton(vector<vector<string>> *B, vector<vector<int>> matrix);

vector<vector<string>> P_1(vector<vector<int>> matrix);

vector<vector<int>> read_from_file(string path);

vector<vector<string>> matrix_of_string(vector<vector<int>> matrix);

vector<vector<string>> normalize(vector<vector<string>> &P);


vector<vector<string>> Hamilton(vector<vector<string>> *B, vector<vector<int>> matrix) {
    vector<vector<string>> P;
    for (int i = 0; i < 4; ++i) {

    }
    return P;
}


vector<vector<string>> P_1(vector<vector<string>> B, vector<vector<int>> matrix) {
    vector<vector<string>> P;
    for (int i = 0; i < 4; ++i) {
        vector<string> P0;
        for (int j = 0; j < 4; ++j) {
            P0.push_back("");
        }
        P.push_back(P0);
    }
    for (int i = 0; i < 4; i++) {             //умножение матриц А и (В - Е)
        for (int j = 0; j < 4; j++) {
            for (int t = 0; t < 4; t++) {
                if (B[i][t] != "0" && matrix[t][j] != 0) {
                    if (P[i][j] != "") {
                        P[i][j] += "+";
                    }
                    P[i][j] += B[i][t];
                }
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (P[i][j] == "") P[i][j] = "0";
        }
    }
    P = normalize(P);
    return P;
}


vector<vector<int>> read_from_file(string path) {
    vector<vector<int>> matrix;
    fstream fin;
    fin.open(path, ios::in);
    string s;
    while (getline(fin, s)) {
        //str[i] - 0x30
        vector<int> vect;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ' ') {
                vect.push_back(s[i] - 0x30);
            }
        }
        matrix.push_back(vect);
    }
    return matrix;
}


vector<vector<string>> normalize(vector<vector<string>> &P) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == j) {
                P[i][j] = "0";
            }
            string str_for_normalize = P[i][j];
            char ch_2(97 + j);
            char ch_1(97 + i);
            if (str_for_normalize.find(ch_1) != string::npos || str_for_normalize.find(ch_2) != string::npos) {
                P[i][j] = "0";
            }
        }
    }
    return P;
}

vector<vector<string>> matrix_of_string(vector<vector<int>> matrix) {
    vector<vector<string>> cicle;
    for (int i = 0; i < 4; ++i) {
        vector<string> row;
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j] == 1) {
                char ch(97 + j);
                row.push_back({ch});
            } else {
                row.push_back("0");
            }
        }
        cicle.push_back(row);
    }
    return cicle;
}


int main() {
    vector<vector<int>> b;
    b = read_from_file("D://reps//path.txt");
    vector<vector<string>> circle = matrix_of_string(b);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << b[i][j] << "\t";
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << circle[i][j] << "\t";
        }
        printf("\n");
    }
    printf("\n");
    circle = P_1(circle, b);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << circle[i][j] << "\t";
        }
        printf("\n");
    }
    return 0;
}
