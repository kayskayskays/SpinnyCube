
#include <cstdlib>
#include <cmath>
#include "matrices.hpp"

struct Cube { // a collection of vertices

    std::vector<sf::Vector3f> vertices;
    std::vector<std::tuple<sf::Vector3f, sf::Vector3f>> edges;
    sf::Vector3f center;

    explicit
    Cube(float window_width, float height = 300) {

        center = {window_width / 2, window_width / 2, window_width / 2};

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

        edges.emplace_back(vertex_1, vertex_2);
        edges.emplace_back(vertex_1, vertex_3);
        edges.emplace_back(vertex_1, vertex_5);
        edges.emplace_back(vertex_2, vertex_4);
        edges.emplace_back(vertex_2, vertex_6);
        edges.emplace_back(vertex_3, vertex_4);
        edges.emplace_back(vertex_3, vertex_7);
        edges.emplace_back(vertex_4, vertex_8);
        edges.emplace_back(vertex_5, vertex_6);
        edges.emplace_back(vertex_5, vertex_7);
        edges.emplace_back(vertex_6, vertex_8);
        edges.emplace_back(vertex_7, vertex_8);

    }

    void updateEdges() {
        edges.clear();
        edges.emplace_back(vertices[0], vertices[1]);
        edges.emplace_back(vertices[0], vertices[2]);
        edges.emplace_back(vertices[0], vertices[4]);
        edges.emplace_back(vertices[1], vertices[3]);
        edges.emplace_back(vertices[1], vertices[5]);
        edges.emplace_back(vertices[2], vertices[3]);
        edges.emplace_back(vertices[2], vertices[6]);
        edges.emplace_back(vertices[3], vertices[7]);
        edges.emplace_back(vertices[4], vertices[5]);
        edges.emplace_back(vertices[4], vertices[6]);
        edges.emplace_back(vertices[5], vertices[7]);
        edges.emplace_back(vertices[6], vertices[7]);
    }

    void rotateVerticesX(float angle) {
        for (auto& vertex : vertices) {
            translateVectorOrigin(vertex);
            vertex = Matrices::rotateVector(Matrices::getRotateX(angle), vertex);
            translateVectorCenter(vertex);
            updateEdges();
        }
    }

    void rotateVerticesY(float angle) {
        for (auto& vertex : vertices) {
            translateVectorOrigin(vertex);
            vertex = Matrices::rotateVector(Matrices::getRotateY(angle), vertex);
            translateVectorCenter(vertex);
            updateEdges();
        }
    }

    void rotateVerticesZ(float angle) {
        for (auto& vertex : vertices) {
            translateVectorOrigin(vertex);
            vertex = Matrices::rotateVector(Matrices::getRotateZ(angle), vertex);
            translateVectorCenter(vertex);
            updateEdges();
        }
    }

    void translateVectorOrigin(sf::Vector3f& p) const {
        p.x -= center.x;
        p.y -= center.y;
        p.z -= center.z;
    }

    void translateVectorCenter(sf::Vector3f& p) const {
        p.x += center.x;
        p.y += center.y;
        p.z += center.z;
    }

    [[nodiscard]]
    std::vector<sf::Vector3f> getVertices() const {
        return vertices;
    }

    [[nodiscard]]
    std::vector<std::tuple<sf::Vector3f, sf::Vector3f>> getEdges() const {
        return edges;
    }

};