#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int size_of_pattern_side;
    
    // Get no_of_rows and no_of_cols as input
    cin >> size_of_pattern_side;
    
    // Output the pattern
    for(int idx=0; idx < size_of_pattern_side; idx++){
        for(int idx=0; idx < size_of_pattern_side; idx++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}

/*

Output -
5
*****
*****
*****
*****
*****

*/
