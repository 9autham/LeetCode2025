class SegTree{
public:
    vector<int> segs;

    SegTree(int n){
        segs.resize(4*n+1);
    }
    
    void build(int ind, int low, int high, vector<int> &arr){
        if(low == high) {
            segs[ind] = low;
            return;
        }

        int mid = (low+high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);

        if(arr[segs[2*ind+1]] >= arr[segs[2*ind+2]]) segs[ind] = segs[2*ind+1];
        else segs[ind] = segs[2*ind+2];
    }

    int query(int ind, int low, int high, int val, vector<int> &arr){
        if(low==high) return arr[segs[ind]] >= val ? segs[ind] : -1;

        int mid = (low+high)/2;
        if(arr[segs[ind]]>=val){
            if(arr[segs[2*ind+1]] >= val) return query(2*ind+1, low, mid, val, arr);
            else return query(2*ind+2, mid+1, high, val, arr);
        }
        return -1; // we couldnt find any basket with capactity >= val
    }

    void update(int ind, int low, int high, vector<int> &arr){
        if(low==high){
            segs[ind] = low;
            return;
        }

        int mid = (low+high)/2;
        update(2*ind+1, low, mid, arr);
        update(2*ind+2, mid+1, high, arr);

        if(arr[segs[2*ind+1]] >= arr[segs[2*ind+2]]) segs[ind] = segs[2*ind+1];
        else segs[ind] = segs[2*ind+2];
    }

};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegTree sgt(n);
        sgt.build(0,0,n-1,baskets);

        int cnt = 0;
        for (int i=0; i<n; i++){
            int val = fruits[i];
            int leftind = sgt.query(0,0,n-1,val,baskets);
            if(leftind>=0) {
                cnt++;
                baskets[leftind] = 0; // used basket
                sgt.update(0,0,n-1,baskets);
            }
        }
        return n-cnt;
    }
};