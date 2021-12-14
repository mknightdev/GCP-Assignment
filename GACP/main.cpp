//#include "Enemy.h"

#include <myengine/myengine.h>
#include <myrenderer/myrenderer.h>

#include <iostream>
#include <fstream>
#include <chrono>

using namespace myengine;

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	// PBR Screen #1
	//std::shared_ptr<Entity> pbrEntity = core->addEntity();
	//std::shared_ptr<PBRScreen> pbrScreen = pbrEntity->addComponent<PBRScreen>();

	std::ofstream outputFile;
	outputFile.open("Blinn_Timetaken.csv");

	for (int i = 1; i <= 500; i++)
	{
		std::chrono::steady_clock::time_point time1 = std::chrono::high_resolution_clock::now();

		core->clear();

		// PBR Screen #1
		std::shared_ptr<Entity> pbrEntity = core->addEntity();
		std::shared_ptr<PBR2Screen> pbrScreen = pbrEntity->addComponent<PBR2Screen>();

		std::chrono::steady_clock::time_point time2 = std::chrono::high_resolution_clock::now();
		std::chrono::milliseconds milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time1);

		outputFile << i << "," << milliseconds.count() << std::endl;
	}

	outputFile.close();


	//std::shared_ptr<Entity> mrEntity = core->addEntity();
	//std::shared_ptr<MeshRenderer> mr = mrEntity->addComponent<MeshRenderer>();
	//mr->setMesh(core->getResourceManager()->load<Mesh>("../resources/models/grenade/grenade"));
	//mr->setTexture(core->getResourceManager()->load<Texture>("../resources/models/grenade/grenade_albedo"));

	//std::shared_ptr<Entity> ee = core->addEntity();
	//std::shared_ptr<Enemy> ec = ee->addComponent<Enemy>();

	// PBR stuff 
	//rowTwo(core);

	// TODO
	// Create an engine texture that creates a myrenderer::Texture simiilar to Mesh
	// In the initialise function, add .png, .bitmap, .jpeg, etc and try for each
		// Audio would have .ogg in initiliase
	// take out "using namespace myrenderer" to avoid conflicts

	core->start();

	return 0;
}