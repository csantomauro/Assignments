void SetupProjectionMatrices(Assignment04* A, float Ar) {
	/**************
	 Method Matrix(int N, glm::mat4 M) of object A,
	 receives in N the number of the matrix that needs to be set, and the matrix in M
	***************/

	glm::mat4 S;


	S = glm::mat4(1);
	glm::mat4 ry = glm::rotate(S, glm::radians(-45.0f), glm::vec3(0, 1, 0));
	glm::mat4 rx = glm::rotate(S, glm::radians(35.26f), glm::vec3(1, 0, 0));
	glm::mat4 P = glm::mat4(0.1, 0, 0, 0, 0, -0.1333333, 0, 0, 0, 0, -0.01, 0, 0, 0, 0.5, 1);
	S = P * rx * ry;
	A->Matrix(1, S); // sets the matrix corresponding to piece 1

	// Dimetric
	S = glm::mat4(1);
	glm::mat4 ry_d = glm::rotate(S, glm::radians(-45.0f), glm::vec3(0, 1, 0));
	glm::mat4 rx_d = glm::rotate(S, glm::radians(25.0f), glm::vec3(1, 0, 0));
	glm::mat4 P_d = glm::mat4(0.1, 0, 0, 0, 0, -0.1333333, 0, 0, 0, 0, -0.01, 0, 0, 0, 0.5, 1);
	S = P_d * rx_d * ry_d;
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	// Trimetric
	S = glm::mat4(1);
	glm::mat4 ry_t = glm::rotate(S, glm::radians(-30.0f), glm::vec3(0, 1, 0));
	glm::mat4 rx_t = glm::rotate(S, glm::radians(65.0f), glm::vec3(1, 0, 0));
	glm::mat4 P_t = glm::mat4(0.1, 0, 0, 0, 0, -0.1333333, 0, 0, 0, 0, -0.01, 0, 0, 0, 0.5, 1);
	S = P_t * rx_t * ry_t;
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// Cabinet
	S = glm::mat4(1);
	glm::mat4 m_c = glm::mat4(1, 0, 0, 0, 0, 1, 0, 0, -0.5 * cos(45.0f), -0.5 * sin(45.0f), 1, 0, 0, 0, 0, 1);
	glm::mat4 P_c = glm::mat4(0.1, 0, 0, 0, 0, -(Ar / 10), 0, 0, 0, 0, -0.01, 0, 0, 0, 0.5, 1);
	S = P_c * m_c;
	//S = P * m_c; BEFORE CORRECTION
	A->Matrix(4, S); // sets the matrix corresponding to piece 4

}