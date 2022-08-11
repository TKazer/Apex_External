#pragma once
#include <Windows.h>

struct Vec3 {
	float x, y, z;
	Vec3() { x = 0; y = 0; z = 0; }
	Vec3(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }
	bool operator==(const float _t) {
		return x == _t && y == _t && z == _t;
	}
	bool operator==(Vec3 _t) {
		return x == _t.x && y == _t.y && z == _t.z;
	}
	bool operator!=(Vec3 _t) {
		return x != _t.x && y != _t.y && z != _t.z;
	}
	bool operator<(const float _t) {
		return x < _t&& y < _t&& z < _t;
	}
	bool operator>(const float _t) {
		return x > _t && y > _t && z > _t;
	}
	bool operator>=(const float _t) {
		return x >= _t && y >= _t && z >= _t;
	}
	bool operator<=(const float _t) {
		return x <= _t && y <= _t && z <= _t;
	}
	bool operator!=(const float _t) {
		return x != _t && y != _t && z != _t;
	}
};

struct Vec2 {
	float x, y;
	Vec2() { x = 0; y = 0; }
	Vec2(float _x, float _y) { x = _x; y = _y; }
	Vec2(Vec3 _t) { x = _t.x; y = _t.y; }
	bool operator==(const float _t) {
		return x == _t && y == _t;
	}
	bool operator<(const float _t) {
		return x < _t&& y < _t;
	}
	bool operator>(const float _t) {
		return x > _t && y > _t;
	}
	bool operator>=(const float _t) {
		return x >= _t && y >= _t;
	}
	bool operator<=(const float _t) {
		return x <= _t && y <= _t;
	}
	bool operator!=(const float _t) {
		return x != _t && y != _t;
	}
};

struct RGB {
	float R, G, B;
};

struct BaseMatrix
{
	float at[4][4]{};
};