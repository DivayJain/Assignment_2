//student_id 1024030294
//Assingment 2 Q1 submitted

#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int k = 2, n = sizeof(arr) / sizeof(arr[0]), count = 0;
    int i = 0, j = 1;
    while (j < n) {
        int diff = arr[j] - arr[i];
        if (diff == k) {
            count++;
            i++; j++;
        } 
        else if (diff > k) i++;
        else j++;
        if (i == j) j++;
    }
    cout << count;
return 0;
}
