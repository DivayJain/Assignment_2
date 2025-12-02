//student_id 1024030294
//Assingment 2 Q4 submitted

#include <iostream>
using namespace std;
void swap(int &a, int &b){
  int temp;
  temp=a;
  a=b;
  b=temp;
}
int main() {
    arr = {0, 1, 2, 0, 1, 2, 1, 0};
    int low = 0, mid = 0, high = 7;
    while (mid <= high) {
        if (arr[mid] == 0) swap(arr[low++], arr[mid++]);
        else if (arr[mid] == 1) mid++;
        else swap(arr[mid], arr[high--]);
    }
    for (int x=0;x<7;x++) cout << x << " ";
}
