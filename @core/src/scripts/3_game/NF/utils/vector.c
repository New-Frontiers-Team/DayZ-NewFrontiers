class NF_Vector {
	// Calculate the distance between X and Z of vectors, ignoring height
    static float Distance2D(vector v1, vector v2) {
		float distanceX = v2[0] - v1[0];
		float distanceZ = v2[2] - v1[2];

		return Math.Sqrt(distanceX * distanceX + distanceZ * distanceZ);
    }

	static vector RandomPositionOnRadius(vector point, int radius) {
		float angleRad = Math.RandomFloat(0, 2 * Math.PI);
        float distance = Math.RandomFloat(0, radius);

        float offsetX = Math.Cos(angleRad) * distance;
        float offsetZ = Math.Sin(angleRad) * distance;

        vector offset = Vector(offsetX, 0, offsetZ);
        vector position = point + offset;

        return position;
	}
}
