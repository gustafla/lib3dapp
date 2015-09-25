#include "mesh.hpp"
#include <iostream>

Mesh::Mesh() {
    
}

void Mesh::pushPosition(vec4 position) {
    positions.push_back(position);
}

void Mesh::pushNormal(vec4 normal) {
    normals.push_back(normal);
}

void Mesh::pushTexcoord(vec2 texcoord) {
    texcoords.push_back(texcoord);
}

std::vector<vec4>& Mesh::getPositions() {
    return positions;
}

std::vector<vec4>& Mesh::getNormals() {
    return normals;
}

std::vector<vec2>& Mesh::getTexcoords() {
    return texcoords;
}

bool Mesh::getAOSArray(std::vector<float>& array) {
    bool success = false;
    if (positions.size()) {
        if (texcoords.size() == 0 || texcoords.size() == positions.size()) {
            if (normals.size() == 0 || normals.size() == positions.size()) {
                for (unsigned int i = 0; i<positions.size(); i++) {
                    std::cout << "Vertex " << i << std::endl;
                    array.push_back(positions[i].x);
                    std::cout << "x: " << positions[i].x << std::endl;
                    array.push_back(positions[i].y);
                    std::cout << "y: " << positions[i].y << std::endl;
                    array.push_back(positions[i].z);
                    std::cout << "z: " << positions[i].z << std::endl;
                    array.push_back(positions[i].w);
                    std::cout << "w: " << positions[i].w << std::endl;
                    if (texcoords.size()) {
                        array.push_back(texcoords[i].x);
                        array.push_back(texcoords[i].y);
                    }
                    if (normals.size()) {
                        array.push_back(normals[i].x);
                        array.push_back(normals[i].y);
                        array.push_back(normals[i].z);
                        array.push_back(normals[i].w);
                    }
                }
                success = true;
            }
        }
    }
    return success;
}

void Mesh::getSOAArray(std::vector<float>& posArray, std::vector<float>& nmlArray, std::vector<float>& texArray) {
    for (int i=0; i<positions.size(); i++) {
        posArray.push_back(positions[i].x);
        posArray.push_back(positions[i].y);
        posArray.push_back(positions[i].z);
        posArray.push_back(positions[i].w);
    }
    for (int i=0; i<positions.size(); i++) {
        nmlArray.push_back(normals[i].x);
        nmlArray.push_back(normals[i].y);
        nmlArray.push_back(normals[i].z);
        nmlArray.push_back(normals[i].w);
    }
    for (int i=0; i<positions.size(); i++) {
        texArray.push_back(texcoords[i].x);
        texArray.push_back(texcoords[i].y);
    }
}
