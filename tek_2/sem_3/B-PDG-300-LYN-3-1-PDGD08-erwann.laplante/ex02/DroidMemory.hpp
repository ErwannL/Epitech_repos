/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD08-erwann.laplante
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
    #define DROIDMEMORY_HPP_

    #include <iostream>
    #include <string>

    class DroidMemory {
        size_t Fingerprint;
        size_t Exp;
        public:
            DroidMemory(DroidMemory const &droid);
            DroidMemory();
            ~DroidMemory();
            size_t getFingerprint() const;
            size_t getExp() const;
            void setFingerprint(size_t fingerprint);
            void setExp(size_t exp);
            DroidMemory &operator<<(DroidMemory const &droid);
            DroidMemory &operator>>(DroidMemory &droid);
            DroidMemory &operator+=(DroidMemory const &droid);
            DroidMemory &operator+=(size_t add);
            DroidMemory &operator+(DroidMemory const &droid);
            DroidMemory &operator+(size_t add);
            bool operator==(DroidMemory const &droid) const;
            bool operator!=(DroidMemory const &droid) const;
            bool operator<(DroidMemory const &droid) const;
            bool operator<(size_t size) const;
            bool operator>(DroidMemory const &droid) const;
            bool operator>(size_t size) const;
            bool operator<=(DroidMemory const &droid) const;
            bool operator<=(size_t size) const;
            bool operator>=(DroidMemory const &droid) const;
            bool operator>=(size_t size) const;
            DroidMemory &operator=(DroidMemory const &droid);
    };
    std::ostream &operator<<(std::ostream &stream, DroidMemory const &droid);

#endif /* !DROIDMEMORY_HPP_ */
