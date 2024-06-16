#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

int main(int argc, char **argv) {
    Matrix3d rotation_matrix = Matrix3d::Identity();
    // The rotation vector uses AngleAxis, the underlying layer is not directly Matrix
    // but the operation can be treated as a matrix because the operator is overloaded
    AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1)); // rotate 45 degrees along the Z axis
    cout.precision(3);
    cout << "rotation matrix = \n" << rotation_vector.matrix() << endl;
    rotation_matrix = rotation_vector.toRotationMatrix();
    // coordinate transformation with AngleAxis
    Vector3d v(1, 0, 0);
    Vector3d v_rotated = rotation_vector * v;
    cout << "(1,0,0) after rotation (by angle axis) = " << v_rotated.transpose() << endl;
    // Or by using a matrix
    v_rotated = rotation_matrix * v;
    cout << "(1,0,0) after rotation (by matrix) = " << v_rotated.transpose() << endl;

    // Euler angle: Converting rotation matrix directly into Euler angles
    Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0); // ZYX order, ie roll pitch yaw order
    cout << "yaw pitch roll = " << euler_angles.transpose() << endl;

    // Euclidean transformations
    Isometry3d T = Isometry3d::Identity(); // although called 3d it is essentially a 4*4 matrix
    T.rotate(rotation_vector); // Rotate according to rotation_vector
    T.pretranslate(Vector3d(1, 3, 4)); // Set the translation vector to (1,4,4)
    cout << "Transform matrix = \n" << T.matrix() << endl;

    // Using the transformation matrix for coordiante transformation
    Vector3d v_transformed = T * v; // equivalent to R*v + t
    cout << "v transformed = " << v_transformed.transpose() << endl;

    // Quaternion
    // Assigning angle axis directly to quaternions, and vice verse
    Quaterniond q = Quaterniond(rotation_vector);
    cout << "quaternion from rotation vector = " << q.coeffs().transpose() << endl;
    // The order of coeffs is (x, y, z, w) where w is the real part, the first 3 imaginary
    // Can also assign a rotation matrix to it
    q = Quaterniond(rotation_matrix);
    cout << "Quaternion from rotation matrix = " << q.coeffs().transpose() << endl;
    // Rotate a vector with a quaternion and use overloaded multiplication
    v_rotated = q * v; // Note that the math is qvq^{-1}
    cout << "(1, 0, 0) after rotation = " << v_rotated.transpose() << endl;
    // Expressed by regular vector multiplication, it should be calculated as follows
    cout << "should be equal to " << (q * Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose() << endl;

    return 0;
}