/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07am-erwann.laplante
** File description:
** Borg
*/

#ifndef BORG_HPP_
    #define BORG_HPP_

    #include "Federation.hpp"

    namespace Federation
    {
        namespace Starfleet
        {
            class Captain;
            class Ship;
            class Ensign;
        }
        class Ship;
    }

    namespace Borg
    {
        class Ship
        {
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
            int _shield;
            int _weaponFrequency;
            short _repair;
            public:
                Ship(int weaponFrequency = 20, short repair = 3);
                ~Ship();
                void setupCore(WarpSystem::Core *core);
                void checkCore(void);
                bool move (int warp, Destination d);
                bool move (int warp);
                bool move (Destination d);
                bool move ();
                int getShield();
                void setShield (int shield);
                int getWeaponFrequency ();
                void setWeaponFrequency (int frequency);
                short getRepair ();
                void setRepair (short repair);
                void fire (Federation::Starfleet::Ship *target);
                void fire (Federation::Ship *target) ;
                void repair ();
        };
    }

#endif /* !BORG_HPP_ */
