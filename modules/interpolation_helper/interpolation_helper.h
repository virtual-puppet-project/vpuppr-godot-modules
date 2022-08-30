#ifndef INTERPOLATION_HELPER_H
#define INTERPOLATION_HELPER_H

#include "core/reference.h"

class InterpolationHelper : public Reference {
	GDCLASS(InterpolationHelper, Reference);

	bool should_interpolate = false;
	float interpolation_rate = 0.0;
	float last_interpolation_rate = 0.0;

	float damping = 1.0;

	Variant last_value;
	Variant target_value;

private:
	_FORCE_INLINE_ float lerp(float p_from, float p_to, float p_weight) {
		return p_from + (p_to - p_from) * p_weight;
	}
	_FORCE_INLINE_ Vector2 lerp(Vector2 p_from, Vector2 p_to, float p_weight) {
		return p_from + (p_to - p_from) * p_weight;
	}
	_FORCE_INLINE_ Vector3 lerp(Vector3 p_from, Vector3 p_to, float p_weight) {
		return p_from + (p_to - p_from) * p_weight;
	}

protected:
	static void _bind_methods();

public:
	void set_both_rates(const float p_new_value);
	void global_rate_changed(const float p_new_value);
	void maybe_reset_rate(const float p_global_rate);

	Variant interpolate(const float p_rate);
	Variant interpolate_no_update(const float p_rate);

	void set_should_interpolate(const bool p_should_interpolate);
	bool get_should_interpolate() const;

	void set_interpolation_rate(const float p_interpolation_rate);
	float get_interpolation_rate() const;

	void set_last_interpolation_rate(const float p_last_interpolation_rate);
	float get_last_interpolation_rate() const;

	void set_damping(const float p_damping);
	float get_damping() const;

	void set_last_value(const Variant &p_last_value);
	Variant get_last_value() const;

	void set_target_value(const Variant &p_target_value);
	Variant get_target_value() const;

	InterpolationHelper();
	~InterpolationHelper();
};

#endif // INTERPOLATION_HELPER_H
