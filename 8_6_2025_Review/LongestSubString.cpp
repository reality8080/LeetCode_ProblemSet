#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int maxLength=0;
        // string s1(1,s[0]);
       	// int left=0,right=left+1;
        // while(true){
        // 	if(s1.find(s[right])==string::npos){
        // 		s1.erase(0,1);
        // 		left++;
        // 		break;
		// 	}
		// 	s1+=s[right];
		// 	right++; 
		// 	maxLength=max(maxLength,(int)s1.size());
        // 	if(left>right){
        // 		return maxLength;
		// 	}
			
		// }

		if(s.size()<2) 
        return s.size();
        int left=0,right=1;
        int maxLength=1;
        string s1="";
        s1+=s[left];
        while(left<=right&&right<s.size()){
            if(s1.find(s[right])!=string::npos){
                s1.erase(0,1);
                left++;
                if(left==right){
                    right++;
				    s1+=s[right];

                } 
            }
            else{
                s1+=s[right];
                right++;                
            }

            maxLength=max(maxLength,int(s1.size()));
        }

        return maxLength;
    }
};

int main(){
    Solution solution;
    string input = "aab";
    int result = solution.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}
