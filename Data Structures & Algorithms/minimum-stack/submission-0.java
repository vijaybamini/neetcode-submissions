class MinStack {
    Stack<Integer> ms = new Stack<>();
    Stack<Integer> s = new Stack<>();

    public MinStack() {
        
    }
    
    public void push(int val) {
        s.push(val);
        if(ms.isEmpty()){
            ms.push(val);
        }
        else {
            if(ms.peek() >= val){
                ms.push(val);
            }
        }
    }
    
    public void pop() {
        int a = s.pop();
        if(a == ms.peek()){
            ms.pop();
        }
    }
    
    public int top() {
        return s.peek();
    }
    
    public int getMin() {
        return ms.peek();
    }
}
