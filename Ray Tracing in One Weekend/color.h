//
//  color.h
//  Ray Tracing in One Weekend
//
//  Created by Cedar Williams on 10/30/25.
//

#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();
    
    // Translate [0,1] cstatic_cast<int>omponent values to the byte range [0,255]
    int rbyte = static_cast<int>(255.99 * r);
    int gbyte = static_cast<int>(255.99 * g);
    int bbyte = static_cast<int>(255.99 * b);
    
    // Write ou the pixel color components
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif // !COLOR_H
