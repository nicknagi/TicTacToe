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

    //Print the x axis legend;
    int count = 2;
    for (int i = 0; i < gridDimensions; ++i) {
        int countPrev = count;
        for (int j = 0; j < countPrev; ++j) {
            cout << " ";
            if (count != 3)
            count++;
        }

        cout << i;
    }

    cout<<endl;

    for (int i = 0; i < gridDimensions; ++i) {
        for (int j = 0; j < gridDimensions; ++j) {

            symbolVal = mainGrid[j][i];

            //Print the y axis legend index
            if(j == 0)
            {
                cout << i << " ";
            }

            //Convert integers into symbols
            if(symbolVal == X) symbol = "X";
            else if(symbolVal == O) symbol = "O";
            else if(symbolVal == 0) symbol = " ";

            //Print the symbol
            cout << symbol << " | ";
        }

        cout << endl;

        //Draw separation lines among each row
        for(int x = 0; x < (4*gridDimensions)+1; x++) cout << "-";

        cout << endl;
    }

    cout << endl << endl;
}

//subroutine for updating grid when a player makes a turn
bool playerTurn(int TurnSymbol, int xLoc, int yLoc){
    if ((xLoc >= 0 && yLoc >= 0) && (xLoc < gridDimensions && yLoc < gridDimensions)) {
        if (mainGrid[xLoc][yLoc] == 0  ) {
            mainGrid[xLoc][yLoc] = TurnSymbol;
            printGrid();
            return true;
        }
        else {
            cout << "Invalid move! try Again" << endl;
            return false;
        }
    }
    else {
        cout << "Out of bounds! try Again" << endl;
        return false;
    }

}

//Simulates turn based gameplay among the two players
void simulateGame(){
    while(!isWin) {
        int xLoc = 0, yLoc = 0;

        if (!isAIPlaying) {


            if (whosTurn == 1) {
                cout << "Player 1's Turn: " << endl;
                cout << "Enter the x and y coordinates: ";
                cin >> xLoc >> yLoc;

                if (playerTurn(X, xLoc, yLoc)) whosTurn = 2;

            } else if (whosTurn == 2) {
                cout << "Player 2's Turn: " << endl;
                cout << "Enter the x and y coordinates: ";
                cin >> xLoc >> yLoc;

                if (playerTurn(O, xLoc, yLoc)) whosTurn = 1;
            }
        }
    }

}


/*
 * TO DO:
 * Add endgame checking logic
 * More dynamic simulate game (by allowing user(s) to select who goes first)
 * AI Implementation
 * GUI Implementation
 * */
int main() {
    initializeGrid();

    simulateGame();

    return 0;
}

