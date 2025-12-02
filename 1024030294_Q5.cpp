//student_id 1024030294
//Assingment 2 Q5 submitted

#include <iostream>
using namespace std;

/* ===================== DIAGONAL MATRIX ===================== */
class Diagonal {
    int *A;
    int n;

public:
    Diagonal(int size) {
        n = size;
        A = new int[n];
        for (int i = 0; i < n; i++) A[i] = 0;
    }

    void setVal(int i, int j, int x) {
        if (i == j)
            A[i-1] = x;
    }

    int getVal(int i, int j) {
        if (i == j)
            return A[i-1];
        return 0;
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    cout << A[i-1] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

/* ===================== TRI-DIAGONAL MATRIX ===================== */
class TriDiagonal {
    int *A;
    int n;

public:
    TriDiagonal(int size) {
        n = size;
        A = new int[3*n - 2];
        for (int i = 0; i < 3*n-2; i++) A[i] = 0;
    }

    void setVal(int i, int j, int x) {
        if (i - j == 1)
            A[i-2] = x;
        else if (i == j)
            A[(n-1) + (i-1)] = x;
        else if (j - i == 1)
            A[(2*n-1) + (i-1)] = x;
    }

    int getVal(int i, int j) {
        if (i - j == 1)
            return A[i-2];
        else if (i == j)
            return A[(n-1) + (i-1)];
        else if (j - i == 1)
            return A[(2*n-1) + (i-1)];
        return 0;
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << getVal(i, j) << " ";
            }
            cout << endl;
        }
    }
};

/* ===================== LOWER TRIANGULAR MATRIX ===================== */
class LowerTriangular {
    int *A;
    int n;

public:
    LowerTriangular(int size) {
        n = size;
        A = new int[n*(n+1)/2];
    }

    void setVal(int i, int j, int x) {
        if (i >= j) {
            int index = (i*(i-1))/2 + (j-1);
            A[index] = x;
        }
    }

    int getVal(int i, int j) {
        if (i >= j) {
            int index = (i*(i-1))/2 + (j-1);
            return A[index];
        }
        return 0;
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << getVal(i, j) << " ";
            }
            cout << endl;
        }
    }
};

/* ===================== UPPER TRIANGULAR MATRIX ===================== */
class UpperTriangular {
    int *A;
    int n;

public:
    UpperTriangular(int size) {
        n = size;
        A = new int[n*(n+1)/2];
    }

    void setVal(int i, int j, int x) {
        if (i <= j) {
            int index = (i-1)*n - (i-1)*(i-2)/2 + (j-i);
            A[index] = x;
        }
    }

    int getVal(int i, int j) {
        if (i <= j) {
            int index = (i-1)*n - (i-1)*(i-2)/2 + (j-i);
            return A[index];
        }
        return 0;
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << getVal(i, j) << " ";
            }
            cout << endl;
        }
    }
};

/* ===================== SYMMETRIC MATRIX ===================== */
class Symmetric {
    int *A;
    int n;

public:
    Symmetric(int size) {
        n = size;
        A = new int[n*(n+1)/2];
    }

    void setVal(int i, int j, int x) {
        if (i >= j) {
            int index = (i*(i-1))/2 + (j-1);
            A[index] = x;
        }
        else {
            int index = (j*(j-1))/2 + (i-1);
            A[index] = x;
        }
    }

    int getVal(int i, int j) {
        if (i >= j) {
            int index = (i*(i-1))/2 + (j-1);
            return A[index];
        }
        else {
            int index = (j*(j-1))/2 + (i-1);
            return A[index];
        }
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << getVal(i, j) << " ";
            }
            cout << endl;
        }
    }
};

/* ===================== MAIN MENU ===================== */
int main() {
    int choice, n;

    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    do {
        cout << "\n===== MATRIX MENU =====\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tri-Diagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Diagonal d(n);
            int x;
            cout << "Enter elements:\n";
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cin >> x;
                    d.setVal(i, j, x);
                }
            }
            cout << "\nDiagonal Matrix:\n";
            d.display();
        }

        else if (choice == 2) {
            TriDiagonal t(n);
            int x;
            cout << "Enter elements:\n";
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cin >> x;
                    t.setVal(i, j, x);
                }
            }
            cout << "\nTri-Diagonal Matrix:\n";
            t.display();
        }

        else if (choice == 3) {
            LowerTriangular l(n);
            int x;
            cout << "Enter elements:\n";
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cin >> x;
                    l.setVal(i, j, x);
                }
            }
            cout << "\nLower Triangular Matrix:\n";
            l.display();
        }

        else if (choice == 4) {
            UpperTriangular u(n);
            int x;
            cout << "Enter elements:\n";
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cin >> x;
                    u.setVal(i, j, x);
                }
            }
            cout << "\nUpper Triangular Matrix:\n";
            u.display();
        }

        else if (choice == 5) {
            Symmetric s(n);
            int x;
            cout << "Enter elements:\n";
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cin >> x;
                    s.setVal(i, j, x);
                }
            }
            cout << "\nSymmetric Matrix:\n";
            s.display();
        }

    } while (choice != 6);

    return 0;
}
