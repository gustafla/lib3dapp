// Copyright 2016 Lauri Gustafsson
/*  This file is part of lib3dapp.

    lib3dapp is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    lib3dapp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with lib3dapp.  If not, see <http://www.gnu.org/licenses/>.*/

#include "obj_file.hpp"
#include "define.hpp"
#include "vectors.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include "util.hpp"
#include "graphics.hpp"

Mesh loadOBJFile(std::string filename) {
    std::vector<std::string> objLine;
    
    Mesh mesh;
    
    std::vector<vec3>   vertices;
    std::vector<vec2>   texcoords;
    std::vector<vec3>   normals;
    std::vector<GLuint> indices;

    std::ifstream in(filename.c_str());
    if (!in.is_open()) {
        std::cout << "loadOBJFile: " << filename << ": no such file.\n";
        exit(ERR_OBJ_FILE);
    }
    
    char buf[255];
    while (!in.eof()){
        in.getline(buf, 255);
        objLine.push_back(std::string(buf));
    }
    
    bool hastextures = false, notextures = false;
    bool hasnormals  = false, nonormals  = false;
    
    float tx, ty, tz;
    int a, b, c, d, e, f, g, h, i;
    
    for (int index=0; index<objLine.size(); index++) {
        if (objLine[index].c_str()[0]=='#')
            continue;
        else if (objLine[index].c_str()[0]=='v' && objLine[index].c_str()[1]==' ') { //vertex
            sscanf(objLine[index].c_str(), "v %f %f %f", &tx, &ty, &tz);
            vertices.push_back(vec3(tx, ty, tz));
        } else if (objLine[index].c_str()[0]=='v' && objLine[index].c_str()[1]=='n') { //normal
            sscanf(objLine[index].c_str(), "vn %f %f %f", &tx, &ty, &tz);
            normals.push_back(vec3(tx, ty, tz));
        } else if (objLine[index].c_str()[0]=='v' && objLine[index].c_str()[1]=='t') { //texture coordinate
            if (count(objLine[index].begin(), objLine[index].end(), ' ') == 3) {
                sscanf(objLine[index].c_str(), "vt %f %f %f", &tx, &ty, &tz);
                texcoords.push_back(vec2(tx, ty));
            } else if (count(objLine[index].begin(), objLine[index].end(), ' ') == 2) {
                sscanf(objLine[index].c_str(), "vt %f %f", &tx, &ty);
                texcoords.push_back(vec2(tx, ty));
            } else {
                std::cout << "loadOBJFile: " << filename << ": Something wrong with line " << index << ".\n";
            }
        } else if (objLine[index].c_str()[0]=='f') { //face
            if (count(objLine[index].begin(), objLine[index].end(), ' ') == 3) { //triangular face
                if (count(objLine[index].begin(), objLine[index].end(), '/') == 0) { //only vertex coords
                    notextures = true;
                    nonormals = true;
                    sscanf(objLine[index].c_str(), "f %d %d %d", &a, &b, &c);
                    indices.push_back(a-1);
                    indices.push_back(b-1);
                    indices.push_back(c-1);
                } else if (countSubstring(objLine[index], "/") == 3) { //vertex coords + texture coords
                    hastextures = true;
                    nonormals = true;
                    sscanf(objLine[index].c_str(), "f %d/%d %d/%d %d/%d", &a, &b, &c, &d, &e, &f);
                    indices.push_back(a-1);
                    indices.push_back(b-1);
                    indices.push_back(c-1);
                    indices.push_back(d-1);
                    indices.push_back(e-1);
                    indices.push_back(f-1);
                } else if (countSubstring(objLine[index], "//") == 3) { //vertex coords + normals
                    hasnormals = true;
                    notextures = true;
                    sscanf(objLine[index].c_str(), "f %d//%d %d//%d %d//%d", &a, &b, &c, &d, &e, &f);
                    indices.push_back(a-1);
                    indices.push_back(b-1);
                    indices.push_back(c-1);
                    indices.push_back(d-1);
                    indices.push_back(e-1);
                    indices.push_back(f-1);
                } else if (countSubstring(objLine[index], "/") == 6) { //vertex coords + texture coords + normals
                    hasnormals = true;
                    hastextures = true;
                    sscanf(objLine[index].c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &a, &b, &c, &d, &e, &f, &g, &h, &i);
                    indices.push_back(a-1);
                    indices.push_back(b-1);
                    indices.push_back(c-1);
                    indices.push_back(d-1);
                    indices.push_back(e-1);
                    indices.push_back(f-1);
                    indices.push_back(g-1);
                    indices.push_back(h-1);
                    indices.push_back(i-1);
                } else
                    std::cout << "loadOBJFile: " << filename << ": Something wrong with line " << index << ".\n";
            } else //not triangular face
                std::cout << "loadOBJFile: " << filename << ": Skipped line " << index << ". not a triangular face :(\n";
        } else {
            if (objLine[index].length())
                std::cout << "loadOBJFile: " << filename << ": Unrecognized: " << objLine[index] << std::endl;
            continue;
        }
    }
    
    if ((hastextures && notextures) || (hasnormals && nonormals)) {
        std::cout << "loadOBJFile: " << filename << ": Mixed indices not supported.\n";
        exit(ERR_OBJ_FILE);
    }
    
    if (!hastextures && texcoords.size()) {
        std::cout << "loadOBJFile: " << filename << ": Warning: Texture coords entirely unused.\n";
    }
    
    if (!hasnormals && normals.size()) {
        std::cout << "loadOBJFile: " << filename << ": Warning: Normals entirely unused.\n";
    }
    
//----------------------------UNROLL------------------------------------
    
    if (!texcoords.size() && !normals.size()) {
        for (unsigned int i=0; i<indices.size(); i++) {
            mesh.pushPosition(vertices[indices[i]]);
        }
    } else if (texcoords.size() && !normals.size()) {
        for (int i=0; i<indices.size(); i+=2) {
            mesh.pushPosition(vertices[indices[i]]);
            mesh.pushTexcoord(texcoords[indices[i+1]]);
        }
    } else if (!texcoords.size() && normals.size()) {
        for (int i=0; i<indices.size(); i+=2) {
            mesh.pushPosition(vertices[indices[i]]);
            mesh.pushNormal(normals[indices[i+1]]);
        }
    } else if (texcoords.size() && normals.size()) {
        for (int i=0; i<indices.size(); i+=3) {
            mesh.pushPosition(vertices[indices[i]]);
            mesh.pushTexcoord(texcoords[indices[i+1]]);
            mesh.pushNormal(normals[indices[i+2]]);
        }
    }
    
    return mesh;
}
