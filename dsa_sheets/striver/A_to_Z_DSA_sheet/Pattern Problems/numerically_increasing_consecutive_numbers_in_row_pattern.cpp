#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int num_of_rows;
    
    cin >> num_of_rows;
    
    for(int row_idx=1; row_idx <= num_of_rows; row_idx++){
        for(int col_idx=1; col_idx <= row_idx; col_idx++){
            cout << col_idx;
        }
        cout << endl;
    }

    return 0;
}

/*

Output -
5
1
12
123
1234
12345

*/

