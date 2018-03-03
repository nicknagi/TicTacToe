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
bool isAIPlaying = true;

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
    //Check if move index within bounds
    if ((xLoc >= 0 && yLoc >= 0) && (xLoc < gridDimensions && yLoc < gridDimensions)) {
        //Check if spot empty
        if (mainGrid[xLoc][yLoc] == 0  ) {
            mainGrid[xLoc][yLoc] = TurnSymbol;
            printGrid();
            return true;
        }
        else {
            if(!(isAIPlaying == true && whosTurn == 2))
            cout << "Invalid move! try Again" << endl;
            return false;
        }
    }
    else {
        if(!(isAIPlaying == true && whosTurn == 2))
        cout << "Out of bounds! try Again" << endl;
        return false;
    }

}

//returns 1 for a win, 0 for a loss and 2 for a draw
int checkEndgame(){

    //bool isEndgame = false;

    //Check for rows
    for (int i = 0; i < gridDimensions; ++i) {
        for (int j = 0; j < gridDimensions - 1; ++j) {
            if (mainGrid[j][i] == 0) break;
            if (mainGrid[j][i] != mainGrid[j + 1][i]) break;
            if(j == gridDimensions - 2) return 1;
        }
    }

    //Check for columns
    for (int i = 0; i < gridDimensions; ++i) {
        for (int j = 0; j < gridDimensions - 1; ++j) {
            if (mainGrid[i][j] == 0) break;
            if (mainGrid[i][j] != mainGrid[i][j + 1]) break;
            if(j == gridDimensions - 2) return 1;
        }
    }

    //Check for negative sloped diagonal
    for (int i = 0; i < gridDimensions-1; ++i) {
            if (mainGrid[i][i] == 0) break;
            if (mainGrid[i][i] != mainGrid[i + 1][i + 1]) break;
            if(i == gridDimensions - 2) return 1;
    }

    int j = 0;
    //Check for positive sloped diagonal
    for (int i = gridDimensions - 1; i >= 1; i--) {
            if (mainGrid[j][i] == 0) break;
            if (mainGrid[i][j] != mainGrid[i-1][j + 1]) break;
            if(j == gridDimensions - 2) return 1;
            j++;
    }

    return  0;
}

//Computer AI logic
//Randomly play a move
void AIMove (int &xLoc, int &yLoc){
    srand(time(NULL));
    xLoc = rand() % (gridDimensions);
    yLoc = rand() % (gridDimensions);
}

//Simulates turn based gameplay among the two players
void simulateGame(){
    while(!isWin) {
        int xLoc = 0, yLoc = 0;

        if (!isAIPlaying) {

            if (whosTurn == 1) {
                cout << "Player 1's (X) Turn: " << endl;
                cout << "Enter the x and y coordinates: ";
                cin >> xLoc >> yLoc;

                if (playerTurn(X, xLoc, yLoc)){
                    if(checkEndgame() == 1){
                        cout << "Player 1 Won!!" << endl;
                        isWin = true;
                    }
                    else whosTurn = 2;
                }

            } else if (whosTurn == 2) {
                cout << "Player 2's (O) Turn: " << endl;
                cout << "Enter the x and y coordinates: ";
                cin >> xLoc >> yLoc;

                if (playerTurn(O, xLoc, yLoc)){
                    if(checkEndgame() == 1){
                        cout << "Player 2 Won!!" << endl;
                        isWin = true;
                    }
                    else whosTurn = 1;
                }
            }
        }
        else{
            if (whosTurn == 1) {
                cout << "Player 1's (X) Turn: " << endl;
                cout << "Enter the x and y coordinates: ";
                cin >> xLoc >> yLoc;

                if (playerTurn(X, xLoc, yLoc)){
                    if(checkEndgame() == 1){
                        cout << "Player 1 Won!!" << endl;
                        isWin = true;
                    }
                    else{
                        whosTurn = 2;
                        //Tp prevent multiple couts as AI is random atm
                        cout << "AI's (O) Turn: " << endl;
                    }
                }

            } else if (whosTurn == 2) {
                AIMove(xLoc, yLoc);

                if (playerTurn(O, xLoc, yLoc)){
                    if(checkEndgame() == 1){
                        cout << "Computer Won!!" << endl;
                        isWin = true;
                    }
                    else whosTurn = 1;
                }
            }
        }
    }

    cout << "Game Over!!" << endl;

}



/*
 * TO DO:
 * More dynamic simulate game (by allowing user(s) to select who goes first)
 * AI Implementation
 * GUI Implementation
 * */
int main() {
    initializeGrid();

    int temp, temp2;
    AIMove(temp, temp2);

    simulateGame();

    return 0;
}

