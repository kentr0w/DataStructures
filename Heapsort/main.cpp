#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;

//Можно создавать любое количество любых вспомогательных классов, структур и методов для решения задачи.

//Функция сортировки на куче
//Необходимо реализовать данную функцию.
//Результат должен быть в массиве numbers.
void Heapify(int* ages, int q, int n)
{
    if(2*q+1 >= n)
        return;
    int L = ages[2*q+1];
    int R;
    if(2*q+2 >= n)
    {
        if(L > ages[q])
        {
            std::swap(ages[2*q+1], ages[q]);
            Heapify(ages, 2*q+1,n);
        }
    }
    else{
        R = ages[2*q+2];
        if(L > ages[q] || R > ages[q])
            if (L >= R) {
                std::swap(ages[2*q+1], ages[q]);
                Heapify(ages, 2*q+1, n);
            } else {
                std::swap(ages[2*q+2], ages[q]);
                Heapify(ages, 2*q + 2, n);
            }
    }
}

void heapBuild(int *ages, int n)
{
    for(int i= (int)(n/2)-1; i>=0; --i)
        Heapify(ages, i, n);
}
void heapSort(int *numbers, int array_size)
{
    heapBuild(numbers, array_size);
    while(array_size!=2){
        std::swap(numbers[0], numbers[array_size-1]);
        --array_size;
        Heapify(numbers, 0, array_size);
    }
    std::swap(numbers[0], numbers[1]);
}

//Не удалять и не изменять метод main без крайней необходимости.
//Необходимо добавить комментарии, если все же пришлось изменить метод main.
int main()
{
    //Объект для работы с файлами
    ReadWriter rw;

    int *brr = nullptr;
    int n;

    //Ввод из файла
    n = rw.readInt();

    brr = new int[n];
    rw.readArray(brr, n);

    //Запуск сортировки, ответ в том же массиве (brr)
    heapSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}