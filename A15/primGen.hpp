void Assignment15::createBoxMesh(std::vector<Vertex>& vDef, std::vector<uint32_t>& vIdx) {
    // The primitive built here is a parallelepiped centered at the origin, with proportions respecting the texture.
    // The parallelepiped is defined by specifying the vertices and indices of its faces.

    // Define the parallelepiped's dimensions (width, height, depth)
    const float width = 0.5f;
    const float height = 2.0f;
    const float depth = 2.0f;

    // Define the parallelepiped's half-dimensions for convenience
    const float halfWidth = width / 2.0f;
    const float halfHeight = height / 2.0f;
    const float halfDepth = depth / 2.0f;

    // Define the vertices of the parallelepiped
    glm::vec3 v0(-halfWidth, -halfHeight, -halfDepth);
    glm::vec3 v1(halfWidth, -halfHeight, -halfDepth);
    glm::vec3 v2(-halfWidth, halfHeight, -halfDepth);
    glm::vec3 v3(halfWidth, halfHeight, -halfDepth);
    glm::vec3 v4(-halfWidth, -halfHeight, halfDepth);
    glm::vec3 v5(halfWidth, -halfHeight, halfDepth);
    glm::vec3 v6(-halfWidth, halfHeight, halfDepth);
    glm::vec3 v7(halfWidth, halfHeight, halfDepth);

    // Define the normal vectors for each face of the parallelepiped
    glm::vec3 normalFront(0.0f, 0.0f, -1.0f);
    glm::vec3 normalBack(0.0f, 0.0f, 1.0f);
    glm::vec3 normalTop(0.0f, 1.0f, 0.0f);
    glm::vec3 normalBottom(0.0f, -1.0f, 0.0f);
    glm::vec3 normalLeft(-1.0f, 0.0f, 0.0f);
    glm::vec3 normalRight(1.0f, 0.0f, 0.0f);

    // Define the vertices for each face of the parallelepiped and add them to the vertex definition array
    // Back face
    vDef.push_back({ v0, normalFront,  glm::vec2(0.53f, 0.82f) }); // br
    vDef.push_back({ v1, normalFront, glm::vec2(0.435f, 0.82f) }); // bl
    vDef.push_back({ v2, normalFront,   glm::vec2(0.53f, 0.18f) }); // tr 
    vDef.push_back({ v3, normalFront, glm::vec2(0.435f, 0.18f) }); // tl

    // Front face
    vDef.push_back({ v5, normalBack, glm::vec2(0.09f, 0.82f) });
    vDef.push_back({ v4, normalBack, glm::vec2(0.0f, 0.82f) });
    vDef.push_back({ v7, normalBack, glm::vec2(0.09f, 0.18f) });
    vDef.push_back({ v6, normalBack, glm::vec2(0.0f, 0.18f) });

    // Top face
    vDef.push_back({ v2, normalTop, glm::vec2(0.435f, 0.0f) });
    vDef.push_back({ v3, normalTop, glm::vec2(0.435f, 0.18f) });
    vDef.push_back({ v6, normalTop, glm::vec2(0.09f, 0.0f) });
    vDef.push_back({ v7, normalTop, glm::vec2(0.09f, 0.18f) });

    // Bottom face
    vDef.push_back({ v0, normalBottom, glm::vec2(0.435f, 1.0f) });//br
    vDef.push_back({ v1, normalBottom, glm::vec2(0.435f, 0.82f) });//bl
    vDef.push_back({ v4, normalBottom, glm::vec2(0.09f, 1.0f) });//tr
    vDef.push_back({ v5, normalBottom, glm::vec2(0.09f, 0.82f) });//tl

    // Left face
    vDef.push_back({ v4, normalLeft, glm::vec2(0.86f, 0.82f) }); //br
    vDef.push_back({ v0, normalLeft, glm::vec2(0.53f, 0.82f) }); //bl
    vDef.push_back({ v6, normalLeft, glm::vec2(0.86f, 0.18f) }); //tr
    vDef.push_back({ v2, normalLeft, glm::vec2(0.53f, 0.18f) }); //tl

    // Right face
    vDef.push_back({ v1, normalRight, glm::vec2(0.435f, 0.82f) }); //bottom right
    vDef.push_back({ v5, normalRight, glm::vec2(0.09f, 0.82f) }); //bottom left 
    vDef.push_back({ v3, normalRight, glm::vec2(0.435f, 0.18f) });  //top right
    vDef.push_back({ v7, normalRight, glm::vec2(0.09f, 0.18f) }); //top left

    // Define the vertex indices for the triangles that form each face of the parallelepiped
    // Front face
    vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);
    vIdx.push_back(1); vIdx.push_back(3); vIdx.push_back(2);

    // Back face
    vIdx.push_back(4); vIdx.push_back(5); vIdx.push_back(6);
    vIdx.push_back(5); vIdx.push_back(7); vIdx.push_back(6);

    // Top face
    vIdx.push_back(8); vIdx.push_back(9); vIdx.push_back(10);
    vIdx.push_back(9); vIdx.push_back(11); vIdx.push_back(10);

    // Bottom face
    vIdx.push_back(12); vIdx.push_back(13); vIdx.push_back(14);
    vIdx.push_back(13); vIdx.push_back(15); vIdx.push_back(14);

    // Left face
    vIdx.push_back(16); vIdx.push_back(17); vIdx.push_back(18);
    vIdx.push_back(17); vIdx.push_back(19); vIdx.push_back(18);

    // Right face
    vIdx.push_back(20); vIdx.push_back(21); vIdx.push_back(22);
    vIdx.push_back(21); vIdx.push_back(23); vIdx.push_back(22);
}

