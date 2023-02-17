/** *********************************************************************
 * @file
 *
 * @brief Takes in a console or file input with board size and starting 
 *       position(s) and outputs corresponding knight's tour solution(s).
 ***********************************************************************/

 /** ********************************************************************
 *
 * @mainpage Take Home Programming Exam 3 - The Knight's Tour
 *
 * @section course_section Course Information
 *
 * @authors Keiran Berry
 *
 * @date April 23, 2022
 *
 * @par Instructor:
 *         Prof. Schrader
 *
 * @par Course:
 *         CSC 215 - Section 2 - 1:00 pm
 *
 * @par Location:
 *         Classroom - Room 329
 *
 * @section program_section Program Information
 *
 * @details This program will take in either a console input or a file 
 * input and find a solution for the corresponding knight's tour. The 
 * console input can solve one knight's tour, and the file input can 
 * solve as many as provided in the file. 
 * 
 * If no command line arguments are provided, then the program will 
 * output a menu to the screen and allow the user to select the board's 
 * size and starting position. Initially the size and starting position 
 * are set to 8x8 and (7,7), respectively. If the user reduces the size of 
 * the board and the starting position is no longer valid, then the 
 * starting position will default to the bottom-right corner of the new 
 * board unless specified by the user. 
 * 
 * If a file name is provided on the command line, then the information 
 * from the file (board size and starting position) will be read in and 
 * the knight's tour will be solved. This process will loop until there 
 * are no more knight's tours to be solved from the file. 
 * 
 * In either case, the knight's tour is solved by dynamically allocating 
 * a two-dimensional array to simulate the board and each move is tested 
 * in a brute force algorithm, moving in a clockwise direction. If there 
 * are no remaining moves for the knight to make and a solution has not 
 * yet been found, then the knight will move back and try again until a 
 * solution has been found. 
 * 
 * The corresponding solution will then be output to either the console 
 * or a file named "Solutions.tours", depending upon how the information 
 * was input. If there is no solution to the knight's tour which was 
 * requested, then "No solutions for this case." will be output.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> thpe3.exe
        
        Example: A menu will be output and can be interacted with to 
                 change the knight's tour which will be solved. The 
                 syntax to provide information to the console is in 
                 the following example: 

                 To change board size to 5x5, input "5" after choosing 
                 the first option from the menu

                 To change starting location to (2,4), input "2 4" after 
                 choosing the second option from the menu.

                 Choose the third option from the menu in order to generate 
                 a solution to the knight's tour.

   c:\> thpExam1.exe inputfile

        inputfile - the name of the file containing the knight's tour 
                    to be solved. This should include extensions and each 
                    knight's tour should be formatted as follows:

        Example: Board size of 5x5 and starting position of (2,4) would be 
           
                 5
                 2 4

                 in the file.
        
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug  Inputs to the console menu can stack if the first one is a valid 
 * option. An example of this is inputting "2 4 2" immediately in the 
 * menu will instantly change the starting position to (4,2). This may 
 * not cause problems for many users, but it was worth noting.
 * 
 * @par Modifications and Development Timeline:
   @verbatim
   Date          Modification
   ------------  --------------------------------------------------------
   Apr 8, 2022    Begun work on the program
   Apr 23, 2022   Completed work on the program
   Full list of commits and modifications available in Gitlab commit log
   @endverbatim

   Gitlab commit log, <a href = "https://gitlab.cse.sdsmt.edu/101080740/
   csc215s22programs/-/commits/master" target="_blank">
   Click Here.</a>
 *
 ***********************************************************************/
#pragma once
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>

using namespace std;

