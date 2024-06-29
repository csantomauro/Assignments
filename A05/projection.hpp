#define GLM_FORCE_DEPTH_ZERO_TO_ONE

void SetupProjectionMatrices(Assignment05* A, float Ar) {
	/**************
	 Method Matrix(int N, glm::mat4 M) of object A,
	 receives in N the number of the matrix that needs to be set, and the matrix in M
	***************/

	glm::mat4 S;
	float nearPlane = 0.1f;
	float farPlane = 50.0f;
	float fovy1 = glm::radians(60.0f);
	float fovy2 = glm::radians(105.0f);
	float fovy3 = glm::radians(25.0f);
	//float fovy4 = 2.0f * atan(tan(glm::radians(45.0f) / 2.0f) / Ar);
	float fovy4 = glm::radians(45.0f / 2);


	// Fov-y = 60 deg
	S = glm::mat4(1);
	glm::mat4 M1 = glm::perspective(fovy1, (float)Ar, nearPlane, farPlane);
	M1[1][1] *= -1;
	S = M1;
	A->Matrix(1, S); // sets the matrix corresponding to piece 1

	// Fov-y = 105 deg
	S = glm::mat4(1);
	glm::mat4 M2 = glm::perspective(fovy2, (float)Ar, nearPlane, farPlane);
	M2[1][1] *= -1;
	S = M2;
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	// Fov-y = 25 deg
	S = glm::mat4(1);
	glm::mat4 M3 = glm::perspective(fovy3, (float)Ar, nearPlane, farPlane);
	M3[1][1] *= -1;
	S = M3;
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// Right View, Fov-x = 45 deg
	S = glm::mat4(1);
	//float l = -Ar * nearPlane * tan(glm::radians(0.0f));
	float r = Ar * nearPlane * tan(fovy4) * 2;
	float l = 0.0f;
	float t = nearPlane * tan(fovy4);
	float b = -nearPlane * tan(fovy4);
	S = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) * glm::frustum(l, r, b, t, nearPlane, farPlane);
	A->Matrix(4, S); // sets the matrix corresponding to piece 4

}