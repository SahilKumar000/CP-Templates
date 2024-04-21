struct FenwickTree
{
    // i+=i&-i is used to get the parent node of the current node the logn ranges
    int n;
    vector<int> bit;
    FenwickTree(vector<int>&arr):n(arr.size()),bit(n+1){
        for(int i = 0;i < n;i++) upd(i,arr[i]);
    }
    void upd(int i,int val){
        for(++i;i <= n;i += i&-i) bit[i] += val;
    }
    ll qry(int i){
        int res = 0;
        for(++i;i;i -= i&-i) res += bit[i];
        return res;
    }
    ll qry(int l,int r){
        return qry(r) - qry(l-1);
    }
};
