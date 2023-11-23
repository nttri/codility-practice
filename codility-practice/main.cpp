//
//  main.cpp
//  codility-practice
//
//  Created by tringuyen on 05/11/2023.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>
#include <stack>

using namespace std;

/* ================================ */
/* Lesson 1: Iterations - BinaryGap */
/* ================================ */

string toBinary(int n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

int solutionBinaryGap(int N) {
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


/* ================================= */
/* Lesson 2: Arrays - CyclicRotation */
/* ================================= */

vector<int> solutionCyclicRotation(vector<int> &A, int K) {
    int n = A.size();
    int k = K;
    vector<int> res(n);
    
    if (n <= 1 || k == 0) { return A; }
    
    if (k > n) {
        k = K % n;
    }
    
    if (k == 0) {
        return A;
    }
    
    for(int i=0; i<n; i++) {
        if (i-k < 0) {
            res[i] = A[n-k+i];
        } else {
            res[i] = A[i-k];
        }
    }
    
    return res;
}


/* ======================================== */
/* Lesson 2: Arrays - OddOccurrencesInArray */
/* ======================================== */

int solutionOddOccurrencesInArray(vector<int> &A) {
    int n = A.size();
    
    if (n == 1) { return A[0]; }
    
    int cnt = 1;
    sort(A.begin(), A.end());
    
    for (int i=0; i<n-1; i++){
        if (A[i] == A[i+1]){
            cnt++;
        } else {
            if (cnt % 2 == 1) {
                return A[i];
            }
            cnt = 1;
        }
    }
    
    return A[n-1];
}


/* =================================== */
/* Lesson 3: Time Complexity - FrogJmp */
/* =================================== */

int solutionFrogJmp(int X, int Y, int D) {
    if (X == Y) { return 0; }
    
    int dis = Y-X;
    if (dis%D == 0) {
        return dis/D;
    }
    return dis/D + 1;
}


/* =========================================== */
/* Lesson 3: Time Complexity - PermMissingElem */
/* =========================================== */

int solutionPermMissingElem(vector<int> &A) {
    int n = A.size();
    if (n==0) { return 1; }
    sort(A.begin(), A.end());
    
    for(int i=0; i<n; i++) {
        if (A[i] != i+1){
            return i+1;
        }
    }
    
    return n+1;
}


/* =========================================== */
/* Lesson 3: Time Complexity - TapeEquilibrium */
/* =========================================== */

int solutionTapeEquilibrium(vector<int> &A) {
    int n = A.size();
    int min = abs(A[0] - A[1]);
    if (n==2) { return min; }
    
    int sum = 0, sumA = 0, sumB = 0;
    min = INT_MAX;
    
    for(int i=0; i<n; i++) { sum += A[i]; }
    
    for(int i=0; i<n-1; i++) {
        sumA += A[i];
        sumB = sum - sumA;
        int ab = abs(sumA-sumB);
        if(ab<min) {
            min=ab;
        }
    }
    
    return min;
}


/* ========================================== */
/* Lesson 4: Counting elements - FrogRiverOne */
/* ========================================== */
// X=5, v = {1,3,1,4,2,3,5,4} ==> 6
// X=5, v = {1,3,1,4,2,3,2,4} ==> -1

// 90% only
int solutionFrogRiverOne(int X, vector<int> &A) {
    int n = A.size();
    string str(X, '0');
    string strEx(X, '1');

    for(int i=0; i<n; i++) {
        int j = A[i] - 1;
        if(str[j] == '0') {
            str[j] = '1';
            if(str == strEx) {
                return i;
            }
        }
    }

    return -1;
}


/* ======================================= */
/* Lesson 4: Counting elements - PermCheck */
/* ======================================= */

int solutionPermCheck(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    for(int i=0; i<n; i++){
        if(A[i] != i+1){
            return 0;
        }
    }
    return 1;
}


/* =============================================== */
/* Lesson 4: Counting elements - MaxCounters [Med] */
/* =============================================== */

// 77% only
vector<int> solutionMaxCounters(int N, vector<int> &A) {
    int nA = A.size();
    vector<int> res(N,0);
    int currentMax = 0;
    
    for(int i=0; i<nA; i++) {
        if(A[i] == N+1) {
            res = {};
            vector<int> newV(N, currentMax);
            res = newV;
            continue;
        }
        res[A[i]-1]++;
        if(currentMax < res[A[i]-1]) {
            currentMax = res[A[i]-1];
        }
    }
    
    return res;
}


/* ================================================== */
/* Lesson 4: Counting elements - MissingInteger [Med] */
/* ================================================== */

int solutionMissingInteger(vector<int> &A) {
    vector<int> B;
    
    for (int a : A) {
        if (a>0) {
            B.push_back(a);
        }
    }
    
    int nB = B.size();
    if (nB == 0) { return 1; }
    
    sort(B.begin(), B.end());
    
    if (B[0] != 1) { return 1; }
    
    if (nB == 1) { return B[0] + 1; }
    
    for (int i=0; i<nB - 1; i++) {
        int d = B[i+1] - B[i];
        if (d>1) {
            return B[i] + 1;
        }
    }
    
    return B[nB - 1] + 1;
}


/* =================================== */
/* Lesson 5: Prefix sums - PassingCars */
/* =================================== */

int solutionPassingCars(vector<int> &A) {
    int n = A.size();
    
    if (n==1) { return 0; }
    
    int zero = 0, cnt = 0;
    
    for (int i=0; i<n; i++) {
        if (A[i]==0) {
            zero++;
        } else {
            cnt = cnt + zero;
            if (cnt > 1000000000) { return -1; }
        }
    }
    
    return cnt;
}


/* ====================================== */
/* Lesson 5: Prefix sums - CountDiv [Med] */
/* ====================================== */

// 87% only
int solutionCountDiv(int A, int B, int K) {
    int cnt = (B-A) / K;
    if(A%K==0 || B%K==0) {
        cnt++;
    } else if(A<K && A!=0 && B>K) {
        cnt++;
    }
    return cnt;
}


/* =============================================== */
/* Lesson 5: Prefix sums - GenomicRangeQuery [Med] */
/* =============================================== */

// 62% only
// Solution: https://codesays.com/2014/solution-to-genomic-range-query-by-codility/
vector<int> solutionGenomicRangeQuery(string &S, vector<int> &P, vector<int> &Q) {
    vector<int> s;
    for (char c:S) {
        if (c=='A') {
            s.push_back(1);
        } else if (c=='C') {
            s.push_back(2);
        } else if (c=='G') {
            s.push_back(3);
        } else {
            s.push_back(4);
        }
    }
    
    vector<int> res;
    
    for(int i=0; i<P.size(); i++) {
        if(P[i]==Q[i]) {
            res.push_back(s[P[i]]);
            continue;
        }
        for(int j=1; j<=4; j++) {
            vector<int>::iterator start = s.begin() + P[i];
            vector<int>::iterator end = s.begin() + Q[i] + 1;
            if (find(start, end, j) != end) {
                res.push_back(j);
                break;
            }
        }
    }
    
    return res;
}


/* ============================================ */
/* Lesson 5: Prefix sums - MinAvgTwoSlice [Med] */
/* ============================================ */

// 60% only
// Solution: https://codesays.com/2014/solution-to-min-avg-two-slice-by-codility/
float avgTwoSlice(vector<int> &A, int P, int Q) {
    int sum = 0;
    for(int i=P; i<=Q; i++) {
        sum += A[i];
    }
    float avg = (sum * 1.0) / (Q-P+1);
    return avg;
}

int solutionMinAvgTwoSlice(vector<int> &A) {
    int n = A.size();
    int pos = 0;
    float min = avgTwoSlice(A,0,1);
    
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            float f = avgTwoSlice(A, i, j);
            if (f < min) {
                min = f;
                pos = i;
            }
        }
    }
    
    return pos;
}


