#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    vector<int> count(maxVal + 1, 0);

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    vector<int> sorted(n);

    for (int i = n - 1; i >= 0; i--) {
        sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    cout << "\nSorted Array:\n";
    for (int i = 0; i < n; i++)
        cout << sorted[i] << " ";

    cout << endl;
    return 0;
}
