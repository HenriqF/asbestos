#include <bits/stdc++.h>
using namespace std;

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void process(std::string name, int type){
    int width, height, channels;
    unsigned char* foto = stbi_load(name.c_str(), &width, &height, &channels, 0);
    if (!foto) {
        std::cerr << "\npor favor fazer o favor de fazer garantir que a imagem que voce colocou exista na pasta seu porra\n" << endl;
    }
    else{
        std::cout << "\ndimensões do arquivo:" << width << "x" << height << " | ";
        if (channels == 3){
            std::string line;
            std::string finalP;
            for (int k = 0; k < height; k++){
                for(int j = 0; j < width; j++){
                    int i = (k * width + j) * channels;
                    unsigned char r = foto[i];
                    unsigned char g = foto[i+1];
                    unsigned char b = foto[i+2];
                    float brightness;
                    if (type == 0){
                        brightness = 0.299f * r + 0.587f * g + 0.114f * b;
                    }
                    else if (type == 1){
                        brightness = 0.2126f * r + 0.7152f * g + 0.0722f * b;
                    }
                    else{
                        brightness = sqrt(0.299f*r*r + 0.587f*g*g + 0.114f*b*b);
                    }

                    //Caracteres por brilho: $@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'.
                    
                    static const std::array<int,12> values = {234, 213, 192, 171, 150, 129, 108, 87, 66 ,45 ,24, -900};
                    static const std::array<string, 12> c =  {"$","%","W","#","Z","v","[","1","?","!",":",","};

                    for(int i = 0; i < 12; i++){
                        if (brightness > values[i]){
                            line += c[i];
                            break;
                        }
                    }
    
                }
                finalP += line;
                finalP += "\n";
                line = "";
            }
            std::string ftNome = name.erase(name.size()-4);
            ftNome += ".txt";
            std::ofstream fw(ftNome);
            fw << finalP;
            fw.close();

            std::cout << "Confira '"<< ftNome <<"' para ver resultado.\n"<< endl;
            finalP = "";
            if (!fw){
                std::cerr << ("nao deu de achar o out.txt eu tentei mas nao consegui acho que voce deve ter feito algo nao muito legal que deve ter afetado minhas capacidades de achar esse tal de arquivo ae obrigado desde entao.");
            }

            stbi_image_free(foto);
        }
        else{
            std::cout << "quantia de canais indevida!" << endl;
        }
    }
    
}

int main(){
    while (true){
        std::string filename;
        int type;
        std::cout << "Digite o nome do arquivo para prosseguir -->";
        std::cin >> filename;
        std::cout << "Escolha o leitor de brilho (0, 1, 2)     -->";
        std::cin >> type;

        process(filename, type);
    }
    return 0;
}