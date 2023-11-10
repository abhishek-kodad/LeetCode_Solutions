class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        
        for(int i=0;i<strs.size();i++){
            string key(26,'0');
            for(auto c: strs[i]){
                key[c-'a']++;
            }
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};