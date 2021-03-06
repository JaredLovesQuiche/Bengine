#pragma once

#include "LinearMath/btTransform.h"
#include <glm.hpp>

typedef struct Player {
	glm::vec3 position;
	glm::vec3 headOffset{ glm::vec3(0.0f, 1.0f, 0.0f) };
	float fov;
	float cam_angle_vertical;
	float cam_angle_horizontal;
	float cam_near_clipping_plane;
	float cam_far_clipping_plane;

	float rArmExtend = 0.0f; //current forward extension of the arm (multiplied by cam forward & right)
	float lArmExtend = 0.0f;
	float armExtendMulti = 0.8f; //max extension of the arm
	float armLerpT = 0.5f;

	glm::vec3 cam_offset;
	float speed;
	float mouseSpeed;

	bool grounded;

	btTransform transform;

	const glm::vec3 GetHeadAnchor() {
		return position + headOffset;
	}

	const glm::vec3 GetRArmAnchor(glm::vec3 front, glm::vec3 right, glm::vec3 up) {
		glm::vec3 anchorPos = (position + glm::vec3(0, 1.5, 0)) + front * 2.5f + right * 1.5f - up * 0.5f;
		anchorPos += front * rArmExtend - right * rArmExtend;
		return anchorPos;
	}

	const glm::vec3 GetLArmAnchor(glm::vec3 front, glm::vec3 right, glm::vec3 up) {
		glm::vec3 anchorPos = (position + glm::vec3(0, 1.5, 0)) + front * 2.5f - right * 1.5f - up * 0.5f;
		anchorPos += front * lArmExtend + right * lArmExtend;
		return anchorPos;
	}

	const glm::vec3 GetRShoulderAnchor(glm::vec3 right) {
		return GetHeadAnchor() + right;
	}

	const glm::vec3 GetLShoulderAnchor(glm::vec3 right) {
		return GetHeadAnchor() - right;
	}
};