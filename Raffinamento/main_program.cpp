#include "empty_class.cpp"



int main()
{
    int numeroIterazioni = 20;
    int howMany = 20;
//  int n = 5; // poi da cambiare: probabilmente è la size di vectsupp in heapsort
    vector<Project::Cell2D> vectSupp;



    Project::Import();
    for (int iter = 0; iter<numeroIterazioni; iter++) {
        HeapSort(vectSupp);
        for (int i = 0; i < howMany; i++) {
            Bisect(vectSupp[i]);
        }
    }


//    empty.Show();

    return 0;
}
