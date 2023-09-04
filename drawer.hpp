#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
class drawer
{
private:
    float mag;
    float freq;
    float theta;
    float lifeTime;

public:
    float cx;
    float cy;
    float x;
    float y;
    drawer(float cx, float cy, float mag, float freq, float theta);
    void update(float deltaTime, float newCx, float newCy);
    void draw(sf::RenderWindow &window)
    {
        // draw the outline circle
        sf::CircleShape outline(mag);
        outline.setOrigin(sf::Vector2f(mag, mag));
        outline.setFillColor(sf::Color::Transparent);
        outline.setOutlineThickness(1.0f);
        outline.setPosition(sf::Vector2f(cx, cy));
        window.draw(outline);
        // draw the tracking line
        sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(cx, cy)),
                sf::Vertex(sf::Vector2f(x, y))};
        window.draw(line, 2, sf::Lines);
    };
};

drawer::drawer(float cx, float cy, float mag, float freq, float theta = 0) : cx(cx), cy(cy), mag(mag), freq(freq), theta(theta), lifeTime(0)
{
    x = cx + mag * cos(theta);
    y = cy + mag * sin(theta);
}
void drawer::update(float deltaTime, float newCx = 0, float newCy = 0)
{
    lifeTime += deltaTime;
    theta = (lifeTime * freq) * (2 * M_PI);
    // theta +=0.01;
    x = newCx + mag * cos( theta);
    y = newCy + mag * sin( theta);
    cx = newCx;
    cy = newCy;
}
