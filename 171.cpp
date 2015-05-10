class Solution {
public:
    int titleToNumber(string s)
    {
        int size = s.size();
        int ans = 0;
        if(size == 0)ans;
        for(int i = 0; i < size; i++)
        {
            ans += (s[i] - 'A' + 1) * pow(26.0, size - i - 1);            
        }
        return ans;
    }
};