void Assignment14::createCubeMesh(std::vector<Vertex>& vDef, std::vector<uint32_t>& vIdx) {

	// Fill array vPos with the positions of the vertices of the mesh
	vDef.push_back({ {-1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f} }); // vertex 0 - Position and Normal
	vDef.push_back({ {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f} }); // vertex 1 - Position and Normal
	vDef.push_back({ {-1.0f, -1.0f, 1.0f}, {0.0f, 0.0f, 1.0f} }); // vertex 2 - Position and Normal
	vDef.push_back({ {1.0f, -1.0f, 1.0f}, {0.0f, 0.0f, 1.0f} }); // vertex 3 - Position and Normal
	vDef.push_back({ {1.0f, -1.0f, 1.0f}, {1.0f, 0.0f, 0.0f} }); // vertex 4 - Position and Normal
	vDef.push_back({ {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 0.0f} }); // vertex 5 - Position and Normal
	vDef.push_back({ {1.0f, 1.0f, -1.0f}, {1.0f, 0.0f, 0.0f} }); // vertex 6 - Position and Normal
	vDef.push_back({ {1.0f, -1.0f, -1.0f}, {1.0f, 0.0f, 0.0f} }); // vertex 7 - Position and Normal
	vDef.push_back({ {1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, -1.0f} }); // vertex 8 - Position and Normal
	vDef.push_back({ {1.0f, 1.0f, -1.0f}, {0.0f, 0.0f, -1.0f} }); // vertex 9 - Position and Normal
	vDef.push_back({ {-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, -1.0f} }); // vertex 10 - Position and Normal
	vDef.push_back({ {-1.0f, 1.0f, -1.0f}, {0.0f, 0.0f, -1.0f} }); // vertex 11 - Position and Normal
	vDef.push_back({ {-1.0f, 1.0f, -1.0f}, {-1.0f, 0.0f, 0.0f} }); // vertex 12 - Position and Normal
	vDef.push_back({ {-1.0f, -1.0f, -1.0f}, {-1.0f, 0.0f, 0.0f} }); // vertex 13 - Position and Normal
	vDef.push_back({ {-1.0f, 1.0f, 1.0f}, {-1.0f, 0.0f, 0.0f} }); // vertex 14 - Position and Normal
	vDef.push_back({ {-1.0f, -1.0f, 1.0f}, {-1.0f, 0.0f, 0.0f} }); // vertex 15 - Position and Normal
	vDef.push_back({ {-1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f} }); // vertex 16 - Position and Normal
	vDef.push_back({ {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f} }); // vertex 17 - Position and Normal
	vDef.push_back({ {1.0f, 1.0f, -1.0f}, {0.0f, 1.0f, 0.0f} }); // vertex 18 - Position and Normal
	vDef.push_back({ {-1.0f, 1.0f, -1.0f}, {0.0f, 1.0f, 0.0f} }); // vertex 19 - Position and Normal
	vDef.push_back({ {1.0f, -1.0f, -1.0f}, {0.0f, -1.0f, 0.0f} }); // vertex 20 - Position and Normal
	vDef.push_back({ {-1.0f, -1.0f, -1.0f}, {0.0f, -1.0f, 0.0f} }); // vertex 21 - Position and Normal
	vDef.push_back({ {1.0f, -1.0f, 1.0f}, {0.0f, -1.0f, 0.0f} }); // vertex 22 - Position and Normal
	vDef.push_back({ {-1.0f, -1.0f, 1.0f}, {0.0f, -1.0f, 0.0f} }); // vertex 23 - Position and Normal

	// Fill the array vIdx with the indices of the vertices of the triangles
	// Front face
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2); // First triangle
	vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3); // Second triangle

	// Right face
	vIdx.push_back(4); vIdx.push_back(5); vIdx.push_back(6); // First triangle
	vIdx.push_back(4); vIdx.push_back(6); vIdx.push_back(7); // Second triangle

	// Front face
	vIdx.push_back(8); vIdx.push_back(9); vIdx.push_back(10); // First triangle
	vIdx.push_back(9); vIdx.push_back(10); vIdx.push_back(11); // Second triangle

	// Back face
	vIdx.push_back(12); vIdx.push_back(13); vIdx.push_back(14); // First triangle
	vIdx.push_back(13); vIdx.push_back(14); vIdx.push_back(15); // Second triangle

	// Left face
	vIdx.push_back(16); vIdx.push_back(17); vIdx.push_back(18); // First triangle
	vIdx.push_back(16); vIdx.push_back(18); vIdx.push_back(19); // Second triangle

	// Right face
	vIdx.push_back(20); vIdx.push_back(21); vIdx.push_back(22); // First triangle
	vIdx.push_back(21); vIdx.push_back(22); vIdx.push_back(23); // Second triangle
}

