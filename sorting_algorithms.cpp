#include<iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include<vector>
#include<stdio.h>
#include <chrono>
#include <cstdio>

using namespace std;



void merge(int array[], int begin,int m,int end) {
    
    int  l = m-begin+1;
    int  r = end-m;
    vector <int> array_l(l);
    vector <int> array_r(r);

   // std::copy(array + begin, array + m, std::back_inserter(array_l));
   // std::copy(array + m+1, array + end, std::back_inserter(array_r));
    for (int i = 0; i < l; i++) {

        array_l[i] = array[begin + i];
    }

    for (int j = 0; j < r; j++) {
    
        array_r[j] = array[m + 1 + j];
    
    }
    

    int i=0, j = 0;
    int k = begin;

    while (i < l && j < r) {
        if (array_l[i] <= array_r[j]) {
            array[k] = array_l[i];
            i++;
        }
        else {
            array[k] = array_r[j];
            j++;
        }
        k++;

    
    }
    
    while (i < l) {
        array[k] = array_l[i];
        i++;
        k++;

    }

    while (j < r) {
        array[k] = array_r[j];
        j++;
        k++;

    }


}

void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {

            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        // put min at the correct position
        int temp = array[min_idx];
        array[min_idx] = array[step];
        array[step] = temp;
    }
}

void bubbleSort(int array[], int n) {

    // Outer loop that corresponds to the number of
    // elements to be sorted
    for (int i = 0; i < n - 1; i++) {

        // Last i elements are already
        // in place
        for (int j = 0; j < n - i - 1; j++) {

            // Comparing adjacent elements
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }

               
        }
    }
}






int partition(int arr[], int leftIndex, int rightIndex)
{
    int pivotIndex = leftIndex;
    int pivotValue = arr[pivotIndex];

    int i = leftIndex;
    int j = rightIndex;


    while (i < j) {
        while (arr[i] <= pivotValue) {
            i++;
            if (i >= rightIndex) break;
        }
        while (arr[j] >= pivotValue) {
            j--;
            if (j <= leftIndex) break;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // swap
    arr[pivotIndex] = arr[j];
    arr[j] = pivotValue;

    return j;
}

void quick_sort(int array[], int p, int  r) {
    if (p < r) {
        int q = partition(array, p, r);

        quick_sort(array, p, q - 1);
        quick_sort(array, q + 1, r);


    }




}


void merge_sort(int arr[], int begin, int end) {
    if (begin < end) {
        int q = begin+(end-begin) / 2;
        merge_sort(arr, begin, q);
        merge_sort(arr, q + 1, end);
        merge(arr, begin, q, end);
    }

}


void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);


        heapify(arr, i, 0);
    }
}
void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;


        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void load_array( int array[],int batch_size) {

  

    string fileName = "small_array.txt";
    ifstream inFile;
    inFile.open(fileName.c_str());


    int index = 0;
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line) && index < batch_size) {
            int number;
            number = std::stod(line);

            array[index] = number;

            index++;
        }
        inFile.close();
    }
}
int main() {
    int option = 0;
    const int batch_size = 20;
    int  array[batch_size];
    string extension = "";
    load_array(array, batch_size);
    string file = "";
    const char* file_names[] = { "quick_sort","merge_sort","bubble_sort","selection_sort","heap_sort","insertion_sort" };
    //loading the arrays
    const char* text = R"(
       _____            __  _                ______          __      
      / ___/____  _____/ /_(_)___  ____ _   /_  __/__  _____/ /______
      \__ \/ __ \/ ___/ __/ / __ \/ __ `/    / / / _ \/ ___/ __/ ___/
     ___/ / /_/ / /  / /_/ / / / / /_/ /    / / /  __(__  ) /_(__  ) 
    /____/\____/_/   \__/_/_/ /_/\__, /    /_/  \___/____/\__/____/  
                                /____/                               
    )";
    cout << text << endl;
    cout << "1.Big Test 49997" << endl;
    cout << "2.Smal Test 20" << endl;
    cout << "3.Exit" << endl;
    cout << "input>>";
    cin >> option;

    if (option == 1) {
        file = "big_array.txt";
        extension = "_big";
    }
    else if (option ==2) {

        file = "small_array.txt";
        extension = "_small";
    }
    else {
        return 0;
    }
    
    
    
    int n = sizeof(array) / sizeof(array[0]);
  

    int iterations = 1000;
  
    for (int i = 0; i < 6; i++) {
        string file_name = file_names[i];
       
       
        
        std::ofstream outputFile(file_name+extension+".csv");

        cout <<"NOW TESTING" << file_name <<" WITH N = "<<n << endl;
        outputFile << std::ios::out; // or "app" for appending
        outputFile << "test_id,algorithm,time,n_size" << std::endl;
        for (int i = 0; i < iterations; i++) {

            //prepare array for testing:
            int array_p[batch_size];

            for (int x = 0; x < batch_size; x++) {
                array_p[x] = array[x];
            }

            //start measuring performance
          
            auto start = std::chrono::high_resolution_clock::now();
            //Start Sorting
            if (file_name == "quick_sort") {
                quick_sort(array_p, 0, n - 1);
            }
            else if (file_name == "merge_sort") {
                merge_sort(array_p, 0, n - 1);
            }
            else if (file_name=="bubble_sort") {
                bubbleSort(array_p, n);
            }
            else if(file_name=="selection_sort") {
                selectionSort(array_p, n);
            }
            else if (file_name == "heap_sort") {
                heapSort(array_p, n);
            }
            else if (file_name == "insertion_sort") {
                insertionSort(array_p, n);
            }
            


            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            //store performance:
            cout << i << "-- " << duration.count() << "\n";
            outputFile << i << "," << "insertion sort" << ","<< duration.count() << ","<<n << std::endl;


        }
        outputFile.close();


        cout.precision(20);

        cout << "\n";
    
    
    }
    
    for (int i = 0; i < n; i++) {

        cout << i<<"--" << array[i] << "\n";
    
    }
   


    return 0;
    



     return 0;
}