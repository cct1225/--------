#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Adjust the size of the vector of bitsets based on the number of people
    vector<bitset<2500>> v(n);

    // Read the list of friends for each person
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int friendid;
            cin >> friendid;
            v[i].set(friendid - 1);  // Set the bit corresponding to the friend ID
        }
    }

    int cnt = 0; // Initialize the count of mutual friends
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((v[i] & v[j]).any()) { // Check if there are any mutual friends
                cnt++;
            }
        }
    }

    cout << cnt << endl; // Output the count of mutual friends
    return 0;
}
