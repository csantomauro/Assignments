#include <glm/gtx/euler_angles.hpp>

//damping
//Pos = Pos * glm::exp(-10 * deltaT) + Pos * (1.0f - glm::exp(-10 * deltaT));

void GameLogic(Assignment07* A, float Ar, glm::mat4& ViewPrj, glm::mat4& World) {
	// The procedure must implement the game logic  to move the character in third person.
	// Input:
	// <Assignment07 *A> Pointer to the current assignment code. Required to read the input from the user
	// <float Ar> Aspect ratio of the current window (for the Projection Matrix)
	// Output:
	// <glm::mat4 &ViewPrj> the view-projection matrix of the camera
	// <glm::mat4 &World> the world matrix of the object
	// Parameters
	// Camera FOV-y, Near Plane and Far Plane
	const float FOVy = glm::radians(45.0f);
	const float nearPlane = 0.1f;
	const float farPlane = 100.0f;

	// Player starting point
	const glm::vec3 StartingPosition = glm::vec3(-41.50, 0.0, -19.5);

	// Camera target height and distance
	const float camHeight = 0.25;
	const float camDist = 1.5;
	// Camera Pitch limits
	const float minPitch = glm::radians(-8.75f);
	const float maxPitch = glm::radians(60.0f);
	// Rotation and motion speed
	const float ROT_SPEED = glm::radians(120.0f);
	const float MOVE_SPEED = 2.0f;

	// Integration with the timers and the controllers
	// returns:
	// <float deltaT> the time passed since the last frame
	// <glm::vec3 m> the state of the motion axes of the controllers (-1 <= m.x, m.y, m.z <= 1)
	// <glm::vec3 r> the state of the rotation axes of the controllers (-1 <= r.x, r.y, r.z <= 1)
	// <bool fire> if the user has pressed a fire button (not required in this assginment)
	float deltaT;
	glm::vec3 m = glm::vec3(0.0f), r = glm::vec3(0.0f);
	bool fire = false;
	A->getSixAxis(deltaT, m, r, fire);

	// Game Logic implementation
	// Current Player Position - statc variables make sure thattheri value remain unchanged in subsequent calls to the procedure
	static glm::vec3 Pos = StartingPosition;

	//----------------------------------------------------------------------------------------

	static float yaw;    // Yaw angle (rotation around the Y-axis)
	static float pitch;  // Pitch angle (rotation around the X-axis)
	static float roll;   // Roll angle (rotation around the Z-axis)

	// Update character position based on controller input
	glm::vec3 ux = glm::vec3(glm::rotate(glm::mat4(1), glm::radians(yaw), glm::vec3(0, 1, 0)) * glm::vec4(1, 0, 0, 1));
	glm::vec3 uy = glm::vec3(0, 1, 0);
	glm::vec3 uz = glm::vec3(glm::rotate(glm::mat4(1), glm::radians(yaw), glm::vec3(0, 1, 0)) * glm::vec4(0, 0, -1, 1));

	// Update pitch, yaw, and roll based on controller input
	pitch += ROT_SPEED * r.x * deltaT;
	yaw += ROT_SPEED * r.y * deltaT;
	roll += ROT_SPEED * r.z * deltaT;
	Pos += ux * MOVE_SPEED * m.x * deltaT;
	Pos += uy * MOVE_SPEED * m.y * deltaT;
	Pos += uz * MOVE_SPEED * m.z * deltaT;

	// Construct the world matrix using provided code
	glm::mat4 Mw = glm::translate(glm::mat4(1.0), Pos) *
		glm::rotate(glm::mat4(1.0), yaw, glm::vec3(0, 1, 0)) *
		glm::rotate(glm::mat4(1.0), pitch, glm::vec3(1, 0, 0)) *
		glm::rotate(glm::mat4(1.0), roll, glm::vec3(0, 0, 1)) *
		glm::scale(glm::mat4(1.0), glm::vec3(1, 1, 1));

	World = Mw;



	// Update camera view matrix (LookAt)
	static glm::vec3 c = glm::vec3(World *
		glm::vec4(0, camHeight + camDist * sin(pitch),
			camDist * cos(pitch), 1));
	glm::vec3 a = glm::vec3(World * glm::vec4(0, 0, 0, 1)) + glm::vec3(0, 0, camHeight);

	// damping
	glm::vec3 newC = glm::vec3(World *
		glm::vec4(0, camHeight + camDist * sin(pitch),
			camDist * cos(pitch), 1));
	c = c * exp(-10 * deltaT) + newC * (1 - exp(-10 * deltaT));


	glm::mat4 viewMatrix = glm::lookAt(c, a, glm::vec3(0, 1, 0));

	// Update view-projection matrix
	glm::mat4 projectionMatrix = glm::perspective(FOVy, Ar, nearPlane, farPlane);
	projectionMatrix[1][1] *= -1;
	ViewPrj = projectionMatrix * viewMatrix;






}