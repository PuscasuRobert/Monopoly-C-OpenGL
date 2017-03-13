#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>

using namespace std;

struct coordinate{
    float x,y,z;
};

struct face{
    int v[3];
    int t[3];
    int n[3];
    string usemtl;
};

struct uv{
    float x;
    float y;
};

struct material{
    char name[100];
    float ns,alpha,illum;
    float amb[3],dif[3],spec[3];
    string tname;
    unsigned int ID;
};

class Model
{
    private:
        vector<coordinate>vertex;
        vector<uv>textureCoordinates;
        vector<coordinate>normals;
        vector<face>faces;
        vector<material>materials;
        void loadMaterials(const char* line);
    public:
        void loadModel(const char *fileName);
        void draw();
};

#endif // MODEL_H
