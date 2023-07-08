#include <iostream>
using namespace std;

// Function to perform the QuickSort algorithm
// Sorts the array based on the values in the specified row
void QuickSort(unsigned long long** array, int start_index, int end_index, int* row);

// Function to determine the pivot index during partitioning
int Pivoting(unsigned long long** array, int start_index, int end_index, int* row);

void DivideAndPrintPendrives(unsigned long long** array, int file_number, unsigned long long pendrive_size);


int main()
{
    // Read the input file number and pendrive size
    int file_number;
    unsigned long long pendrive_size;
    cin >> file_number;
    cin >> pendrive_size;

    // Allocate memory for the array to store file sizes and pendrive sizes
    unsigned long long** array = new unsigned long long* [2];
    array[0] = new unsigned long long[file_number];
    array[1] = new unsigned long long[file_number];

    // Read file sizes and pendrive sizes from input
    for (int i = 0; i < file_number; i++) {
        cin >> array[1][i];
        cin >> array[0][i];
    }

    DivideAndPrintPendrives(array, file_number, pendrive_size);

    // Deallocate the dynamically allocated memory
    delete[] array[0];
    delete[] array[1];
    delete[] array;

    return 0;
}

// Function to perform the QuickSort algorithm
// Sorts the array based on the values in the specified row
void QuickSort(unsigned long long** array, int start_index, int end_index, int* row) {
    if (start_index < end_index) {
        int pivot_index = Pivoting(array, start_index, end_index, row);
        QuickSort(array, start_index, pivot_index - 1, row);
        QuickSort(array, pivot_index + 1, end_index, row);
    }
}

// Function to determine the pivot index during partitioning
int Pivoting(unsigned long long** array, int start_index, int end_index, int* row) {
    unsigned long long* array_pivoted[2];
    array_pivoted[0] = new unsigned long long[end_index - start_index + 1];
    array_pivoted[1] = new unsigned long long[end_index - start_index + 1];

    int i, count = 0, count2 = end_index - start_index;
    int second_row = (*row + 1) % 2, pivot_index;

    for (i = start_index; i < end_index; i++) {
        if (array[*row][end_index] >= array[*row][i]) {
            array_pivoted[*row][count] = array[*row][i];
            array_pivoted[second_row][count] = array[second_row][i];
            count++;
        }
        else {
            array_pivoted[*row][count2] = array[*row][i];
            array_pivoted[second_row][count2] = array[second_row][i];
            count2--;
        }
    }

    array_pivoted[*row][count] = array[*row][end_index];
    array_pivoted[second_row][count] = array[second_row][end_index];
    pivot_index = start_index + count;

    for (i = 0; i <= count; i++) {
        array[*row][i + start_index] = array_pivoted[*row][i];
        array[second_row][i + start_index] = array_pivoted[second_row][i];
    }
    count++;
    for (i = end_index - start_index; i > count2; i--) {
        array[*row][count + start_index] = array_pivoted[*row][i];
        array[second_row][count + start_index] = array_pivoted[second_row][i];
        count++;
    }

    // Deallocate the dynamically allocated memory
    delete[] array_pivoted[0];
    delete[] array_pivoted[1];
    return pivot_index;
}

void DivideAndPrintPendrives(unsigned long long** array, int file_number, unsigned long long pendrive_size)
{
    // Sort the array based on the first row (pendrive sizes)
    int row[2] = { 0, 1 };
    QuickSort(array, 0, file_number - 1, &row[0]);

    // Initialize variables to track the end indices of the first and second pendrives
    int end_first_pendrive, end_second_pendrive;

    // Calculate the end index of the first pendrive
    unsigned long long cumulative_size = 0;
    int i = 0;
    while (cumulative_size < pendrive_size) {
        cumulative_size += array[row[0]][i];
        i++;
    }
    end_first_pendrive = i - 2;

    // Reset the cumulative size and decrement the index to exclude the last file added to the first pendrive
    cumulative_size = 0;
    i--;

    // Calculate the end index of the second pendrive
    while (cumulative_size < pendrive_size) {
        cumulative_size += array[0][i];
        i++;
    }
    end_second_pendrive = i - 2;

    // Sort the files in the second pendrive based on the second row (file sizes)
    QuickSort(array, end_first_pendrive + 1, end_second_pendrive, &row[1]);

    // Output the results
    cout << i - 1 << endl;
    cout << "1:";
    for (i = end_first_pendrive; i >= 0; i--) {
        cout << " " << array[row[1]][i];
    }

    cout << endl << "2:";
    for (i = end_second_pendrive; i >= end_first_pendrive + 1; i--) {
        cout << " " << array[row[1]][i];
    }
}