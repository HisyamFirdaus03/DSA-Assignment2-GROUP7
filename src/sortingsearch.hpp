#include <string>
#include <iostream>
using namespace std;

template <class T, class P>
void improvedBubbleSort(T arr[], int size, P compare[]){

    bool isSorted = false;
    for(int pass = 1; pass <= size && !isSorted; pass++){

        isSorted = true;
        for(int i = 0; i < size - pass; i++){

            if(compare[i] > compare[i + 1]){

                swap(arr[i], arr[i + 1]);
                swap(compare[i], compare[i + 1]);
                isSorted = false;
            }
        }
    }
}

template <class T, class P>
void improvedSelectionSort(T arr[], int size, P compare[]){

    for(int last = size - 1; last > 0; last--){

        int largest = 0;
        for(int i = 0; i <= last; i++){

            if(compare[i] > compare[largest])
                largest = i;
        }
        if(largest != last){

            swap(arr[largest], arr[last]);
            swap(compare[largest], compare[last]);
        }
    }
}

template <typename T>
int binarySearch(T arr[], T key, int size){

    bool found = false;
    int index = -1;
    int middle;
    int left = 0;
    int right = size - 1;

    while((left <= right) && (!found)){

        middle = (left + right) / 2;
        if(arr[middle] == key){

            index = middle;
            found = true;
        }
        else if(arr[middle] > key){

            right = middle - 1;
        }
        else{

            left = middle + 1;
        }
    }

    return index;
}


//Quicksort
template <class T, class P>
int partition(T arr[], int first, int last, P compare[]){

    int cutPoint;
    int pivot = first;
    int top = last;
    int bottom = first;

    while(true){

        while(compare[top] > compare[pivot]){

            top--;
        }    
        
        while(compare[bottom] < compare[pivot]){

            bottom++;
        }

        if(compare[top] < compare[bottom]){


            swap(arr[top], arr[bottom]);
            swap(compare[top], compare[bottom]);
        }
        else{

            cutPoint = top;
            break;
        }
    } 

    return cutPoint;
}

template <class T, class P>
void quickSort(T arr[], int first, int last, P compare[]){

    if(first < last){

        int cut = partition<T, P>(arr, first, last, compare);

        quickSort(arr, first, cut, compare);

        quickSort(arr, cut + 1, last, compare);
    }
}
