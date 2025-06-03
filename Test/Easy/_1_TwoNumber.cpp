#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {}; // Trả về vector rỗng nếu không tìm thấy
    }

    vector<int> twoSumChatBot(vector<int>& nums, int target) {
        unordered_map<int,int> unorderedMap;
        for(int i=0;i<nums.size();i++){
            int difference = target - nums[i];
            // Kiểm tra xem difference đã có trong unorderedMap chưa
            if(unorderedMap.find(difference)!=unorderedMap.end()){
                // Nếu có, trả về chỉ số của difference và chỉ số hiện tại
                return {unorderedMap[difference], i};
            }
            // Nums[i] là giá trị của i trong mảng được đưa vào băm làm key, i là chỉ số trong mảng 1 chiều
            unorderedMap[nums[i]] = i;
        }
        return {}; 
    }
    // Thiếu phương pháp Sort và 2 con trỏ
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> indexNums;
            for(int i=0;i<nums.size();i++){
                indexNums.push_back({nums[i], i});
            }
            sort(indexNums.begin(),indexNums.end());
            int left = 0, right = indexNums.size()-1;
            while(left<right){
                if(indexNums[left].first+indexNums[right].first==target){
                    return {indexNums[left].second,indexNums[right].second};
                }
                else if(indexNums[left].first+indexNums[right].first<target){
                    left++;
                }
                else{
                    right--;
                }
            } 
            return {};
        }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    if(!result.empty()){
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }else{
        cout << "No two sum solution found." << endl;
    }
    return 0;
}