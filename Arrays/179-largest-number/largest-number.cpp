class Solution {
public:
    static bool mycmp(string a, string b)
    {
        string t1=a+b;
        string t2=b+a;
        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(int i=0; i<nums.size(); i++)
            ans.push_back(to_string(nums[i]));
        sort(ans.begin(), ans.end(), mycmp);
        if(ans[0]=="0")
            return "0";
        string res="";
        for(auto i: ans)
            res+=i;
        return res;
    }
};