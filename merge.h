#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}

    void mergeSort(int input[], int l, int h)
    {
            if (l==h)
                    return;
            int mid = (h+l)/2;
            mergeSort(input, l, mid);
            mergeSort(input, mid + 1, h);
            merge(input,l, mid,h);

    }
    void merge(int elements[],int l,int mid, int h)
    {

            int i = l;
            int j = mid + 1;
            int k = l;
            int *temp = new int[h+1]{};
            while (i <= mid && j<=h)
            {
                    if (elements[i] < elements[j])
                    {
                            temp[k] = elements[i];
                            i++;

                    }
                    else
                    {
                            temp[k] = elements[j];
                            j++;
                    }
                    k++;
            }

            while (i <= mid)
            {
                    temp[k] = elements[i];
                    i++;
                    k++;
            }
            while (j <= h)
            {
                    temp[k] = elements[j];
                    j++;
                    k++;
            }

            for (i = l;i < h+1;i++)
            {
                    elements[i]=temp[i];
            }
            delete[] temp;

    }

    void execute() override
    {
            mergeSort(elements, 0, size-1);
    }

        inline string name() { return "MergeSort"; }
};

#endif