#include <stdio.h>

int factorial_recursive(int N)
{
    if(N==0) return 1;
    else return N * factorial_recursive(N-1);
}

int factorial_loop_as(int N)
{   
    if(N==0) return 1;
    int ans = 1;
    for(int i=1; i<=N; i++) {
        ans *= i;
    }
    return ans;
}

int factorial_loop_des(int N)
{
    if(N==0) return 1;
    int ans = 1;
    for(int i=N; i>0; i--) {
        ans *= i;
    }
    return ans;
}

int main()
{
    int N = 10;
    int ans1 = factorial_recursive(N);
    int ans2 = factorial_loop_as(N);
    int ans3 = factorial_loop_des(N);
    return 0; // set break point here to check result
}