
#include <SFML/graphics.hpp>
#include "cube.hpp"
#include "renderer.hpp"

int main() {

    constexpr uint32_t window_width = 1000;
    constexpr uint32_t window_height = 1000;
    const uint32_t frame_rate = 60;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Cube", sf::Style::Default, settings);
    window.setFramerateLimit(frame_rate);

    Renderer renderer(window);

    Cube cube(static_cast<float>(window_width), 300);

    const float angle_increment = 0.0005f;
    float roll = 0.0f;  // x
    float pitch = 0.0f; // y
    float yaw = 0.0f;  // z

    while (window.isOpen()) {

        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                roll -= angle_increment;
                cube.rotateVerticesX(roll);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                roll += angle_increment;
                cube.rotateVerticesX(roll);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                pitch -= angle_increment;
                cube.rotateVerticesY(pitch);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                pitch += angle_increment;
                cube.rotateVerticesY(pitch);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                yaw -= angle_increment;
                cube.rotateVerticesZ(yaw);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                yaw += angle_increment;
                cube.rotateVerticesZ(yaw);
            }

        }

        window.clear(sf::Color::Black);
        renderer.render(cube);
        window.display();

    }

    return 0;
}
