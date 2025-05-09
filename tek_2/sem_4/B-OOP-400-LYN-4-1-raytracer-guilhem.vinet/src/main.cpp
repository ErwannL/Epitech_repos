/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** main
*/

#include "main.hpp"

Vector3D ray_color(const Ray& r, const ObjectList &world, int depth)
{
    hit_record rec;

    if (depth <= 0)
        return Vector3D(0,0,0);
    if (world.collide(r, 0.001, infinity, rec)) {
        Ray scattered;
        Vector3D attenuation;
        if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, world, depth-1);
        return Vector3D(0,0,0);
    }
    Vector3D unit_direction = unit_vector(r.getDirection());
    auto t = 0.5*(unit_direction.y + 1.0);
    return (1.0-t)*Vector3D(1.0, 1.0, 1.0) + t*Vector3D(0.5, 0.7, 1.0);
}

int main (int ac, char **av)
{
    auto parser = std::make_shared<Parsing>(ac, av);
    if (parser->fillData() == 84)
        return 84;

    auto camData = parser->getCameraData();

    const int image_width = std::stoi(camData["width"]);
    const int image_height = std::stoi(camData["height"]);

    Camera cam(camData);

    const int samples_per_pixel = 10;
    const int max_depth = 50;

    std::shared_ptr<File> outputFile = std::make_shared<File>(av[1], image_height, image_width);
    if (outputFile->createFile() == 84)
        return 84;

    auto primData = parser->getPrimitivesData();

    ObjectList world = createObjectList(primData);

    for (int j = image_height - 1; j >= 0 ; j--) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            Vector3D pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + random_double()) / (image_width - 1);
                auto v = (j + random_double()) / (image_height - 1);
                Ray r = cam.getRay(u, v);
                pixel_color += ray_color(r, world, max_depth);
            }
            outputFile->setCase(i, j, pixel_color, samples_per_pixel);
        }
    }
    std::cerr << "\nDone\n";
    return 0;
}
