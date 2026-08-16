class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> st;
        int n = t.size();
        for(int i = 0; i < n; i++){
            int sum = 0;
            if(t[i] == "+"){
                sum = st.top();
                st.pop();
                sum = st.top() + sum;
                st.pop();
                st.push(sum);
            }
            else if(t[i] == "-"){
                sum = st.top();
                st.pop();
                sum = st.top() - sum;
                st.pop();
                st.push(sum);
            }
            else if(t[i] == "*"){
                sum = st.top();
                st.pop();
                sum = sum * st.top();
                st.pop();
                st.push(sum);
            }
            else if(t[i] == "/"){
                sum = st.top();
                st.pop();
                sum = st.top() /sum ;
                st.pop();
                st.push(sum);
            }
            else{
                st.push(stoi(t[i]));
            }
        }

        return st.top();

    }
};
