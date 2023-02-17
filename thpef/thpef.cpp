/** *********************************************************************
 * @file
 *
 * @brief Takes in either seeds or files to fill 2 players hands with 
 * a deck of cards each, then plays the card game war with the two 
 * hands. Outputs results to either a file or console, depending on input.
 ***********************************************************************/

 /** ********************************************************************
 *
 * @mainpage Take Home Programming Exam Final - War
 *
 * @section course_section Course Information
 *
 * @authors Keiran Berry
 *
 * @date May 1, 2022
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
 * @details This program will take in either seeds or files containing 
 * information with which to fill in queues containing a deck of cards 
 * for each player. These hands which the players possess will be used 
 * to play the card game War. The card at the front of the queue for 
 * each player is set onto their stack, and compared to the other 
 * player's card. The player whose card has the higher face value wins 
 * the round, and the player gets all of the cards from the round. 
 * The cards from the losing player's stack are queued first, then the 
 * cards from the winning player are queued back into their hand. 
 * 
 * In the event that the cards tie, each player puts down three more 
 * cards and then the top cards are compared. This goes on as long as 
 * the top cards tie, and once a player wins the hand they get all 
 * of each stack in the method described above. In the event that a 
 * "war" breaks out and one player runs out of cards before three 
 * cards have been put down, each player puts down the number of 
 * cards that the player who ran out put down. If there is still a 
 * tie, each player gets their cards queued back into their hand 
 * and they try again.
 * 
 * Once a player has all of the cards in their queue and the other 
 * player has an empty queue, the number of rounds played and the 
 * hands of each player are output. If at startup the user elected 
 * to utilize the included random number generator and input seeds 
 * to make the hands with, then the information is output to the 
 * console. If the user elected to use files containing card values, 
 * then the results are output to a file called "results.rst".
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\>thpef.exe -s playerOneSeed playerTwoSeed
   Or: thpef.exe -f playerOneFile playerTwoFile

   -s - seeds will be used for input
   -f - files will be used for input
   playerOneSeed - the seed number to take player 1's hand from
   playerTwoSeed - the seed number to take player 2's hand from
   playerOneFile - the file to take player 1's hand from
   playerTwoFile - the file to take player 2's hand from

   @endverbatim
 *
 * @par Modifications and Development Timeline:
   @verbatim
   Date          Modification
   ------------  --------------------------------------------------------
   Apr 25, 2022    Begun work on the program
   May  1, 2022    Completed work on the program
   Full list of commits and modifications available in Gitlab commit log
   @endverbatim

   Gitlab commit log, <a href = "https://gitlab.cse.sdsmt.edu/101080740/
   csc215s22programs/-/commits/master" target="_blank">
   Click Here.</a>
 *
 ***********************************************************************/

#define CATCH_CONFIG_RUNNER

#include "thpef.h"
#include "..\\catch.hpp"

