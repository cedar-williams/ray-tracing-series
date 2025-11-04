//
//  color.h
//  Ray Tracing in One Weekend
//
//  Created by Cedar Williams on 10/30/25.
//

#ifndef COLOR_H
#define COLOR_H

#include "interval.h"
#include "vec3.h"

using color = vec3;

inline double linear_to_gamma(double linear_component) {
    if (linear_component > 0) {
        return std::sqrt(linear_component);
    }
    
    return 0;
}

void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();
    
    // Apple a liner to gamma transformation for gamme 2
    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);
    
    // Translate [0,1] cstatic_cast<int>omponent values to the byte range [0,255]
    static const interval intensity(0.000, 0.999);
    int rbyte = static_cast<int>(256 * intensity.clamp(r));
    int gbyte = static_cast<int>(256 * intensity.clamp(g));
    int bbyte = static_cast<int>(256 * intensity.clamp(b));
    
    // Write ou the pixel color components
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif // !COLOR_H
