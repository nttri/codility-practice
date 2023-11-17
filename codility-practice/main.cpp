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

int main(int argc, const char * argv[]) {
    int res = solution(999);
    cout << res;
    return 0;
}
