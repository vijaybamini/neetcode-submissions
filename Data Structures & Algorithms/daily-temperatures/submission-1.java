class Solution {
    public int[] dailyTemperatures(int[] t) {
        Stack<Integer> st=new Stack<>();
        int[] an=new int[t.length];
        for(int i=t.length-1;i>-1;i--){
                while(!st.isEmpty()&&t[st.peek()]<=t[i]){
                    st.pop();
                }
            if(st.isEmpty()){
                an[i]=0;
            }else{
                an[i]=st.peek()-i;
            }
            st.push(i);
        }
        return an;
    }
}
