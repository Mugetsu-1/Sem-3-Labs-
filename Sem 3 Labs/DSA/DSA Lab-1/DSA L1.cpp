#include <iostream>
using namespace std;

int choice, aSize;
int **arr, *pSize;

void printArray()
{
    for (int i = 0; i < choice; ++i)
    {
        cout << "Elements of array " << i + 1 << ": ";
        for (int j = 0; j < pSize[i]; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void getData()
{
    cout << "Enter how many arrays you want to create? ";
    cin >> choice;

    arr = new int *[choice];
    pSize = new int[choice];

    for (int i = 0; i < choice; ++i)
    {
        cout << "Enter the size for array " << i + 1 << ": ";
        cin >> aSize;

        arr[i] = new int[aSize];
        pSize[i] = aSize;

        cout << "Enter the elements for array " << i + 1 << ": " << endl;
        for (int j = 0; j < aSize; ++j)
        {
            cin >> arr[i][j];
        }
    }
}

void deleteElement()
{
    int arrIndex, arrValue;

    cout << "The array has the following values: " << endl;
    printArray();

    cout << "Enter which array you want to delete from (1 to " << choice << "): ";
    cin >> arrIndex;

    --arrIndex; // Convert to zero-based index

    cout << "Enter the value you want to delete: ";
    cin >> arrValue;

    cout << "Before deleting: " << endl;
    for (int i = 0; i < pSize[arrIndex]; ++i)
    {
        cout << arr[arrIndex][i] << " ";
    }
    cout << endl;

    // Deleting the value
    for (int i = 0; i < pSize[arrIndex]; ++i)
    {
        if (arr[arrIndex][i] == arrValue)
        {
            for (int j = i; j < pSize[arrIndex] - 1; ++j)
            {
                arr[arrIndex][j] = arr[arrIndex][j + 1];
            }
            pSize[arrIndex]--;  
            break;
        }
    }

    cout << "After deleting the element: " << endl;
    for (int i = 0; i < pSize[arrIndex]; ++i)
    {
        cout << arr[arrIndex][i] << " ";
    }
    cout << endl;
}

void sortArray()
{
    cout << "Sorting arrays in ascending order:" << endl;

    for (int i = 0; i < choice; ++i)
    {
        for (int j = 0; j < pSize[i] - 1; ++j)
        {
            for (int k = j + 1; k < pSize[i]; ++k)
            {
                if (arr[i][j] > arr[i][k])
                {
                    int temp = arr[i][k];
                    arr[i][k] = arr[i][j];
                    arr[i][j] = temp;
                }
            }
        }
    }
    printArray();
}

void searchElement()
{
    int arrIndex, searchValue, found = 0;

    cout << "Enter the array index to search in (1 to " << choice << "): ";
    cin >> arrIndex;
    --arrIndex; // Convert to zero-based index

    cout << "Enter the value to search for: ";
    cin >> searchValue;

    for (int i = 0; i < pSize[arrIndex]; ++i)
    {
        if (arr[arrIndex][i] == searchValue)
        {
            cout << "Element found at index " << i + 1 << " of array " << arrIndex + 1 << endl;
            found = 1;
            break;
        }
    }

    if (!found)
    {
        cout << "Element not found in array " << arrIndex + 1 << endl;
    }
}

void mergeArrays()
{
    int arrIndex1, arrIndex2;

    cout << "Enter the indices of two arrays to merge (1 to " << choice << "): ";
    cin >> arrIndex1 >> arrIndex2;
    --arrIndex1; --arrIndex2;  // Convert to zero-based index

    int newSize = pSize[arrIndex1] + pSize[arrIndex2];
    int *mergedArray = new int[newSize];

    int k = 0;
    // Copy elements of first array
    for (int i = 0; i < pSize[arrIndex1]; ++i)
    {
        mergedArray[k++] = arr[arrIndex1][i];
    }
    // Copy elements of second array
    for (int i = 0; i < pSize[arrIndex2]; ++i)
    {
        mergedArray[k++] = arr[arrIndex2][i];
    }

    cout << "Merged array: ";
    for (int i = 0; i < newSize; ++i)
    {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    delete[] mergedArray;
}

int main()
{
    char menuChoice;
    string continueChoice = "A";

    while (continueChoice == "A")
    {
        cout << "Enter your choice:" << endl;
        cout << "A. Enter any element in the array." << endl;
        cout << "B. Delete any element in the array." << endl;
        cout << "C. Sort the array." << endl;
        cout << "D. Search for an element in an array." << endl;  // Swapped with search
        cout << "E. Merge two arrays." << endl;
        cout << "F. Display elements of the array." << endl;  // Swapped with print

        cin >> menuChoice;

        switch (menuChoice)
        {
        case 'A':
            getData();
            break;
        case 'B':
            deleteElement();
            break;
        case 'C':
            sortArray();
            break;
        case 'D':  // Search case
            searchElement();
            break;
        case 'E':
            mergeArrays();
            break;
        case 'F':  // Print case
            printArray();
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }

        cout << "Do you want to do more?" << endl;
        cout << "A. Yes" << endl;
        cout << "B. No" << endl;
        cin >> continueChoice;
    }

    // Cleanup dynamically allocated memory
    for (int i = 0; i < choice; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] pSize;

    return 0;
}
