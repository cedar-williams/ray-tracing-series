//
//  main.cpp
//  Ray Tracing in One Weekend
//
//  Created by Cedar Williams on 10/30/25.
//

#include "color.h"
#include "vec3.h"

#include <iostream>

int main(int argc, const char * argv[]) {
    
    // Image
    int32_t image_width = 256;
    int32_t image_height = 256;
    
    // Render
    
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    
    for (int32_t j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << " " << std::flush;
        for (int32_t i = 0; i < image_width; i++) {
            auto pixel_color = color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0 );
            write_color(std::cout, pixel_color);
        }
    }
    
    std::clog << "\rDone.                 \n";
};
