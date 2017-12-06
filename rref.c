void rref(double **mat, int rows, int cols) {


	double tol = 1e-8;

	int r = 0;
	for (int c = 0; c < cols && r < rows; c++) {

		int j = r;

		for (int i = r + 1; i < rows; i++) {

			if (abs(mat[i][c]) > abs(mat[j][c])) {
				j = i;
			}

		}

		if (abs(mat[j][c]) < tol) {
			continue;
		}

		double *temp = (double*)malloc(sizeof(double)*cols);

		for (int k = 0; k < cols; k++) {
			temp[k] = mat[j][k];
			mat[j][k] = mat[r][k];
			mat[r][k] = temp[k];
		}

		free(temp);

		double s = 1.0 / mat[r][c];

		for (j = 0; j < cols; j++) {
			mat[r][j] *= s;
		}

		for (int i = 0; i < rows; i++) {

			if (i != r) {
				double t = mat[i][c];

				for (j = 0; j < cols; j++) {
					mat[i][j] -= t * mat[r][j];
				}

			}

		}

		r++;

	}

}