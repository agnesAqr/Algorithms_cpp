#include <iostream>
#include <vector>
using namespace std;

int result{};
int N{};
const int MAX_N = 15;

bool check_col[MAX_N + 5];  // 세로
bool check_diag1[2 * MAX_N + 5]; // 우상향 대각선 (row+col)
bool check_diag2[2 * MAX_N + 5]; // 우하향 대각선 (row-col+N -> 마이너스 값 보정)
// => 대각선에 있는 위치들은 모두 같은 규칙(y=-1x+b, y=1x+b)에 의해 해당 위치에 있는 것이므로 b라는 값을 인덱스로 사용해 모든 곳에 금지구역을 표시하는 것

void Chess(int row)
{
    if (row == N)
    {
        result++;
        return;
    }

    for (int i = 0; i < N; ++i)  // i는 col
    {
        if (check_col[i] || check_diag1[row + i] || check_diag2[row - i + N])
            continue;

        // 방문 체크
        check_col[i] = true;
        check_diag1[row + i] = true;
        check_diag2[row - i + N] = true;

        Chess(row + 1);

        // 원상 복구
        check_col[i] = false;
        check_diag1[row + i] = false;
        check_diag2[row - i + N] = false;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    Chess(0);
    cout << result;

    return 0;
}