/** ********************************************************************
* @brief Structure to be filled in with information on the board and 
* the knight's position
***********************************************************************/
struct knight
{
/** ********************************************************************
* @brief Int to be filled in with the current row that the knight is 
* occupying on the board 
***********************************************************************/
    int currRow = 11;
/** ********************************************************************
* @brief Int to be filled in with the current column that the knight is
* occupying on the board
***********************************************************************/
    int currCol = 11;
/** ********************************************************************
* @brief Int to be filled in with the prospective next row the knight 
* will move to
***********************************************************************/
    int nextRow;
/** ********************************************************************
* @brief Int to be filled in with the prospective next column the 
* knight will move to
***********************************************************************/
    int nextCol;
/** ********************************************************************
* @brief Int to be filled in with the total rows which the board will 
* have
***********************************************************************/
    int totRow = 12;
/** ********************************************************************
* @brief Int to be filled in with the total columns which the board 
* will have
***********************************************************************/
    int totCol = 12;
/** ********************************************************************
* @brief A dynamically allocated two-dimensional array to simulate 
* the chess board which the knight will be on
***********************************************************************/
    int** board;
/** ********************************************************************
* @brief The actual size of the board, disregarding the padding on 
* either side. This is used to accurately retrieve information on 
* board size from the menu, and is an integer
***********************************************************************/
    int boardSize = 8;
/** ********************************************************************
* @brief Int to be filled in with the starting row of the knight 
***********************************************************************/
    int startX = 7;
/** ********************************************************************
* @brief Int to be filled in with the starting column of the knight
***********************************************************************/
    int startY = 7;
/** ********************************************************************
* @brief An integer array containing the values with which the row that 
* the knight is on will change with each prospective move
***********************************************************************/
    int moveRow[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
/** ********************************************************************
* @brief An integer array containing the values with which the column 
* that the knight is on will change with each prospective move
***********************************************************************/
    int moveCol[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

};

/************************************************************************
 *                         Function Prototypes
 ***********************************************************************/
bool openInput(ifstream& file, string fileName);
bool openOutput(ofstream& file, string fileName);
void allocArray(knight& knt);
void deleteDArray(knight& knt);
void initialArray(knight& knt);
void menu(knight& knt);
void printBoard(knight& knt);
void printFile(knight& knt, ostream& out, int tour);
bool knightsPath(knight& knt, int move, bool& solution);



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This is the starting point to the program.  If there is a command line 
 * argument, then the program will open the file, read in the information 
 * from it and solve the knight's tours, returning the solutions to an 
 * output file named "Solutions.tours". If there are no command line 
 * arguments, then the program will output a menu for the user to 
 * input their selected board size and starting position, and then the 
 * solution to the knight's tour requested will be output to the console. 
 * In either case, if there is no solution for the knight's tour in 
 * question, then "No solutions for this case." will be output.
 *
 * @param[in] argc - the number of arguments from the command prompt.
 * @param[in] argv - a 2d array of characters containing the arguments.
 *
 * @returns 0 program performed properly and solution was output.
 * @returns 0 and error message - something went wrong, see error.
 *
 * @verbatim
   see usage statement above.
   @endverbatim
 *
 ***********************************************************************/
int main(int argc, char** argv)
{
    knight kn;
    bool solFound = false;
    ifstream input;
    ofstream output;
    int nums;
    int i = 1;

    if (argc != 1 && argc != 2)//if num of args is incorrect, output usage 
    {
        cout << "Usage: thpe3.exe" << endl;
        cout << "OR: thpe3.exe tourfile" << endl;
    }

    if (argc == 1)                  //if no file from console
    {
        menu(kn);                   //run menu function
        allocArray(kn);             //allocate array 
        initialArray(kn);           //initialize array with -1s and 0s
        kn.currRow = kn.startX + 2; //starting x is startX + 2 due to pad
        kn.currCol = kn.startY + 2; //starting y is startY + 2 due to pad
        kn.board[kn.currRow][kn.currCol] = 1; //first spot on board
        if (knightsPath(kn, 2, solFound) == false)//if no solution, say so
        { 
            cout << endl << "No solutions for this case." << endl;
        }
        else
        { 
            printBoard(kn);//if there is a solution, print it to console
        }
        deleteDArray(kn); //clean up
    }

    if (argc == 2) //if there is a file to take in
    {
        if (openInput(input, argv[1]) == false) //open file
        { 
            cout << "Error opening input file: " << argv[1] << endl;
            return 0;//if it didnt open, say so
        }
        if (openOutput(output, "Solutions.tours") == false) //open output
        { 
            cout << "Error opening output file" << endl;
            return 0; //if it didnt open, say so
        }

        while (input >> nums) //while there is information in the file
        {
            kn.boardSize = nums; //get board size
            kn.totCol = kn.boardSize + 4; 
            kn.totRow = kn.boardSize + 4;
            input >> kn.startX; //get starting row and col
            input >> kn.startY;
            allocArray(kn); //allocate array
            initialArray(kn); //initialize array
            kn.currRow = kn.startX + 2;
            kn.currCol = kn.startY + 2;
            kn.board[kn.currRow][kn.currCol] = 1;
            
 
            if (knightsPath(kn, 2, solFound) == false)
            { 
                output << "Tour: #" << i << endl;//if no solution, say so
                output << "          " << kn.boardSize << "x" << kn.boardSize <<
                " starting at (" << kn.startX << "," << kn.startY << ")" << endl;
                output << endl << "          ";
                output << "No solutions for this case." << endl << endl << endl;
            }
            else //otherwise print out the solution to the file
            { 
                printFile(kn, output, i);
            }
            i++; //increment tour number
            deleteDArray(kn); //clean up
            solFound = false; //reset solFound
        }
        input.close(); //clean up files
        output.close();
    }

    return 0;
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description:
 *  Checks that the input file has opened successfully.
 *
 *  @param[in] file - The ifstream file input.
 *
 *  @param[in] fileName - The name of the file which is being checked.
 *
 *  @returns  A boolean value, whether the file has opened successfully
 *           or not.
 *
 *
 *  @par Example
 *  @verbatim
    //returns true if the file has opened successfully

    //returns false if the file has not opened

    @endverbatim
 ************************************************************************/
bool openInput(ifstream& file, string fileName)
{
    file.open(fileName);
    //open file, and if it opened successfully return true
    if (file.is_open() == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description:
 *  Checks that the output file has opened successfully.
 *
 *  @param[in] file - The ofstream file input.
 *
 *  @param[in] fileName - The name of the file which is being checked.
 *
 *  @returns  A boolean value, whether the file has opened successfully
 *           or not.
 *
 *
 *  @par Example
 *  @verbatim
    //returns true if the file has opened successfully

    //returns false if the file has not opened

    @endverbatim
 ************************************************************************/
bool openOutput(ofstream& file, string fileName)
{
    file.open(fileName, ios::app);
    //open output file, and return true if opened
    if (file.is_open() == true)
    {
        return true;
    }

    else
    {
        return false;
    }

}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the total rows and columns from the knight 
 * structure and dynamically allocates a two-dimensional array which 
 * will be stored inside knt.board. The total rows and columns are each 
 * two larger than the size which was input, so that there can be 
 * padding to prevent the knight from stepping off the board.
 *
 * @param[in] knt - the knight structure to be allocated into.
 *
 * @par Example:
   @verbatim
   knight knt; //knt.totRow and knt.totCol have been filled using the 
               //board size from the console/file
   allocArray(knt);
   //the board portion of the structure now contains a two-dimensional 
   //dynamic array
   @endverbatim

 ***********************************************************************/
void allocArray(knight& knt)
{
    int i;
    bool alloc = true;
    //allocate array with size of the board plus border
    knt.board = new(nothrow) int * [knt.totRow];
    if (knt.board == nullptr)
    {
        deleteDArray(knt);
        alloc = false;
    }

    //add arrays to each spot to make it 2d
    for (i = 0; i < knt.totRow; i++)
    {
        knt.board[i] = new(nothrow) int[knt.totCol];
        if (knt.board[i] == nullptr)
        {
            deleteDArray(knt);
            alloc = false;
        }
    }

    //if allocation failed at any point, output error message and exit
    if (alloc = false)
    {
        cout << "Memory Allocation Error" << endl;
        exit(0);
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the dynamic array from the structure, and
 * deletes the dynamically allocated array. In order to avoid memory
 * leaks, this function deletes each row in the array before deleting
 * the whole thing. This function is to be called at the end of the
 * function, midway through if there has been a problem and the
 * arrays have already been allocated, or in between knight's tours 
 * being solved from a file input.
 *
 * @param[in] knt - the knight structure to delete the array from.
 *
 * @par Example:
   @verbatim
   knight knt; //all areas have been filled
   deleteDArray(knight);
   //the dynamically allocated array in knt.board will be deleted
   @endverbatim

 ***********************************************************************/
void deleteDArray(knight& knt)
{
    int i;

    for (i = 0; i < knt.totRow; i++)
    {   //delete each row in the array first
        delete[] knt.board[i];
    }

    //delete the whole array now
    delete[] knt.board;
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the dynamic array from the structure and 
 * initializes it so that the knight's tour can be solved. A border with 
 * width 2 surrounds the outermost parts of the array, and the actual 
 * board size is contained within the border. This border prevents the 
 * knight from overstepping the bounds of the array when trying potential 
 * moves. The portion of the array which acts as the actual board is 
 * filled with zeros, so that as the knight moves it can tell which 
 * spaces are unused. The border is filled with -1's.
 *
 * @param[in] knt - the knight structure containing the array to be filled.
 *
 * @par Example:
   @verbatim
   knight knt; //knt.board's array has already been allocated
   initialArray(knt);
   //the dynamically allocated array will be initialized with -1's and 0's
   @endverbatim

 ***********************************************************************/
void initialArray(knight& knt)
{
    int i;
    int j;

    for (i = 0; i < 2; i++) //fill in border of size 2 with -1s
    {
        for (j = 0; j < knt.totCol; j++)
        {
            knt.board[i][j] = -1;
        }
    }

    for (i = knt.totRow - 1; i > knt.totRow - 3; i--)
    {
        for (j = 0; j < knt.totCol; j++)
        {
            knt.board[i][j] = -1;
        }
    }

    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < knt.totRow; i++)
        {
            knt.board[i][j] = -1;
        }
    }

    for (j = knt.totCol - 1; j > knt.totCol - 3; j--)
    {
        for (i = 0; i < knt.totRow; i++)
        {
            knt.board[i][j] = -1;
        }
    }
    //everything that was not part of the border gets a 0 
    for (i = 0; i < knt.totRow; i++)
    {
        for (j = 0; j < knt.totCol; j++)
        {
            if (knt.board[i][j] != -1)
            {
                knt.board[i][j] = 0;
            }
        }
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function outputs a menu to the console if no command line 
 * argument containing a file name was provided. This gives the user 
 * the opportunity to customize the knight's path which they want solved. 
 * A menu will be output to the screen, asking the user to select whether 
 * they would like to change the size of the board, the starting position, 
 * or run the program and find a solution. 
 * 
 * @param[in] knt - the knight structure to be filled with information.
 *
 * If an invalid board size is provided, then a message will be output to 
 * the console and the user will be provided with a new menu to try again. 
 * If an invalid starting position is provided, the same thing will happen.
 * In the event that changing board size makes a starting position no 
 * longer valid, then the starting position will automatically change 
 * to the bottom-right corner of the new board. As inputs are made, the 
 * menu will update to show the user the current status of the tour. 
 * 
 * When the third option is selected, no more menus will be output and the 
 * program will run.
 *
 * @par Example:
   @verbatim
   knight knt; //default board size is 8 and default starting position
               //is (7,7)
   menu(knt);
   //1) Change board size from 8x8
   //2) Change starting location from [7, 7]
   //3) Exit and Solve Tour
   //Enter Choice:
   //
   //will be output to the console
   @endverbatim

 ***********************************************************************/
void menu(knight& knt)
{
    int in = 0;
    int size;
    int x;
    int y;

    //output initial menu
    cout << "1) Change board size from " << knt.boardSize << "x"
        << knt.boardSize << endl;
    cout << "2) Change starting location from [" << knt.startX
        << ", " << knt.startY << "]" << endl;
    cout << "3) Exit and Solve Tour" << endl;
    cout << "Enter Choice: ";
    cin >> in;

    while (in != 3) //while the user doesnt say to run the program
    {
        if (in != 1 && in != 2)
        { //if the option requested doesnt exist, say so
            cout << endl << "Invalid option selected" << endl;
        }

        if (in == 1)
        { //if they want to change board size output that menu
            cout << endl << "Enter the size of the NxN Board (>3): ";
            cin >> size;
            if (size <= 3)
            { //make sure size entered is valid
                cout << endl << "Invalid board size provided" << endl;
            }
            else
            { //set board size and total rows and cols
                knt.boardSize = size;
                knt.totRow = size+4;
                knt.totCol = size+4;
            }
            if (knt.boardSize < 8)
            { 
                knt.startX = knt.boardSize - 1;
                knt.startY = knt.boardSize - 1;
            }
        }
        else if (in == 2)
        { //output starting coords menu
            cout << endl << "Enter Starting Coordinates [ row , col ]: ";
            cin >> x;
            cin >> y;
            if (x > knt.boardSize-1 || y > knt.boardSize-1)
            { //if the starting pos is invalid then say so
                cout << endl << "Invalid starting position provided" << endl;
            }

            else
            { //otherwise set the starting position
                knt.startX = x;
                knt.startY = y;
            }
        } 
        //give them a new menu until they want to run the program
        cout <<  endl << "1) Change board size from " << knt.boardSize << "x"
            << knt.boardSize << endl;
        cout << "2) Change starting location from [" << knt.startX
            << ", " << knt.startY << "]" << endl;
        cout << "3) Exit and Solve Tour" << endl;
        cout << "Enter Choice: ";
        cin >> in;
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function is to be used if the input for the knight's tour was 
 * done through the console. The solution to the knight's tour will be 
 * output if it exists, and if it doesn't then "No solutions for this 
 * case." will be output to the console.
 * 
 * This function will go through the board array and output each number 
 * which is not a -1. This will result in the solution being output but 
 * not the border which was used to pad the array.
 *
 * @param[in] knt - the knight structure containing the board to be output.
 *
 * @par Example:
   @verbatim
   knight knt; //knt.board contains the solution already
               //board is size 5 and starting position is (2,4)
   printBoard(knt);
   //Tour: #1
   //       5x5 starting at (2,4)


   //       25  16   5  10  19
   //        4  11  18  15   6
   //       17  24   9  20   1
   //       12   3  22   7  14
   //       23   8  13   2  21
   //
   //will be output to the console
   @endverbatim

 ***********************************************************************/
void printBoard(knight& knt)
{
    int i, j; 
    //since it's console, there will only ever be one tour
    //after that, output the solution with pretty formatting
    cout << endl << "Tour: #1" << endl;
    cout << "            " << knt.boardSize << "x" << knt.boardSize <<
        " starting at (" << knt.startX << "," << knt.startY << ")";
    cout << endl << "          ";

    for (i = 0; i < knt.totRow; i++)
    {
        for (j = 0; j < knt.totCol; j++)
        {
            if (knt.board[i][j] != -1)
            {
                cout << setw(4) << right << knt.board[i][j];
            }
        }

        cout << endl << "          ";
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function is to be used if the input for the knight's tour was
 * done through a file. The solution to each knight's tour will be
 * output if they exist, and if it doesn't then "No solutions for this
 * case." will be output to the file.
 *
 * This function will go through the board array and output each number
 * which is not a -1. This will result in the solution being output but
 * not the border which was used to pad the array.
 * 
 * This can be repeated any amount of times to output more solutions 
 * to the same "Solution.tours" file. If the file already exists, any 
 * solutions will be appended to the end of the file instead of 
 * overwriting existing information.
 *
 * @param[in] knt - the knight structure containing the board to be output.
 *
 * @param[in] out - the ostream file to be output to.
 * 
 * @param[in] tour - the tour number which is being output.
 * 
 * @par Example:
   @verbatim
   knight knt; //knt.board contains the solution already
               //board is size 5 and starting position is (2,4)
   printBoard(knt);
   //Tour: #1
   //       5x5 starting at (2,4)


   //       25  16   5  10  19
   //        4  11  18  15   6
   //       17  24   9  20   1
   //       12   3  22   7  14
   //       23   8  13   2  21
   //
   //will be output to the console
   //tour number will increment by one each time a new tour is output
   @endverbatim

 ***********************************************************************/
void printFile(knight& knt, ostream& out, int tour)
{
    int i, j;
    //with the file, figure out what tour number it is and add it
    //then output everything else formatted nicely with space 
    //for the next tour to not look bad underneath
    out << "Tour: #" << tour << endl;
    out << "            " << knt.boardSize << "x" << knt.boardSize <<
        " starting at (" << knt.startX << "," << knt.startY << ")";
    out << endl << "          ";

    for (i = 0; i < knt.totRow; i++)
    {
        for (j = 0; j < knt.totCol; j++)
        {
            if (knt.board[i][j] != -1)
            {
                out << setw(4) << right << knt.board[i][j];
            }
        }

        out << endl << "          ";
    }

    out << endl << endl << endl;
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description:
 * Takes in a knight structure and starts at its starting point, choosing 
 * valid moves starting at the "2 up, 1 right" move and moving in a 
 * clockwise direction. Valid moves continue to be chosen until either the 
 * tour is solved or there are no more moves. If there are no more moves and 
 * the tour has not been solved, then the knight will backtrack until there 
 * is an unused valid move and try again until it finds a solution. 
 * 
 * If every move has been tried and no solution has been found, the knight's 
 * tour cannot be solved using the given information and the function will 
 * return false. Otherwise, once the knight is on a move that is higher than 
 * the number of squares on the board, then knt.board will contain the solution
 * to the knight's tour and the function will return true. It is worth noting 
 * that this function will recursively call itself each time it works on a 
 * new move.
 *
 *  @param[in] knt - The knight structure to solve the tour from.
 *
 *  @param[in] move - The move number which the knight is on.
 *
 *  @param[in] solution - Whether a solution was found, used in main.
 * 
 *  @returns  A boolean value, whether there is a solution to the knight's 
 *            tour or not.
 *
 *
 *  @par Example
 *  @verbatim
    //returns true if the knight's tour was solved
    //knt.board now contains the solution for the knight's tour

    //returns false if there is no solution for the knight's tour

    @endverbatim
 ************************************************************************/
bool knightsPath(knight& knt, int move, bool& solution)
{
    int i;
    int boardSq = knt.boardSize * knt.boardSize;

    //if the tour has been solved, just leave
    if (move == boardSq + 1)
    {
        solution = true;
    }

    if (solution == true)
    {
        return true;
    }

    //go through each possible move and see if it is valid
    //this acts as its own record of what has been used
    //so no used array is necessary

    for (i = 0; i < 8; i++)
    {
        knt.nextRow = knt.currRow + knt.moveRow[i];
        knt.nextCol = knt.currCol + knt.moveCol[i];

        if (knt.board[knt.nextRow][knt.nextCol] == 0)
        {
            knt.currRow = knt.nextRow;
            knt.currCol = knt.nextCol;
            knt.board[knt.currRow][knt.currCol] = move;
            //recursive call

            if (knightsPath(knt, move + 1, solution) == true)
            {
                return true;
            }

            //if it wasnt the solution, go back and try again
            knt.board[knt.currRow][knt.currCol] = 0;
            knt.currRow = knt.currRow - knt.moveRow[i];
            knt.currCol = knt.currCol - knt.moveCol[i];
        }
    }

    return false;
}
