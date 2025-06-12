#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    float findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        float n=nums1.size()%2;
        if(n!=0){
            return nums1[(nums1.size()*1/2)];
        }
        else{
            return float(nums1[(nums1.size()*1/2)]+nums1[(nums1.size()*1/2)-1])/2;
        }
    }
};