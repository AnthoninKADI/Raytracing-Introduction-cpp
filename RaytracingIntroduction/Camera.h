#pragma once
#include "Color.h"
#include "Hittable.h"

class Camera
{
public:
	Camera() = default;
	Camera(double imageWidth, double ratio, int samplePerPixel = 10, int bounces = 10, double vFoV = 90) :
		aspectRatio(ratio), width(imageWidth), sampleCount(samplePerPixel), maxBounces(bounces), verticalFoV(vFoV), defocusAngle(0), focusDistance(10) {}
	void SetTransform(Position origin = Position(0, 0, 0), Position lookAt = Vector3(0, 0, -1), Vector3 upDirection = Vector3(0, 1, 0));
	void SetFocus(double angle = 0, double distance = 10);
	void Render(const Hittable& rWorld);
private:
	int height;
	double aspectRatio, width;
	int sampleCount;
	int maxBounces;
	double verticalFoV;
	double defocusAngle, focusDistance;
	Position position, target;
	Vector3 viewUp;
	Vector3 right, up, forward;
	Vector3 defocusDiskX, defocusDiskY;
	Position center, originPixelLocation;
	Vector3 pixelDeltaX, pixelDeltaY;

	void Initialize();
	Color RayColor(const Ray& rRay, int bouncesLeft, const Hittable& rWorld) const;
	Ray GetRay(int x, int y) const;
	Vector3 PixelSampleSquared() const;
	Position DefocusDiskSample() const;
};
