#include "empty_class.hpp"



int main()
{

    vector<Cells::Cell2D> vectSupp;

    unsigned int numbercell0D;
    vector<Project::Cell0D> vectp;
    unsigned int numbercell1D;
    vector<Project::Cell1D> vects;
    vector<double> LengthEdges;
    unsigned int numbercell2D;
    std::vector<vector<unsigned int>> LenghtMax;
    vector<Project::Cell2D> vectt;


    Project::ImportCell0Ds();
    Project::ImportCell1Ds();
    Project::ImportCell2Ds();
    Project::MatrAdiac MatriceAdiacenza = Project::MatrAdiac(mesh.vectt, mesh.vects);

   for (int iter = 0; iter<20; iter++) {
        HeapSort(vectSupp, Project::mesh.vectt);
        for (int i = 0; i < 20; i++) {
            Project::Cell2D& trisupp = vectSupp[i];
            Bisect(trisupp, mesh.vectp, mesh.vects, mesh.vectt, MatriceAdiacenza.Matr);
        }

   }


    return 0;
}
