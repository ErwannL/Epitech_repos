/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-Vector3Dtracer-guilhem.vinet
** File description:
** Ray
*/

#ifndef Vector3D_HPP_
    #define Vector3D_HPP_

    #include "Vector3D.hpp"

    class Ray {
        protected:
            Point3D origin;
            Vector3D direction;
        public:
            Ray() {};
            Ray(const Point3D &o, const Vector3D &d) { origin = o; direction = d; }
            ~Ray() {};

            Point3D pointAt(double t) const { return origin + (direction * t); }
            Point3D getOrigin() const { return origin; }
            Vector3D getDirection() const { return direction; }
    };

#endif /* !Vector3D_HPP_ */