void Assignment14::createFunctionMesh(std::vector<Vertex>& vDef, std::vector<uint32_t>& vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	// The primitive built here is the surface y = sin(x) * cos(z) with -3 <= x <= 3 and -3 <= z <= 3.

		// Define the range for x and z
	float minX = -3.0f;
	float maxX = 3.0f;
	float minZ = -3.0f;
	float maxZ = 3.0f;

	// Define the number of segments for x and z
	int numSegmentsX = 100;
	int numSegmentsZ = 100;

	// Calculate the step sizes for x and z
	float stepX = (maxX - minX) / numSegmentsX;
	float stepZ = (maxZ - minZ) / numSegmentsZ;

	// Generate vertices and normals for the surface
	for (int i = 0; i <= numSegmentsX; ++i) {
		float x = minX + i * stepX;
		for (int j = 0; j <= numSegmentsZ; ++j) {
			float z = minZ + j * stepZ;
			float y = sin(x) * cos(z); // Calculate y based on the function

			// Calculate the normal vector using gradient (partial derivatives)
			glm::vec3 normal(
				-cos(x) * cos(z),   // Partial derivative with respect to x
				1.0f,               // dy/dy = 1
				sin(x) * sin(z)     // Partial derivative with respect to z
			);
			normal = glm::normalize(normal);

			// Add the vertex to the vector
			vDef.push_back({ glm::vec3(x, y, z), normal });
		}
	}

	// Generate indices for triangles
	for (int i = 0; i < numSegmentsX; ++i) {
		for (int j = 0; j < numSegmentsZ; ++j) {
			int currentIndex = i * (numSegmentsZ + 1) + j;
			int nextIndex = currentIndex + 1;
			int nextRowIndex = (i + 1) * (numSegmentsZ + 1) + j;
			int nextRowNextIndex = nextRowIndex + 1;

			// Create two triangles for each quad
			vIdx.push_back(currentIndex);
			vIdx.push_back(nextIndex);
			vIdx.push_back(nextRowNextIndex);

			vIdx.push_back(currentIndex);
			vIdx.push_back(nextRowNextIndex);
			vIdx.push_back(nextRowIndex);
		}
	}
}


void Assignment14::createCylinderMesh(std::vector<Vertex>& vDef, std::vector<uint32_t>& vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	// The primitive built here is a cylinder, with radius 1, and height 2, centered in the origin.

	const int numSegments = 50; // Number of segments to approximate the circle
	const float height = 2.0f;
	const float radius = 1.0f;
	const float M_PI = 3.1415926;

	// Generate vertices for the side surface of the cylinder
	for (int i = 0; i < numSegments; ++i) {
		float theta = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(numSegments); // Angle around the circle
		float x = radius * std::cos(theta);
		float z = radius * std::sin(theta);
		float nx = std::cos(theta);
		float nz = std::sin(theta);

		// Top vertex of the side surface
		vDef.push_back({ {x, height / 2.0f, z}, {nx, 0.0f, nz} });

		// Bottom vertex of the side surface
		vDef.push_back({ {x, -height / 2.0f, z}, {nx, 0.0f, nz} });
	}

	// Generate vertices for the top circle
	for (int i = 0; i < numSegments; ++i) {
		float theta = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(numSegments); // Angle around the circle
		float x = radius * std::cos(theta);
		float z = radius * std::sin(theta);

		vDef.push_back({ {x, height / 2.0f, z}, {0.0f, 1.0f, 0.0f} });
	}

	// Generate vertices for the bottom circle
	for (int i = 0; i < numSegments; ++i) {
		float theta = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(numSegments); // Angle around the circle
		float x = radius * std::cos(theta);
		float z = radius * std::sin(theta);

		vDef.push_back({ {x, -height / 2.0f, z}, {0.0f, -1.0f, 0.0f} });
	}

	// Generate indices for the side surface of the cylinder
	for (int i = 0; i < numSegments; ++i) {
		int nextIdx = (i + 1) % numSegments;
		// First triangle of the quad
		vIdx.push_back(2 * i);
		vIdx.push_back(2 * i + 1);
		vIdx.push_back(2 * nextIdx + 1);

		// Second triangle of the quad
		vIdx.push_back(2 * nextIdx + 1);
		vIdx.push_back(2 * nextIdx);
		vIdx.push_back(2 * i);
	}

	// Generate indices for the top circle
	for (int i = 0; i < numSegments; ++i) {
		int nextIdx = (i + 1) % numSegments;
		vIdx.push_back(2 * numSegments);
		vIdx.push_back(2 * numSegments + i);
		vIdx.push_back(2 * numSegments + nextIdx);
	}

	// Generate indices for the bottom circle
	for (int i = 0; i < numSegments; ++i) {
		int nextIdx = (i + 1) % numSegments;
		vIdx.push_back(3 * numSegments);
		vIdx.push_back(3 * numSegments + i);
		vIdx.push_back(3 * numSegments + nextIdx);
	}
}
