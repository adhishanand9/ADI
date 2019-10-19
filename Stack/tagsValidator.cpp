#include<iostream>
#include<stack>
using namespace std;
bool tags(const string& code) {
        if (code.size() < 2 || code[0] != '<' || code[1] < 'A' || code[1] > 'z') return false;
        stack<string> tagname_stack;
        int i = 0, j = 0, n = code.size();
        while (i < n) {
            while (i < n && code[i] != '<') ++i;
            if (i == n || i + 1 == n) break;
            ++i;
            if (code[i] == '/') {   // end tag
                if (tagname_stack.empty()) break;
                ++i;
                j = i;
                while (j < n && code[j] != '>' && j < i + 9
                    && code[j] >= 'A' && code[j] <= 'z') ++j;
                if (j == n || code[j] != '>' || i == j) break;
                if (tagname_stack.top() != code.substr(i, j - i)) break;
                tagname_stack.pop();
                i = j + 1;
                if (i == n) return tagname_stack.empty();
                if (tagname_stack.empty()) break;
            }
            else if (code[i] == '!') {  // cdata
                ++i;
                if (code.substr(i, 7) != "[CDATA[") break;
                i += 7;
                j = code.find("]]>", i);
                if (j == string::npos) break;
                i = j + 3;
            }
            else {  // start tag
                j = i;
                while (j < n && code[j] != '>' && j < i + 9
                    && code[j] >= 'A' && code[j] <= 'z') ++j;
                if (j == n || code[j] != '>' || i == j) break;
                tagname_stack.push(code.substr(i, j - i));
                i = j + 1;
            }
        }
        return false;
    }
int main()
{
 string str;
 getline(cin,str);
 if(tags(str))
    cout<<"Valid";
 else
    cout<<"Invalid";
}
