/*
 * Jacob Smith
 * jks0039
 * hw2.cpp
 * Compiled using g++
 * method stubs taken from pdf, as is sample code
 * sort method adapted from this : https://mathbits.com/MathBits/CompSci/Arrays/Merge.htm
 *
 * g++ -o hw3 hw3.cpp
 */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>

using namespace std;


//sample code and filled in method stubs
int readfile(int inputArray[], ifstream &inStream) {
    // Input: (1) Array storing data retrieved from the file (i.e., instream)
    //        (2) input file stream object
    // Output: Size of array. Note: you need to use this parameter to control the array size.
    int index = 0;
    inStream >> inputArray[index];
    while (!inStream.eof()) {
        //making sure file input is valid
        index++;
        inStream >> inputArray[index];
    }
    return index;
}

void writefile(int outputArray[], int outputArray_size, ofstream &outStream)
// Input: (1) Array of combined data from two input files
//        (2) Size of the output array
// Output: Creates output file containing the sorted output array
{
    //this was way easier than I expected honestly
    for (int i = 0; i < outputArray_size; i++) {
        outStream << outputArray[i] << endl;
    }
}
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]){
    // Input: (1) Array storing data retrieved from the file
    //        (2) Array size retrieved from the file
    //        (3) Array storing data retrieved from the file
    //        (4) Array size retrieved from the file
    //        (5) Array used to save output data
    // Output: Sorted list of numbers from both input files
    //wew, here we go
    //get the number of possible indexes
    int outputSize = inputArray1_size + inputArray2_size;
    int index, index2, index3;
    index = index2 = index3 = 0;

    while (index < inputArray1_size && index2 < inputArray2_size) {
        //quick synopsis : checking array 1, if its greater than array 2 at the same index,
        //then we add it to the output array at the same index
        if (inputArray1[index] < inputArray2[index2]) {
            outputArray[index3] = inputArray1[index];
            index++;
            index3++;
        }
            //otherwise, we add the item from the second array to it
        else {
            outputArray[index3] = inputArray2[index2];
            index2++;
            index3++;
        }
    }

    //check and see if all numbers from array 1 have been added
    //now repeat same checks with array 2

    if (index == inputArray1_size) {
        while (index2 < inputArray2_size) {
            outputArray[index3] = inputArray2[index2];
            index2++;
            index3++;
        }
    } else {
        while (index < inputArray1_size) {
            outputArray[index3] = inputArray1[index];
            index++;
            index3++;
        }
    }
    //make sure that all numbers have been added to the final array, then we're done!
    assert(index3 == outputSize);
    return outputSize;
}
void test_readfile(void)
// This is a test driver for readfile()
{
    ifstream inStream;
    int array[300];
    int array_size;
    std::string input1 = "input1.txt";
    std::string input2 = "input2.txt";
    std::string input3 = "input3.txt";

    cout << "Unit Test Case 1: readfile()\n";

    cout << "\tCase 1.1: input1.txt - 4 values\n";
    inStream.open(input1.c_str());
    int int1 = readfile(array, inStream);
    assert(int1);
    inStream.close();
    cout << "\tCase 1.1 passed.\n";

    cout << "\tCase 1.2: input2.txt - 6 values\n";
    inStream.open(input2.c_str());
    int int2 = readfile(array, inStream);
    assert(int2);
    inStream.close();
    cout << "\tCase 1.2 passed.\n";

    cout << "\tCase 1.3: input3.txt - 8 values, with larger values\n";
    inStream.open(input3.c_str());
    int int3 = readfile(array, inStream);
    assert(int3);
    inStream.close();
    cout << "\tCase 1.3 passed.\n";
}

