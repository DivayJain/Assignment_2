//student_id 1024030294
//Assingment 2 Q3a submitted

#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n)
{
    // Array size is n-1
    for (int i = 0; i < n - 1; i++)
    {
        // In a perfect array arr[i] should be i+1
        if (arr[i] != i + 1)
        {
            return i + 1;   // Missing number found
        }
    }

    // If no mismatch inside loop, missing number is n
    return n;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[100]; // assuming max size 100

    cout << "Enter " << n-1 << " sorted elements: ";
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    int missing = findMissingLinear(arr, n);
    cout << "Missing Number = " << missing;

    return 0;
}
