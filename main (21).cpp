#include <iostream>
#include <stack>
#include <vector>
#include <string>

bool isBalanced(const std::string& s) {
	std::stack<char> st;
	for(char c : s) {
		if(c=='(' || c=='[' || c=='{') {
			st.push(c);
		} else if(c==')' || c=='}' || c==']') {
    if(st.empty()){
        return false;
    }
     if ((c == ')' && st.top() != '(') ||
                (c == ']' && st.top() != '[') ||
                (c == '}' && st.top() != '{')) {
                return false;
            }
            st.pop();
		}
		
	}
	return st.empty();
}

int evaluateRPN(const std::vector<std::string>& expr) {
    std::stack<int> st;

    for (const std::string& s : expr) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            if (s == "+") st.push(a + b);
            else if (s == "-") st.push(a - b);
            else if (s == "*") st.push(a * b);
            else if (s == "/") st.push(a / b);
        }
        else {
            st.push(std::stoi(s));
        }
    }

    return st.top();
}

void reverseString(std::string& s) {
    std::stack<char> st;

    for (char c : s) {
        st.push(c);
    }

    for (int i = 0; i < s.size(); i++) {
        s[i] = st.top();
        st.pop();
    }
}
int main() {

std::cout << isBalanced("({[]})") << '\n';  // 1 (true)
std::cout << isBalanced("([)]") << '\n';    // 0 (false)
std::cout << isBalanced("{[}]") << '\n';    // 0 (false)

std::vector<std::string> expr = {"2", "1", "+", "3", "*"};
std::cout << evaluateRPN(expr) << '\n';  // 9
// (2 + 1) * 3 = 9

std::string s = "Hello";
reverseString(s);
std::cout << s << '\n';  // olleH

	return 0;
}
