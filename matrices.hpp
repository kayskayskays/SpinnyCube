
#include <cmath>
#include <cstdlib>

struct Matrices {

    static std::vector<std::vector<float>> getRotateX(float angle) {

        std::vector<std::vector<float>> rotateX = {
            { 1.0f, 0.0f, 0.0f },
            { 0.0f, cosf(angle), -sinf(angle) },
            { 0.0f, sinf(angle), cosf(angle) }
        };

        return rotateX;
    };

    static std::vector<std::vector<float>> getRotateY(float angle) {

        std::vector<std::vector<float>> rotateY = {
            { cosf(angle),  0.0f, sinf(angle)},
            { 0.0f, 1.0f, 0.0f},
            { -sinf(angle), 0.0f, cosf(angle)}
        };

        return rotateY;
    }

    static std::vector<std::vector<float>> getRotateZ(float angle) {

        std::vector<std::vector<float>> rotateZ = {
            { cosf(angle), -sinf(angle), 0.0f},
            { sinf(angle), cosf(angle), 0.0f},
            { 0.0f, 0.0f, 1.0f }
        };

        return rotateZ;
    };

    static sf::Vector3f rotateVector(std::vector<std::vector<float>> r, sf::Vector3f p) {

        std::vector<float> v = {0.0f, 0.0f, 0.0f};

        for (uint i{0}; i < 3; i++) {
            v[i] = r[i][0] * p.x + r[i][1] * p.y + r[i][2] * p.z;
        }

        return sf::Vector3f{v[0], v[1], v[2]};
    }

};