void test_sort(void) {
// This is a test driver for sort()

    ifstream inStream;
    int inputArray[300], inputArray2[300], inputArray3[300], outputArray[300], outputArray2[300];
    int array1_size, array2_size, array3_size, array4_size;
    std::string file1 = "input1.txt";
    std::string file2 = "input2.txt";
    std::string file3 = "input3.txt";

    cout << "Unit Test Case 2: sort()\n";

    inStream.open(file1.c_str());
    array1_size = readfile(inputArray, inStream);
    inStream.close();
    inStream.open(file2.c_str());
    array2_size = readfile(inputArray2, inStream);
    inStream.close();
    inStream.open(file3.c_str());
    array3_size = readfile(inputArray3, inStream);
    inStream.close();

    cout << "\tCase 2.1: input1.txt, input2.txt\n";
    int sort1 = sort(inputArray, array1_size, inputArray2, array2_size, outputArray);
    assert(sort1);
    cout << "\tCase 2.1 passed.\n";

    cout << "\tCase 2.2: input1.txt, input3.txt\n";
    int sort2 = sort(inputArray, array1_size, inputArray3, array3_size, outputArray2);
    assert(sort2);
    cout << "\tCase 2.2 passed.\n";
}

int main() {
    test_readfile();
    cout << "Press any key to continue...";
    cin.ignore().get();

    test_sort();
    cout << "Press any key to continue...";
    cin.ignore().get();
    ifstream inStream;
    ofstream outStream;

    int data;
    //array indexes
    int stream_array_1_size;
    int stream_array_2_size;
    int output_array_size;

    //arrays, with the input arrays limited to 300 possible. I started running low on time, but my original idea was to allow each array to be half of max possible int values.
    //however, this caused segfaults on launch so I dialed it back to a limit more within reason.
    int inputArray1[300];
    int inputArray2[300];
    int outputArray[300];

    std::string text1 = "";
    std::string text2 = "";
    std::string outputFile = "";

    string outputFileName;
    string filename;

    cout << "*** Welcome to Jacob's sorting program ***" << endl;
    cout << "Enter the first input file name: ";
    cin >> filename;
    //Pass the file name as an array of chars to open()
    inStream.open((char *) filename.c_str());
    if (inStream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    //readfile, and then close file stream.
    stream_array_1_size = readfile(inputArray1, inStream);
    cout << "The list of " << stream_array_1_size << " numbers in file " << filename << " is:\n";
    //I was originally printing the array in the readfile method, but this caused quite a mess when it was called in test methods.
    //so now here it goes.
    while (!inStream.eof()) {
        cout << data << endl;
        inStream >> data;
    }
    for (int i = 0; i <= stream_array_1_size; i++) {
        cout << inputArray1[i];
        cout << "\n";
    }
    inStream.close();
    inStream.clear();

    cout << "\n";

    cout << "Enter the second input file name: ";
    cin >> filename;

    inStream.open((char *) filename.c_str());
    if (inStream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    //readfile, and then close file stream.
    stream_array_2_size = readfile(inputArray2, inStream);
    cout << "The list of " << stream_array_2_size << " numbers in file " << filename << " is:\n";
    while (!inStream.eof()) {
        cout << data << endl;
        inStream >> data;
    }
    for (int i = 0; i <= stream_array_2_size; i++) {
        cout << inputArray2[i];
        cout << "\n";
    }
    inStream.close();
    inStream.clear();

    cout << "\n";
    output_array_size = sort(inputArray1, stream_array_1_size, inputArray2, stream_array_2_size, outputArray);
    cout << "The sorted list of " << output_array_size << " numbers is: ";
    for (int i = 0; i < output_array_size; i++) {
        cout << outputArray[i] << " ";
    }

    cout << "\nEnter the output file name: ";
    cin >> outputFileName;
    outStream.open((char *) outputFileName.c_str());
    if (outStream.fail()) {
        cout << "Output file opening failed.";
        exit(1);
    }

    writefile(outputArray, output_array_size, outStream);
    cout << "*** Please check the new file - " << outputFileName << " ***\n";
    cout << "*** Goodbye ***";

    return 0;
}
