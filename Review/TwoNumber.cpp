#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
    vector<int> twoSumSort2Pointers(vector<int>& nums, int target){
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

    vector<int> twoSumHashTable(vector<int>& nums, int target){
        unordered_map<int,int> hashTable;
        for(int i=0;i<nums.size();i++){
            int difference = target - nums[i];
            if(hashTable.find(difference)!=hashTable.end()){
                // hashTable.count(difference)>0
                return {hashTable[difference], i};
            }
            hashTable[nums[i]]=i;
        }
        return {};
    }
};


int main(){
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSumSort2Pointers(nums, target);
    if(!result.empty()){
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }else{
        cout << "No two sum solution found." << endl;
    }
    return 0;
}