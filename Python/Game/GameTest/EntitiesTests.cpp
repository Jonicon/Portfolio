#include "stdafx.h"
#include "CppUnitTest.h"

#include "Entity.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "GraphicsComponent.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameTest
{		
	TEST_CLASS(EntitiesTest)
	{
	public:		
		TEST_METHOD(EntityInitTest)
		{
			auto e = new Entity( new InputComponent(), new PhysicsComponent(), new GraphicsComponent( SDL_LoadBMP("player.bmp") ) );
			Assert::IsNotNull( e );
			Assert::AreEqual( e->getX(), 0 );
			Assert::AreEqual( e->getY(), 0 );
		}

	};
}