#include "Scene.h"

int main()
{
	Scene* mainScene = new Scene(800, 600, "Project RvR");

	while(mainScene->isActive())
	{
		mainScene->update();
	}

	delete mainScene;

	return 0;
}