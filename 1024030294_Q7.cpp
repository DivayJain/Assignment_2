//student_id 1024030294
//Assingment 2 Q7 submitted

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[100];   // assuming max size 100 for simplicity

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    int invCount = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(A[i] > A[j]) {
                invCount++;
            }
        }
    }

    cout << "Total Inversions = " << invCount;

    return 0;
}
