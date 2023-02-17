/** *********************************************************************
 * @file
 *
 * @brief   Functions that deal with image processing.
 ***********************************************************************/
#include "netPBM.h"



 /** *********************************************************************
  * @author Keiran Berry
  * 
  * @par Description:
  * This function takes in the image structure which has been filled and 
  * flips the image about its x-axis. This is done by switching the 
  * pointers to the rows from the beginning to the end, and then 
  * incrementing towards the center of the image by one row each time 
  * that a row has been flipped, until the whole image has been flipped.
  *
  * @param[in] im - the image structure to be manipulated.
  *
  * @par Example:
    @verbatim
    img picture; //all areas of picture have been filled already
    xFlip(picture);
    //the rows in picture's arrays will all be flipped, resulting in the 
    //image which is output being flipped about its x-axis
    @endverbatim

  ***********************************************************************/
void xFlip(image& im)
{
    pixel* temp;
    int beg;
    int end;
    beg = 0;
    end = im.rows - 1;
    //while the beginning of the switch is hasnt crossed the end
    //swap r, g, b pointers to the whole lines of rows 
    while (beg < end)
    {
        temp = im.redGray[beg];
        im.redGray[beg] = im.redGray[end];
        im.redGray[end] = temp;
        temp = im.green[beg];
        im.green[beg] = im.green[end];
        im.green[end] = temp;
        temp = im.blue[beg];
        im.blue[beg] = im.blue[end];
        im.blue[end] = temp;
        beg++;//beginning goes one towards the center
        end--;//end goes one towards the center
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the image structure which has been filled and
 * flips the image about its y-axis. This is done by starting at the 
 * outside of the arrays, and flipping each individual item with its 
 * counterpart on the other side. Once whole columns have bene flipped, 
 * then the columns to be flipped increment in by one and the starting 
 * point for where to flip returns to the first row in the arrays so 
 * that it can increment down.
 *
 * @param[in] im - the image structure to be manipulated.
 *
 * @par Example:
   @verbatim
   img picture; //all areas of picture have been filled already
   yFlip(picture);
   //the columns in picture's arrays will all be flipped, resulting in the
   //image which is output being flipped about its y-axis
   @endverbatim

 ***********************************************************************/
void yFlip(image& im)
{
    pixel temp;
    int beg;
    int end;
    int i = 0;

    for (i = 0; i < im.rows; i++)
    {
        beg = 0;
        end = im.cols - 1;
        while (beg < end)
        {   //while the beginning of switch hasnt crossed the end
            //flip the specific pixels in each array
            //we can't do the whole line becuse the pointers to the 
            //1D arrays are not defined in this direction
            temp = im.redGray[i][beg];
            im.redGray[i][beg] = im.redGray[i][end];
            im.redGray[i][end] = temp;
            temp = im.green[i][beg];
            im.green[i][beg] = im.green[i][end];
            im.green[i][end] = temp;
            temp = im.blue[i][beg];
            im.blue[i][beg] = im.blue[i][end];
            im.blue[i][end] = temp;
            beg++;//beginning goes one towards the center
            end--;//end goes one towards the center
        }
    }

}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the image structure which has been filled and
 * rotates the image clockwise. This is done by taking the first row 
 * in the array and making it the last column in the resulting image. 
 * Three new arrays are allocated with the rows and columns switched, and 
 * the resulting arrays are filled with the data from the initial ones 
 * before deleting the initial ones and filling the structure with the 
 * new arrays.
 *
 * @param[in] img - the image structure to be manipulated.
 *
 * @par Example:
   @verbatim
   img picture; //all areas of picture have been filled already
   rotateCW(picture);
   //the resulting picture will be turned 90 degrees clockwise
   @endverbatim

 ***********************************************************************/
void rotateCW(image& img)
{
    pixel** tempRed = nullptr;
    pixel** tempGreen = nullptr;
    pixel** tempBlue = nullptr;
    int i = 0;
    int j = 0;
    int temp;
    //allocate 3 new arrays with the columns flipped from the rows 
    allocFlipCR(img, tempRed, tempBlue, tempGreen);
    for (i = 0; i < img.rows; i++)
    {
        for (j = 0; j < img.cols; j++)
        {   //each row copied down the final column of the temp
            //increment what is being filled by how many have been filled
            tempRed[j][img.rows - 1 - i] = img.redGray[i][j];
            tempGreen[j][img.rows - 1 - i] = img.green[i][j];
            tempBlue[j][img.rows - 1 - i] = img.blue[i][j];
        }

    }
    //delete old array
    deleteDArray(img);
    //flip rows and cols in the structure
    temp = img.cols;
    img.cols = img.rows;
    img.rows = temp;
    //put the new arrays into the structure
    img.redGray = tempRed;
    img.green = tempGreen;
    img.blue = tempBlue;
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the image structure which has been filled and
 * rotates the image counterclockwise. This is done by allocating three 
 * new arrays with the columns and rows flipped and filling them with 
 * the original data, the first row in the original being copied into 
 * the first column of the new array, and so on. The original arrays 
 * are deleted prior to the end of the function to avoid memory leaks.
 *
 * @param[in] img - the image structure to be manipulated.
 *
 * @par Example:
   @verbatim
   img picture; //all areas of picture have been filled already
   rotateCCW(picture);
   //the resulting picture will be turned 90 degrees counterclockwise
   @endverbatim

 ***********************************************************************/
void rotateCCW(image& img)
{
    pixel** tempRed = nullptr;
    pixel** tempGreen = nullptr;
    pixel** tempBlue = nullptr;
    int i = 0;
    int j = 0;
    int temp;
    //allocate 3 new arrays in the correct dimension
    allocFlipCR(img, tempRed, tempBlue, tempGreen);
    for (i = 0; i < img.rows; i++)
    {
        for (j = 0; j < img.cols; j++)
        {   //increment what is being filled by how many have been filled
            //each row in the original goes to the first column in the new
            tempRed[img.cols - 1 - j][i] = img.redGray[i][j];
            tempGreen[img.cols - 1 - j][i] = img.green[i][j];
            tempBlue[img.cols - 1 - j][i] = img.blue[i][j];
        }

    }
    //delete old arrays
    deleteDArray(img);
    //flip rows and columns in structure
    temp = img.cols;
    img.cols = img.rows;
    img.rows = temp;
    //fill structure with new arrays
    img.redGray = tempRed;
    img.green = tempGreen;
    img.blue = tempBlue;
}




/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the image structure which has been filled and
 * changes its contents to be prepared to output a grayscale image. This 
 * is done by manipulating the data in all three existing arrays using 
 * a preset formula and then filling the redGray array with the 
 * resulting data. The result is one array ready to be output to a 
 * .pgm file.
 *
 * @param[in] img - the image structure to be manipulated.
 *
 * @par Example:
   @verbatim
   img picture; //all areas of picture have been filled already
   grayscale(picture);
   //the resulting picture will be grayscale
   @endverbatim

 ***********************************************************************/
void grayscale(image& img)
{
    int i;
    int j;
    int current;
    double currentD;
    for (i = 0; i < img.rows; i++)
    {
        for (j = 0; j < img.cols; j++)
        {   //go through each array slot and do the grayscale calculation
            currentD = .3 * img.redGray[i][j] + .6 * img.green[i][j]
                + .1 * img.blue[i][j];
            //typecast current to an int
            current = int(currentD);
            //new redGray value is filled into the array
            img.redGray[i][j] = current;
        }
        j = 0;
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the image structure which has been filled and
 * changes its contents to antique the image. This is done by taking in 
 * all three existing arrays and manipulating the contents of each 
 * using a preset formula. The data is then cropped before being put 
 * back into the structure. The new data is filled back into the arrays, 
 * and the resulting image will be antiqued.
 *
 * @param[in] img - the image structure to be manipulated.
 *
 * @par Example:
   @verbatim
   img picture; //all areas of picture have been filled already
   sepia(picture);
   //the resulting picture will be antiqued
   @endverbatim

 ***********************************************************************/
void sepia(image& img)
{
    int i;
    int j;
    int currentR;
    int currentG;
    int currentB;
    double currentDR;
    double currentDG;
    double currentDB;
    for (i = 0; i < img.rows; i++)
    {
        for (j = 0; j < img.cols; j++)
        {   //for each item, do the sepia calculation
            currentDR = .393 * img.redGray[i][j] + .769 * img.green[i][j]
                + .189 * img.blue[i][j];
            currentDG = .349 * img.redGray[i][j] + .686 * img.green[i][j]
                + .168 * img.blue[i][j];
            currentDB = .272 * img.redGray[i][j] + .534 * img.green[i][j]
                + .131 * img.blue[i][j];
            //crop each new item if the value is greater than 255
            if (currentDR > 255)
            {
                currentDR = 255;
            }
            if (currentDG > 255)
            {
                currentDG = 255;
            }
            if (currentDB > 255)
            {
                currentDB = 255;
            }
            //typecast the new values
            currentR = int(currentDR);
            currentG = int(currentDG);
            currentB = int(currentDB);
            img.redGray[i][j] = currentR;
            img.green[i][j] = currentG;
            img.blue[i][j] = currentB;

        }
        j = 0;
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the image structure which has been filled and
 * the option which has been input by the console. Using this string 
 * input from the console, this function directs the image structure 
 * to the corresponding function in order to manipulate it in the 
 * fashion requested.
 *
 * @param[in] img - the image structure to be manipulated.
 * @param[in] opUsed - the option which was provided in the console.
 *
 * @par Example:
   @verbatim
   img picture; //all areas of picture have been filled already
   string option = "--sepia";
   manipImage(picture, option);
   //the structure will be passed into the sepia function
   @endverbatim

 ***********************************************************************/
void manipImage(image& img, string opUsed)
{   //what function to execute based on the arguments provided
    if (opUsed == "--grayscale")
    {
        grayscale(img);
    }
    else if (opUsed == "--sepia")
    {
        sepia(img);
    }
    else if (opUsed == "--flipX")
    {
        xFlip(img);
    }
    else if (opUsed == "--flipY")
    {
        yFlip(img);
    }
    else if (opUsed == "--rotateCW")
    {
        rotateCW(img);
    }
    else if (opUsed == "--rotateCCW")
    {
        rotateCCW(img);
    }
}