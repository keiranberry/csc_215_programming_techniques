/** *********************************************************************
 * @file
 *
 * @brief   Functions that deal with allocation and freeing of arrays.
 ***********************************************************************/
#include "netPBM.h"



 /** *********************************************************************
  * @author Keiran Berry
  *
  * @par Description:
  * This function takes in the rows and columns from the image structure 
  * and allocates dynamic arrays for the redGray, green, and blue 
  * portions of the structure. These functions are then placed into the 
  * structure to be used later.
  *
  * @param[in] img - the image structure to be allocated into.
  *
  * @par Example:
    @verbatim
    image picture; //all areas except redGray, green, and blue have been
                 //filled already
    allocArray(picture);
    //the redGray, green, and blue portions of the structure will be 
    //filled with empty 2D dynamic arrays
    @endverbatim

  ***********************************************************************/
void allocArray(image& img)
{
    int i;
    bool alloc = true;
    //allocate redGray array based on rows and cols
    img.redGray = new(nothrow) pixel * [img.rows];
    if (img.redGray == nullptr)
    {
        deleteDArray(img);
        alloc = false;
    }
    for (i = 0; i < img.rows; i++)
    {
        img.redGray[i] = new(nothrow) pixel[img.cols];
        if (img.redGray[i] == nullptr)
        {
            deleteDArray(img);
            alloc = false;
        }
    }
    //allocate green array based on rows and cols
    img.green = new(nothrow) pixel * [img.rows];
    if (img.green == nullptr)
    {
        deleteDArray(img);
        alloc = false;
    }
    for (i = 0; i < img.rows; i++)
    {
        img.green[i] = new(nothrow) pixel[img.cols];
        if (img.green[i] == nullptr)
        {
            deleteDArray(img);
            alloc = false;
        }
    }
    //allocate blue array based on rows and cols
    img.blue = new(nothrow) pixel * [img.rows];
    if (img.blue == nullptr)
    {
        deleteDArray(img);
        alloc = false;
    }
    for (i = 0; i < img.rows; i++)
    {
        img.blue[i] = new(nothrow) pixel[img.cols];
        if (img.blue[i] == nullptr)
        {
            deleteDArray(img);
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
 * This function takes in the dynamic arrays from the structure, and 
 * deletes the dynamically allocated arrays. In order to avoid memory 
 * leaks, this function deletes each row in the array before deleting 
 * the whole thing. This function is to be called at the end of the 
 * function, or midway through if there has been a problem and the 
 * arrays have already been allocated.
 *
 * @param[in] img - the image structure to delete arrays from.
 *
 * @par Example:
   @verbatim
   image picture; //all areas have been filled
   deleteDArray(picture);
   //the dynamically allocated arrays in picture will be deleted
   @endverbatim

 ***********************************************************************/
void deleteDArray(image& img)
{
    int i;
    for (i = 0; i < img.rows; i++)
    {   //delete each row in the array first
        delete[] img.redGray[i];
        delete[] img.green[i];
        delete[]img.blue[i];
    }
    //delete the whole array now
    delete[] img.redGray;
    delete[] img.green;
    delete[] img.blue;
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the dynamic arrays from the structure, and
 * deletes the dynamically allocated arrays. In order to avoid memory
 * leaks, this function deletes each row in the array before deleting
 * the whole thing. This function is to be called at the end of the
 * function, or midway through if there has been a problem and the
 * arrays have already been allocated. This function takes the place 
 * of the deleteDArray function in the event that an array with 
 * flipped rows and columns has been allocated.
 *
 * @param[in] img - the image structure to delete arrays from.
 *
 * @par Example:
   @verbatim
   image picture; //all areas have been filled
   deleteDArrayFlip(picture);
   //the dynamically allocated arrays in picture will be deleted
   @endverbatim

 ***********************************************************************/
void deleteDArrayFlip(image& img)
{
    int i;
    for (i = 0; i < img.cols; i++)
    {   //delete each column of the array first
        delete[] img.redGray[i];
        delete[] img.green[i];
        delete[]img.blue[i];
    }
    //delete the whole array now
    delete[] img.redGray;
    delete[] img.green;
    delete[] img.blue;
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the rows and columns from the image structure
 * and allocates dynamic arrays for the redGray, green, and blue
 * portions of the structure, if the image is to be rotated clockwise
 * or counterclockwise. This allocates the arrays with the rows and 
 * columns switched so that the data can be transferred to an array 
 * with the correct final dimensions. 
 *
 * @param[in] img - the image structure to be allocated into.
 * @param[in] redT - the temporary redGray array to be allocated.
 * @param[in] greenT - the temporary green array to be allocated.
 * @param[in] blueT - the temporary blue array to be allocated.
 *
 * @par Example:
   @verbatim
   image picture; //all areas of the structure have been filled already
   pixel** tempRed = nullptr;
   pixel** tempGreen = nullptr;
   pixel** tempBlue = nullptr;
   allocFlipCR(picture, tempRed, tempGreen, tempBlue);
   //temporary redGray, green, and blue arrays with flipped rows and 
   //columns will be allocated to be filled with the data from the 
   //existing ones
   @endverbatim

 ***********************************************************************/
void allocFlipCR(image& img, pixel**& redT, pixel**& greenT, pixel**& blueT)
{
    int i;
    bool alloc = true;
    //allocate red array for new array with flipped cols and rows
    redT = new(nothrow) pixel * [img.cols];
    if (redT == nullptr)
    {
        deleteDArrayFlip(img);
        alloc = false;
    }
    for (i = 0; i < img.cols; i++)
    {
        redT[i] = new(nothrow) pixel[img.rows];
        if (redT == nullptr)
        {
            deleteDArrayFlip(img);
            alloc = false;
        }
    }
    //allocate green array for flipped cols and rows
    greenT = new(nothrow) pixel * [img.cols];
    if (greenT == nullptr)
    {
        deleteDArrayFlip(img);
        alloc = false;
    }
    for (i = 0; i < img.cols; i++)
    {
        greenT[i] = new(nothrow) pixel[img.rows];
        if (greenT[i] == nullptr)
        {
            deleteDArrayFlip(img);
            alloc = false;
        }
    }
    //allocate blue array for flipped cols and rows
    blueT = new(nothrow) pixel * [img.cols];
    if (blueT == nullptr)
    {
        deleteDArrayFlip(img);
        alloc = false;
    }
    for (i = 0; i < img.cols; i++)
    {
        blueT[i] = new(nothrow) pixel[img.rows];
        if (blueT[i] == nullptr)
        {
            deleteDArrayFlip(img);
            alloc = false;
        }
    }
    //if allocation failed at any point, send error message and exit
    if (alloc = false)
    {
        cout << "Memory Allocation Error" << endl;
        exit(0);
    }
}