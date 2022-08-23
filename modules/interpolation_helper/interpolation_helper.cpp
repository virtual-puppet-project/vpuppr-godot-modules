#include "interpolation_helper.h"

void InterpolationHelper::set_both_rates(float p_new_value) {
    if (should_interpolate) {
        interpolation_rate = p_new_value;
    }
    last_interpolation_rate = p_new_value;
}

void InterpolationHelper::global_rate_changed(float p_new_value) {
    if (!should_interpolate) {
        interpolation_rate = p_new_value;
    }
}

void InterpolationHelper::maybe_reset_rate(float p_global_rate) {
    if (should_interpolate) {
        interpolation_rate = last_interpolation_rate;
    } else {
        last_interpolation_rate = interpolation_rate;
        interpolation_rate = p_global_rate;
    }
}

Variant InterpolationHelper::interpolate(const float p_rate) {
    last_value = interpolate_no_update(p_rate);

    return last_value;
}

Variant InterpolationHelper::interpolate_no_update(const float p_rate) {
    switch (target_value.get_type()) {
        case Variant::REAL:
            return Variant(lerp(float(last_value), float(target_value) * damping, p_rate));
        case Variant::VECTOR2:
            return Variant(lerp(Vector2(last_value), Vector2(target_value) * damping, p_rate));
        case Variant::VECTOR3:
            return Variant(lerp(Vector3(last_value), Vector3(target_value) * damping, p_rate));
        default:
            return Variant();
    }
}

void InterpolationHelper::set_should_interpolate(bool p_should_interpolate) {
    should_interpolate = p_should_interpolate;
}

bool InterpolationHelper::get_should_interpolate() const {
    return should_interpolate;
}

void InterpolationHelper::set_interpolation_rate(const float p_interpolation_rate) {
    interpolation_rate = p_interpolation_rate;
}

float InterpolationHelper::get_interpolation_rate() const {
    return interpolation_rate;
}

void InterpolationHelper::set_last_interpolation_rate(const float p_last_interpolation_rate) {
    last_interpolation_rate = p_last_interpolation_rate;
}

float InterpolationHelper::get_last_interpolation_rate() const {
    return last_interpolation_rate;
}

void InterpolationHelper::set_last_value(const Variant &p_last_value) {
    last_value = p_last_value;
}

Variant InterpolationHelper::get_last_value() const {
    return last_value;
}

void InterpolationHelper::set_target_value(const Variant &p_target_value) {
    target_value = p_target_value;
}

Variant InterpolationHelper::get_target_value() const {
    return target_value;
}

InterpolationHelper::InterpolationHelper() {}

InterpolationHelper::~InterpolationHelper() {}

void InterpolationHelper::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_both_rates", "new_rate"), &InterpolationHelper::set_both_rates);
    ClassDB::bind_method(D_METHOD("global_rate_changed", "new_rate"), &InterpolationHelper::global_rate_changed);
    ClassDB::bind_method(D_METHOD("maybe_reset_rate", "global_rate"), &InterpolationHelper::maybe_reset_rate);
    ClassDB::bind_method(D_METHOD("interpolate", "rate"), &InterpolationHelper::interpolate);
    ClassDB::bind_method(D_METHOD("interpolate_no_update", "rate"), &InterpolationHelper::interpolate_no_update);

    ClassDB::bind_method(D_METHOD("set_should_interpolate", "should_interpolate"), &InterpolationHelper::set_should_interpolate);
    ClassDB::bind_method(D_METHOD("get_should_interpolate"), &InterpolationHelper::get_should_interpolate);

    ClassDB::bind_method(D_METHOD("set_interpolation_rate", "interpolation_rate"), &InterpolationHelper::set_interpolation_rate);
    ClassDB::bind_method(D_METHOD("get_interpolation_rate"), &InterpolationHelper::get_interpolation_rate);

    ClassDB::bind_method(D_METHOD("set_last_interpolation_rate", "last_interpolation_rate"), &InterpolationHelper::set_last_interpolation_rate);
    ClassDB::bind_method(D_METHOD("get_last_interpolation_rate"), &InterpolationHelper::get_last_interpolation_rate);

    ClassDB::bind_method(D_METHOD("set_last_value", "last_value"), &InterpolationHelper::set_last_value);
    ClassDB::bind_method(D_METHOD("get_last_value"), &InterpolationHelper::get_last_value);

    ClassDB::bind_method(D_METHOD("set_target_value", "target_value"), &InterpolationHelper::set_target_value);
    ClassDB::bind_method(D_METHOD("get_target_value"), &InterpolationHelper::get_target_value);

    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "should_interpolate"), "set_should_interpolate", "get_should_interpolate");

    ADD_PROPERTY(PropertyInfo(Variant::REAL, "interpolation_rate"), "set_interpolation_rate", "get_interpolation_rate");
    ADD_PROPERTY(PropertyInfo(Variant::REAL, "last_interpolation_rate"), "set_last_interpolation_rate", "get_last_interpolation_rate");

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "last_value"), "set_last_value", "get_last_value");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "target_value"), "set_target_value", "get_target_value");
}
