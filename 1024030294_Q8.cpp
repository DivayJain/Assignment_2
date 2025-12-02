//student_id 1024030294
//Assingment 2 Q8 submitted

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[100];   // assuming max 100
    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    int distinctCount = 0;

    for(int i = 0; i < n; i++) {
        bool found = false;

        // Check if A[i] appeared before
        for(int j = 0; j < i; j++) {
            if(A[i] == A[j]) {
                found = true;
                break;
            }
        }

        // If not found before → it is distinct
        if(!found)
            distinctCount++;
    }

    cout << "Total distinct elements = " << distinctCount;

    return 0;
}
