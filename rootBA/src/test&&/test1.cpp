//
// Created by yxt on 2022/8/31.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    Matrix3d A;
    A << 1, 1, 1,
            2, -1, -1,
            2, -4, 5;

    // &&B为什么可以这么写
    MatrixXd &&B = A.block(0, 0, 2, 1);
    cout << B << endl;
//    MatrixX<Scalar> &&Jl = this->storage.block(0, cols - 4, rows - 3, 3);
    HouseholderQR<MatrixXd> qr;
    qr.compute(A);
//    MatrixXd R = qr.matrixQR().triangularView<Eigen::Upper>();
//    MatrixXd Q = qr.householderQ();
//    cout << "HouseholderQR" << endl;
//    cout << "A " << endl << A << endl << endl;
//    cout << "qr.matrixQR()" << endl << qr.matrixQR() << endl << endl;
//    cout << "Q " << endl << Q << endl << endl;
//    cout << "Q*Q " << endl << Q * Q.transpose() << endl << endl;
//    cout << "R" << endl << R << endl << endl;
//    cout << "Q*R" << endl << Q * R << endl;
}