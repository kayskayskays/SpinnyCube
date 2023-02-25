
#include <cstdlib>
#include <cmath>
#include "matrices.hpp"

struct Cube { // a collection of vertices

    sf::Vector3f position;
    std::vector<sf::Vector3f> vertices;
    std::vector<std::tuple<sf::Vector3f, sf::Vector3f>> edges;
    float height = 300.0;

    explicit
    Cube(float window_width, float height = 300) {

        sf::Vector3f center = {window_width / 2, window_width / 2, window_width / 2};

        sf::Vector3f vertex_1 = {center.x + height / 2, center.y + height / 2, center.z - height / 2};
        vertices.emplace_back(vertex_1);
        sf::Vector3f vertex_2 = {center.x - height / 2, center.y + height / 2, center.z - height / 2};
        vertices.emplace_back(vertex_2);
        sf::Vector3f vertex_3 = {center.x + height / 2, center.y - height / 2, center.z - height / 2};
        vertices.emplace_back(vertex_3);
        sf::Vector3f vertex_4 = {center.x - height / 2, center.y - height / 2, center.z - height / 2};
        vertices.emplace_back(vertex_4);
        sf::Vector3f vertex_5 = {center.x + height / 2, center.y + height / 2, center.z + height / 2};
        vertices.emplace_back(vertex_5);
        sf::Vector3f vertex_6 = {center.x - height / 2, center.y + height / 2, center.z + height / 2};
        vertices.emplace_back(vertex_6);
        sf::Vector3f vertex_7 = {center.x + height / 2, center.y - height / 2, center.z + height / 2};
        vertices.emplace_back(vertex_7);
        sf::Vector3f vertex_8 = {center.x - height / 2, center.y - height / 2, center.z + height / 2};
        vertices.emplace_back(vertex_8);

    }

    void rotateVerticesX(float angle) {
        for (auto& vertex : vertices) {
            vertex = Matrices::rotateVector(Matrices::getRotateX(angle), vertex);
        }
    }

    void rotateVerticesY(float angle) {
        for (auto& vertex : vertices) {
            vertex = Matrices::rotateVector(Matrices::getRotateY(angle), vertex);
        }
    }

    void rotateVerticesZ(float angle) {
        for (auto& vertex : vertices) {
            vertex = Matrices::rotateVector(Matrices::getRotateZ(angle), vertex);
        }
    }

    [[nodiscard]]
    std::vector<sf::Vector3f> getVertices() const {
        return vertices;
    }




};