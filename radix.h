#ifndef RADIX_H
#define RADIX_H

#include "sort.h"
#include "vector"

class RadixSort : public Sort {       
    public:
        RadixSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {

                int n = 1;
                int max = 0;

                bool ordenado = false;
                for (int i = 0; i < size; i++) {
                        if (elements[i] > max) {
                                max = elements[i];
                        }
                }

                while(max) {

                        vector<int> buckets(10, 0);
                        vector<int> tmp_v(size, 0);

                        max = max / 10;

                        for (int i=0; i<size; i++) {
                                buckets[ elements[i] / n % 10 ] += 1;
                        }
                        for (int i=1; i<buckets.size(); i++) {
                                buckets[i] += buckets[i-1];
                        }
                        for (int i=size-1; i>=0; --i) {
                                tmp_v[ --buckets[elements[i] / n % 10]] = elements[i];
                        }
                        for (int i=0; i<size; i++) {
                                elements[i] = tmp_v[i];
                        }

                        n = n*10;
                }
        }

        inline string name() { return "RadixSort"; }
};

#endif