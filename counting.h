#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>
#include <vector>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
                std::vector<int> vector(size, 0);
                for (int &i: vector)
                {
                        ++vector[i];
                }
                int j=0;
                int i=0;
                for (j=0; j<vector.size(); j++)
                {
                        while(vector[j]-->0) {
                                elements[i++]=j;
                        }
                }
        }

        inline string name() { return "CountingSort"; }
};

#endif