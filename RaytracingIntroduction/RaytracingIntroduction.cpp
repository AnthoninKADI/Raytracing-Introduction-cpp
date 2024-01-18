#include <iostream>
#include "Color.h"
#include "Ray.h"
#include "Hittable.h"
#include "HittableCollection.h"
#include "Sphere.h"
#include "Utility.h"
#include "Camera.h"
#include "DialectricMaterial.h"
#include "Material.h"
#include "LambertianMaterial.h"
#include "MetalMaterial.h"

using namespace std;

int main(int argc, char* argv[])
{
	//World
	HittableCollection world;

	shared_ptr<Material> groundMat = make_shared<LambertianMaterial>(Color(0.8, 0.8, 0.0));
	shared_ptr<Material> centerMat = make_shared<LambertianMaterial>(Color(0.1, 0.2, 0.5));
	shared_ptr<Material> leftMat = make_shared<DialectricMaterial>(1.5);
	shared_ptr<Material> rightMat = make_shared<MetalMaterial>(Color(0.8, 0.6, 0.2), 0.0);

	world.Add(make_shared<Sphere>(Position(0, -100.5, -1), 100, groundMat));
	world.Add(make_shared<Sphere>(Position(0, 0, -1), 0.5, centerMat));
	world.Add(make_shared<Sphere>(Position(-1, 0, -1), 0.5, leftMat));
	world.Add(make_shared<Sphere>(Position(-1, 0, -1), -0.4, leftMat));
	world.Add(make_shared<Sphere>(Position(1, 0, -1), 0.5, rightMat));

	Camera camera(400, 16.0 / 9.0, 100, 50, 90);
	camera.SetTransform(Position(-2, 2, 1), Position(0, 0, -1), Vector3(0, 1, 0));
	camera.Render(world);
	return 0;
}

