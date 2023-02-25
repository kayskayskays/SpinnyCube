
#include <cmath>
#include <cstdlib>


struct Matrices {

    float angle = 0.0f;

    float rotateX[3][3] = {
            {1, 0, 0},
            {0, cos(angle), -sin(angle)},
            {0, sin(angle), cos(angle)}
    };

    float rotateY[3][3] = {
            {cos(angle), 0, sin(angle)},
            {0, 1, 0},
            {-sin(angle), 0, cos(angle)}
    };

    float rotateZ[3][3] = {

    };

};