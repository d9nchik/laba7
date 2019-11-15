#include <iostream>
#include <random>

using namespace std;

int max(const float array[], int maxArray);

void show(float array[], int maxArray);

int min(const float array[], int maxArray);

void set(float array[], int maxArray);


int main() {
    const int maxf = 5;
    const int maxg = 5;
    float f[maxf];
    float g[maxg];
    set(f, maxf);
    set(g, maxg);
    int maximum = max(f, maxf);
    int minimum = min(g, maxg);
    show(f, maxf);
    show(g, maxg);
    cout << "Максимум f: " << f[maximum] << endl;
    cout << "Минимум g: " << g[minimum] << endl;
    float z =(f[maximum]+g[minimum])/2;
    g[minimum]=f[maximum]=z;
    cout << "z=" << z << endl;
    show(f, maxf);
    show(g, maxg);
    return 0;
}

int max(const float *array, int maxArray) {
    int maxReturn = 0;

    for (int i = 1; i < maxArray - 1; ++i) {
        maxReturn = (array[maxReturn] < array[i]) ? i : maxReturn;
    }
    return maxReturn;
}

int min(const float *array, int maxArray) {
    int minReturn = 0;

    for (int i = 1; i < maxArray - 1; ++i) {
        minReturn = (array[minReturn] > array[i]) ? i : minReturn;
    }
    return minReturn;
}

void show(float array[], int maxArray) {
    for (int i = 0; i < maxArray; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void set(float array[], int maxArray) {
    random_device rd;
    mt19937 mersenne(rd());
    for (int i = 0; i < maxArray; ++i) {
        array[i] = (float)(mersenne()/10000.0);
    }
}