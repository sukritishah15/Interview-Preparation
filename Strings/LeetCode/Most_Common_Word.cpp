/*
    819. Most Common Word (EASY)

    Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

    Words in the list of banned words are given in lowercase, and free of punctuation.  
    Words in the paragraph are not case sensitive.  The answer is in lowercase.

    Example:

    Input: 
    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
    banned = ["hit"]
    Output: "ball"
    Explanation: 
    "hit" occurs 3 times, but it is a banned word.
    "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
    Note that words in the paragraph are not case sensitive,
    that punctuation is ignored (even if adjacent to words, such as "ball,"), 
    and that "hit" isn't the answer even though it occurs more because it is banned.
 

    Note:

    1 <= paragraph.length <= 1000.
    0 <= banned.length <= 100.
    1 <= banned[i].length <= 10.
    The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, 
    and even if it is a proper noun.)
    paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
    There are no hyphens or hyphenated words.
    Words only consist of letters, never apostrophes or other punctuation symbols.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        int len = paragraph.length();
        string temp;
        map<string, int> mp;
        for (int i = 0; i < len; i++)
        {
            if ((paragraph[i] >= 65 && paragraph[i] <= 90) || (paragraph[i] >= 97 && paragraph[i] <= 122))
            {
                temp += tolower(paragraph[i]);
            }
            else
            {
                mp[temp]++;
                temp = "";
            }
        }
        if (!temp.empty())
        {
            mp[temp]++;
        }
        string ans;
        int count = INT_MIN;
        for (auto x : mp)
        {
            if (find(banned.begin(), banned.end(), x.first) == banned.end())
            {
                if (x.first != "" && x.second > count)
                {
                    ans = x.first;
                    count = x.second;
                }
            }
        }
        return ans;
    }
};

int main(){
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    vector<string> v;
    string temp;
    while(n--){
        cin >> temp;
        v.push_back(temp);
    }
    Solution obj;
    cout << obj.mostCommonWord(s,v) << endl;
}