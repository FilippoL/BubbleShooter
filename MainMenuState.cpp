#include "MainMenuState.h"
#include "GameStates.h"
#include "RunState.h"
#include "HighScoreState.h"
#include "Game.h"
#include "ArcadeMode.h"
#include "NormalMode.h"
#include "InstructionState.h"

MainMenuState::MainMenuState(GameStates* current) : GameStates(current)
{
	TheAudio::Instance()->LoadFromFile("Assets//Audio//Traccia_Darietto_intro_loop.ogg", TheAudio::Instance()->MUSIC_AUDIO, "MAINMENU_MUSIC");
	
	_settings.InitialiseSection("MAIN_MENU_TEXTURES");

	_isActive = _isAlive = true;

	(!TheTexture::Instance()->GetTexture("ANIMATED_LINE")) ?
		TheTexture::Instance()->LoadTextureFromFile(_settings.GetAlphabeticVariable("ANIMATED_LINE"), "ANIMATED_LINE"):0;


	background = new Background; 
	decoration = new Animation;

	background->Initialise("GUI_BACK"); //BACKGROUND WITH A GUI ELEMENT

	title.Initialise("TEXT",500, 150,glm::vec2((WIDTH/2 - 250),0),glm::vec3(250,50,0)); //TITLE 
	title.SetLabel("BUBBLE SHOOTER");


	mode.Initialise("TEXT",WIDTH/1.5, HEIGHT/6,glm::vec2(WIDTH/2 - ((WIDTH/1.5)/2), 250),glm::vec3(250,50,0)); //TITLE 
	_modes = "ARCADE MODE";
	mode.SetLabel(_modes);

	decoration->SetTexture("ANIMATED_LINE"); //this nneds to be changed in an object itself for GUI 
	decoration->SetAnimationVelocity(40.0f); 
	decoration->SetSpriteDimension(WIDTH/1.5, HEIGHT/6);
	decoration->SetTextureCell(0,0);
	decoration->SetTextureDimension(3, 5, 900/3, 1200/5);
	decoration->IsAnimationLooping() = true;

	background_music.SetAudio("MAINMENU_MUSIC", background_music.MUSIC_AUDIO);
	background_music.SetVolume(100);

	btn_PLAY.initialise(100,100, glm::vec2(WIDTH/2 - 50, 400),"PLAY"); //buttons
	btn_MODE.initialise(100,100, glm::vec2(WIDTH/2 - 50, 500), "MODE"); //buttons


	btn_HIGHSCORE.initialise(200, 200, glm::vec2(WIDTH/3 - 100, 400), "HIGHSCORE");//buttons
	btn_INSTRUCT.initialise(200, 200, glm::vec2(WIDTH/1.5 - 100, 400), "INSTRUCTIONS");//buttons

}


MainMenuState::~MainMenuState()
{
	delete background;

	TheAudio::Instance()->UnloadFromMemory( TheAudio::Instance()->MUSIC_AUDIO, TheAudio::Instance()->CUSTOM_AUDIO,"MAINMENU_MUSIC" ); //WONT NEED IN FUTURE

	delete decoration;
}

bool MainMenuState::update(double dt)
{
	btn_PLAY.update(dt);
	btn_MODE.update(dt);

	btn_HIGHSCORE.update(dt);
	btn_INSTRUCT.update(dt);

	background_music.Play(background_music.PLAY_ENDLESS);
	
	if (btn_MODE.Clicked())
	{
		(_modes == "ARCADE MODE") ? _modes = "NORMAL MODE" : _modes = "ARCADE MODE";
		mode.SetLabel(_modes);
	}

	if (btn_PLAY.Clicked())
	{
		if (_modes == "ARCADE MODE") {

			TheGame::Instance()->ChangeState(new ArcadeMode(this)); //menu state ususally happens to be the first
			_isActive = false; //there is no need to set any previous state to be deleted
			_isAlive = false; //just mark its own to be removed
		}
		else
		{
			TheGame::Instance()->ChangeState(new NormalMode(this)); //menu state ususally happens to be the first
			_isActive = false; //there is no need to set any previous state to be deleted
			_isAlive = false; //just mark its own to be removed
		}
	}


	if (btn_HIGHSCORE.Clicked())
	{
		TheGame::Instance()->AddTempState(new HighScoreState(this)); //menu state ususally happens to be the first
		_isActive = false; //there is no need to set any previous state to be deleted
		_isAlive = false; 
		//SOMETHING IS GONNA HAPPEN FOR OPTIONS
	}
	
	if (btn_INSTRUCT.Clicked())
	{
		TheGame::Instance()->AddTempState(new InstructionState(this)); //menu state ususally happens to be the first
		_isActive = false; //there is no need to set any previous state to be deleted
		_isAlive = false; 

		//SOMETHING IS GONNA HAPPEN FOR CREDITS
	}

	return false;
}

bool MainMenuState::Draw()
{
	background->draw();
	decoration->Draw(WIDTH/2 - ((WIDTH/1.5)/2), 250);
	title.draw();
	mode.draw();
	btn_PLAY.draw();
	btn_HIGHSCORE.draw();
	btn_INSTRUCT.draw();
	btn_MODE.draw();

	return false;
}

