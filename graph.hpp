#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
class graph
{
private:
    std::vector<sf::Vertex> wave{};

public:
    float startX;
    graph(float startX);
    void draw(sf::RenderWindow &window)
    {
        if (wave.size() > 1500)
        {
            wave.pop_back();
        }
        window.draw(&wave[0], wave.size(), sf::LinesStrip);
    }
    void update(float y)
    {
        std::vector<sf::Vertex> tempWave{sf::Vertex(sf::Vector2f(startX, y), sf::Color::Yellow)};
        for (int i = 0; i < wave.size(); i++)
        {
            tempWave.push_back(sf::Vertex(sf::Vector2f(startX + (i + 1), wave[i].position.y), sf::Color::Yellow));
        }
        wave = tempWave;
    }
};

graph::graph(float startX) : startX(startX)
{
}
