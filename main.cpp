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
int gridDimensions = 3;

//Variable to hold whos turn it is
//Player 1 gets Xs and player 2 gets Ys
int whosTurn = 1;

//AI toggle
bool isAIPlaying = false;

//Bool to hold if endgame reached
bool isWin = false;

//Initialize the mainGrid with zeroes when given dimensions by the user
void initializeGrid(){
//    cout << "Enter nxn dimensions of grid: ";
//    cin >> gridDimensions;

    vector<int> emptyVec(gridDimensions, 0);
    for (int i = 0; i < gridDimensions; ++i) {
        mainGrid.push_back(emptyVec);
    }
}

//Subroutine for displaying the grid visually in the console
void printGrid(){
    string symbol;
    int symbolVal = 0;
    for (int i = 0; i < gridDimensions; ++i) {
        for (int j = 0; j < gridDimensions; ++j) {

            symbolVal = mainGrid[j][i];

            if(symbolVal == X) symbol = "X";
            else if(symbolVal == O) symbol = "O";
            else if(symbolVal == 0) symbol = " ";

            cout << symbol << " | ";
        }
        cout << endl;
        for(int x = 0; x < (4*gridDimensions)-1; x++) cout << "-";
        cout << endl;
    }

    cout << endl << endl;
}

//subroutine for updating grid when a player makes a turn
void playerTurn(int TurnSymbol, int xLoc, int yLoc){
    mainGrid[xLoc][yLoc] = TurnSymbol;
    printGrid();
}

void simulateGame(){
    while(!isWin) {
        int xLoc = 0, yLoc = 0;
        if (!isAIPlaying) {
            cout << "Enter the x and y coordinates: ";
            cin >> xLoc >> yLoc;
        }

        if (whosTurn == 1) {
            playerTurn(X, xLoc, yLoc);
            whosTurn = 2;
        } else if (whosTurn == 2) {
            playerTurn(O, xLoc, yLoc);
            whosTurn = 1;
        }
    }


}

/*
 * TO DO:
 * Add endgame checking logic
 * no overwriting allowed functionality
 * More dynamic simulate game (by allowing user(s) to select who goes first)
 * AI Implementation
 * */
int main() {
    initializeGrid();

    simulateGame();

    return 0;
}

