//
//  main.cpp
//  Honors Project
//
//  Created by Aman Grewal on 6/19/21.
//

#include <iostream>
#include <fstream>
#include "Object.h"
#include "Stack.h"

using namespace std;

// Function prototype
int check(Object** &arr, int row, int col, int totalRows, int totalCols);
void DFS(Object** &arr, int row, int col, int totalRows, int totalCols, int& a);
void countObjectsRecursive(Object** &arr, int totalRows, int totalCols);
void countObjectsIterative(Object** &arr, int totalRows, int totalCols);


int main() {
    
    // Initialize variables
    string filename;
    int rows, cols;
    char input;
    
    // Enter filename
    cout << "Enter File name: ";
    cin >> filename;
    cout << endl << endl;
    
    // Create file object
    ifstream fin;
    fin.open(filename);
    
    // Check file
    if(!fin)
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }
    
    fin >> rows >> cols;
    
    
    // Double pointer to allocate 2d array
    Object** array = new Object*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new Object[cols];
    }
    
    // Read in text file
    for( int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            fin >> input;
            array[r][c].setValue(input);
            array[r][c].setChecked(false);
        }

    }
    // Close file
    fin.close();
    
    // Menu for solutions
    char answer;
   
    cout << "Recursive or Iterative Solution(Q to quit) [R/I]: ";
    cin >> answer;
    cout << endl;
    
    while (answer == 'r' || answer == 'R' || answer == 'i' || answer == 'I') {
        
        // Display recursive solution
        if (answer == 'r' || answer == 'R') {
            countObjectsRecursive(array, rows, cols);
        }
        
        // Display iterative solution
        else if (answer == 'i' || answer == 'I') {
            countObjectsIterative(array, rows, cols);
        }
        
        // Reset the array
        for( int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                array[r][c].setChecked(false);
            }
        }
        
        cout << "Recursive or Iterative Solution(Q to quit) [R/I]: ";
        cin >> answer;

 
    }
    
    return 0;
    
}


// Function to check if DFS can be run
int check(Object** &arr, int row, int col, int totalRows, int totalCols)
{
    
    // Check if the row/cols value is greater than 0 and less than total rows/cols
    // Check if square is not 0 and hasn't been checked
    return (row >= 0) && (row < totalRows) && (col >= 0) && (col < totalCols) && (arr[row][col].getValue() != '0' && !(arr[row][col].getChecked()));
}
 
// Depth First Search function to find neighbors of
// square and computes the area
void DFS(Object** &arr, int row, int col, int totalRows, int totalCols, int& area)
{
    // Arrays used to find neighbors of squares
    static int rowNbr[] = { -1, 0, 0, 1};
    static int colNbr[] = { 0, -1, 1, 0 };
 
    // Set checked value of object to true
    arr[row][col].setChecked(true);
    area++;
 
    // Recur for all connected neighbours
    for (int k = 0; k < 4; ++k)
        if (check(arr, row + rowNbr[k], col + colNbr[k], totalRows, totalCols)) {
            DFS(arr, row + rowNbr[k], col + colNbr[k], totalRows, totalCols, area);
            }
            
}
 
// Function that calculates the number
// of objects and the areas of those
// objects recursively
void countObjectsRecursive(Object** &arr, int totalRows, int totalCols)
{
    // Initialize count and area to 0
    int count = 0;
    int area = 0;
    
    // Traverse through each cell
    for (int i = 0; i < totalRows; ++i) {
        for (int j = 0; j < totalCols; ++j) {
             
            // Set area to 0 for each new object
            area = 0;
            
            // Check if square is not 0 and hasnt been checked
            if (arr[i][j].getValue() != '0' && !arr[i][j].getChecked()) {
    
                // Visit all squares in this object and compute area.
                DFS(arr, i, j, totalRows, totalCols, area);
                
                // Increment count
                ++count;
                
                // Print area of object
                cout << "Object " << count << ": " << area << endl;

            }
        }
    }
 
}

// Function that calculates the number
// of objects and the areas of those
// objects iteratively
void countObjectsIterative(Object** &arr, int totalRows, int totalCols) {
        
       // Create a stack for rows and cols
        Stack<int> rowsStack;
        Stack<int> colsStack;
        
        // Initialize variables to 0
        int area = 0;
        int count = 0;
        
        // Traverse through each square
        for (int i = 0; i < totalRows; ++i) {
            for (int j = 0; j < totalCols; ++j) {
                
                // Check if square is not 0 and hasnt been checked
                if (arr[i][j].getValue() != '0' && !arr[i][j].getChecked()) {
                    
                    // Set area to 0 for each new object and increase object count
                    area = 0;
                    count++;
                    
                    // Push locations of square in stacks
                    rowsStack.push(i);
                    colsStack.push(j);
                    
                    // Visit neighboring squares
                    while (!rowsStack.isEmpty()) {
                        int x = rowsStack.pop();
                        int y = colsStack.pop();
                        
                        // If already visited
                        if (arr[x][y].getChecked())
                            continue;
                        
                        static int rowNbr[] = { -1, 0, 0, 1};
                        static int colNbr[] = { 0, -1, 1, 0 };
 
                        // Mark this cell as visited
                        arr[x][y].setChecked(true);
                        area++;
 
                        // Push neighbors into stack if not visited
                        for (int k = 0; k < 4; ++k) {
                            int r = x + rowNbr[k];
                            int c = y +colNbr[k];
                            if (check(arr, r, c, totalRows, totalCols)) {
                                rowsStack.push(r);
                                colsStack.push(c);
                                
                            }
                        
                            
                    }
                    
                    
                }
                // Display objects with area
                cout << "Object : " << area << endl;
            }
        
        
        }

    }

}
