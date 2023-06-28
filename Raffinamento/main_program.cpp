#include "empty_class.cpp"



int main()
{
//  int n = 5; // poi da cambiare: probabilmente è la size di vectsupp in heapsort
    vector<Project::Cell2D> vectSupp;
    Project::TriangularMesh mesh;
    Project::Import();
    Project::MatrAdiac MatriceAdiacenza = Project::MatrAdiac(mesh.vectt, mesh.vects);



    for (int iter = 0; iter<20; iter++) {
        HeapSort(vectSupp, Project::mesh.vectt);
        for (int i = 0; i < 20; i++) {
            Project::Cell2D& trisupp = vectSupp[i];
            Bisect(trisupp, mesh.vectp, mesh.vects, mesh.vectt, MatriceAdiacenza.Matr);
        }
    }


//    empty.Show();

    return 0;
}
