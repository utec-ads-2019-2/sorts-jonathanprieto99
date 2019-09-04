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

    int ordenar (int input[], int low, int high)
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

    void execute2(int input[], int low, int high){
            if (low < high)
            {
                    int pi = ordenar(input, low, high);
                    execute2(input, low, pi - 1);
                    execute2(input, pi + 1, high);
            }
    }

    void execute(){
        execute2(elements,0,size-1);
    }


    inline string name() { return "QuickSort"; }
};

#endif