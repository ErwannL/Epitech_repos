/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07am-erwann.laplante
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
    #define FEDERATION_HPP_

    #include <iostream>
    #include "WarpSystem.hpp"
    #include "Destination.hpp"
    #include "Borg.hpp"

    namespace Borg
    {
        class Ship;
    }

    namespace Federation
    {
        namespace Starfleet
        {
            class Captain
            {
                std::string _name;
                int _age;
                public:
                    Captain(std::string name);
                    ~Captain();
                    std::string getName ();
                    int getAge ();
                    void setAge (int age);
            };
            class Ship
            {
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Destination _location;
                Destination _home;
                int _shield;
                int _photonTorpedo;
                std::string _captain;
                public:
                    Ship (int length = 289, int width = 132, std::string name = "Entreprise", short maxWarp = 6, int torpedo = 0);
                    ~Ship();
                    void setupCore(WarpSystem::Core *core);
                    void checkCore(void);
                    void promote (Captain *captain);
                    bool move (int warp, Destination d);
                    bool move (int warp);
                    bool move (Destination d);
                    bool move ();
                    int getShield ();
                    void setShield (int shield);
                    int getTorpedo () ;
                    void setTorpedo (int torpedo);
                    void fire (Borg::Ship *target);
                    void fire (int torpedoes, Borg::Ship *target);
            };
            class Ensign
            {
                std :: string _name ;
                public:
                    Ensign(std :: string name);
                    ~Ensign();
            };
        }
        class Ship
        {
            int _length;
            int _width;
            std::string _name;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
            public:
                Ship (int length, int width, std::string name);
                ~Ship();
                void setupCore(WarpSystem::Core *core);
                void checkCore(void);
                bool move (int warp, Destination d);
                bool move (int warp);
                bool move (Destination d);
                bool move ();
                WarpSystem::Core *getCore(void);
        };
    }

#endif /* !FEDERATION_HPP_ */
