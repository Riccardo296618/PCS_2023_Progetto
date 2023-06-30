#include "empty_class.hpp"
#include "sorting.hpp"

using namespace std;
using namespace Eigen;
using namespace Sorting;
using namespace Project;


int main()
{
//  int n = 5; // poi da cambiare: probabilmente è la size di vectsupp in heapsort
    unsigned int numbercell0D12 = 0;
    vector<Project::Cell0D> vectp12;
    unsigned int numbercell1D12 = 0;
    vector<Project::Cell1D> vects12;
    vector<double> LengthEdges12;
    unsigned int numbercell2D12 = 0;
    std::vector<vector<unsigned int>> LenghtMax12;
    vector<Project::Cell2D> vectt12;


    vector<Project::Cell2D> vectSupp;

    //Project::TriangularMesh mesh;
    Project::ImportCell0Ds(vectp12);
    Project::ImportCell1Ds(vects12);
    Project::ImportCell2Ds(vectt12);
    //Project::MatrAdiac MatriceAdiacenza = Project::MatrAdiac(mesh.vectt, mesh.vects);

    Project::TriangularMesh mesh = Project::TriangularMesh(numbercell0D12, vectp12, numbercell1D12, vects12, LengthEdges12, numbercell2D12, LenghtMax12, vectt12);
    Project::MatrAdiac MatriceAdiacenza = Project::MatrAdiac(mesh.vectt, mesh.vects);

    for (int iter = 0; iter<20; iter++) {
        HeapSort(vectSupp, mesh.vectt);
        for (int i = 0; i < 20; i++) {
            Project::Cell2D& trisupp = vectSupp[i];
            Bisect(trisupp, mesh.vectp, mesh.vects, mesh.vectt, MatriceAdiacenza.Matr);
        }
    }


//    empty.Show();

    return 0;
}