/** *********************************************************************
* @brief Whether testcases will run
************************************************************************/
const bool RUNCATCH = false;



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This is the starting point to the program.  The command line arguments 
 * will be read in and depending on the option selected the program will 
 * take that route of filling in the queues which represent the players' 
 * decks of cards. If an invalid argument, file, or number of arguments 
 * were provided, then the usage statement will be output. Otherwise, 
 * the program will fill in the hands of the players using whatever 
 * method was requested and play the game of War using the cards from 
 * the players. 
 * 
 * War is played using the template queue written in thpef.h, and the 
 * STL stack. See program header for full information on the rules of 
 * the game. After the game has concluded, the number of rounds played 
 * as well as the hands of each player will be output. Each card is 
 * formatted before being output, so that an ace of hearts will be 
 * "AH" instead of "00", for example.
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
    ifstream input, input2;
    ofstream output;
    unsigned int s1, s2;
    int rounds;
    queue<card> play1, play2;
    string option = argv[1];

    Catch::Session session;
    int result;

    if (RUNCATCH)
    {
        result = session.run();
        if (result != 0)
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
    }

    if (argc != 4) //if incorrect number of arguments
    {
        usageStatement(); //give usage statement
        return 0;
    }

    if (option == "-f") //file input
    {
        if (openInput(input, argv[2]) == false)
        {   //if player 1 file doesnt open, say so
            cout << "Error opening player 1 file: " << argv[2] << endl;
            return 0;
        }
        if (openInput(input2, argv[3]) == false)
        {   //if player 2 file doesnt open, say so
            cout << "Error opening player 2 file: " << argv[3] << endl;
            return 0;
        }
        if (openOutput(output, "results.rst") == false)
        {   //if output file doesnt open, say so
            cout << "Error opening output file" << endl;
            return 0;
        }
        file(input, play1); //fill hands from files
        file(input2, play2);
    }

    else if (option == "-s") //seed input
    {
        s1 = stoi(argv[2]);
        s2 = stoi(argv[3]);
        dealHands(play1, s1); //deal hands from seeds
        dealHands(play2, s2);
        
    }

    else //if neither seed nor file, its invalid, say so
    {
        cout << "Invalid option provided" << endl;
        usageStatement();
        return 0;
    }

    rounds = playGame(play1, play2); //play the game and return how many rounds
    if (option == "-s")
    {   //if from a seed, output it to console
        cOutput(play1, play2, rounds);
    }

    else
    {   //if from a file, output it to a file
        fOutput(play1, play2, rounds, output);
    }
    return 0;
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * Outputs a usage statement to the console if the incorrect number of
 * arguments has been provided, or there is otherwise an issue with the
 * arguments which have been input.
 *
 * @par Example:
   @verbatim
   Input: thpef.exe -s 10101 20202
   Output: nothing

   Input: thpef.exe thisisanincorrectnumberofarguments
   Output: Usage: thpef.exe -s playerOneSeed playerTwoSeed
           Or:    thpef.exe -f playerOneFile playerTwoFile
   @endverbatim
 ***********************************************************************/
