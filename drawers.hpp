#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "drawer.hpp"
#include <string>
class drawers
{
private:
    float cx;
    float cy;
    int n;

public:
    std::vector<drawer> elements;
    drawers(float cx, float cy, int n,std::string func);
    void draw(sf::RenderWindow &window)
    {
        for (auto &element : elements)
        {
            element.draw(window);
        }
    }
    void update(float deltaTima)
    {
        float newCx = cx;
        float newCy = cy;
        for (auto &element : elements)
        {
            element.update(deltaTima, newCx, newCy);
            newCx = element.x;
            newCy = element.y;
        }
    }
};

drawers::drawers(float cx, float cy, int n,std::string func) : cx(cx), cy(cy), n(n)
{
    float newCx = cx;
    float newCy = cy;
    for (int i = 0; i <= n; i++)
    {
        float freq = i*2+1;
        drawer element = drawer(newCx, newCy, 50 * (4 /  ((freq)* M_PI)), (freq));
        elements.push_back(element);
        newCx = element.x;
        newCy = element.y;
    }
}
