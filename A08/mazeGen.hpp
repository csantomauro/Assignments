void Assignment08::createMazeMesh(int row, int col, char** maze) {
	int r, c, i = 0;


	for (r = 0; r < row; r++) {
		for (c = 0; c < col; c++) {
			if (maze[r][c] == '#') {
				// Check if we can extend the current wall horizontally
				int width = 1;
				while (c + width < col && maze[r][c + width] == '#') {
					width++;
				}

				// Check if we can extend the current wall vertically
				int height = 1;
				while (r + height < row) {
					bool canExtend = true;
					for (int w = 0; w < width; w++) {
						if (maze[r + height][c + w] != '#') {
							canExtend = false;
							break;
						}
					}
					if (canExtend) {
						height++;
					}
					else {
						break;
					}
				}

				// Create a merged wall rectangle
				vPos.push_back(r); vPos.push_back(0.0); vPos.push_back(c);
				vPos.push_back(r + height); vPos.push_back(0.0); vPos.push_back(c);
				vPos.push_back(r); vPos.push_back(0.0); vPos.push_back(c + width);
				vPos.push_back(r + height); vPos.push_back(0.0); vPos.push_back(c + width);

				vPos.push_back(r); vPos.push_back(1.0); vPos.push_back(c);
				vPos.push_back(r + height); vPos.push_back(1.0); vPos.push_back(c);
				vPos.push_back(r); vPos.push_back(1.0); vPos.push_back(c + width);
				vPos.push_back(r + height); vPos.push_back(1.0); vPos.push_back(c + width);

				//base square
				vIdx.push_back(i + 0); vIdx.push_back(i + 1); vIdx.push_back(i + 2);
				vIdx.push_back(i + 1); vIdx.push_back(i + 2); vIdx.push_back(i + 3);

				//top square
				vIdx.push_back(i + 4); vIdx.push_back(i + 5); vIdx.push_back(i + 6);
				vIdx.push_back(i + 5); vIdx.push_back(i + 6); vIdx.push_back(i + 7);

				//left square
				vIdx.push_back(i + 0); vIdx.push_back(i + 4); vIdx.push_back(i + 2);
				vIdx.push_back(i + 2); vIdx.push_back(i + 4); vIdx.push_back(i + 6);

				//front square
				vIdx.push_back(i + 0); vIdx.push_back(i + 4); vIdx.push_back(i + 5);
				vIdx.push_back(i + 0); vIdx.push_back(i + 1); vIdx.push_back(i + 5);

				//right square
				vIdx.push_back(i + 1); vIdx.push_back(i + 3); vIdx.push_back(i + 5);
				vIdx.push_back(i + 3); vIdx.push_back(i + 5); vIdx.push_back(i + 7);

				//back square
				vIdx.push_back(i + 2); vIdx.push_back(i + 3); vIdx.push_back(i + 6);
				vIdx.push_back(i + 3); vIdx.push_back(i + 6); vIdx.push_back(i + 7);

				i += 8;

				// Mark the merged wall segments as visited
				for (int h = 0; h < height; h++) {
					for (int w = 0; w < width; w++) {
						maze[r + h][c + w] = '.';
					}
				}
			}
		}
	}

}