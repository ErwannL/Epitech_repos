/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-Vector3Dtracer-guilhem.vinet
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "IObject.hpp"

    class Sphere : virtual public IObject {
        public:
            Sphere(Point3D cen, double r, std::shared_ptr<Material> m)
            : center(cen), radius(r), mat_ptr(m) {};
            ~Sphere() {};

            bool collide(const Ray&r, double t_min, double t_max, hit_record& rec) const;

        public:
            Point3D center;
            double radius;
            std::shared_ptr<Material> mat_ptr;
    };

#endif /* !SPHERE_HPP_ */
