#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
// Cách một dùng chuỗi string để đánh giá
    int lengthOfLongestSubstring(string s) {
        if(s.size()<1){
            return 0;
        }
        int k=1;
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
// Cách 2 dùng Quy Hoạch Động(Không cần thêm vào readme trừ khi làm lại hay hơn)
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int i=0;
        vector<int> a(s.size(),1);
        while(i<s.size()-1){
            string s1="";
            s1+=s[i];
            int j=i+1;
            while(j<s.size()){
                if(s1.find(s[j])==string::npos){
                a[i]+=a[j];
                s1+=s[j];
                } else {
                    break;
                }
                j++;
            }
            i++;
        }
        sort(a.begin(), a.end());
        return int(a.back());
    }

// Cách 3 dùng 2 con trỏ kết hợp hashmap lưu trữ vị trí cuối cùng.
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int left=0,right=1;
        int maxLength=1;
        string s1="";
        s1+=s[left];
        while(right<s.size()){

            if(s1.find(s[right])==string::npos){
                s1+=s[right];
                maxLength=max(maxLength,right-left+1);
                right++;
            }
            else{
                s1.erase(s1.find(s[left]),1);
                left++;
                if(left==right){
                    right++;
                }
            }
        }
        return maxLength;
    }
};
int main(){
    Solution solution;
    string input = "dvdf";
    int result = solution.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}