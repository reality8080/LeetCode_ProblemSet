#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numMaps;
        for(int i=0;i<nums.size();i++){
            int substrahend= target - nums[i];
            if(numMaps.count(substrahend)){
                return {numMaps[substrahend], i};
            }
            else{
                numMaps[nums[i]]=i;
            }
        }
        return {};
    }
};