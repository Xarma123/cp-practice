#include <bits/stdc++.h>

using namespace std;

map<pair<char, char>, string> grammar_map;

vector<vector<string>> output_to_print;

void initialize_map()
{
    grammar_map = {
        {{'E', 'i'}, "Te"},
        {{'E', '('}, "Te"},
        {{'e', '+'}, "+Te"},
        {{'e', ')'}, "n"},
        {{'e', '$'}, "n"},
        {{'T', 'i'}, "Ft"},
        {{'T', '('}, "Ft"},
        {{'t', '+'}, "n"},
        {{'t', '*'}, "*Ft"},
        {{'t', ')'}, "n"},
        {{'t', '$'}, "n"},
        {{'F', 'i'}, "i"},
        {{'F', '('}, "(E)"}};
}

string reverse_transform(char c)
{
    if (c == 'E')
        return "E";
    if (c == 'e')
        return "E\'";
    if (c == 'T')
        return "T";
    if (c == 't')
        return "T\'";
    if (c == 'F')
        return "F";
    if (c == 'i')
        return "id";
    if (c == 'n')
        return "ε";
    string s = "";
    s += c;
    return s;
}

string reverse_transforms(const string &input_str)
{
    string result;
    for (char c : input_str)
    {
        result += reverse_transform(c);
    }
    return result;
}

string transform(const string &input_str)
{
    int lexeme_begin = 0;
    int forward = lexeme_begin + 1;
    string output = "";

    while (lexeme_begin < input_str.length() && output != "invalid")
    {
        char current = input_str[lexeme_begin];

        if (current == 'i')
        {
            if (forward < input_str.length() && input_str[forward] == 'd')
            {
                output += 'i';
                lexeme_begin += 2;
                forward = lexeme_begin + 1;
            }
            else
            {
                output = "invalid";
            }
        }
        else if (current == '+')
        {
            output += '+';
            lexeme_begin += 1;
            forward = lexeme_begin + 1;
        }
        else if (current == '(')
        {
            output += '(';
            lexeme_begin += 1;
            forward = lexeme_begin + 1;
        }
        else if (current == ')')
        {
            output += ')';
            lexeme_begin += 1;
            forward = lexeme_begin + 1;
        }
        else if (current == '*')
        {
            output += '*';
            lexeme_begin += 1;
            forward = lexeme_begin + 1;
        }
        else if (current == ' ')
        {
            lexeme_begin += 1;
            forward = lexeme_begin + 1;
        }
        else
        {
            output = "invalid";
        }
    }

    return output;
}

bool is_terminal(char ch)
{
    return ch != 'E' && ch != 'e' && ch != 'T' && ch != 't' && ch != 'F' && ch != 'n';
}

bool stack_iterate(const string &input_str)
{
    stack<char> st;
    st.push('E');
    int lexeme_begin = 0;
    vector<string> temp;

    while (!st.empty())
    {
        temp.clear();
        string matched = lexeme_begin != 0 ? reverse_transforms(input_str.substr(0, lexeme_begin)) : " ";

        temp.push_back(matched);
        string stack_content = "";
        stack<char> st_copy = st;
        while (!st_copy.empty())
        {
            stack_content += reverse_transform(st_copy.top());
            st_copy.pop();
        }
        stack_content += '$';
        temp.push_back(stack_content);

        temp.push_back(reverse_transforms(input_str.substr(lexeme_begin)));
        string action = "";

        if (st.top() == input_str[lexeme_begin])
        {
            action = "match " + reverse_transform(st.top());
            temp.push_back(action);
            st.pop();
            lexeme_begin += 1;
        }
        else if (is_terminal(st.top()) || grammar_map.find({st.top(), input_str[lexeme_begin]}) == grammar_map.end())
        {
            return false;
        }
        else
        {
            action = "output " + reverse_transform(st.top()) + " --> ";
            string right_prod = grammar_map[{st.top(), input_str[lexeme_begin]}];
            action += reverse_transforms(right_prod);
            temp.push_back(action);
            st.pop();
            for (int i = right_prod.length() - 1; i >= 0; i--)
            {
                if (right_prod[i] != 'n')
                {
                    st.push(right_prod[i]);
                }
            }
        }
        output_to_print.push_back(temp);
    }

    temp = {reverse_transforms(input_str), "$", "$", "Successfully parsed!"};
    output_to_print.push_back(temp);
    return true;
}

string beautify(const string &input_str)
{
    int total = 15;
    int rem = total - input_str.length();
    return input_str + string(rem, ' ');
}

string rev_beautify(const string &input_str)
{
    if (input_str.empty())
    {
        return input_str; // Return the empty string as is
    }

    int rem = 25 - input_str.length();
    string answer = "";

    if (input_str[0] == 'o' || input_str[0] == 'm' || input_str[0] == 'S' || input_str[0] == 'A')
    {
        int remaining = 10;
        answer += string(remaining, ' ');
    }

    answer += input_str + string(rem, ' ');
    return answer;
}

void print_line()
{
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << rev_beautify("Matched") << beautify("Stack") << beautify("Input") << rev_beautify("Action") << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    for (const auto &item : output_to_print)
    {
        if (item[0].empty())
        {
            cout << " ";
        }
        else
        {
            cout << rev_beautify(item[0]) << beautify(item[1]) << beautify(item[2]) << rev_beautify(item[3]) << endl;
        }
    }
}
string remove_spaces(string a)
{
    string result = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ' ')
        {
            int j = i + 1;
            while (j < a.size() && a[j] == ' ')
                j++;
            i = j - 1;
        }
        else
            result += a[i];
    }
    return result;
}
int main()
{
    initialize_map();
    string input_exp;
    cout << "Enter the expression:" << endl;
    getline(cin, input_exp);
    input_exp = remove_spaces(input_exp); // Remove redundant spaces

    string input_str = transform(input_exp);

    if (input_str != "invalid")
    {
        input_str += '$';
        output_to_print.clear();
        bool global_truth = stack_iterate(input_str);

        if (!global_truth)
        {
            cout << "This input is not accepted by the grammar: " << input_exp << endl;
        }
        else
        {
            print_line();
            cout << "\nInput   : " << input_exp << endl;
            cout << "Matched : " << input_exp << endl;
        }
    }
    else
    {
        cout << "Invalid Input" << endl;
    }

    return 0;
}
