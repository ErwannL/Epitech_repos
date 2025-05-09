/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "Parsing.hpp"
    #include "Ray.hpp"
    #include "utility.hpp"
    #include "RandomUnits.hpp"

    class Camera {
        public:
            Camera(std::map<std::string, std::string> camData);
            ~Camera();

            Vector3D *getViewRect() const;
            Point3D getOrigin() const;
            Ray getRay(double, double) const;

        private:
        protected:
            Point3D _origin;
            double FOV;
            Vector3D horizontal;
            Vector3D vertical;
            Point3D left_corner;
    };

#endif /* !CAMERA_HPP_ */
