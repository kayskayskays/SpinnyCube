
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
        }
    }
};