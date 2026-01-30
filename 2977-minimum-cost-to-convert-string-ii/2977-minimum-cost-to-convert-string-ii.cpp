class Solution {
public:

long long f2(int ind, vector<long long>& dp,
             string& src, string& tar,
             unordered_map<int, vector<pair<int,int>>>& checkmp,
             int n) {

    const long long INF = LLONG_MAX;

    if (ind == n) return 0;
    if (dp[ind] != -1) return dp[ind];

    long long ans = INF;

    if (src[ind] == tar[ind]) {
        ans = f2(ind + 1, dp, src, tar, checkmp, n);
    }

    if (checkmp.count(ind)) {
        for (auto &it : checkmp[ind]) {
            int len = it.first;
            int cost = it.second;

            long long nxt = f2(ind + len, dp, src, tar, checkmp, n);
            if (nxt != INF)
                ans = min(ans, cost + nxt);
        }
    }

    return dp[ind] = ans;
}

void f(map<pair<string,string>,int>& paths,map<string,vector<pair<string,int>>>& adj,vector<string>& arr){
            priority_queue<
                pair<int, string>,
                vector<pair<int, string>>,
                greater<pair<int, string>>
            > pq;

            for(auto itre:arr){
                pq.push({0,itre});
                map<string,int> mp;

                while(!pq.empty()){
                    auto it=pq.top();
                    pq.pop();

                    int cost=it.first;
                    string str=it.second;

                    if(mp.find(str)!=mp.end())continue;
                    else{
                        paths[{itre,str}]=cost;
                        mp[str]++;
                    }

                    for(auto itr:adj[str]){
                        pq.push({itr.second+cost,itr.first});
                    }
                }
                mp.clear();
            }

            
    }


    long long minimumCost(string src, string tar, vector<string>& o, vector<string>& c, vector<int>& cost) {

       map<pair<string,string>,int> mp;
        for(int i=0;i<o.size();i++){
            if(mp.find({o[i],c[i]})==mp.end()){
                mp[{o[i],c[i]}]=cost[i];
            }
            else{
                mp[{o[i],c[i]}]=min(mp[{o[i],c[i]}],cost[i]);
            }
        }

        map<string,vector<pair<string,int>>> adj;
        for(auto &[key,val]:mp){
            string str1=key.first;
            string str2=key.second;
            int c=val;
            adj[str1].push_back({str2,c});
        }
       
        map<pair<string,string>,int> paths;
        f(paths,adj,o);


        int n=src.size();
        cout<<n<<endl;
        unordered_set<int> validLen;
        for (auto &it : paths) {
            validLen.insert(it.first.first.size());
        }

       unordered_map<int, vector<pair<int,int>>> checkmp;


        for (int i = 0; i < n; i++) {
            for (int len : validLen) {
                if (i + len > n) continue;

                string s1 = src.substr(i, len);
                string s2 = tar.substr(i, len);

                if (s1 == s2) continue;

                auto it = paths.find({s1, s2});
                if (it != paths.end()) {
                    checkmp[i].push_back({len, it->second});
                }
            }
        }

        vector<long long> dp(n,-1);
        bool flag=false;
        long long val=f2(0,dp,src,tar,checkmp,n);
        if(val==LLONG_MAX)return -1;
        return val;
    }
};