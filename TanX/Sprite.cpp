#include "Sprite.h"


void Sprite::setOrientation(const Vector& v) {
	// scalar to transform from radians to degrees
	const float transformScalar = 180.0f / 3.14159265358979f;

	// cos angle between two vector is equal to their dot product divided by their magnitudes
	// we're performing dot product on reflected vector, because screen coordinate system is left-handed
	// we want to know angle from vertical line, so we're computing dot product of v and [0, -1]
	float cosAlpha = (0.0f * v.x - 1.0f * v.y) / sqrt(v.x * v.x + v.y * v.y);
	float alpha = transformScalar * acos(cosAlpha);

	// we have to check what quater of coordinates system is given vector in
	if (v.x > 0)
		setRotation(alpha);
	else
		setRotation(360.f - alpha);
}


Vector Sprite::getOrientation() const {
	float alpha = getRotation();
	return Vector(sin(alpha), -cos(alpha));
}
