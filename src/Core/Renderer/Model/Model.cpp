#include "Model.h"

Model::Model(const std::string &filePath) : m_directory(filePath) {
    loadModel(filePath);
}

void Model::addTexture(const Texture &texture) {
    m_textures.emplace_back(texture);
}

const std::vector<Texture> &Model::Textures() const {
    return m_textures;
}

void Model::loadModel(const std::string &filePath) {
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(filePath, aiProcess_Triangulate | aiProcess_GenSmoothNormals |
      aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

    if(!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        throw std::exception();
    }
    m_directory = m_directory.substr(0, m_directory.find_last_of('/'));
    processNode(*(scene->mRootNode), *scene);
}

void Model::processNode(aiNode &node, const aiScene &scene) {
    // process all the node's meshes (if any)
    for(unsigned int i = 0; i < node.mNumMeshes; i++){
        aiMesh *mesh = scene.mMeshes[node.mMeshes[i]];
        m_meshes.push_back(processMesh(*mesh, scene));
    }
    // then do the same for each of its children
    for(unsigned int i = 0; i < node.mNumChildren; i++){
        processNode(*(node.mChildren[i]), scene);
    }
}

Mesh Model::processMesh(aiMesh &mesh, const aiScene &scene) {
    std::vector<Vertex> vertices;
    std::vector<uint> indices;
    std::vector<Texture> texture;
    //process vertex data
    for(unsigned int i = 0; i < mesh.mNumVertices; i++)
        vertices.emplace_back(
                Vertex {getVertices(mesh, i), getNormals(mesh, i), getTexCoords(mesh, i)});
    // process indices
    for(unsigned int i = 0; i < mesh.mNumFaces; i++){
        aiFace face = mesh.mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }
    return Mesh(vertices, indices);
}

glm::vec3 Model::getVertices(const aiMesh &mesh, uint i) {
    glm::vec3 vector;
    vector.x = mesh.mVertices[i].x;
    vector.y = mesh.mVertices[i].y;
    vector.z = mesh.mVertices[i].z;
    return vector;
}

glm::vec3 Model::getNormals(const aiMesh &mesh, uint i) {
    glm::vec3 vector;
    if(mesh.HasNormals()) {
        vector.x = mesh.mNormals[i].x;
        vector.y = mesh.mNormals[i].y;
        vector.z = mesh.mNormals[i].z;
    }
    return vector;
}

glm::vec2 Model::getTexCoords(const aiMesh &mesh, uint i) {
    glm::vec2 vector(0.0f, 0.0f);
    if(mesh.mTextureCoords[0]) {
        vector.x = mesh.mTextureCoords[0][i].x;
        vector.y = mesh.mTextureCoords[0][i].y;
    }
    return vector;
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial &material, aiTextureType textureType) {
    std::vector<Texture> textures;
    std::vector<Texture> textureLoaded;
    for(uint i = 0; i < material.GetTextureCount(textureType); i++){
        aiString str;
        material.GetTexture(textureType, i, &str);
        bool skip = false;
        for(size_t j = 0; j < textureLoaded.size(); j++){
            if(textureLoaded[j].getFilePath() == m_directory + "/" + str.C_Str()){
                textures.push_back(textureLoaded[j]);
                skip = true;
                break;
            }
        }
        if(!skip){
            Texture texture;
            texture.loadTexture(m_directory + "/" + str.C_Str());
            textureLoaded.push_back(texture);
        }
    }
    return textures;
}
