#include<iostream>
#include<vector>
#include<bits/stdc++.h> 
#include<unordered_set>
using namespace std;
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> good(words.begin(), words.end());
        for (const string& word: words) {
            for (int k = 1; k < word.size(); ++k) {
                good.erase(word.substr(k));
            }
        }

        int ans = 0;
        for (const string& word: good) {
            ans += word.size() + 1;
        }
        return ans;
    }
    Solution(){}
};
int main()
{
	Solution a;
	vector t;
	t.push_back("time");
	t.push_back("me");
	t.push_back("bell"); 
	int r=a.minimumLengthEncoding(t);
	cout<<r<<endl;
}
