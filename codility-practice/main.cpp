//
//  main.cpp
//  codility-practice
//
//  Created by tringuyen on 05/11/2023.
//

#include <iostream>
#include <algorithm>

using namespace std;

/* Lesson 1: Iterations - BinaryGap */

string toBinary(int n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

int solution(int N) {
    int max = 0, cnt = 0;
    string strN = toBinary(N);
    
    if (N == 1) { return 0; }
    
    for (char ch : strN) {
        if (ch == '1') {
            if (cnt > max) {
                max = cnt;
            }
            cnt = 0;
        } else {
            cnt++;
        }
    }
    return max;
}

int main(int argc, const char * argv[]) {
    int res = solution(999);
    cout << res;
    return 0;
}
