class StockSpanner {
public:
    stack<int>st;
    vector<int>prices;
    StockSpanner() {
        
    }
    
    int next(int price) {

        int size = prices.size();
        prices.push_back(price);

        int currCt = 0;

        while(!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }

        currCt = st.empty() ? size + 1 : size - st.top();
        st.push(size);
        return currCt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */