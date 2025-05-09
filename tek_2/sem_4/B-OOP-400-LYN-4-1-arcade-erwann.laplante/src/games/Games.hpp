/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Games
*/

#ifndef GAMES_HPP_
    #define GAMES_HPP_

    #include "IArcade.hpp"

    namespace Arcade {
        class Games {
            public:
                virtual ~Games() = default;

                virtual Arcade::Type getTypeClass (void) = 0;

            private:
                Arcade::Type what = Game;

            protected:
        };

    }


#endif /* !GAMES_HPP_ */
