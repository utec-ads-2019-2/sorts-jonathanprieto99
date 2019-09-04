#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

    void swap(int* a, int* b)
    {
            int t = *a;
            *a = *b;
            *b = t;
    }

        int place (int input[], int low, int high)
    {
            int pivot = input[high];
            int i = (low - 1);

            for (int j = low; j <= high - 1; j++)
            {
                    if (input[j] < pivot)
                    {
                            i++;
                            swap(&input[i], &input[j]);
                    }
            }
            swap(&input[i + 1], &input[high]);
            return (i + 1);
    }

    void execute(int input[], int low, int high){
            if (low < high)
            {
                    int pi = place(input, low, high);
                    //QuickSort(input, low, pi - 1);
                    //QuickSort(input, pi + 1, high);
            }
    }

        inline string name() { return "QuickSort"; }
};

#endif