#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A, B;
    cin >> A >> B;
    
    // 소수점 아래(fixed) 10자리 이상(precision) 출력하도록 설정
    cout << fixed;
    cout.precision(12); 
    
    cout << (double)A / B;
    
    return 0;
}