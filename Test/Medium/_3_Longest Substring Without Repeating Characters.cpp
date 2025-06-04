#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int k=0;
        string t="";
        for(int i=0;i<s.size()-1;i++){
            int o=1;
            t+=s[i];
            for(int j=i+1;j<s.size();j++){
                if(t.find(s[j])==string::npos){
                    t+=s[j];
                    o++;
                    k=max(k,o);
                }
                else{
                    t="";
                    break;
                }
            }
        }
        return k;
    }
};
int main(){
    Solution solution;
    string input = "pwwkew";
    int result = solution.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}