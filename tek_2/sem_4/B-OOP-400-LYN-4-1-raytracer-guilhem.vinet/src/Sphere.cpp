/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-Vector3Dtracer-guilhem.vinet
** File description:
** Sphere
*/

#include "Sphere.hpp"

//---------- Sphere

bool Sphere::collide(const Ray&r, double t_min, double t_max, hit_record& rec) const
{
    Vector3D oc = r.getOrigin() - center;
    auto a = r.getDirection().length_sqrt();
    auto half_b = dot(oc, r.getDirection());
    //auto b = 2.0*dot(oc, r.getDirection());
    auto c = oc.length_sqrt() - radius * radius;

    auto discriminant = half_b*half_b - a*c;
    if (discriminant < 0) return false;
    auto sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return false;
    }

    rec.t = root;
    rec.p = r.pointAt(rec.t);
    Vector3D outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat_ptr = mat_ptr;

    return true;
}
