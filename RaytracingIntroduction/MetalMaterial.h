#pragma once
#include "Material.h"

class MetalMaterial :public Material
{
private:
	Color albedo;
public:
	MetalMaterial(const Color& baseColor) : albedo(baseColor) {}

	bool Scatter(const Ray& rRayIn, const HitInfo& hitInfo, Color& attenuation, Ray& scattered) const override;
};
