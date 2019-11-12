#include "stdio.h"
#include <iostream>
#include <algorithm>

#define M 3
#define N 4
#define PENALTY 2

using namespace std;
//
//int DPMaxSum(int mat[M][N]){
//
//}

int maxSum(int mat[M][N]) {

    int sum = 0;
    int firstPrevMaxRow = 0;
    int secondPrevMaxRow = 0;
    int currentMaxRow = 0;
    int currentEntry = 0;
    int upperLimit, lowerLimit;

    for (int i = 0; i < N; i++) {

        int max = 0;
        for (int j = 0; j < M; j++) {
            currentEntry = mat[j][i];

            if (firstPrevMaxRow == secondPrevMaxRow) {
                upperLimit = firstPrevMaxRow;
                lowerLimit = secondPrevMaxRow;
            } else if (firstPrevMaxRow < secondPrevMaxRow) {
                upperLimit = firstPrevMaxRow;
                lowerLimit = secondPrevMaxRow;
            } else if (firstPrevMaxRow > secondPrevMaxRow) {
                lowerLimit = firstPrevMaxRow;
                upperLimit = secondPrevMaxRow;
            }

            if (j < upperLimit) {
                currentEntry -= PENALTY * (upperLimit - j);
            } else if (j > lowerLimit) {
                currentEntry -= PENALTY * (j - lowerLimit);
            }
            if (currentEntry >= max) {

                max = currentEntry;
                currentMaxRow = j;

            }
            if (j == M - 1) {
                secondPrevMaxRow = firstPrevMaxRow;
                firstPrevMaxRow = currentMaxRow;
            }
        }
        sum += max;
    }
    return sum;
};


int main() {
    int mat[M][N] = {{2, 3, 4, 1},
                     {5, 1, 2, 4},
                     {4, 5, 3, 4}};

    cout << maxSum(mat);
    cin.get();
    return 0;
}


