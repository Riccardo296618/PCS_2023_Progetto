#include <iostream>
#include "Eigen/Eigen"
#include <fstream>
#include <algorithm>
#include "cmath"
#include "empty_class.hpp"
#include "sorting.hpp"

using namespace std;
using namespace Eigen;
using namespace Sorting;
using namespace Project;


int main()
{
//  int n = 5; // poi da cambiare: probabilmente è la size di vectsupp in heapsort

    vector<Project::Cell2D> vectSupp;

    //Project::TriangularMesh mesh;

    unsigned int numbercell0D = 0;
    extern vector<Project::Cell0D> vectp;
    Project::ImportCell0Ds(vectp);

    unsigned int numbercell1D = 0;
    extern vector<Project::Cell1D> vects;
    vector<double> LengthEdges;
    Project::ImportCell1Ds(vects);

    unsigned int numbercell2D = 0;
    std::vector<vector<unsigned int>> LenghtMax;
    extern vector<Project::Cell2D> vectt;
    Project::ImportCell2Ds(vectt);

    //Project::MatrAdiac MatriceAdiacenza = Project::MatrAdiac(mesh.vectt, mesh.vects);

    Project::TriangularMesh mesh = Project::TriangularMesh(numbercell0D, vectp, numbercell1D, vects, LengthEdges, numbercell2D, LenghtMax, vectt);
    vector<vector<unsigned int>> Matr = MatrAdiac(vectt, vects);
    //Project::MatrAdiac MatriceAdiacenza = Project::MatrAdiac(vectt, vects);

    for (int iter = 0; iter<20; iter++) {
        HeapSort(vectSupp, vectt);
        for (int i = 0; i < 20; i++) {
            Project::Cell2D& trisupp = vectSupp[i];
            Bisect(trisupp, vectp, vects, vectt, Matr);   //, MatriceAdiacenza.Matr);
        }
    }


//    empty.Show();

    return 0;
}
