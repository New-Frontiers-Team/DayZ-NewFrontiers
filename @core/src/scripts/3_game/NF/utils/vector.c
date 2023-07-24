class NF_Vector {
	// Calculate the distance between X and Z of vectors, ignoring height
    static float Distance2D(vector v1, vector v2) {
		float distanceX = v2[0] - v1[0];
		float distanceZ = v2[2] - v1[2];
		
		return Math.Sqrt(distanceX * distanceX + distanceZ * distanceZ);
    }
}
