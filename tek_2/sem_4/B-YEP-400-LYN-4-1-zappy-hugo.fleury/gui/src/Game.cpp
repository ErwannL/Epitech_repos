/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Game
*/

#include "../include/Game.hpp"
#include <sstream>

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(sf::RenderWindow &window, std::shared_ptr<Client> &client)
{
    _client = client;
    std::vector<std::string> initData = splitCmd(client.get()->recvCmd());
    _textureMap["AllAssets"].loadFromFile("gui/assets/MiniWorldSprites/AllAssetsPreview.png");
    _font.loadFromFile("gui/assets/Minecraft.ttf");

    sf::View _view = window.getView();
    unsigned int size = 100;
    _viewUI.setViewport(sf::FloatRect(_view.getCenter().x, _view.getCenter().y, size, window.getSize().y*size/window.getSize().x));
    _viewUI.setViewport(sf::FloatRect(1.f-(1.f*_viewUI.getSize().x)/window.getSize().x-0.02f, 1.f-(1.f*_viewUI.getSize().y)/window.getSize().y-0.02f, (1.f*_viewUI.getSize().x)/window.getSize().x, (1.f*_viewUI.getSize().y)/window.getSize().y));
    _viewUI.zoom(4.f);
    _viewUI.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));

    std::cout << "======================" << std::endl;
    setTileMap(getMapContent(client));
    if (_mapSize.empty()) {
        std::vector<std::string> m = getMapSize(client);
        _mapSize = {std::atoi(m[1].c_str()), std::atoi(m[2].c_str())};
        for (auto i : _mapSize)
            std::cout << i << std::endl;
    }
    std::cout << "======================" << std::endl;
}

