
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

        const auto& edges = cube.getEdges();
        for (auto& edge : edges) {
            sf::Vertex line[] {
                sf::Vertex(sf::Vector2f(std::get<0>(edge).x, std::get<0>(edge).y)),
                sf::Vertex(sf::Vector2f(std::get<1>(edge).x, std::get<1>(edge).y))
            };
            target.draw(line, 2, sf::Lines);
        }
    }
};