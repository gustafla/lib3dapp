#include "mesh.hpp"
#include <iostream>

Mesh::Mesh() {
    
}

void Mesh::pushPosition(vec3 position) {
    positions.push_back(position);
}

void Mesh::pushNormal(vec3 normal) {
    normals.push_back(normal);
}

void Mesh::pushTexcoord(vec2 texcoord) {
    texcoords.push_back(texcoord);
}

const std::vector<vec3>& Mesh::getPositions() {
    return positions;
}

const std::vector<vec3>& Mesh::getNormals() {
    return normals;
}

const std::vector<vec2>& Mesh::getTexcoords() {
    return texcoords;
}

const bool Mesh::getAOSArray(std::vector<float>& array) {
    bool success = false;
    if (positions.size()) {
        if (texcoords.size() == 0 || texcoords.size() == positions.size()) {
            if (normals.size() == 0 || normals.size() == positions.size()) {
                for (unsigned int i = 0; i<positions.size(); i++) {
                    array.push_back(positions[i].x);
                    array.push_back(positions[i].y);
                    array.push_back(positions[i].z);
                    if (texcoords.size()) {
                        array.push_back(texcoords[i].x);
                        array.push_back(texcoords[i].y);
                    }
                    if (normals.size()) {
                        array.push_back(normals[i].x);
                        array.push_back(normals[i].y);
                        array.push_back(normals[i].z);
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
    }
    for (int i=0; i<positions.size(); i++) {
        nmlArray.push_back(normals[i].x);
        nmlArray.push_back(normals[i].y);
        nmlArray.push_back(normals[i].z);
    }
    for (int i=0; i<positions.size(); i++) {
        texArray.push_back(texcoords[i].x);
        texArray.push_back(texcoords[i].y);
    }
}

void Mesh::transform(mat4 matrix) {
    vec4 tmp;
    for (int i=0; i<positions.size(); i++) {
        tmp = matrix * vec4(positions[i], 1.0);
        positions[i] = vec3(tmp.x, tmp.y, tmp.z);
    }
    for (int i=0; i<normals.size(); i++) {
        tmp = matrix * vec4(normals[i], 0.0);
        normals[i] = vec3(tmp.x, tmp.y, tmp.z);
    }
}

void Mesh::join(Mesh& mesh) {
    positions.insert(positions.end(), mesh.getPositions().begin(), mesh.getPositions().end());
    normals.insert(normals.end(), mesh.getNormals().begin(), mesh.getNormals().end());
    texcoords.insert(texcoords.end(), mesh.getTexcoords().begin(), mesh.getTexcoords().end());
}
