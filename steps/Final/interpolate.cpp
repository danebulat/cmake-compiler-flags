#include "interpolate.h"

namespace animation {

const float fPI = static_cast<float>(M_PI);

float linear(float t, float b, float c, float d) {
	return c * t/d + b;
}

// quadratic easing in - accelerating from zero velocity
float easeInQuad(float t, float b, float c, float d) {
	t /= d;
	return c*t*t + b;
}

// quadratic easing out - decelerating to zero velocity
float easeOutQuad(float t, float b, float c, float d) {
	t /= d;
	return -c * t*(t-2.f) + b;
}

// sinusoidal easing in - accelerating from zero velocity
float easeInSine(float t, float b, float c, float d) {
	return -c * std::cos(t/d * (fPI/2.f)) + c + b;
}

// sinusoidal easing out - decelerating to zero velocity
float easeOutSine(float t, float b, float c, float d) {
	return c * std::sin(t/d * (fPI/2.f)) + b;
}

// exponential easing in - accelerating from zero velocity
float easeInExpo(float t, float b, float c, float d) {
	return c * powf( 2.f, 10.f * (t/d - 1.f) ) + b;
}

// exponential easing out - decelerating to zero velocity
float easeOutExpo(float t, float b, float c, float d) {
	return c * ( -powf( 2.f, -10.f * t/d ) + 1.f ) + b;
}

// ease in back - pulls back before easing in
float easeInBack(float t, float b, float c, float d, float c1) {
	// tweak x for a more dramatic pull back
	t /= d; // 0-1 on curve
	float c3 = c1 + 1.f;
	float val = c3 * t * t * t - c1 * t * t; // modify t with ease in back formula
	return (c * val) + b;
}

// ease out back - over throws before easing out
float easeOutBack(float t, float b, float c, float d, float c1) {
	// tweak c1 value for a more dramatic over throw
	t /= d; // 0-1 on curve
	float c3 = c1 + 1.f;
	float val = 1.f + c3 * powf(t - 1.f, 3.f) + c1 * powf(t - 1.f, 2.f); // apply ease in back formula
	return (c * val) + b;
}

} /* animation namespace */
