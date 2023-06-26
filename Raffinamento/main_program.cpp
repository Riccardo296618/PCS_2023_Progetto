#include "empty_class.cpp"


// INSERIRE IMPORT


int main()
{
    int numeroIterazioni = 20;
    int howMany = 20;
//  int n = 5; // poi da cambiare: probabilmente è la size di vectsupp in heapsort
    vector<Cells::Cell2D> vectSupp;

    for (int iter = 0; iter<numeroIterazioni; iter++) {
        HeapSort(vectSupp);
        for (int i = 0; i < howMany; i++) {
            Bisect(vectSupp[i]);
        }
    }


//    empty.Show();

    return 0;
}
