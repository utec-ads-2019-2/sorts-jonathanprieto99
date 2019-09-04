#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
                int llave;
                int i;
                int j;
                for (i = 1; i < size; i++)
                {
                        llave = elements[i];
                        j = i - 1;

                        while (j >= 0 && elements[j] > llave)
                        {
                                elements[j + 1] = elements[j];
                                j = j - 1;
                        }
                        elements[j + 1] = llave;
                }
        }

        inline string name() { return "InsertSort"; }
};

#endif