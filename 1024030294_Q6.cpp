//student_id 1024030294
//Assingment 2 Q6 submitted

#include <iostream>
using namespace std;

// Max non-zero elements (for simplicity)
#define MAX 100

// Structure of a triplet sparse matrix
struct Sparse {
    int data[MAX][3];  // row, col, value
    int n;             // number of non-zero elements
};

/* ===================== INPUT SPARSE MATRIX ===================== */
void inputSparse(Sparse &s) {
    int rows, cols, value;
    cout << "Enter total rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter number of non-zero elements: ";
    cin >> s.n;

    // Store metadata
    s.data[0][0] = rows;
    s.data[0][1] = cols;
    s.data[0][2] = s.n;

    cout << "Enter row, col, value of non-zero elements:\n";
    for (int i = 1; i <= s.n; i++) {
        cin >> s.data[i][0] >> s.data[i][1] >> s.data[i][2];
    }
}

/* ===================== DISPLAY SPARSE MATRIX ===================== */
void display(Sparse s) {
    cout << "Row  Col  Val\n";
    for (int i = 0; i <= s.n; i++) {
        cout << s.data[i][0] << "   " << s.data[i][1] << "   " << s.data[i][2] << endl;
    }
}

/* ===================== TRANSPOSE ===================== */
Sparse transpose(Sparse s) {
    Sparse t;
    int k = 1;

    t.data[0][0] = s.data[0][1];
    t.data[0][1] = s.data[0][0];
    t.data[0][2] = s.data[0][2];
    t.n = s.n;

    for (int col = 0; col < s.data[0][1]; col++) {
        for (int i = 1; i <= s.n; i++) {
            if (s.data[i][1] == col) {
                t.data[k][0] = s.data[i][1];
                t.data[k][1] = s.data[i][0];
                t.data[k][2] = s.data[i][2];
                k++;
            }
        }
    }
    return t;
}

/* ===================== ADDITION ===================== */
Sparse add(Sparse a, Sparse b) {
    Sparse c;
    int i = 1, j = 1, k = 1;

    if (a.data[0][0] != b.data[0][0] || a.data[0][1] != b.data[0][1]) {
        c.data[0][2] = -1; // indicate invalid
        return c;
    }

    c.data[0][0] = a.data[0][0];
    c.data[0][1] = a.data[0][1];

    while (i <= a.n && j <= b.n) {
        if (a.data[i][0] < b.data[j][0]) {
            c.data[k][0] = a.data[i][0];
            c.data[k][1] = a.data[i][1];
            c.data[k][2] = a.data[i][2];
            i++;  k++;
        }
        else if (a.data[i][0] > b.data[j][0]) {
            c.data[k][0] = b.data[j][0];
            c.data[k][1] = b.data[j][1];
            c.data[k][2] = b.data[j][2];
            j++;  k++;
        }
        else {
            // same row → compare column
            if (a.data[i][1] < b.data[j][1]) {
                c.data[k][0] = a.data[i][0];
                c.data[k][1] = a.data[i][1];
                c.data[k][2] = a.data[i][2];
                i++; k++;
            }
            else if (a.data[i][1] > b.data[j][1]) {
                c.data[k][0] = b.data[j][0];
                c.data[k][1] = b.data[j][1];
                c.data[k][2] = b.data[j][2];
                j++; k++;
            }
            else {
                // same position → add values
                int sum = a.data[i][2] + b.data[j][2];
                if (sum != 0) {
                    c.data[k][0] = a.data[i][0];
                    c.data[k][1] = a.data[i][1];
                    c.data[k][2] = sum;
                    k++;
                }
                i++; j++;
            }
        }
    }

    // copy remaining elements
    while (i <= a.n) {
        c.data[k][0] = a.data[i][0];
        c.data[k][1] = a.data[i][1];
        c.data[k][2] = a.data[i][2];
        i++; k++;
    }

    while (j <= b.n) {
        c.data[k][0] = b.data[j][0];
        c.data[k][1] = b.data[j][1];
        c.data[k][2] = b.data[j][2];
        j++; k++;
    }

    c.n = k - 1;
    c.data[0][2] = c.n;

    return c;
}

/* ===================== MULTIPLICATION ===================== */
Sparse multiply(Sparse a, Sparse b) {
    Sparse c;

    if (a.data[0][1] != b.data[0][0]) {
        c.data[0][2] = -1; // invalid
        return c;
    }

    // Transpose b to easily match columns
    Sparse bt = transpose(b);

    c.data[0][0] = a.data[0][0];
    c.data[0][1] = b.data[0][1];
    c.n = 0;
    int k = 1;

    for (int i = 1; i <= a.n; i++) {
        for (int j = 1; j <= bt.n; j++) {
            if (a.data[i][1] == bt.data[j][1]) {
                int row = a.data[i][0];
                int col = bt.data[j][0];
                int val = a.data[i][2] * bt.data[j][2];

                // check if this c[row][col] already exists
                int found = 0;
                for (int x = 1; x <= c.n; x++) {
                    if (c.data[x][0] == row && c.data[x][1] == col) {
                        c.data[x][2] += val;
                        found = 1;
                        break;
                    }
                }

                if (!found && val != 0) {
                    c.data[k][0] = row;
                    c.data[k][1] = col;
                    c.data[k][2] = val;
                    k++;
                    c.n++;
                }
            }
        }
    }

    c.data[0][2] = c.n;

    return c;
}

/* ===================== MAIN MENU ===================== */
int main() {
    Sparse A, B, C;
    int choice;

    do {
        cout << "\n==== SPARSE MATRIX MENU ====\n";
        cout << "1. Transpose\n";
        cout << "2. Addition\n";
        cout << "3. Multiplication\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            inputSparse(A);
            C = transpose(A);
            cout << "\nTranspose Matrix:\n";
            display(C);
        }

        else if (choice == 2) {
            cout << "Enter Matrix A:\n";
            inputSparse(A);
            cout << "Enter Matrix B:\n";
            inputSparse(B);

            C = add(A, B);

            if (C.data[0][2] == -1)
                cout << "Error: Matrices must have same dimensions.\n";
            else {
                cout << "\nResult of Addition:\n";
                display(C);
            }
        }

        else if (choice == 3) {
            cout << "Enter Matrix A:\n";
            inputSparse(A);
            cout << "Enter Matrix B:\n";
            inputSparse(B);

            C = multiply(A, B);

            if (C.data[0][2] == -1)
                cout << "Error: Column of A must equal row of B.\n";
            else {
                cout << "\nResult of Multiplication:\n";
                display(C);
            }
        }

    } while (choice != 4);

    return 0;
}
