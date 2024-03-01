#pragma once

namespace Nebula
{

	struct Color
	{

	public:

		//Constructors

		Color() = default;

		Color(float R, float G, float B, float A)
			:R(R), G(G), B(B), A(A)
		{}


		//Static Constructors

		static Color Black;
		static Color White;
		static Color Red;
		static Color Green;
		static Color Blue;

		//Variables

		float R = 0.0f;
		float G = 0.0f;
		float B = 0.0f;
		float A = 1.0f;

	};

}