class Solution {
public:
    int func(vector<int>& nums) {
        vector<int> temp;
        for (int x : nums) {
            auto it = lower_bound(temp.begin(), temp.end(), x);
            if (it != temp.end()) *it = x;
            else temp.push_back(x);
        }
        return temp.size();
    }

    int longestSubsequence(vector<int>& nums) {
        int mx = 0;
        for (int i = 0; i <= 30; i++) {
            vector<int> temp;
            for (int x : nums) {
                if (x & (1LL << i)) temp.push_back(x);
            }
            if (!temp.empty())
                mx = max(mx, func(temp));
        }
        return mx;
    }
};