/* ============================ */
/* Lesson 6: Sorting - Distinct */
/* ============================ */

int solution(vector<int> &A) {
    if(A.size() == 0) { return 0; }
    set<int> sA(A.begin(), A.end());
    return sA.size();
}


/* ===================================== */
/* Lesson 6: Sorting - MaxProductOfThree */
/* ===================================== */

int solutionMaxProductOfThree(vector<int> &A) {
    vector<int> B;
    bool haveZero = false;
    for (int a : A) {
        if(a != 0) {
            B.push_back(a);
        } else {
            haveZero = true;
        }
    }
    
    int n = B.size();
    if (n<3) { return 0; }
    if (n==3) { return B[0] * B[1] * B[2]; }
    
    sort(B.begin(), B.end());
    
    if (B[n-1] < 0 && haveZero) { return 0; }
    
    int option1 = B[n-1] * B[n-2] * B[n-3];
    int option2 = B[0] * B[1] * B[n-1];
    
    if (option1 > option2) {
        return option1;
    }
    
    return option2;
}


/* ============================ */
/* Lesson 6: Sorting - Triangle */
/* ============================ */

// 93% only, should use `long` type to store the sum
int solutionTriangle(vector<int> &A) {
    int n = A.size();
    
    if (n<3) { return 0; }
    
    sort(A.begin(), A.end());
    
    for (int i=0; i<n-2; i++) {
        bool isTriangular = (A[i] + A[i+1] > A[i+2]) && (A[i+2] + A[i+1] > A[i]) && (A[i] + A[i+2] > A[i+1]);
        if (isTriangular == true) {
            return 1;
        }
    }
    
    return 0;
}


/* =================================================== */
/* Lesson 6: Sorting - NumberOfDiscIntersections [Med] */
/* =================================================== */

// 70% only
bool isIntersect(int c1, int r1, int c2, int r2) {
    long long le1 = c1 - r1;
    long long ri1 = c1 + r1;
    long long le2 = c2 - r2;
    long long ri2 = c2 + r2;
    
    if ((le2 > ri1) || (ri2 < le1)) {
        return false;
    }
    
    return true;
}

int solutionNumberOfDiscIntersections(vector<int> &A) {
    int n = A.size();
    
    if (n<2) { return 0; }
    
    int cnt = 0;
    
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            bool flag = isIntersect(i, A[i], j, A[j]);
            if (flag) {
                cnt++;
            }
        }
    }
    
    return cnt;
}


/* ====================================== */
/* Lesson 7: Stacks and Queues - Brackets */
/* ====================================== */

int solutionBrackets(string &S) {
    if(S.size() == 0) {
        return 1;
    }
    
    stack<char> stackChar;
    
    for (char c:S) {
        if (c == '(' || c == '{' || c == '[') {
            stackChar.push(c);
        } else {
            char topChar = stackChar.top();
            if ((c == ')' && topChar != '(')
                || (c == ']' && topChar != '[')
                || (c == '}' && topChar != '{')) {
                return 0;
            } else {
                stackChar.pop();
            }
        }
    }
    
    if (stackChar.empty()) {
        return 1;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    int res = solution(999);
    cout << res;
    return 0;
}
