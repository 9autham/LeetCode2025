class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int length=2;
        set<int>st;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            st.insert(arr[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=arr[i];
                int b=arr[j];
                int len=2;
                while(st.find(a+b) != st.end()){
                    len++;
                    int c=a;
                    a=b;
                    b=c+b;
                }
                length=max(length,len);
            }
        }
        // (length==2 ? return 0:return length);
        if(length==2)
        return 0;
        return length;
    }
};