std::vector<std::string> Game::splitCmd(std::vector<std::string> cmd)
{
    std::vector<std::string> tokens;

    for (const std::string& line : cmd) {
        std::istringstream iss(line);
        std::string token;

        while (iss >> token) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

std::map<std::string, sf::Sprite> Game::createInventory(std::map<std::string, int> inventory, sf::Vector2f pos)
{
    SpriteFactory spriteFactory;
    std::map<std::string, sf::Sprite> inventorySprite;
    int i = 0;
    int j = 1;
    float scale = 1;

    for (auto item : inventory) {
        sf::Sprite sprite = spriteFactory.createSprite(item.first, pos);
        sprite.setTexture(_textureMap["AllAssets"]);
        if (std::atoi(item.first.c_str()) > 4) {
            j = 2;
            i = 1;
        }
        sprite.setPosition(sf::Vector2f(pos.x * sprite.getScale().x + (j * SizeSprite), pos.y * sprite.getScale().y  + (i * SizeSprite)));
        sprite.setScale(scale, scale);
        inventorySprite[item.first] = sprite;
        i ++;
    }
    return inventorySprite;
}

void Game::setTileMap(std::vector<std::string> map)
{
    SpriteFactory spriteFactory;
    int nbSprite = 0;

    std::cout << "set tile map" << std::endl;
    for (size_t i = 0; i < map.size(); i++) {
        if (map[i].find("pnw") != std::string::npos)
            createAi(map, i);
        if (map[i].compare("msz") == 0) {
            _mapSize.push_back(std::atoi(map[i + 1].c_str()));
            _mapSize.push_back(std::atoi(map[i + 2].c_str()));
        }
        if (map[i].compare("bct") == 0) {
            nbSprite++;
            float x = std::atof(map[i + 1].c_str()) * SizeSprite;
            float y = std::atof(map[i + 2].c_str()) * SizeSprite;
            std::shared_ptr<Tile> tile = std::make_shared<Tile>(spriteFactory.createSprite("sand", sf::Vector2f(x, y)), sf::Text("test", _font, 7));
            std::map<std::string, int> inventory;
            for (int j = 3;  j < 10; j++)
                if (std::atoi(map[i + j].c_str()) > 0)
                    inventory[std::to_string(j - 3)] = std::atoi(map[j].c_str());
            tile->setInventory(createInventory(inventory, sf::Vector2f(x, y)));
            tile->setTexture(_textureMap["AllAssets"]);
            addTile("sand" + std::to_string(nbSprite),tile);
        }
    }
}

void Game::updateTileMap(std::vector<std::string> map)
{
    SpriteFactory spriteFactory;
    int nbSprite = 0;

    size_t size = map.size();
    for (size_t i = 0; i < map.size(); i++) {
        if  (map[i].find("pnw") != std::string::npos)
            createAi(map, i);
        if (map[i].compare("bct") == 0 && i + 9 < size) {
            nbSprite++;
            float x = std::atoi(map[i + 1].c_str()) * SizeSprite;
            float y = std::atoi(map[i + 2].c_str()) * SizeSprite;

            std::map<std::string, int> inventory;
            for (int j = 3;  j < 10; j++)
                if (std::atoi(map[i + j].c_str()) > 0)
                    inventory[std::to_string(j - 3)] = std::atoi(map[j].c_str());

            std::string name = "sand" + std::to_string(nbSprite);
            if (_tileMap.find(name) != _tileMap.end())
                _tileMap["sand" + std::to_string(nbSprite)]->setInventory(createInventory(inventory, sf::Vector2f(x, y)));
        }
    }
}

void Game::setSpriteMap(std::string map)
{
    SpriteFactory spriteFactory;
    float x = 0;
    float y = 0;
    int nbSprite = 0;

    for (auto symbol : map) {
        if (symbol == 'X') {
            addSprite("grass" + std::to_string(nbSprite), spriteFactory.createSprite("grass", sf::Vector2f(x, y)));
            nbSprite++;
        }
        if (symbol == 'T') {
            addSprite("tree" + std::to_string(nbSprite), spriteFactory.createSprite("tree", sf::Vector2f(x, y)));
            nbSprite++;
        }
        if (symbol == 'W') {
            addSprite("water" + std::to_string(nbSprite), spriteFactory.createSprite("water", sf::Vector2f(x, y)));
            nbSprite++;
        }
        if (symbol == 'S') {
            addSprite("sand" + std::to_string(nbSprite), spriteFactory.createSprite("sand", sf::Vector2f(x, y)));
            nbSprite++;
        }
        if (symbol == 'L') {
            addSprite("linemate" + std::to_string(nbSprite), spriteFactory.createSprite("linemate", sf::Vector2f(x, y)));
            nbSprite++;
        }
        if (symbol == '\n') {
            x = 0;
            y += SizeSprite;
        } else {
            x += SizeSprite;
        }
    }
}

void Game::addTile(std::string name, std::shared_ptr<Tile> tile)
{
    _tileMap.insert(std::make_pair(name, tile));
}

void Game::addAi(std::string name, std::shared_ptr<AI> ai)
{
    _AImap.insert(std::make_pair(name, ai));
}

void Game::draw(sf::RenderWindow &window)
{
    int mapWidth = _mapSize[0];
    int mapHeight = _mapSize[1];
    int numCols = mapWidth;
    int numRows = mapHeight;

    for (auto sprite : _spritesMap) {
         window.draw(sprite.second);
    }
    for (auto tile : _tileMap) {
        tile.second->draw(window);
    }
    for (int x = 0; x < numCols; x++)
    {
        for (int y = 0; y < numRows; y++)
        {
            sf::RectangleShape rect(sf::Vector2f(gridSize, gridSize));
            rect.setPosition(x * gridSize, y * gridSize);
            rect.setFillColor(sf::Color::Transparent);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(1.0f);
            window.draw(rect);
        }
    }
    for (auto ai : _AImap) {
        ai.second->draw(window);
    }
}

void Game::timeUpdate(std::shared_ptr<Client> &client)
{
    updateTileMap(getMapContent(client));
}

void Game::update(std::shared_ptr<Client> &client, sf::RenderWindow &)
{
    if (client.get()->sendCmd("")) {
        std::vector<std::string> recv = splitCmd(client.get()->recvCmd());
        if (!recv.empty()) {
            for (size_t i = 0; i < recv.size(); i ++) {
                createAi(recv, i);
                killAi(recv, i);
            }
        }
    }
    updateTileMap(getMapContent(client));
    for (auto ai : _AImap) {
        std::vector<std::string> pos = getPlayerPos(client, std::to_string(ai.second->getId()));
        if (!pos.empty())
            if (pos[0].compare("ppo") == 0) {
                if (ai.second->getId() == std::atoi(pos[1].c_str()))
                    ai.second->setPos(sf::Vector2f(std::atof(pos[2].c_str()) * SizeSprite * 5, std::atof(pos[3].c_str()) * SizeSprite * 5));
            }
    }
}

void Game::animation(int currentFrame)
{
    for (auto& pair : _AImap) {
        pair.second->update();
        pair.second->animate(currentFrame);
    }
}

void Game::handleEvent(sf::Event &, sf::RenderWindow &)
{
}

void Game::addSprite(std::string name, sf::Sprite sprite)
{
    _spritesMap[name] = sprite;
    _spritesMap[name].setTexture(_textureMap["AllAssets"]);
}

void Game::addButton(Button &)
{
}

std::vector<std::string> Game::getMapContent(std::shared_ptr<Client> &client)
{
    if (client.get()->sendCmd("mct")) {
        std::vector<std::string> mct = client.get()->recvCmd();
        if (!mct.empty()) {
            return splitCmd(mct);
        }
    }

    return std::vector<std::string>();
}

std::vector<std::string> Game::getMapSize(std::shared_ptr<Client> &client)
{
    if (client.get()->sendCmd("msz")) {
        std::vector<std::string> msz = splitCmd(client.get()->recvCmd());
        if (!msz.empty()) {
            return msz;
        } else {
            std::cout << "msz empty" << std::endl;
        }
    }

    return std::vector<std::string>();
}

std::vector<std::string> Game::getTileContent(std::shared_ptr<Client> &client, std::vector<std::string> pos)
{
    if (client.get()->sendCmd("btc" + pos[0] + pos[1])) {
        std::vector<std::string> btc = client.get()->recvCmd();
        if (!btc.empty() && btc[0] == "btc") {
            return btc;
        }
    }

    return std::vector<std::string>();
}

std::vector<std::string> Game::getTeamsName(std::shared_ptr<Client> &client)
{
    if (client.get()->sendCmd("tna")) {
        std::vector<std::string> tna = client.get()->recvCmd();
        if (!tna.empty()) {
            return tna;
        }
    }

    return std::vector<std::string>();
}

std::vector<std::string> Game::getPlayerLevel(std::shared_ptr<Client> &client, std::string id)
{
    if (client.get()->sendCmd("plv " + id)) {
        std::vector<std::string> plv = client.get()->recvCmd();
        if (!plv.empty()) {
            return plv;
        }
    }

    return std::vector<std::string>();
}

std::vector<std::string> Game::getPlayerInventory(std::shared_ptr<Client> &client, std::string id)
{
    if (client.get()->sendCmd("pin " + id)) {
        std::vector<std::string> pin = client.get()->recvCmd();
        if (!pin.empty()) {
            return splitCmd(pin);
        }
    }
    return std::vector<std::string>();
}

std::vector<std::string> Game::getPlayerPos(std::shared_ptr<Client> &client, std::string id)
{
    if (client.get()->sendCmd("ppo " + id)) {
        std::vector<std::string> ppo = client.get()->recvCmd();
        if (!ppo.empty()) {
            return splitCmd(ppo);
        }
    }
    return std::vector<std::string>();
}

void Game::createAi(std::vector<std::string> playerConnect, size_t i)
{
    if (playerConnect[i].compare("pnw") == 0) {
        int aiId = std::stoi(playerConnect[i + 1]);
        int posX = std::stoi(playerConnect[i + 2]);
        int posY = std::stoi(playerConnect[i + 3]);
        std::string level = playerConnect[i + 5];
        std::string teamName = playerConnect[i + 6];
        std::shared_ptr<AI> ai = std::make_shared<AI>(SpriteFactory::createSprite("Slime", sf::Vector2f(posX, posY)), _font);
        ai->setId(aiId);
        ai->setSpriteName("Slime");
        ai->setTexture(_textureMap["AllAssets"]);
        ai->setLevel(level);
        ai->setTeamName(teamName);
        ai->getUI().setView(_viewUI);

        addAi(std::to_string(ai->getId()), ai);
        nbAI++;
    }
}

void Game::collectRessource(std::vector<std::string> data, size_t i)
{
    if (data[i].compare("pgt") == 0) {
        if (_AImap.find(data[i + 1]) != _AImap.end()) {
            int idTile = (_AImap[data[i + 1]]->getPos().x / SizeSprite / 5) + (_AImap[data[i + 1]]->getPos().y / SizeSprite / 5) * 10 + 1;
            if (_tileMap["sand" + std::to_string(idTile)] == nullptr) {
                return;
            }
            _tileMap["sand" + std::to_string(idTile)]->popResource(data[i + 2]);
        }
    }
}

void Game::dropRessource(std::vector<std::string> data, size_t i)
{
    if (data[i].compare("pdr") == 0) {
        std::cout << "==============================" << std::endl;
        std::cout << data[i] << " " <<  data[i+ 1] << std::endl;
        int idTile = (_AImap[data[i + 1]]->getPos().x / SizeSprite / 5) + (_AImap[data[i + 1]]->getPos().y / SizeSprite / 5) * 10 + 1;
        _tileMap["sand" + std::to_string(idTile)]->addResource(data[i + 2]);

        std::cout << "id tile : " << idTile << std::endl;
        std::cout << "ressource : " << data[i + 2] << std::endl;
    }
}

void Game::killAi(std::vector<std::string> data, size_t i)
{
    if (data[i].compare("pdi") == 0) {
        std::cout << "==============================" << std::endl;
        std::cout << "kill ai" << std::endl;
        _AImap.erase(data[i + 1]);
        nbAI--;
        std::cout << "nb ai : " << nbAI << std::endl;
    }
}
