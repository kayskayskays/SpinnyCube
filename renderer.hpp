
struct Renderer {

    sf::RenderTarget& target;

    explicit
    Renderer(sf::RenderTarget& target_)
    : target {target_}
    {}

    void render(const Cube& cube) {

        sf::CircleShape circle{1.0f};
        circle.setPointCount(32);
        circle.setOrigin(1.0f, 1.0f);

        const auto& vertices = cube.getVertices();
        for (auto& vertex : vertices) {
            circle.setPosition(vertex.x, vertex.y);
            circle.setScale(15.0f, 15.0f);
            circle.setFillColor(sf::Color::White);
            target.draw(circle);
        }

        for (uint i{0}; i < vertices.size(); i++) {
            for (uint j{0}; j < vertices.size(); j++) {
                sf::Vertex line[] {
                    sf::Vertex(sf::Vector2f(vertices[i].x, vertices[i].y)),
                    sf::Vertex(sf::Vector2f(vertices[j].x, vertices[j].y))
                };
                target.draw(line, 2, sf::Lines);
            }
        }
    }
};