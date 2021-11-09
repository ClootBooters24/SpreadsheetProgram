// WarstlerC_CSCE2004_Project5.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

// Global constants
const int ROWS = 9;
const int COLS = 9;

// Read and convert location string to row col value
void getLocation(int& row, int& col)
{
    // Initialize variables
    row = -1;
    col = -1;

    // Loop until a valid location is entered
    while (row < 0 || row > ROWS - 1 || col < 0 || col > COLS - 1)
    {
        // Get user input
        cout << "Enter location between A1 and I9: " << endl;
        string location = "";
        cin >> location;

        // Calculate col between 0 and COLS-1
        if (location.length() > 0)
            col = location[0] - 'A';

        // Print error message
        if (col < 0 || col > COLS - 1)
            cout << "Error: column should be between A and I" << endl;

        // Calculate row between 0 and ROWS-1
        if (location.length() > 1)
            row = location[1] - '1';

        // Print error message
        if (row < 0 || row > ROWS - 1)
            cout << "Error: row should be between 1 and 9" << endl;
    }
}

//Print command menu to user and get input
int getMenuChoice()
{
    //Print command menu
    cout << "\nWelcome to MiniCalc the PF1 Killer App\n"
        << "   0) Quit the program\n"
        << "   1) Store specified data value\n"
        << "   2) Store random data values\n"
        << "   3) Calculate minimum of data values\n"
        << "   4) Calculate maximum of data values\n"
        << "   5) Calculate sum of data values\n"
        << "   6) Calculate product of data values\n"
        << "   7) Calculate average of data values\n"
        << "   8) Calculate standard deviation of data values\n";

    //Initialize variables
    string input = "";
    int command = -1;

    //Loop until a valid location is entered
    while (command < 0 || command > 8)
    {
        //Get user input
        cout << "Enter command: ";
        cin >> input;
        if (input.length() == 1)
            command = input[0] - '0';

        //Print error message
        if (command < 0 || command > 8)
            cout << "Error: command should be between 0 and 8" << endl;
    }
    return command;
}

void print(float data[ROWS][COLS])
{
    //Print values
    cout << "     ";
    for (int col = 0; col < COLS; col++)
        cout << char('A' + col) << "   ";
    cout << endl;

    //Print line
    cout << "   +";
    for (int col = 0; col < COLS; col++)
        cout << "---+";
    cout << "\n";

    //Print board
    for (int row = 0; row < ROWS; row++)
    {
        //Print values
        cout << " " << row + 1 << " | ";
        for (int col = 0; col < COLS; col++)
            cout << data[row][col] << " | ";
        cout << endl;

        //Print line
        cout << "   +";
        for (int col = 0; col < COLS; col++)
            cout << "---+";
        cout << "\n";
    }
}

void storeSpec(float data[ROWS][COLS])
{
    float value;
    int row1, row2, col1, col2;

    cout << "What value do you want to store: ";
    cin >> value;

    cout << "Where do you want to store this value: ";
    getLocation(row1, col1);
    getLocation(row2, col2);

    //Store value for each element in array
    for (int row = row1; row <= row2; row++)
        for (int col = col1; col <= col2; col++)
            data[row][col] = value;
}

void storeRand(float data[ROWS][COLS])
{
    int maxValue;
    int minValue;
    int row1, row2, col1, col2;

    //Set minimum and maximum values for rand()
    cout << "What would you like the minimum value to be: ";
    cin >> minValue;
    cout << "What would you like the maximum value to be: ";
    cin >> maxValue;

    cout << "Where do you want to store this value: ";
    getLocation(row1, col1);
    getLocation(row2, col2);

    //Not sure if needed - FIX
    srand(time(NULL));

    for (int row = row1; row <= row2; row++)
        for (int col = col1; col <= col2; col++)

            //Get random value and store in each element
            data[row][col] = rand() % maxValue + minValue;
}

