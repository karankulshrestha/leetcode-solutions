class SmallestInfiniteSet {
public:
    int currSmallest;
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int> > pq;
    SmallestInfiniteSet() {
        currSmallest = 1;
    }
    
    int popSmallest() {
        int res;
        if(!pq.empty()) {
            res = pq.top();
            pq.pop();
            st.erase(res);
        } else {
            res = currSmallest;
            currSmallest += 1;
        }
        return res;
    }
    
    void addBack(int num) {
        if(num >= currSmallest || st.find(num) != st.end())
            return;
        pq.push(num);
        st.insert(num);
    }
};