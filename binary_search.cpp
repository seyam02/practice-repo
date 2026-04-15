#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {3, 4, 12, 23, 32, 40};
    int n = 6;
    int key = 4;
    
    int low = 0, high = n - 1;
    int mid;
    int found = -1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            found = mid;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (found != -1)
        cout << "Found at index " << found << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
