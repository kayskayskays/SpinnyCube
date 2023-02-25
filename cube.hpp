
#include <cstdlib>
#include <cmath>
#include "matrices.hpp"

struct Vertex {

    sf::Vector3f position;
    sf::Color color = sf::Color::White;
    float radius = 15.0f;

    Vertex() = default;

    explicit
    Vertex(sf::Vector3f position_, float radius_ = 15.0f)
    : position {position_}
    , radius {radius_}
    {}

};

struct Cube { // a collection of vertices

    sf::Vector3f position;
    std::vector<Vertex> vertices;
    float height = 300.0;


    Cube(float window_width, float height = 300) {

        sf::Vector3f center = {window_width / 2, window_width / 2, window_width / 2};
        vertices.emplace_back(center);

        sf::Vector3f vertex_1 = {center.x + height / 2, center.y + height / 2, center.z - height / 2};
        vertices.emplace_back(vertex_1);
        sf::Vector3f vertex_2 = {center.x - height / 2, center.y + height / 2, center.z - height / 2};
        vertices.emplace_back(vertex_2);
        sf::Vector3f vertex_3 = {center.x + height / 2, center.y - height / 2, center.z - height / 2};
        vertices.emplace_back(vertex_3);
        sf::Vector3f vertex_4 = {center.x - height / 2, center.y - height / 2, center.z - height / 2};
        vertices.emplace_back(vertex_4);
        sf::Vector3f vertex_5 = {center.x + height / 2, center.y + height / 2, center.z - height / 2};
        vertices.emplace_back(vertex_5);
        sf::Vector3f vertex_6 = {center.x - height / 2, center.y + height / 2, center.z - height / 2};
        vertices.emplace_back(vertex_6);
        sf::Vector3f vertex_7 = {center.x + height / 2, center.y - height / 2, center.z - height / 2};
        vertices.emplace_back(vertex_7);
        sf::Vector3f vertex_8 = {center.x - height / 2, center.y - height / 2, center.z - height / 2};
        vertices.emplace_back(vertex_8);

    }

    [[nodiscard]]
    std::vector<Vertex> getVertices() const {
        return vertices;
    }


};