#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
                int i;
                int j;
                int min_idx;

                for (i = 0; i < size-1; i++)
                {
                        min_idx = i;
                        for (j = i+1; j < size; j++)
                                if (elements[j] < elements[min_idx])
                                        min_idx = j;
                        //Swap
                        int temp = elements[min_idx];
                        elements[min_idx] = elements[i];
                        elements[i] = temp;
                }
        }

        inline string name() { return "SelectSort"; }
};

#endif