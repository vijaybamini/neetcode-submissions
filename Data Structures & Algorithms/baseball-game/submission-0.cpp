class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> res;
        int sum = 0;
        int first = 0;
        int second = 0;
        for(string op : ops){
            if(op == "+"){
                if(!res.empty()){
                    first = res.top();
                    res.pop();
                    
                    second = res.top();
                    sum = first + second;
                    res.push(first);
                    res.push(sum);
                }
            }
            else if(op == "D"){
                int top = res.top();
                
                res.push(2* top);   
            }
            else if(op == "C"){
                if(!res.empty()){
                    res.pop();
                }
            }
            else{
                res.push(stoi(op));
            }
        }
        sum = 0;
        while(!res.empty()){
            int s = res.top();
            sum += s;
            res.pop();
        }

        return sum;
    }
};