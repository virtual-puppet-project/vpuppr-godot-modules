#include "interpolation_helper.h"

void Interpolation::set_both_rates(const float p_new_value) {
	if (should_interpolate) {
		interpolation_rate = p_new_value;
	}
	last_interpolation_rate = p_new_value;
}

void Interpolation::global_rate_changed(const float p_new_value) {
	if (!should_interpolate) {
		interpolation_rate = p_new_value;
	}
}

void Interpolation::maybe_reset_rate(const float p_global_rate) {
	if (should_interpolate) {
		interpolation_rate = last_interpolation_rate;
	} else {
		last_interpolation_rate = interpolation_rate;
		interpolation_rate = p_global_rate;
	}
}
