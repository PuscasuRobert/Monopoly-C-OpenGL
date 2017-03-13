#include "Model.h"


void Model::loadModel(const char *fileName)
{
    vector<string>line;
    vector<string>tmp;
    ifstream fin(fileName);
    char aux[200],matFileName[200];
    unsigned int i,j;
    coordinate v;
    uv t;
    face f;
    while(!fin.eof())
    {
        fin.getline(aux,256);
        line.push_back(aux);
    }
    fin.close();

    ///*********************************///

    sscanf(line[2].c_str(),"mtllib %s",&matFileName);
    string x=matFileName;
    fin.open(("models/"+x).c_str());

    while(!fin.eof())
    {
        fin.getline(aux,200);
        tmp.push_back(aux);
    }
    for(unsigned int i=0;i<tmp.size();i++)
    {
        material M;
        if(tmp[i][0]=='\n')
            continue;
        if(tmp[i][0]=='n'&&tmp[i][1]=='e'&&tmp[i][2]=='w')
        {
            sscanf(tmp[i++].c_str(),"newmtl %s",&M.name);
            if(tmp[i][0]=='N'&&tmp[i][1]=='s')
                sscanf(tmp[i++].c_str(),"Ns %f",&M.ns);
            if(tmp[i][0]=='K'&&tmp[i][1]=='a')
                sscanf(tmp[i++].c_str(),"Ka %f %f %f",&M.amb[0],&M.amb[1],&M.amb[2]);
            if(tmp[i][0]=='K'&&tmp[i][1]=='d')
                sscanf(tmp[i++].c_str(),"Kd %f %f %f",&M.dif[0],&M.dif[1],&M.dif[2]);
            if(tmp[i][0]=='K'&&tmp[i][1]=='s')
                sscanf(tmp[i++].c_str(),"Ks %f %f %f",&M.spec[0],&M.spec[1],&M.spec[2]);
            if(tmp[i][0]=='N'&&tmp[i][1]=='i')
                i++;
            if(tmp[i][0]=='d'&&tmp[i][1]==' ')
                sscanf(tmp[i++].c_str(),"d %f",&M.alpha);
            if(tmp[i][0]=='i'&&tmp[i][1]=='l')
            sscanf(tmp[i++].c_str(),"illum %f",&M.illum);
            string x;
            x=tmp[i];
            for(j=x.size();j>0;j--)
                if(x[j]==92)
                {
                    x.erase(x.begin(),x.begin()+j+1);
                    break;
                }
            M.tname="images/"+x;

            sf::Image image;
            unsigned int ID;
            image.loadFromFile(M.tname);
            image.flipHorizontally();
            glGenTextures(1,&ID);
            glBindTexture(GL_TEXTURE_2D,ID);

            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
            M.ID=ID;
            materials.push_back(M);
        }
    }
    ///****************************////

    for(i=3;i<line.size();i++)
    {
        char matName[100];
        if(line[i][0]=='v'&& line[i][1]==' ')
        {
            sscanf(line[i].c_str(),"v %f %f %f",&v.x,&v.y,&v.z);
            vertex.push_back(v);
            continue;
        }
        if(line[i][0]=='v'&&line[i][1]=='t')
        {
            sscanf(line[i].c_str(),"vt %f %f",&t.x,&t.y);
            textureCoordinates.push_back(t);
            continue;
        }
        if(line[i][0]=='v'&&line[i][1]=='n')
        {
            sscanf(line[i].c_str(),"vn %f %f %f",&v.x,&v.y,&v.z);
            normals.push_back(v);
            continue;
        }
        if(line[i][0]=='u'&&line[i][1]=='s'&&line[i][2]=='e')
            sscanf(line[i].c_str(),"usemtl %s",&matName);
        if(line[i][0]=='f'&&line[i][1]==' ')
        {
            sscanf(line[i].c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",&f.v[0],&f.t[0],&f.n[0],&f.v[1],&f.t[1],&f.n[1],&f.v[2],&f.t[2],&f.n[2]);
            f.usemtl=matName;
            faces.push_back(f);
            continue;
        }
    }
}

void Model::draw()
{
    unsigned int i,j;
    for(i=0;i<faces.size();i++)
    {
        for(j=0;j<materials.size();j++)
        {
            if(materials[j].name==faces[i].usemtl)
                break;
        }
        glBindTexture(GL_TEXTURE_2D,materials[j].ID);
        glBegin(GL_TRIANGLES);
            glTexCoord2f (textureCoordinates[faces[i].t[0]-1].x,textureCoordinates[faces[i].t[0]-1].y);
            glNormal3f(normals[faces[i].n[0]-1].x,normals[faces[i].n[0]-1].y,normals[faces[i].n[0]-1].z);
            glVertex3f(vertex[faces[i].v[0]-1].x,vertex[faces[i].v[0]-1].y,vertex[faces[i].v[0]-1].z);

            glTexCoord2f (textureCoordinates[faces[i].t[1]-1].x,textureCoordinates[faces[i].t[1]-1].y);
            glNormal3f(normals[faces[i].n[1]-1].x,normals[faces[i].n[1]-1].y,normals[faces[i].n[1]-1].z);
            glVertex3f(vertex[faces[i].v[1]-1].x,vertex[faces[i].v[1]-1].y,vertex[faces[i].v[1]-1].z);

            glTexCoord2f (textureCoordinates[faces[i].t[2]-1].x,textureCoordinates[faces[i].t[2]-1].y);
            glNormal3f(normals[faces[i].n[2]-1].x,normals[faces[i].n[2]-1].y,normals[faces[i].n[2]-1].z);
            glVertex3f(vertex[faces[i].v[2]-1].x,vertex[faces[i].v[2]-1].y,vertex[faces[i].v[2]-1].z);
        glEnd();
    }
}

