#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> result(n, 0);
        int cream = 0;


        for (int i = n - 1; i >= 0; i--) {

            if (a[i] > cream) {
                cream = a[i];
            }

            if (cream > 0) {
                result[i] = 1;
                cream--;
            }
        }


        for (int i = 0; i < n; i++) {
            cout << result[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}