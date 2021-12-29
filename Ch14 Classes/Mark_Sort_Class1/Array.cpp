/* 
 * File:   Array.h
 * Author: arlen
 * Created on November 28, 2021, 4:42 PM
 * Purpose: Class specification
 */

#include "Array.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Array::Array(int n){
    //Allocate the data
    size=(n>=2&&n<=1000)?n:2;
    data=new int[size];
    //Fill the array
    for(int i=0;i<size;i++){
        data[i]=rand()%90+10;//[10,99]
    }
}

Array::~Array(){
    delete []data;
}

void Array::display(int perLine){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<data[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void Array::sort(){
    for(int pos=0;pos<size-1;pos++){//Works on each position in the list
        for(int i=pos+1;i<size;i++){//Compare and swap with lower elements in the list
            if(data[pos]>data[i]){//Swap
                data[pos]=data[pos]^data[i];
                data[i]=data[pos]^data[i];
                data[pos]=data[pos]^data[i];
            }
        }
    }
}