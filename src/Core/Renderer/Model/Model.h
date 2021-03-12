#pragma once

#include <vector>
#include <string>

#include "Mesh/Mesh.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

class Model {
private:
    using ModelType = std::vector<Mesh>;
    ModelType m_meshes;

public:
    explicit Model(const std::string &filePath);
    Mesh& operator[](int i){return m_meshes[i];}
    size_t size() {return m_meshes.size();}
    ModelType::iterator begin(){return m_meshes.begin();}
    ModelType::iterator end(){return m_meshes.end();}

private:
    void loadModel(const std::string &filePath);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
};
