//student_id 1024030294
//Assingment 2 Q2 submitted

#include <iostream>
using namespace std;

int main() {
    string s; 
    cin >> s;
    int n = s.size(), ok = 0;

    for (int len = 1; len < n; len++) {
        string sub = s.substr(0, len);

        for (int i = 1; i + len <= n; i++) {
            if (s.substr(i, len) == sub) {
                ok = 1;
                break;
            }
        }

        if (ok) break;
    }

    cout << (ok ? "YES" : "NO");
}
