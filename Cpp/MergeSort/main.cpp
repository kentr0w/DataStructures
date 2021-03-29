#include "ReadWriter.h"
#include "MergeSort.h"
//iostream, fstream включены в ReadWriter.h

//Не рекомендуется добавлять собственные вспомогательные классы и методы.
//Необходимо использовать уже имеющиеся классы и методы, добавив реализацию, соответствующую описанию.
using namespace std;

//Описание методов на английском языке имеется в классе MergeSort, в файле MergeSort.h
void MergeSort::sort(int *arr, int length)
{
    divide_and_merge(arr, 0, length-1);
}

void MergeSort::merge(int* arr, int first, int second, int end) {
    int l, r;
    l = r = 0;
    int x = second - first + 1;
    int y = end - second;

    int* left_arr = new int[x];
    int* right_arr = new int[y];

    for (int i = 0; i < x; ++i)
        left_arr[i] = arr[first + i];
    for (int i = 0; i < y; ++i)
        right_arr[i] = arr[second + 1 + i];

    int count = first;
    while (l < x && r < y) {
        if (left_arr[l] <= right_arr[r]) {
            arr[count] = left_arr[l];
            ++l;
        } else {
            arr[count] = right_arr[r];
            ++r;
        }
        ++count;
    }
    if (l != x) {
        while (l < x) {
            arr[count] = left_arr[l];
            l++;
            count++;
        }
    }
    if(r!=y){
        while (r < y) {
            arr[count] = right_arr[r];
            r++;
            count++;
        }
    }
    delete [] right_arr;
    delete [] left_arr;
}

void MergeSort::divide_and_merge(int *arr, int left, int right)
{
    if(left < right){
        int m = (left + right)/2;
        divide_and_merge(arr, left, m);
        divide_and_merge(arr, m+1, right);
        merge(arr, left, m , right);
    }
}

int main()
{
    ReadWriter rw;

    int *brr = nullptr;
    int length;

    //Read data from file
    length = rw.readInt();

    brr = new int[length];
    rw.readArray(brr, length);

    //Start sorting
    MergeSort s;

    s.sort(brr, length);

    //Write answer to file
    rw.writeArray(brr, length);

    delete[] brr;

    return 0;
}