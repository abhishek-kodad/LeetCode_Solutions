class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> pq{0};
        vector<pair<int,int>> points;
        
        for(auto b: buildings){
            points.push_back({b[0],-b[2]});
            points.push_back({b[1],b[2]});
        }
        
        sort(points.begin(),points.end());
        int ongoingheight = 0;
        for(int i=0;i<points.size();i++){
            int cp = points[i].first;
            int hap = points[i].second;
            if(hap<0){
                pq.insert(-hap);
            }
            else{
                pq.erase(pq.find(hap));
            }
            auto pqTop = *pq.rbegin();
            if(ongoingheight != pqTop){
                ongoingheight = pqTop;
                ans.push_back({cp,ongoingheight});
            }
        }
        return ans;
    }
};