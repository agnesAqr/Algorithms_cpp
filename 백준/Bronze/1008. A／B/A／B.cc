#include <cstdio>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    // %.9lf : double(lf)형을 소수점 9자리(.9)까지 출력
    printf("%.12lf", (double)A / B); 
    return 0;
}