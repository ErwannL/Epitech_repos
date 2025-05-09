/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07pm-erwann.laplante
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
    #define KREOGCOM_HPP_

    #include <iostream>

    class KreogCom
    {
        public:
            KreogCom (int x, int y, int serial);
            ~ KreogCom ();
            void addCom (int x, int y, int serial);
            void removeCom ();
            KreogCom *getCom ();
            void ping () const;
            void locateSquad () const;
        private:
            const int m_serial;
            int _x;
            int _y;
            KreogCom *_next;
            KreogCom *_previous;
    };

#endif /* !KREOGCOM_HPP_ */
