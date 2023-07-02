#include "empty_class.hpp"



int main()
{

    vector<Cells::Cell2D> vectSupp;

    unsigned int numbercell0D12 = 0;
    vector<Project::Cell0D> vectp12;
    unsigned int numbercell1D12 = 0;
    vector<Project::Cell1D> vects12;
    vector<double> LengthEdges12;
    unsigned int numbercell2D12 = 0;
    std::vector<vector<unsigned int>> LenghtMax12;
    vector<Project::Cell2D> vectt12;


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
