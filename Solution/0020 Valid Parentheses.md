### 题目描述：
> 原题目：

> Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

> An input string is valid if:

> 1、Open brackets must be closed by the same type of brackets.

> 2、Open brackets must be closed in the correct order.

题目的要求是验证输入的括号组是不是正确配对了，比如（）是对的，但是（ ]是错误的。

### 思路：
本题的核心思路就是利用栈的先进后出。

我们可以将括号分为左型（包括'(','{','['）和右型（')','}',']'）。每次读取一个符号后进行判断，如果是左型则压入栈；如果是右型则和栈顶元素判断是否匹配，匹配则将当前栈顶元素弹出，否则即算是错误。

涉及知识点：栈的特性

涉及操作知识：栈的初始化、push、pop，基本判断语法、循环。

### 解法：

```
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (auto ch:s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }else if (ch=='}' || ch ==']' || ch == ')') {
                if (st.empty()) return false;
                char sch = st.top();
                if ((sch=='{' && ch =='}') || (sch=='[' && ch==']') || (sch=='(' && ch==')' )) {
                    st.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        return st.empty();
    }
};
```
### Note: 
auto的用法、for的遍历（ch：s）
