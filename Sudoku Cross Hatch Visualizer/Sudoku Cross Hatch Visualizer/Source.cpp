#include <iostream>

using namespace std;

int puzzleBoard[9][9] =
{
    {5, 3, 4, 0, 7, 0, 9, 1, 2},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 0, 0, 5},
    {3, 4, 5, 0, 8, 0, 0, 7, 9},
};

void sudokuReset(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            grid[i][j] = 0;
        }
    }
}
void sudokuPrint(int grid[9][9])
{
    cout << "-------------------" << endl;
    for (int y = 0; y < 9; y++)
    {
        cout << '|';
        for (int x = 0; x < 9; x++)
        {
            cout << grid[y][x];
            if (x % 3 == 2)
                cout << '|';
            else cout << ' ';
        }
        if (y % 3 == 2)
        {
            cout << endl << "-------------------";
        }
        cout << endl;
    }
}

void sudokuMarkRowAndCol(int grid[9][9], int x, int y)
{
    for (int i = 0; i < 9; i++) //marks column
    {
        grid[x][i] = 1;
    }

    for (int j = 0; j < 9; j++) //marks row
    {
        grid[j][y] = 1;
    }
}

void sudokuCrossHatch(int sudoku[9][9], int crosshatch[9][9], int val)
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (sudoku[x][y] == val)
            {
                sudokuMarkRowAndCol(crosshatch, x, y);
            }
        }
    }
}

int main()
{
    //declarations
    int val;
    int crossHatch[9][9];

    //get user input
    cout << "Enter the number you wish to crosshatch: ";
    cin >> val;
    cout << endl;

    //output
    cout << "Cross Hatch before:";
    cout << endl;
    sudokuReset(crossHatch);
    sudokuPrint(crossHatch);
    cout << endl << endl;

    cout << "Puzzle Contents:";
    cout << endl;
    sudokuPrint(puzzleBoard);
    cout << endl << endl;

    cout << "Cross Hatch after:";
    cout << endl;
    sudokuCrossHatch(puzzleBoard, crossHatch, val);
    sudokuPrint(crossHatch);

    return 0;
}
