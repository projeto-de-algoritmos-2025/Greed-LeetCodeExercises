#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

class Solution {
private:
    vector<int> maxArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int drops = n - k; 

        for (int num : nums) {
            while (!res.empty() && res.back() < num && drops > 0) {
                res.pop_back();
                drops--;
            }
            res.push_back(num);
        }

        res.resize(k);
        return res;
    }


    bool greater(vector<int>& arr1, int i, vector<int>& arr2, int j) {
        while (i < arr1.size() && j < arr2.size() && arr1[i] == arr2[j]) {
            i++;
            j++;
        }
        return j == arr2.size() || (i < arr1.size() && arr1[i] > arr2[j]);
    }

    vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int i = 0, j = 0;
        int k = arr1.size() + arr2.size();
        
        while (res.size() < k) {
            if (greater(arr1, i, arr2, j)) {
                res.push_back(arr1[i++]);
            } else {
                res.push_back(arr2[j++]);
            }
        }
        return res;
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> bestResult; 
        for (int i = max(0, k - n); i <= min(m, k); ++i) {
            int j = k - i;

            vector<int> arr1 = maxArray(nums1, i);
            vector<int> arr2 = maxArray(nums2, j);
            vector<int> candidate = merge(arr1, arr2);

            if (candidate > bestResult) {
                bestResult = candidate;
            }
        }
        return bestResult;
    }
};



