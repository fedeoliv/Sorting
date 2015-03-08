#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*  Quick sort using 3-way partitioning. It's considered more efficient than
    common quicksort, because it's prepared for duplicate keys. */

vector<string> a;

void shuffle() {
    int N = a.size();
    for (int i = 0; i < N; i++) {
        int r = i + (rand() % (N-i));     // between i and N-1
        string temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}

// exchange a[i] and a[j]
void swap(int i, int j) {
    string tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

// quicksort the subarray a[lo .. hi] using 3-way partitioning
void quickSort(int lo, int hi) {
    if (hi <= lo) return;
    int lt = lo, gt = hi;
    string v = a[lo];
    int i = lo;
    while (i <= gt) {
        if (a[i] < v) swap(lt++, i++);
        else if (a[i] > v) swap(i, gt--);
        else i++;
    }

    quickSort(lo, lt-1);
    quickSort(gt+1, hi);
}

void printArr() {
    for(vector<string>::iterator it = a.begin(); it != a.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void sortArr() {
    shuffle();
    quickSort(0, a.size() - 1);
    printArr();
}

int main() {
    srand(time(NULL));

    a.push_back("P");
    a.push_back("A");
    a.push_back("B");
    a.push_back("X");
    a.push_back("W");
    a.push_back("P");
    a.push_back("P");
    a.push_back("D");
    a.push_back("C");

    sortArr();
    return 0;
}
