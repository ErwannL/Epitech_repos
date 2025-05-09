/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_
    #include "IScene.hpp"
    #include "Tile.hpp"
    class Game : virtual public IScene {
        public:
            Game();
            ~Game();
            void init(sf::RenderWindow &, std::shared_ptr<Client>&);
            void update(std::shared_ptr<Client> &, sf::RenderWindow &);
            void animation(int);
            void draw(sf::RenderWindow &);
            void handleEvent(sf::Event &, sf::RenderWindow &);
            void addSprite(std::string, sf::Sprite);
            void addButton(Button &);
            void setName(std::string name){_name = name;};
            void setSpriteMap(std::string);
            std::map<std::string, sf::Sprite> &getSpritesMap(){return _spritesMap;};
            int getSwitchScene(){return _switchScene;};
            std::vector<std::string> splitCmd(std::vector<std::string>);
            void updateTileMap(std::vector<std::string> map);
            void timeUpdate(std::shared_ptr<Client> &client);
        protected:
            std::string _name;
            sf::Font _font;
            std::map<std::string, sf::Texture> _textureMap;
            std::map<std::string, sf::Sprite> _spritesMap;
            std::map<std::string, Button> _buttonsMap;
            std::map<std::string, std::shared_ptr<AI>> _AImap;
            std::map<std::string, std::shared_ptr<Tile>> _tileMap;
            int _switchScene = 2;
            sf::View _viewUI;
            sf::View _view;
            int SizeSprite = 16;
            int gridSize = 80;
            std::vector<int> _mapSize;
            int nbAI = 0;
        private:
            std::map<std::string, sf::Sprite> createInventory(std::map<std::string, int>, sf::Vector2f);
            void setTileMap(std::vector<std::string>);
            void addTile(std::string, std::shared_ptr<Tile>);
            void addAi(std::string, std::shared_ptr<AI>);
            std::shared_ptr<Client> _client;
            std::vector<std::string> getMapContent(std::shared_ptr<Client> &);
            std::vector<std::string> getMapSize(std::shared_ptr<Client> &);
            std::vector<std::string> getTileContent(std::shared_ptr<Client> &, std::vector<std::string>);
            std::vector<std::string> getTeamsName(std::shared_ptr<Client> &);
            std::vector<std::string> getPlayerLevel(std::shared_ptr<Client> &, std::string);
            std::vector<std::string> getPlayerPos(std::shared_ptr<Client> &, std::string);
            std::vector<std::string> getPlayerInventory(std::shared_ptr<Client> &, std::string);

            void collectRessource(std::vector<std::string>, size_t);
            void dropRessource(std::vector<std::string>, size_t);
            void createAi(std::vector<std::string>, size_t);
            void killAi(std::vector<std::string>, size_t);
    };

#endif /* !GAME_HPP_ */
