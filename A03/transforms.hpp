#define GLM_FORCE_RADIANS


void SetupMatrices(Assignment03* A) {
	/**************
	 Method Matrix(int N, glm::mat4 M) of object A,
	 receives in N the number of the matrix that needs to be set, and the matrix in M
	***************/

	glm::mat4 S;


	// To solve the puzzle: scale 2x proportionally, centered in (2,0,-3)
	S = glm::mat4(1);
	glm::mat4 M1_1 = glm::translate(S, glm::vec3(2, 0, -3));
	glm::mat4 M1_2 = glm::scale(S, glm::vec3(2, 2, 2));
	S = M1_1 * M1_2 * inverse(M1_1);
	A->Matrix(1, S); // sets the matrix corresponding to piece 1

	// To solve the puzzle: scale 2x on an axis oriented 45 degrees between the x and z axis and passing through point (1,0,0)
	S = glm::mat4(1);
	glm::mat4 M2_1 = glm::translate(S, glm::vec3(1, 0, 0));
	glm::mat4 M2_2 = glm::scale(S, glm::vec3(3, 1, 1));
	glm::mat4 M2_3 = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0, 1, 0));
	S = M2_1 * M2_3 * M2_2 * inverse(M2_3) * inverse(M2_1);
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	// To solve the puzzle: find it yourself! Hint: compose a rotation around an arbitrary point with a translation
	S = glm::mat4(1);
	glm::mat4 M3_1 = glm::translate(S, glm::vec3(-2.55, 0, 1.3));
	glm::mat4 M3_2 = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0, 1, 0));
	//glm::mat4 M3_3 = glm::translate(S, glm::vec3(1, 0, 0));
	S = M3_1 * M3_2;
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// To solve the puzzle: rotate 60 degree around the y axis, centered in (-1,0,-2)
	S = glm::mat4(1);
	glm::mat4 M4_1 = glm::translate(S, glm::vec3(-1, 0, -2));
	glm::mat4 M4_2 = glm::rotate(glm::mat4(1), glm::radians(60.0f), glm::vec3(0, 1, 0));
	S = M4_1 * M4_2 * inverse(M4_1);
	A->Matrix(4, S); // sets the matrix corresponding to piece 4

	// To solve the puzzle: rotate -90 degree around an arbitrary axis passing in (-1,0,0). The x axis can be aligned to this arbitrary direction with a rotation of -45 around the y axis.	
	S = glm::mat4(1);
	glm::mat4 M5_1 = glm::translate(S, glm::vec3(-1, 0, 0));
	glm::mat4 M5_2 = glm::rotate(glm::mat4(1), glm::radians(-90.0f), glm::vec3(1, 0, 0));
	glm::mat4 M5_3 = glm::rotate(glm::mat4(1), glm::radians(-45.0f), glm::vec3(0, 1, 0));
	S = M5_1 * M5_3 * M5_2 * inverse(M5_3) * inverse(M5_1);
	A->Matrix(5, S); // sets the matrix corresponding to piece 5

	// To solve the puzzle: find it yourself! Hint: compose a non-proportional scaling that halves the object along one of the main axes, centered in an arbitrary point, with a translation
	S = glm::mat4(1);
	glm::mat4 M6_1 = glm::translate(S, glm::vec3(1, 0, 2));
	glm::mat4 M6_2 = glm::scale(S, glm::vec3(0.5, 1, 1));
	S = M6_1 * M6_2 * inverse(M6_1);
	A->Matrix(6, S); // sets the matrix corresponding to piece 6

}