#include <SDL.h> 
#include <iostream>
#include <string>

#include "AudioManager.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "ScreenManager.h"
#include "GameObject.h"
#include "Animation.h"
#include "Game.h"
#include "Audio.h"
 
#include "GameStates.h"
#include "PauseState.h"
#include "RunState.h"

#include "MainMenuState.h"

Game::Game()
{
	


}


bool Game::Initialise(std::string GameName, int Width, int Height)
{
	//initialise game screen and background rendering color

	if (!TheScreen::Instance()->Initialize(GameName.c_str(), Width, Height, true))
	{
		std::cout << "Screen not initialised" << std::endl;
		return false;
	}

	TheScreen::Instance()->SetClearColor(100, 149, 237);
	
	//initialize audio && texture
	if (!TheAudio::Instance()->Initialize() || !TheTexture::Instance()->Initialize())
	{
		std::cout << "Audio not initialised" << std::endl;
		return false;
	}
		



	m_Gstates.push_back(new MainMenuState(nullptr));

	std::cout << "Initialisation succeded" << std::endl;

	return true;
}

void Game::Run()
{

	const Uint8* keys = nullptr;
	
	while (isRunning == true)
		{
			NOW = SDL_GetTicks();
			
			
			if (m_Gstates.front()->isAlive() && m_Gstates.front()->isActive())
			{
				
				//update screen by clearing SDL frame buffer
				TheScreen::Instance()->Update();

				//update input handling by listening for input events
				TheInput::Instance()->Update();
	
				//read keyboard state
				keys = TheInput::Instance()->GetKeyStates();
		
				
				m_Gstates.front()->update(DeltaTime);
				
				if (m_Gstates.size() > 1 && m_Gstates.at(0)->isAlive())
				{
					m_Gstates.at(1)->Draw();
				}
			
				m_Gstates.front()->Draw();
		
				//if game window's top right X is clicked flag game to end
				if (TheInput::Instance()->IsXClicked())
				{	
					for (size_t s = 0; s < m_Gstates.size(); s++)
						{

							m_Gstates[s]->isActive() = false;
							m_Gstates[s]->isAlive() = false;
						}
				}

				//if escape key is pressed flag game to end
				if (keys[SDL_SCANCODE_ESCAPE])
				{
					for (size_t s = 0; s < m_Gstates.size(); s++)
						{
							m_Gstates[s]->isActive() = false;
							m_Gstates[s]->isAlive() = false;
						}
				}
		
				//draw screen by swapping SDL frame buffer
				TheScreen::Instance()->Draw();

			}

			if (!m_Gstates.front()->isAlive())
			{
 				DeleteState();
			}


			if (m_Gstates.empty()) //if everything is deleted exit
				{
					isRunning = false;
				}

			LAST = SDL_GetTicks();
			DeltaTime = (LAST - NOW) / 1000;

			LAST = NOW = 0;
		}


}


void Game::ShutDown()
{
	TheTexture::Instance()->UnloadFromMemory(TheTexture::Instance()->TEXTURE_DATA, TheTexture::Instance()->ALL_DATA);

	//close down audio 
	TheAudio::Instance()->ShutDown();

	//close down game screen 
	TheScreen::Instance()->ShutDown();
}

void Game::AddTempState(GameStates * my_state)
{
	m_Gstates.push_front(my_state);
}

void Game::ChangeState(GameStates * my_state)
{
	m_Gstates.push_back(my_state);

	m_Gstates.front()->isActive() = false;
	m_Gstates.front()->isAlive() = false;
}

void Game::DeleteState()
{
	delete m_Gstates.front();
	m_Gstates.pop_front();
}
