/*
遗漏最后没匹配
{{}
*/
string isBalanced(string s) {
    stack<char> check;
    for(char c : s) {
        switch(c) {
            case '(':
            case '[':
            case '{':
                check.push(c);
                break;
            case ')':
                if(check.empty() || check.top()!='(') return "NO";
                check.pop();
                break;
            case ']':
                if(check.empty() || check.top()!='[') return "NO";
                check.pop();
                break;
            case '}':
                if(check.empty() || check.top()!='{') return "NO";
                check.pop();
                break;
        }        
    }
    
    if(!check.empty()) return "NO";
    return "YES";
}