#define M_PI 3.141595f
void Assignment15::createSphereMesh(std::vector<Vertex>& vDef, std::vector<uint32_t>& vIdx) {
    const int numLatitudes = 50;   // Number of latitude divisions
    const int numLongitudes = 50;  // Number of longitude divisions

    // Generate vertices for the sphere
    for (int lat = 0; lat <= numLatitudes; ++lat) {
        float theta = static_cast<float>(lat) * M_PI / static_cast<float>(numLatitudes); // Latitude angle
        for (int lon = 0; lon <= numLongitudes; ++lon) {
            float phi = static_cast<float>(lon) * 2.0f * M_PI / static_cast<float>(numLongitudes); // Longitude angle

            // Convert spherical coordinates to Cartesian coordinates
            float x = std::cos(phi) * std::sin(theta);
            float y = std::cos(theta);
            float z = std::sin(phi) * std::sin(theta);

            // Vertex position
            glm::vec3 position(x, y, z);
            // Normal vector is simply the vertex position normalized, as it points from the origin to the surface
            glm::vec3 normal = glm::normalize(position);
            // Texture coordinates based on latitude and longitude
            float u = static_cast<float>(lon) / static_cast<float>(numLongitudes);
            float v = static_cast<float>(lat) / static_cast<float>(numLatitudes);

            // Add the vertex to the vertex definition array
            vDef.push_back({ position, normal, { u, v } });
        }
    }

    // Generate indices for the sphere triangles
    for (int lat = 0; lat < numLatitudes; ++lat) {
        for (int lon = 0; lon < numLongitudes; ++lon) {
            int index0 = lat * (numLongitudes + 1) + lon;
            int index1 = index0 + 1;
            int index2 = (lat + 1) * (numLongitudes + 1) + lon;
            int index3 = index2 + 1;

            // First triangle
            vIdx.push_back(index0);
            vIdx.push_back(index2);
            vIdx.push_back(index1);

            // Second triangle
            vIdx.push_back(index1);
            vIdx.push_back(index2);
            vIdx.push_back(index3);
        }
    }
}

