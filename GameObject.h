#pragma once

class GameObject {
	Position x, y; // Game object position
	Size width, height // Game object size

public:
	GameObject();

	void OnCollision(GameObject collider);
	void OnUpdate();
	void OnDestroy();
	void OnStart();
};