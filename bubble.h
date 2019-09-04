#ifndef BUBBLE_H
#define BUBBLE_H

#include "sort.h"
#include <algorithm>

class BubbleSort : public Sort {       
    public:
        BubbleSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int  j;
            int i;
            for (i=0; i<size-1 ; i++) {
                for (j=0; j<size-i-1 ; j++){
                    int valor1=elements[j];
                    int valor2=elements[j+1];
                    if(valor1>valor2){
                        elements[j]=valor2;
                        elements[j+1]=valor1;
                    }
                }
            }
        }

        inline string name() { return "BubbleSort"; }
};

#endif