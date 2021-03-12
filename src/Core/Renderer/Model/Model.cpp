#include "Model.h"

Model::Model(const std::string &filePath) {
    loadModel(filePath);
}

void Model::loadModel(const std::string &filePath) {
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(filePath, aiProcess_Triangulate | aiProcess_GenSmoothNormals |
    aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

    if(!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        throw std::exception();
    }
    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene) {
    // process all the node's meshes (if any)
    for(unsigned int i = 0; i < node->mNumMeshes; i++){
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        m_meshes.push_back(processMesh(mesh, scene));
    }
    // then do the same for each of its children
    for(unsigned int i = 0; i < node->mNumChildren; i++){
        processNode(node->mChildren[i], scene);
    }
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene) {
    std::vector<Vertex> vertices;
    std::vector<uint> indices;
    Vertex vertex{glm::vec3 (0.0f, 0.0f, 0.0f),
                  glm::vec3 (0.0f, 0.0f, 0.0f)};

    for(unsigned int i = 0; i < mesh->mNumVertices; i++){
        // process vertex positions, normals
        glm::vec3 vector;
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.position = vector;

        if(mesh->HasNormals()){
            vector.x = mesh->mNormals[i].x;
            vector.y = mesh->mNormals[i].y;
            vector.z = mesh->mNormals[i].z;
            vertex.normal = vector;
        }
        vertices.push_back(vertex);
    }
    // process indices
    for(unsigned int i = 0; i < mesh->mNumFaces; i++){
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }

    return Mesh(vertices, indices);
}
