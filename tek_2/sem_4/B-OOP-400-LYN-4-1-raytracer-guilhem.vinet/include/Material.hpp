/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Material
*/

#ifndef MATERIAL_HPP_
    #define MATERIAL_HPP_

    #include "RandomUnits.hpp"
    #include "hitReccord.hpp"

    class Material {
        public:
            virtual bool scatter(const Ray&, const hit_record&, Vector3D&, Ray&) const = 0;
        private:
        protected:
    };

#endif /* !MATERIAL_HPP_ */
