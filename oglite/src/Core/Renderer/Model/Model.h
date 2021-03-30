#pragma once

#include <vector>
#include <string>

#include "Mesh/Mesh.h"
#include "assimp/postprocess.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"

namespace oglite{
    class Model {
    private:
        using ModelType = std::vector<Mesh>;
        ModelType m_meshes;
        std::vector<Texture> m_textures;
        std::string m_directory;

    public:
        explicit Model(const std::string &filePath);
        void addTexture(const Texture &texture);
        const std::vector<Texture> &Textures() const;
        Mesh& operator[](int i){return m_meshes[i];}
        size_t size() const {return m_meshes.size();}
        ModelType::iterator end(){return m_meshes.end();}
        ModelType::iterator begin(){return m_meshes.begin();}

    private:
        void loadModel(const std::string &filePath);
        void processNode(aiNode &node, const aiScene &scene);
        Mesh processMesh(aiMesh &mesh, const aiScene &scene);
        static glm::vec3 getVertices(const aiMesh &mesh, uint i);
        static glm::vec3 getNormals(const aiMesh &mesh, uint i);
        static glm::vec2 getTexCoords(const aiMesh &mesh, uint i);
        std::vector<Texture> loadMaterialTextures(aiMaterial &material, aiTextureType textureType);
    };
}