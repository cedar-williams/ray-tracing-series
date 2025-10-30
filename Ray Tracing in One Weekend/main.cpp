//
//  main.cpp
//  Ray Tracing in One Weekend
//
//  Created by Cedar Williams on 10/30/25.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    // Image
    int32_t image_width = 256;
    int32_t image_height = 256;
    
    // Render
    
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    
    for (int32_t y = 0; y < image_height; y++) {
        std::clog << "\rScanlines remaining: " << (image_height - y) << " " << std::flush;
        for (int32_t x = 0; x < image_width; x++) {
            auto r = double(x) / (image_width - 1);
            auto g = double(y) / (image_width - 1);
            auto b = 0.0;
            
            int32_t ir = int32_t(255.999 * r);
            int32_t ig = int32_t(255.999 * g);
            int32_t ib = int32_t(255.999 * b);
            
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}
