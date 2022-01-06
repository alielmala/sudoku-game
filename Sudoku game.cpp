#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;


void printGame(int a[9][9]){
    cout << setw(5);
    for (int y=0; y < 9;++y){
        cout <<" c"<<y+1<<" ";
    }
    cout <<endl;
    for (int i =0; i<9; ++i ){
        cout << "r" << i+1<<"# ";
        for (int j =0; j < 9;++j){
            cout << a[i][j]<<" | ";
        }
        cout<<endl<<"    ***********************************"<<endl;
    }
}
int countZero(int (&a)[9][9]){
    int numZero=0;
    for(int i=0; i <9; ++i ){
        for (int j =0; j <9; ++j){
            if ( a[i][j]==0){
                ++numZero;
            }
        }
    }
    return numZero;
}

void userPlay(int (& a)[9][9],int  b [9][9], string & answer){
    int q = countZero(a)+5;
    for (int i =0;i <q+5; ++i){

    int numOfRemainingCells = countZero(a);
    system("cls");
    int remainingTries = q-i;
    if (numOfRemainingCells > remainingTries){
        cout << "game over"<<endl<<endl;
        break;
    }
    else if (numOfRemainingCells == 0){
        cout<< "Congratulations!" <<endl<<endl;
        break;
    }
    cout << "Remaining number of tries is: "<<remainingTries <<endl<<endl;
    printGame(a);
    int rowNum,colNum,value;
    cout << answer<<endl;
    cout << "Enter row number: ";
    cin >> rowNum;
    cout << "Enter col number: ";
    cin >>colNum;
    cout << "Enter value: ";
    cin >> value;

    if (value == b[rowNum-1][colNum-1] ){
    a[rowNum-1][colNum-1]=value;
        answer= "well done";
        --numOfRemainingCells;}
    else {
        answer= "wrong answer"; }
    }
}


int main (){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,1);
    for (int i = 0; i< 40 ; ++i)
        cout << "=";
    cout <<endl;

    SetConsoleTextAttribute(hConsole,2);
    cout  <<"Welcome to Our Sudoku game"<<endl<<endl;

    SetConsoleTextAttribute(hConsole,4);
    cout <<"Choose the level of the game:"<<endl<<endl;
    cout <<setw(10)<<"1) Easy"<<endl;
    cout<<setw(12) << "2) Medium"<<endl;
    cout <<setw(10)<<"3) Hard"<<endl;

    SetConsoleTextAttribute(hConsole,1);
    for (int i = 0; i< 40 ; ++i)
        cout << "=";
    cout <<endl;

    int gameLevel;
    SetConsoleTextAttribute(hConsole,10);
    cout << "Enter Level Number: ";
    cin >> gameLevel;
    string answer="Let's play";
   int easyArr[9][9]={
    {0,0,0,2,6,0,7,0,1},
    {6,8,0,0,7,0,0,9,0},
    {1,9,0,0,0,4,5,0,0},
    {8,2,0,1,0,0,0,4,0},
    {0,0,4,6,0,2,9,0,0},
    {0,5,0,0,0,3,0,2,8},
    {0,0,9,3,0,0,0,7,4},
    {0,4,0,0,5,0,0,3,6},
    {7,0,3,0,1,8,0,0,0}};

    int easyArrSolution[9][9]{
    {4,3,5,2,6,9,7,8,1},
    {6,8,2,5,7,1,4,9,3},
    {1,9,7,8,3,4,5,6,2},
    {8,2,6,1,9,5,3,4,7},
    {3,7,4,6,8,2,9,1,5},
    {9,5,1,7,4,3,6,2,8},
    {5,1,9,3,2,6,8,7,4},
    {2,4,8,9,5,7,1,3,6},
    {7,6,3,4,1,8,2,5,9}};

    int mediumArr[9][9]{
    {0,0,0,0,0,8,0,0,1},
    {0,0,8,0,4,0,0,0,0},
    {0,0,3,0,9,1,0,4,2},
    {0,3,1,0,0,0,0,0,0},
    {6,0,0,7,5,0,0,0,0},
    {0,2,0,3,0,6,0,9,5},
    {0,6,2,8,0,0,0,0,4},
    {0,0,5,9,0,4,0,0,7},
    {0,0,4,0,0,0,2,0,9}};

    int mediumArrSolution[9][9]{
    {4,9,6,2,3,8,5,7,1},
    {2,1,8,5,4,7,9,6,3},
    {7,5,3,6,9,1,8,4,2},
    {5,3,1,4,8,9,7,2,6},
    {6,4,9,7,5,2,3,1,8},
    {8,2,7,3,1,6,4,9,5},
    {9,6,2,8,7,3,1,5,4},
    {1,8,5,9,2,4,6,3,7},
    {3,7,4,1,6,5,2,8,9}};

    int hardArr[9][9] = {
        {0,0,0,6,0,0,4,0,0},
        {7,0,0,0,0,3,6,0,0},
        {0,0,0,0,9,1,0,8,0},
        {0,0,0,0,0,0,0,0,0},
        {0,5,0,1,8,0,0,0,3},
        {0,0,0,3,0,6,0,4,5},
        {0,4,0,2,0,0,0,6,0},
        {9,0,3,0,0,0,0,0,0},
        {0,2,0,0,0,0,1,0,0} };
    int hardArrSolution[9][9]{
        {5,8,1,6,7,2,4,3,9},
        {7,9,2,8,4,3,6,5,1},
        {3,6,4,5,9,1,7,8,2},
        {4,3,8,9,5,7,2,1,6},
        {2,5,6,1,8,4,9,7,3},
        {1,7,9,3,2,6,8,4,5},
        {8,4,5,2,1,9,3,6,7},
        {9,1,3,7,6,8,5,2,4},
        {6,2,7,4,3,5,1,9,8} };

    switch (gameLevel){
    case 1:
    // easy
        userPlay(easyArr, easyArrSolution, answer);
        break;
    case 2:
        userPlay(mediumArr,mediumArrSolution, answer);
        break;
    case 3:
        userPlay(hardArr,hardArrSolution,answer);
        break;
    }
        return 0;
}