void calcMin(float data[ROWS][COLS])
{
    int row1, row2, row3, col1, col2, col3;

    cout << "Where would you like to calculate the minimum from: ";
    getLocation(row1, col1);
    getLocation(row2, col2);

    cout << "Where do you want to store the minimum: ";
    getLocation(row3, col3);

    //Set minimum as first datapoint to check less thans
    float minimum = data[row1][col1];

    //Check minimum and if more set as minimum
    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            if (minimum > data[row][col])
            {
                minimum = data[row][col];
            }
        }
    }

    //Store value
    data[row3][col3] = minimum;
}

void calcMax(float data[ROWS][COLS])
{
    int row1, row2, row3, col1, col2, col3;

    cout << "Where would you like to calculate the minimum from: ";
    getLocation(row1, col1);
    getLocation(row2, col2);

    cout << "Where do you want to store the minimum: ";
    getLocation(row3, col3);

    //Set maximum as first datapoint to check greater thans
    float maximum = data[row1][col1];

    //Check maximum and if less set as maximum
    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            if (maximum < data[row][col])
            {
                maximum = data[row][col];
            }
        }
    }

    //Store value
    data[row3][col3] = maximum;
}

void calcSum(float data[ROWS][COLS])
{
    int row1, row2, row3, col1, col2, col3;
    float sum = 0;

    cout << "Where would you like to calculate the sum from: ";
    getLocation(row1, col1);
    getLocation(row2, col2);

    cout << "Where do you want to store the sum: ";
    getLocation(row3, col3);

    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            sum += data[row][col];
        }
    }

    //Store value
    data[row3][col3] = sum;
}

void calcProduct(float data[ROWS][COLS])
{
    int row1, row2, row3, col1, col2, col3;
    float product = 1;

    cout << "Where would you like to calculate the product from: ";
    getLocation(row1, col1);
    getLocation(row2, col2);

    cout << "Where do you want to store the product: ";
    getLocation(row3, col3);

    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            product = product * data[row][col];
        }
    }
    data[row3][col3] = product;
}

void calcAvg(float data[ROWS][COLS])
{
    int row1, row2, row3, col1, col2, col3;
    float avg = 0;
    float sum = 0;
    int i = 0;

    cout << "Where would you like to calculate the average from: ";
    getLocation(row1, col1);
    getLocation(row2, col2);

    cout << "Where do you want to store the average: ";
    getLocation(row3, col3);

    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            i++;
            sum += data[row][col];
        }
    }

    avg = sum / i;
    data[row3][col3] = avg;
}

void calcSD(float data[ROWS][COLS])
{
    float sum = 0;
    float mean;
    float standardDeviation = 0;
    int i = 0;
    int row1, row2, row3, col1, col2, col3;

    cout << "Where would you like to calculate the standard deviation from: ";
    getLocation(row1, col1);
    getLocation(row2, col2);

    cout << "Where do you want to store the standard deviation: ";
    getLocation(row3, col3);


    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            i++;
            sum += data[row][col];
        }
    }

    mean = sum / i;

    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            standardDeviation = pow(data[row][col] - mean, 2);
        }
    }

    data[row3][col3] = sqrt(standardDeviation / i);
}

int main()
{
    // Initialize spreadsheet array
    float data[ROWS][COLS];
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            data[row][col] = 0;

    // Loop processing menu commands
    int command = getMenuChoice();
    while (command != 0)
    {
        //Get command to call function
        if (command == 1)
        {
            storeSpec(data);
        }
        else if (command == 2)
        {
            storeRand(data);
        }
        else if (command == 3)
        {
            calcMin(data);
        }
        else if (command == 4)
        {
            calcMax(data);
        }
        else if (command == 5)
        {
            calcSum(data);
        }
        else if (command == 6)
        {
            calcProduct(data);
        }
        else if (command == 7)
        {
            calcAvg(data);
        }
        else if (command == 8)
        {
            calcSD(data);
        }

        print(data);

        // Get next command
        command = getMenuChoice();
    }
    return 0;
}