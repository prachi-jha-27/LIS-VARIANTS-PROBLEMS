# Longest Subsequence with AND > 0

## 🔍 Observation
If the bitwise AND of a subsequence is greater than 0,  
then all numbers in the subsequence must share at least one common set bit.

## 💡 Approach
- Iterate over each bit position (0 to 30)
- Collect all numbers that have the current bit set
- Compute the Longest Increasing Subsequence (LIS) on this subset
- The maximum LIS over all bits is the answer

## 🧠 LIS using Patience Sorting
```cpp
int func(vector<int>& nums) {
    vector<int> temp;
    for (int x : nums) {
        auto it = lower_bound(temp.begin(), temp.end(), x);
        if (it != temp.end()) *it = x;
        else temp.push_back(x);
    }
    return temp.size();
}
