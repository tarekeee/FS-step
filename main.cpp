#include "drawer.hpp"
#include "graph.hpp"
#include "drawers.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    // create the window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Default, settings);
    sf::Clock clock;
    // run the program as long as the window is open
    window.setFramerateLimit(60);
    int n;
    if (argc == 0)
    {
        n = 10;
    }
    else
    {
        n = std::stoi(argv[1]);
    }
    drawers test(200, 200, n,"stesp");
    graph wave(300);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        float deltaTime = clock.restart().asSeconds();
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        test.update(deltaTime);
        wave.update(test.elements[test.elements.size() - 1].y);

        sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(test.elements[test.elements.size() - 1].x, test.elements[test.elements.size() - 1].y), sf::Color::Yellow),
                sf::Vertex(sf::Vector2f(wave.startX, test.elements[test.elements.size() - 1].y), sf::Color::Yellow)};
        window.draw(line, 2, sf::Lines);
        test.draw(window);
        wave.draw(window);

        // end the current frame
        window.display();
    }

    return 0;
}
