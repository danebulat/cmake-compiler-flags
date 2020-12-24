#pragma once
#include <cmath>

namespace animation {

/*
Interpolation functions implemented for some standard easing
functions documented here:
    https://easings.net/

Signature parameter documentation:
    t = elapsed_time   (the current elapsed time)
    b = start_value    (starting value of tween)
    c = change_value   (how much to change the start value)
    d = duration       (how long the tween is)
*/

// linear - no easing, no acceleration
float linear(float t, float b, float c, float d);

// quadratic easing in - accelerating from zero velocity
float easeInQuad(float t, float b, float c, float d);

// quadratic easing out - decelerating to zero velocity
float easeOutQuad(float t, float b, float c, float d);

// sinusoidal easing in - accelerating from zero velocity
float easeInSine(float t, float b, float c, float d);

// sinusoidal easing out - decelerating to zero velocity
float easeOutSine(float t, float b, float c, float d);

// exponential easing in - accelerating from zero velocity
float easeInExpo(float t, float b, float c, float d);

// exponential easing out - decelerating to zero velocity
float easeOutExpo(float t, float b, float c, float d);

// ease in back - pulls back before easing in
float easeInBack(float t, float b, float c, float d, float c1=1.70158f);

// ease out back - over throws before easing out
float easeOutBack(float t, float b, float c, float d, float c1=1.70158f);

} /* animation namespace */

