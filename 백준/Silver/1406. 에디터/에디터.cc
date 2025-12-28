#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string initialStr;
    cin >> initialStr;

    list<char> editor(initialStr.begin(), initialStr.end());

    int M;
    cin >> M;

    auto cursor = editor.end();
    
    for (int i = 0; i < M; ++i)
    {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (cursor != editor.begin()) {
                cursor--;
            }
        }
        else if (cmd == 'D') {
            if (cursor != editor.end()) {
                cursor++;
            }
        }
        else if (cmd == 'B') {
            if (cursor != editor.begin()) {
                cursor = editor.erase(--cursor); 
            }
        }
        else if (cmd == 'P') {
            char addChar;
            cin >> addChar;
            editor.insert(cursor, addChar);
        }
    }

    for (char c : editor) {
        cout << c;
    }

    return 0;
}
