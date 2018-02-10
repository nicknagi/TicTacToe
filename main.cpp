#include <iostream>
#include <vector>

using namespace std;

//Global Variables

//Empty places in grid map are 0, X is 1 and O is 2
#define X 1
#define O 2

//Grid is represented by a 2d vector
vector<vector<int>> mainGrid;

//Store the dimensions of the grid
int gridDimesnions = 3;

//Initialize the mainGrid with zeroes when given dimensions by the user
void initializeGrid(){
//    cout << "Enter nxn dimensions of grid: ";
//    cin >> gridDimesnions;

    vector<int> emptyVec(gridDimesnions, 0);
    for (int i = 0; i < gridDimesnions; ++i) {
        mainGrid.push_back(emptyVec);
    }
}

//Subroutine for displaying the grid visually in the console
void printGrid(){
    for (int i = 0; i < gridDimesnions; ++i) {
        for (int j = 0; j < gridDimesnions; ++j) {
            cout << mainGrid[j][i] << " | ";
        }
        cout << endl;
        for(int x = 0; x < (gridDimesnions*gridDimesnions)+2; x++) cout << "-";
        cout << endl;
    }
}

int main() {
    initializeGrid();
    printGrid();
    return 0;
}

