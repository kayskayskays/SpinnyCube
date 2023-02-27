
#include <SFML/graphics.hpp>
#include "cube.hpp"
#include "renderer.hpp"

int main() {

    constexpr uint32_t window_width = 1000;
    constexpr uint32_t window_height = 1000;
    const uint32_t frame_rate = 60;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Spinny Cube", sf::Style::Default, settings);
    window.setFramerateLimit(frame_rate);

    Renderer renderer(window);

    Cube cube(static_cast<float>(window_width), 300);

    const float angle_increment = 0.05f;

    while (window.isOpen()) {

        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                cube.rotateVerticesX(-angle_increment);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                cube.rotateVerticesX(angle_increment);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                cube.rotateVerticesY(-angle_increment);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                cube.rotateVerticesY(angle_increment);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                cube.rotateVerticesZ(-angle_increment);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                cube.rotateVerticesZ(angle_increment);
            }

        }

        window.clear(sf::Color::Black);
        renderer.render(cube);
        window.display();

    }

    return 0;
}