void usageStatement()
{
    //if anything is incorrect from the console input, show how its done
    cout << "Usage: thpef.exe -s playerOneSeed playerTwoSeed" << endl;
    cout << "Or:    thpef.exe -f playerOneFile playerTwoFile" << endl;
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
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
 *  @par Description
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
    file.open(fileName);
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



/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Deals random deck based on the seed from the console. This is done 
 *  with the -s argument. Takes the card value and determines its face value 
 *  and suit based on the card value itself before filling the card queue with 
 *  each card.
 *
 *  @param[in] hand - The card queue which the deck will be dealt into.
 *
 *  @param[in] seedIn - The seed from the console.
 *
 *  @par Example
 *  @verbatim
    queue<card> q;
    int seed = 12;

    dealHands(q, seed);

    //results in 52 unique cards being dealt into q with seed 12

    @endverbatim
 ************************************************************************/
void dealHands(queue<card>& hand, int seedIn)
{
    default_random_engine generator(seedIn);
    uniform_int_distribution<int> distribution(0, 51);

    int i = 0;
    int used[52] = { 0 };
    int aCard;
    card fCard;

    while (i < 52)
    {
        //get card from generator
        aCard = distribution(generator);
        if (used[aCard] == 0)
        {
            //fill in face value
            fCard.faceValue = aCard % 13;
            //fill in suit
            fCard.suit = aCard / 13;
            //put card into hand
            hand.enque(fCard);
            //mark card as used
            used[aCard] = 1;
            i++;
        }
    }
}



/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Deals hands using the cards whose data is available in the input file. 
 *  Takes the card value and determines its face value and suit based on 
 *  the card value itself before filling the card queue with each card. 
 *  This is used with the -f argument.
 *
 *  @param[in] input - the ifstream file to read the cards from.
 *
 *  @param[in] player - The card queue which the deck will be dealt into.
 *
 *  @par Example
 *  @verbatim
    queue<card> q;
    ifstream input;
    //input file is already open

    file(input, q);

    //q now contains all 52 cards from the input file

    @endverbatim
 ************************************************************************/
void file(ifstream& input, queue<card>& player)
{
    int nums;
    card aCard;
    while (input >> nums)
    {
        aCard.faceValue = nums % 13;
        aCard.suit = nums / 13;
        player.enque(aCard);
    }
}




/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Used if there is a tie in the parts of the game where the players 
 *  put down one card at a time. Takes the queues and stacks from each 
 *  player and simulates putting down three cards, if they have enough, 
 *  before determining the winner of the stack. This function can 
 *  recursively call itself if there is another tie.
 *
 *  @param[in] player1 - the card queue representing player 1's hand
 *
 *  @param[in] player2 - the card queue representing player 2's hand
 * 
 *  @param[in] p1 - the card stack representing player 1's pile
 * 
 *  @param[in] p2 - the card stack representing player 2's pile
 *
 *  @par Example
 *  @verbatim
    //playRound results in a draw
    //equal is called
    //results are passed back to playRound so that playGame can progress

    @endverbatim
 ************************************************************************/
void equal(queue<card>& player1, queue<card>& player2,
           stack<card>& p1, stack<card>& p2)
{
    int i;
    card currp1;
    card currp2;

    for (i = 0; i < 3 && !player1.isEmpty() && !player2.isEmpty(); i++)
    {
        //pull 3 cards unless one runs out of cards
        player1.deque(currp1);
        player2.deque(currp2);
        p1.push(currp1);
        p2.push(currp2);
    }

    if (currp1 != currp2) //if the new cards are different
    {
        if (currp1 < currp2)
        {
            while (!p1.empty())
            {   //if player 2 won, give them the cards
                player2.enque(p1.top());
                p1.pop();
            }
            while (!p2.empty())
            {   
                player2.enque(p2.top());
                p2.pop();
            }
        }

        else
        {
            while (!p2.empty())
            {   //if player 1 won, give them the cards
                player1.enque(p2.top());
                p2.pop();
            }
            while (!p1.empty())
            {
                player1.enque(p1.top());
                p1.pop();
            }
        }
    }

    else if (player1.isEmpty() || player2.isEmpty())
    {   //if one of them ran out, give the cards back
        while (!p1.empty())
        {
            player1.enque(p1.top());
            p1.pop();
        }
        while (!p2.empty())
        {
            player2.enque(p2.top());
            p2.pop();
        }
        equal(player1, player2, p1, p2); //try again
    }

    else if(currp1 == currp2)
    {   //if the new cards are the same, try again
        equal(player1, player2, p1, p2);
    }
}



/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Used to play each individual round of war. Gives the winning player 
 *  the stacks of both players, and if there is a tie and a "war" breaks 
 *  out then the equal function is called to settle it. This function 
 *  is called for as many rounds as are played in the game, and is 
 *  called from the playGame function.
 *
 *  @param[in] player1 - the card queue representing player 1's hand
 *
 *  @param[in] player2 - the card queue representing player 2's hand
 *
 *  @par Example
 *  @verbatim
    //playGame is called
    //playRound is called
    //player 1 wins, gets player 2's stack and his own
    //playGame receives the new queues and playRound is called again
    //unless a player has won already

    @endverbatim
 ************************************************************************/
void playRound(queue<card>& player1, queue<card>& player2)
{
    stack<card> p1;
    stack<card> p2;
    card currp1;
    card currp2;

    player1.deque(currp1); //get the first cards
    player2.deque(currp2);
    p1.push(currp1); //put them on the stack
    p2.push(currp2);

    if (p1.top() > p2.top())
    {   //if player 1 wins, give them the cards
        giveCards(player1, p1, p2);
    }

    else if (p1.top() < p2.top())
    {   //if player 2 wins, give them the cards
        giveCards(player2, p2, p1);
    }

    else if (p1.top() == p2.top())
    {   //if theyre the same, call the equal function
        equal(player1, player2, p1, p2);
    }
}



/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Called when someone wins a round of war. This takes in the winner's 
 *  queue and both player's stacks, then enques the entire loser's stack 
 *  before enquing the entire winner's stack. The loser's hand does not 
 *  need to be called because all of the cards that they will have lost 
 *  have already been transferred from their queue to their stack.
 *
 *  @param[in] winner - the queue of the winner
 *
 *  @param[in] w - the stack of the winner
 * 
 *  @param[in] l - the stack of the loser
 *
 *  @par Example
 *  @verbatim
    //playRound is called
    //player 1 wins
    //player 1 enques all of player 2's stack
    //player 1 enques all of player 1's stack
    //the new queues can be used for the next round

    @endverbatim
 ************************************************************************/
void giveCards(queue<card>& winner, stack<card>& w, stack<card>& l)
{
    while (!l.empty())
    {   //give the winner the loser's pile first
        winner.enque(l.top());
        l.pop();
    }

    while (!w.empty())
    {   //give them their own cards back next
        winner.enque(w.top());
        w.pop();
    }
}



/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Used to play the whole game of war and count how many rounds were 
 *  played. Called in main to determine how many rounds were played and 
 *  receive the final queues of the players at the same time. This 
 *  function calls playRound until one of the queues is empty, and 
 *  increments a counter each time for the number of rounds.
 *
 *  @param[in] player1 - the card queue representing player 1's hand
 *
 *  @param[in] player2 - the card queue representing player 2's hand
 * 
 *  @returns An int value, how many rounds were played to find the winner.
 *
 *  @par Example
 *  @verbatim
    //playGame is called
    //playRound is called until one of the players has no cards and 
    //the other has all 104
    //the number of rounds is returned to main for output and the 
    //card queues contain the final values

    @endverbatim
 ************************************************************************/
int playGame(queue<card>& player1, queue<card>& player2)
{
    //initialize i to 0
    int i = 0;
    while (!player1.isEmpty() && !player2.isEmpty())
    {
        //while they both have cards, play war!
        playRound(player1, player2);
        i++;
    }

    //return i as the number of rounds played
    return i;
}



/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Outputs the queues of the players into the console. This is to be 
 *  used in the event that a -s input was used. The number of rounds 
 *  as well as the hands of the players will be output. An overloaded 
 *  operator is used to output the queues. Also dequeues to clear 
 *  dynamic memory.
 *
 *  @param[in] player1 - the card queue representing player 1's hand
 *
 *  @param[in] player2 - the card queue representing player 2's hand
 * 
 *  @param[in] rounds - the number of rounds played to reach a winner
 *
 *  @par Example
 *  @verbatim
    //player1 won and their hand is {AH, 9H, 8S, ..., 10H, 4C, KD}
    //game took 100 rounds
    //Output to console:
    //Player 1 wins after 100 rounds. 
    //Player 1 hand: AH 9H 8S ... 10H 4C KD
    //Player 2 hand: 

    @endverbatim
 ************************************************************************/
void cOutput(queue<card>& player1, queue<card>& player2, int rounds)
{
    if (player1.isEmpty())
    {
        //if player 1 has no cards, player 2 won, and output their cards
        cout << "Player 2 wins after " << rounds << " rounds." << endl;
        cout << "Player 1 Hand: " << endl;
        cout << "Player 2 Hand: " << endl << player2 << endl;
    }

    else
    {
        //if player 1 won, output their cards
        cout << "Player 1 wins after " << rounds << " rounds." << endl;
        cout << "Player 1 Hand: " << endl << player1 << endl;
        cout << "Player 2 Hand: " << endl;
    }

}



/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Outputs the queues of the players into the file. This is to be
 *  used in the event that a -f input was used. The number of rounds
 *  as well as the hands of the players will be output. An overloaded
 *  operator is used to output the queues. The output file is named 
 *  "results.rst". Also dequeues to clear dynamic memory.
 *
 *  @param[in] player1 - the card queue representing player 1's hand
 *
 *  @param[in] player2 - the card queue representing player 2's hand
 *
 *  @param[in] rounds - the number of rounds played to reach a winner
 * 
 *  @param[in] output - the ofstream output file to put the results in
 *
 *  @par Example
 *  @verbatim
    //player1 won and their hand is {AH, 9H, 8S, ..., 10H, 4C, KD}
    //game took 100 rounds
    //Output to file:
    //Player 1 wins after 100 rounds.
    //Player 1 hand: AH 9H 8S ... 10H 4C KD
    //Player 2 hand:

    @endverbatim
 ************************************************************************/
void fOutput(queue<card>& player1, queue<card>& player2, int rounds, 
    ofstream& output)
{
    if (player1.isEmpty())
    {   //if player 2 won, output their cards
        output << "Player 2 wins after " << rounds << " rounds." << endl;
        output << "Player 1 Hand: " << endl;
        output << "Player 2 Hand: " << endl << player2 << endl;
    }

    else
    {   //if player 1 won, output their cards
        output << "Player 1 wins after " << rounds << " rounds." << endl;
        output << "Player 1 Hand: " << endl << player1 << endl;
        output << "Player 2 Hand: " << endl;
    }

}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Compares two cards by looking at their face value. If the face value 
 *  of card one is less than that of card two, then true is returned.
 *
 *  @param[in] c1 - the card on the left side of the operator
 * 
 *  @param[in] c2 - the card on the right side of the operator
 *
 *  @returns  A boolean value, whether c1 is less than c2 or not.
 *
 *
 *  @par Example
 *  @verbatim
    card one;
    card two;

    one.faceValue = 9;
    two.faceValue = 10;

    bool less = (one < two);

    //less contains true

    @endverbatim
 ************************************************************************/
bool operator<(card& c1, card& c2)
{
    //compare the face value of two cards
    if (c1.faceValue < c2.faceValue)
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
 *  @par Description
 *  Compares two cards by looking at their face value. If the face value
 *  of card one is greater than that of card two, then true is returned.
 *
 *  @param[in] c1 - the card on the left side of the operator
 *
 *  @param[in] c2 - the card on the right side of the operator
 *
 *  @returns  A boolean value, whether c1 is greater than c2 or not.
 *
 *
 *  @par Example
 *  @verbatim
    card one;
    card two;

    one.faceValue = 9;
    two.faceValue = 10;

    bool greater = (one > two);

    //greater contains false

    @endverbatim
 ************************************************************************/
bool operator>(card& c1, card& c2)
{
    //compare the face value of two cards
    if (c1.faceValue > c2.faceValue)
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
 *  @par Description
 *  Compares two cards by looking at their face value. If the face value
 *  of card one is equal that of card two, then true is returned.
 *
 *  @param[in] c1 - the card on the left side of the operator
 *
 *  @param[in] c2 - the card on the right side of the operator
 *
 *  @returns  A boolean value, whether c1 is equal to c2 or not.
 *
 *
 *  @par Example
 *  @verbatim
    card one;
    card two;

    one.faceValue = 10;
    two.faceValue = 10;

    bool eq = (one == two);

    //eq contains true

    @endverbatim
 ************************************************************************/
bool operator==(card& c1, card& c2)
{
    //compare the face value of two cards
    if (c1.faceValue == c2.faceValue)
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
 *  @par Description
 *  Compares two cards by looking at their face value. If the face value
 *  of card one is inequal that of card two, then true is returned.
 *
 *  @param[in] c1 - the card on the left side of the operator
 *
 *  @param[in] c2 - the card on the right side of the operator
 *
 *  @returns  A boolean value, whether c1 is inequal to c2 or not.
 *
 *
 *  @par Example
 *  @verbatim
    card one;
    card two;

    one.faceValue = 10;
    two.faceValue = 10;

    bool ineq = (one != two);

    //ineq contains false

    @endverbatim
 ************************************************************************/
bool operator!=(card& c1, card& c2)
{
    //compare the face value of two cards
    if (c1.faceValue == c2.faceValue)
    {
        return false;
    }

    else
    {
        return true;
    }
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Outputs a card to an ostream, either a file or cout. This is done by 
 *  changing the int face value and suit of the card to something readable 
 *  by the user and outputting it to whatever is requested by out.
 *
 *  @param[in] out - the ostream output 
 *
 *  @param[in] l - the card to be output
 *
 *  @returns  An ostream, the output of the operator
 *
 *
 *  @par Example
 *  @verbatim
    card one;

    one.faceValue = 0;
    one.suit = 0;

    cout << one;

    // "AH" is output

    @endverbatim
 ************************************************************************/
ostream& operator<<(ostream& out, card& l)
{ 
    //set all unique card types first
    if (l.faceValue == 0)
    {
        out << "A";
    }
    else if (l.faceValue == 10)
    {
        out << "J";
    }
    else if (l.faceValue == 11)
    {
        out << "Q";
    }
    else if (l.faceValue == 12)
    {
        out << "K";
    }
    else
    {
        out << l.faceValue + 1;
    }

    //set all suits
    if (l.suit == 0)
    {
        out << "H ";
    }

    else if (l.suit == 1)
    {
        out << "D ";
    }

    else if (l.suit == 2)
    {
        out << "C ";
    }

    else
    {
        out << "S ";
    }
    return out;
}

