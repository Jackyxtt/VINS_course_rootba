//
// Created by yxt on 2022/8/31.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main() {
//    Matrix3d A;
//    A << 1, 0, 0,
//            0, 1, 0,
//            0, 0, 1;
//    cout << "test scalar" << endl;
//    Vector4d b1(1, 0, 1, 0);
//    Vector4d b2(0, 1, 0, 1);
////    Vector4d b3(0, 0, 0, 1);
//
//    Eigen::JacobiRotation<double> gr;
//
////    gr.makeGivens(b3.x(), b3.w());
////    b1.applyOnTheLeft(0, 3, gr.adjoint());
////    b2.applyOnTheLeft(0, 3, gr.adjoint());
//////    b3.applyOnTheLeft(0, 3, gr.adjoint());
////    cout << "second time givens" << endl;
////    cout << "b1 = \n" << b1 << endl;
////    cout << "b2 = \n" << b2 << endl;
////    cout << "b3 = \n" << b3 << endl;
//
//    gr.makeGivens(b1.x(), b1.z());
//    b1.applyOnTheLeft(0, 2, gr.adjoint());
//    b2.applyOnTheLeft(0, 2, gr.adjoint());
////    b3.applyOnTheLeft(0, 1, gr.adjoint());
//    cout << "first time givens" << endl;
//    cout << "b1 = \n" << b1 << endl;
//    cout << "b2 = \n" << b2 << endl;
////    cout << "b3 = \n" << b3 << endl;
//
//    gr.makeGivens(b2.y(), b2.w());
//    b1.applyOnTheLeft(1, 3, gr.adjoint());
//    b2.applyOnTheLeft(1, 3, gr.adjoint());
////    b3.applyOnTheLeft(0, 2, gr.adjoint());
//    cout << "second time givens" << endl;
//    cout << "b1 = \n" << b1 << endl;
//    cout << "b2 = \n" << b2 << endl;
////    cout << "b3 = \n" << b3 << endl;

    cout << "test matrix" << endl;

    Vector4d bb1(1, 0, 1, 0);
    Vector4d bb2(1, 1, 0, 1);

    Matrix<double, 4, 2> B;
    B.block(0,0,4,1) = bb1;
    B.block(0,1,4,1) = bb2;
    cout << B << endl;

    Eigen::JacobiRotation<double> gr;
    gr.makeGivens(B(0,0), B(2,0));
    B.applyOnTheLeft(0, 2, gr.adjoint());
//    b3.applyOnTheLeft(0, 1, gr.adjoint());
    cout << "first time givens" << endl;
    cout << "B = \n" << B << endl;

    gr.makeGivens(B(1,1), B(3,1));
    B.applyOnTheLeft(1, 3, gr.adjoint());
//    b3.applyOnTheLeft(0, 1, gr.adjoint());
    cout << "second time givens" << endl;
    cout << "B = \n" << B << endl;


    return 0;
}