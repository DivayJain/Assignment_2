//student_id 1024030294
//Assingment 2 Q3b submitted

#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n)
{
    int low = 0;
    int high = n - 2; // last index of array of size n-1

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // If element matches expected value
        if (arr[mid] == mid + 1)
        {
            // missing number is on right side
            low = mid + 1;
        }
        else
        {
            // missing number is on left side
            high = mid - 1;
        }
    }

    // low becomes the index of the missing number
    return low + 1;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[100];

    cout << "Enter " << n-1 << " sorted elements: ";
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    int missing = findMissingBinary(arr, n);
    cout << "Missing Number = " << missing;

    return 0;
}
