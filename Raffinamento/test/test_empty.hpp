#ifndef __TEST_EMPTY_H
#define __TEST_EMPTY_H

#include <gtest/gtest.h>

#include "empty_class.hpp"

using namespace testing;
using namespace Project;

// constr x3
// import x3

// sorting

// bisect
// propagazione

TEST(TestCostruttori, TestCell0D)
{
  unsigned int marker0DT = 0;
  unsigned int id0DT = 1;
  Vector2d CoordT = {2.9, 3.1415};
  Cell0D puntoT = Cell0D(id0DT, marker0DT, CoordT);
  EXPECT_EQ(puntoT.marker0D, marker0DT);
  EXPECT_EQ(puntoT.Id0D, id0DT);
  EXPECT_EQ(puntoT.Coord, CoordT);

}

TEST(TestCostruttori, TestCell1D)
{
  unsigned int marker1DT = 1;
  unsigned int id1DT = 7;
  vector<unsigned int> Vertices1DT = {2, 9};
  Cell1D latoT = Cell1D(id1DT, marker1DT, Vertices1DT);
  EXPECT_EQ(latoT.marker1D, marker1DT);
  EXPECT_EQ(latoT.Id1D, id1DT);
  EXPECT_EQ(latoT.Vertices1D, Vertices1DT);
}


TEST(TestCostruttori, TestCell2D)
{
    unsigned int id2DT = 7;
    array<unsigned int, 3> Vertices2DT = {2, 5, 9};
    array<unsigned int, 3> Edges2DT = {3, 6, 10};
    Cell2D triangoloT = Cell2D(id2DT, Vertices2DT, Edges2DT);
    EXPECT_EQ(triangoloT.Id2D, id2DT);
    EXPECT_EQ(triangoloT.Vertices2D, Vertices2DT);
    EXPECT_EQ(triangoloT.Edges, Edges2DT);
}

// ----------------------------------------------------------------------------------

TEST(TestImport, TestCell0D)
{

    vector<Project::Cell0D> vectpT;

    Vector2d coord3T = {0.0000000000000000e+00, 0.655};

    if(ImportCell0Ds(vectpT))
        EXPECT_EQ(vectpT[0].marker0D, 1);
        EXPECT_EQ(vectpT[2].Id0D, 2);
        EXPECT_EQ(vectpT[3].Coord, coord3T);


}


TEST(TestImport, TestCell1D)
{

    vector<Project::Cell1D> vectsT;
    
    if(ImportCell1Ds(vectsT))
        EXPECT_EQ(vectsT[0].marker1D, 0);
        EXPECT_EQ(vectsT[2].Id1D, 2);
        EXPECT_EQ(vectsT[3].Vertices1D[0], 23);
        EXPECT_EQ(vectsT[7].Vertices1D[1], 50);

}


TEST(TestImport, TestCell2D)
{

    vector<Project::Cell2D> vecttT;
    
    if(ImportCell2Ds(vecttT))
        EXPECT_EQ(vecttT[0].Id2D, 41);
        EXPECT_EQ(vecttT[1].Vertices2D[0], 23);
        EXPECT_EQ(vecttT[2].Vertices2D[1], 51);
        EXPECT_EQ(vecttT[3].Vertices2D[2], 61);
        EXPECT_EQ(vecttT[4].Edges[0], 6);
        EXPECT_EQ(vecttT[5].Edges[1], 9);
        EXPECT_EQ(vecttT[6].Edges[2], 12);

}

// ----------------------------------------------------------------------------------

TEST(TestSorting, TestHeapSort)
{
    vector<unsigned int> vecttSuppT = {31, 45, 23, 3, 99, 7, 10, 25, 66, 69, 77, 88};
    HeapSort(vecttSuppT);
    vector<int> OrderedT = {99, 88, 77, 69, 66, 45, 31, 25, 23, 10, 7, 3};
    EXPECT_EQ(vecttSuppT, OrderedT);
}


// ----------------------------------------------------------------------------------


TEST(TestEmpty, TestEmpty)
{
  Cells::Empty empty;
  ASSERT_NO_THROW(empty.Show());
}



TEST(TestEmpty, TestEmpty)
{
  Cells::Empty empty;
  ASSERT_NO_THROW(empty.Show());
}



#endif // __TEST_EMPTY_H


// constr x3


// sorting
// import x3
// bisect
// propagazione
