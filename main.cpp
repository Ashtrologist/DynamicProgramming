#include "stdio.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

#define PENALTY 2

using namespace std;

//int DPMaxSum(int arr[M][N]){
//
//int grade = 10;
//return grade;
//}
//
//int maxSum(int arr[M][N]) {
//
//    int sum = 0;
//    int firstPrevMaxRow = 0;
//    int secondPrevMaxRow = 0;
//    int currentMaxRow = 0;
//    int currentEntry = 0;
//    int upperLimit, lowerLimit;
//
//
//
//    for (int i = 0; i < N; i++) {
//
//        int max = 0;
//        for (int j = 0; j < M; j++) {
//            currentEntry = arr[j][i];
//
//            if (firstPrevMaxRow == secondPrevMaxRow) {
//                upperLimit = firstPrevMaxRow;
//                lowerLimit = secondPrevMaxRow;
//            } else if (firstPrevMaxRow < secondPrevMaxRow) {
//                upperLimit = firstPrevMaxRow;
//                lowerLimit = secondPrevMaxRow;
//            } else if (firstPrevMaxRow > secondPrevMaxRow) {
//                lowerLimit = firstPrevMaxRow;
//                upperLimit = secondPrevMaxRow;
//            }
//
//            if (j < upperLimit) {
//                currentEntry -= PENALTY * (upperLimit - j);
//            } else if (j > lowerLimit) {
//                currentEntry -= PENALTY * (j - lowerLimit);
//            }
//            if (currentEntry >= max) {
//
//                max = currentEntry;
//                currentMaxRow = j;
//
//            }
//            if (j == M - 1) {
//                secondPrevMaxRow = firstPrevMaxRow;
//                firstPrevMaxRow = currentMaxRow;
//            }
//        }
//        sum += max;
//    }
//    return sum;
//};


int main() {

    //Initializes variables
    string userInput;
    ifstream myFile;
    int M, N;

    //Prompts the user to enter the file name
    cout << "Please enter the name of the file you would like analyzed: " << endl;
    cin >> userInput;

    //Opens file to read in data
    myFile.open(userInput);

    //If file open failed, throw an error
    if (!myFile) {
        cout << "Unable to open file";
        exit(1);
    }

    //Reads in the first two values within the file
    myFile >> M;
    myFile >> N;

    cout << "The value of M is: " << M << endl;
    cout << "The value of N is: " << N << endl;

    int bestScore = 0;
    int rOld = 0;
    int rNew = 0;
    int temp = 0;
    int arr[M][N];

    //Reading in the values from the file and storing them in an array
    while(!myFile.eof()) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                myFile >> temp;
                arr[i][j] = temp;
                cout << temp << endl;
            }
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    

    //cout << maxSum(mat);
    //cin.get();
    return 0;
}


