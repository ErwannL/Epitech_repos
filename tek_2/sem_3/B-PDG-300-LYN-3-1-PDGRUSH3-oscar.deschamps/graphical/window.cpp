/*
** EPITECH PROJECT, 2023
** illegale_rush_3
** File description:
** window
*/

#include "window.hpp"

void Event(sf::RenderWindow &window, sf::Event event)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

}

void draw_element(subInterface subInter, std::list<infoBlock> list_blocks, sf::RenderWindow &window)
{
    window.draw(subInter.getRec_back());
    window.draw(subInter.getScale());
    window.draw(subInter.getTime());

    for (infoBlock block : list_blocks)
    {
        window.draw(block.getRec_back());
        window.draw(block.getGraph());
    }
}

float getFloat(const std::string& string)
{
    std::stringstream ss(string);
    std::string temp;
    float usedMemory;
    ss >> temp >> usedMemory >> temp;
    return usedMemory;
}

void draw_simplElement(CreateText box, sf::RenderWindow &window)
{
    window.draw(box.getText());
    window.draw(box.getRect());
}


int window()
{
    var var;
    IMonitorModuleUser user(0, 0, 50, 5);
    IMonitorModuleCPU cpu(51, 0, 70, 8);
    IMonitorModuleOS os(0, 6, 50, 5);
    IMonitorModuleRAM ram(122, 0, 50, 6);
    IMonitorModuleTime time(122, 7, 50, 4);
    IMonitorModuleNetwork network(51, 9, 70, 4);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default);
    subInterface cpuInterface(1, sf::Vector2f(10, 300), sf::Vector2f(700, 200), "cpu");
    CreateText userInterface(std::string("USER : " + user.getUser()), sf::Vector2f(10, 10), sf::Vector2f(150.f, 50.f));
    CreateText osInterface(std::string("OS : " + os.getOname()), sf::Vector2f(10, 100), sf::Vector2f(150.f, 25.f));
    CreateText subRam(std::string("Ram use " + ram.getUsed()), sf::Vector2f(220, 170), sf::Vector2f(250.f, 25.f));
    CreateText TotalRam(std::string("Ram total " + ram.getTotal()), sf::Vector2f(500, 170), sf::Vector2f(250.f, 25.f));
    CreateText timeInterface(time.getTime(), sf::Vector2f(10, 550), sf::Vector2f(300.f, 25.f));
    subInterface ramInterface(1, sf::Vector2f(200, 10), sf::Vector2f(590, 200), "ram");
    CreateText networdInterface(std::string("NETWORK : " + network.getIP()), sf::Vector2f(450, 550), sf::Vector2f(320.f, 25.f));
    CreateText Ramdispo(sf::String("RAM dispo :" + ram.getAvailable()), sf::Vector2f(10, 470), sf::Vector2f(400.f, 25.f));
    cpu.getInfos();

    while (window.isOpen())
    {
        var.elapsed1 = var.clock.getElapsedTime();
        Event(window, var.event);
        if (var.elapsed1.asSeconds() <= 0.1) {
            draw_element(cpuInterface, cpuInterface.getBlocks(), window);
            draw_element(ramInterface, ramInterface.getBlocks(), window);
            draw_simplElement(userInterface, window);
            draw_simplElement(osInterface, window);
            draw_simplElement(timeInterface, window);
            draw_simplElement(networdInterface, window);
            draw_simplElement(TotalRam, window);
            draw_simplElement(subRam, window);
            draw_simplElement(Ramdispo, window);
        } else {
            std::cout << cpu.getValues()[2] << std::endl;
            cpuInterface.updateListGraph((getFloat(cpu.getValues()[3]))/100);
            ramInterface.updateListGraph((getFloat(ram.getUsed()) * 100) / getFloat(ram.getTotal()));
            subRam.updateText((sf::String("Ram use ") + sf::String(ram.getUsed())));
            cpu.refresh();
            ram.refresh();
            window.display();
            window.clear();
            var.clock.restart();
        }
    }

    return 0;
}
