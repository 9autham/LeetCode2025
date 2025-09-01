class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<double,double>>>pq;
        int no_of_class=classes.size();
        for(int i=0;i<no_of_class;i++){
            double pass=classes[i][0];
            double total=classes[i][1];
            double average=(double)(pass/total)-(double)((pass+1)/(total+1));
            pq.push({abs(average),{pass,total}});
        }

        while(extraStudents!=0){
            auto min_average=pq.top();
            pq.pop();//O(logn)
            double pass=min_average.second.first;
            double total=min_average.second.second;
            double new_ration=(double)((pass+1)/(total+1))-(double)(pass+2)/(total+2);
            pq.push({abs(new_ration),{pass+1,total+1}});
            extraStudents--;
        }
        double ans;
        double sum=0;
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            double average=front.second.first/front.second.second;
            sum+=average;
        }
        ans=sum/(double)(no_of_class);
        return ans;
        
    }
};