/// <summary>
/// Name: James Murray
/// Date: 17/01/22
/// </summary>

#include "MyVector2.h"


/// <summary>
/// get length of vector using sqrt of the sum of the squares
/// </summary>
/// <param name="t_vector">input vector</param>
/// <returns>length</returns>
float vectorLength(const sf::Vector2f t_vectorA)
{
	float sumOfSquares = (t_vectorA.x * t_vectorA.x ) + (t_vectorA.y * t_vectorA.y);
	const float length = std::sqrt(sumOfSquares);
	return length;
}

/// <summary>
/// get length of vector ^2, using the fact that, SumOfSquares = Length^2
/// </summary>
/// <param name="t_vectorA">input vector</param>
/// <returns>length^2</returns>
float vectorLengthSquared(const sf::Vector2f t_vectorA)
{
	float lengthSqr = (t_vectorA.x * t_vectorA.x) + (t_vectorA.y * t_vectorA.y);
	return lengthSqr;
}

/// <summary>
/// get cross product, using (X1 x Y2) - (X2 x Y1)
/// </summary>
/// <param name="t_vectorA">input vector A</param>
/// <param name="t_VectorB">input vector B</param>
/// <returns>cross product of vector A & B</returns>
float vectorCrossProduct(const sf::Vector2f t_vectorA, const sf::Vector2f t_vectorB)
{
	const float Cross1 = t_vectorA.x * t_vectorB.y;
	const float Cross2 = t_vectorB.x * t_vectorA.y;
	float crossP = Cross1 - Cross2;
	return crossP;
}

/// <summary>
/// get dot product, using (X1 x X2) + (Y1 x Y2)
/// </summary>
/// <param name="t_vectorA">input vector A</param>
/// <param name="t_vectorB">input vector B</param>
/// <returns>cross product of vector A & B</returns>
float vectorDotProduct(const sf::Vector2f t_vectorA, const sf::Vector2f t_vectorB)
{
	const float result = (t_vectorA.x * t_vectorB.x) + (t_vectorA.y * t_vectorB.y);
	return result;
}

/// <summary>
/// get angle between, using cos@ = (U> . V>) / (||U>|| . ||V>||)
/// </summary>
/// <param name="t_vectorA">input vector A</param>
/// <param name="t_vectorB">input vector B</param>
/// <returns>cross product of vector A & B</returns>
float vectorAngleBetween(const sf::Vector2f t_vectorA, const sf::Vector2f t_vectorB)
{
	float cosine = vectorDotProduct(t_vectorA, t_vectorB);
	cosine = cosine / (vectorLength(t_vectorA) * vectorLength(t_vectorB));
	if (cosine > 1.0f) // just make sure rounding errors don't put us outside domain limits - 1 < -> 1
	{
		cosine = 1.0f;
	}
	if (cosine < -1.0f)
	{
		cosine = -1.0f;
	}
	const float angleInRadians = std::acos(cosine);
	const float angleInDegrees = angleInRadians * 180.0f / PI;
	return angleInDegrees;
}

sf::Vector2f vectorRotateBy(const sf::Vector2f t_vectorA, const  float t_angleRadians)
{
	const float cos = std::cos(t_angleRadians); //calculate once use twice
	const float sin = std::sin(t_angleRadians);
	const float xComponent = (t_vectorA.x * cos) - (t_vectorA.y * sin);
	const float yComponent = (t_vectorA.x * sin) + (t_vectorA.y * cos);
	const sf::Vector2f result{ xComponent, yComponent };
	return result;
}

sf::Vector2f vectorProjection(const sf::Vector2f t_vectorA, const  sf::Vector2f t_onto)
{
	float scale = vectorDotProduct(t_vectorA, t_onto) / vectorLengthSquared(t_onto);
	const sf::Vector2f result = t_onto * scale;
	return result;
}

sf::Vector2f vectorRejection(const sf::Vector2f t_vectorA, const  sf::Vector2f t_onto)
{
	const sf::Vector2f result = t_vectorA - vectorProjection(t_vectorA, t_onto);
	return result;
}

float vectorScalarProjection(const sf::Vector2f t_vector, const  sf::Vector2f t_onto)
{
	float result = vectorDotProduct(t_vector, t_onto) / vectorLength(t_onto);
	return result;
}

sf::Vector2f vectorUnitVector(const sf::Vector2f t_vectorA)
{
	sf::Vector2f result{ 0.0f,0.0f };
	const float lenght = vectorLength(t_vectorA);
	if (lenght != 0.0f) // never divide by zero unless the zombies are overrunning the base
	{
	result = sf::Vector2f{ t_vectorA.x / lenght, t_vectorA.y / lenght };
	}
	return result;
}

