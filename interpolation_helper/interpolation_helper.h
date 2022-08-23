#ifndef INTERPOLATION_HELPER_H
#define INTERPOLATION_HELPER_H

#include "core/reference.h"

class Interpolation : public Reference {
	bool should_interpolate = false;
	float interpolation_rate = 0.0;
	float last_interpolation_rate = 0.0;

	float damping = 1.0;

public:
	void set_both_rates(const float p_new_value);
	void global_rate_changed(const float p_new_value);
	void maybe_reset_rate(const float p_global_rate);

	virtual void interpolate(const float p_rate = interpolation_rate) = 0;
	virtual void interpolate_no_update(const float p_rate = interpolation_rate) = 0;

	virtual void set_last_value(const float p_last_value) = 0;
	virtual float get_last_value() const = 0;

	virtual void set_last_value(const Vector2 p_last_value) = 0;
	virtual Vector2 get_last_value() const = 0;

	virtual void set_last_value(const Vector3 p_last_value) = 0;
	virtual Vector3 get_last_value() const = 0;

	virtual void set_target_value(const float p_target_value) = 0;
	virtual float get_target_value() const = 0;

	virtual void set_last_value(const Vector2 p_target_value) = 0;
	virtual Vector2 get_target_value() const = 0;

	virtual void set_last_value(const Vector3 p_target_value) = 0;
	virtual Vector3 get_target_value() const = 0;
}

class InterpolatedFloat : public Interpolation {
	float last_value = 0.0;
	float target_value = 0.0;

	void set_last_value(const float p_last_value) override;
	float get_last_value() const override;

	void set_target_value(const float p_target_value) override;
	float get_target_value() const override;
}

class InterpolatedVector2 : public Interpolation {
	Vector2 last_value = 0.0;
	Vector2 target_value = 0.0;

	void set_last_value(const Vector2 p_last_value) override;
	Vector2 get_last_value() const override;

	void set_target_value(const Vector2 p_target_value) override;
	Vector2 get_target_value() const override;
}

class InterpolatedVector3 : public Interpolation {
	Vector3 last_value = 0.0;
	Vector3 target_value = 0.0;

	void set_last_value(const Vector3 p_last_value) override;
	Vector3 get_last_value() const override;

	void set_target_value(const Vector3 p_target_value) override;
	Vector3 get_target_value() const override;
}

class InterpolationHelper : public Reference {
	Vector<Interpolation> interpolations;

	void set_interpolations(Vector<Interpolation> p_interpolations);
	Vector<Interpolation> get_interpolations();
};

#endif // INTERPOLATION_HELPER_H
