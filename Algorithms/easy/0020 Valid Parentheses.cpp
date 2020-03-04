#核心思路为利用栈的特性进行匹配
#输入一个符合左半边的符号后便压入栈底，后来者与栈顶进行比较（后来者不入栈）
class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    for(auto ch : s) {
        if (ch=='{' || ch =='[' || ch=='(' ) {
            st.push(ch);
        }else if (ch=='}' || ch ==']' || ch == ')' ){
            if (st.empty()) return false;
            char sch = st.top();
            if ( (sch=='{' && ch =='}') || (sch=='[' && ch==']') || (sch=='(' && ch==')' ) ){
                st.pop();
            }else {
                return false;
            }
        }else{
            return false;
        }
    }
    return st.empty();
}
};
