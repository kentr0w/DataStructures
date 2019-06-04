#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;

// Функция цифровой сортировки
void radixSort(int *numbers, int array_size)
{
    union Un {
        unsigned int a;
        char ch[sizeof(unsigned int)];
    };

    Un* arr_un = new Un[array_size];

    for(int i=0; i<array_size; ++i){
        arr_un[i].a=(unsigned)numbers[i];
    }

    for(int j=0; j<4; ++j) {
        int max = 0;
        for (int i = 0; i < array_size; i++)
            if ((unsigned char) arr_un[i].ch[j] > max)
                max = (unsigned char) arr_un[i].ch[j];
        max += 1;
        int *C = new int[max];
        for (int i = 0; i < max; ++i)
            C[i] = 0;
        for (int i = 0; i < array_size; ++i)
            C[(unsigned char) arr_un[i].ch[j]] += 1;
        for (int i = 1; i < max; ++i)
            C[i] += C[i - 1];
        for (int i = array_size - 1; i >= 0; --i) {
            numbers[C[(unsigned char) arr_un[i].ch[j]] - 1] = arr_un[i].a;
            C[(unsigned char) arr_un[i].ch[j]] -= 1;
        }
        for (int i = 0; i < array_size; ++i)
            arr_un[i].a = (unsigned int)numbers[i];
        delete []C;

    }
    delete[] arr_un;
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
    radixSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}
