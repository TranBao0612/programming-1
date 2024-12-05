#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int calculate(char* s[], int N)
{
    int a, b, ans;

    a = atoi(s[0]);
    
    for(int i = 0; i <= N -2; i += 2) {
        b = atoi(s[i+2]);
        switch(s[i+1][0]) {
            case '+':
                ans = a + b;
                break;
            case '-':
                ans = a - b;
                break;
            case '*':
                ans = a * b;
                break;
            case '/':
                if (b == 0) {
                    printf("Error! Denominator cannot be 0.");
                    return -1;
                }
                ans = floor(a/b);
                break;
            default:
                printf("Error! Operator not exist.");
                return -1;
                break;
        }
        a = ans;

    }
    // sample code for N == 3

    // int a = atoi(s[0]);
    // int b = atoi(s[2]);

    // switch (s[1][0])
    // {
    // case '+':
    //     return a + b;
    // case '-':
    //     return a - b;
    // case '*':
    //     return a * b;
    // case '/':
    //     return floor of (a/b);
    // default:

    //     break;
    // }

    return ans;
}

int main()
{
    char* s[9] = { "25", "+", "3", "/", "10", "+", "12", "*", "3" };
    int ans = calculate(s, 9);
    printf("THe answer is: %d", ans);
    return 0;
}