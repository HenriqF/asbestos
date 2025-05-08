#include <bits/stdc++.h>
using namespace std;

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(){
    int width, height, channels;
    unsigned char* foto = stbi_load("a.png", &width, &height, &channels, 0);
    if (!foto) {
        std::cerr << "por favor faça o favor de fazer o favor de garantir que a imagem seja penesge e seja nome a: a.png";
        return 1;
    }
    std::cout << width << "x" << height << " | " << channels << endl;

    if (channels == 3){
        std::string line;

        for (int k = 0; k < height; k++){
            for(int j = 0; j < width; j++){
                int idx = (k * width + j) * channels;

                unsigned char r = foto[idx];
                unsigned char g = foto[idx+1];
                unsigned char b = foto[idx+2];
                //float brightness = 0.299f * r + 0.587f * g + 0.114f * b;
                float brightness = 0.2126f * r + 0.7152f * g + 0.0722f * b;

                //brilho vai de 0 a 255 -> pura aproximacao issea em cima
                //$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'.
                
                if (brightness > 224){line+="$";}
                else if (brightness > 193 && brightness <= 224){line+="%";}
                else if (brightness > 162 && brightness <= 193){line+="W";}
                else if (brightness > 131 && brightness <= 162){line+="#";}
                else if (brightness > 100 && brightness <= 131){line+="l";}
                else if (brightness > 69 && brightness <= 100){line+="|";}
                else if (brightness > 38 && brightness <= 69){line+="!";}
                else {line+=":";}

            }
            std::cout << line << endl;
            line = "";
        }
        stbi_image_free(foto);
    }
    else{
        std::cout << "quantia de canais indevida!" << endl;
    }
    return 0;
}