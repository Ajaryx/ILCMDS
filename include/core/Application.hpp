// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#pragma once


/*-----------------------------------------*/
constexpr uint8_t MAIN_MENU_INDEX = 0;
constexpr uint8_t LIST_COMMAND_MENU_INDEX = 1;
constexpr uint8_t ADD_COMMAND_MENU_INDEX = 2;
constexpr uint8_t APP_STATUS_MENU_INDEX = 3;
/*-----------------------------------------*/

//IMPORTANT: the index of the EAppState members should have exactly the same index as above with constexpr
enum class EAppState : uint8_t
{
	E_MAIN_MENU = MAIN_MENU_INDEX,
	E_LIST_COMMAND_MENU = LIST_COMMAND_MENU_INDEX,
	E_ADD_COMMAND_MENU = ADD_COMMAND_MENU_INDEX,


	/*---------------------*/
	E_LAST
};
/*--------------------------------------*/
class Application
{
public:
	
	Application(const Application&) = delete;
	
	static Application& GetInstance()
	{
		static Application instance;
		return instance;
	}

	 void InitMenus();

	/*the entire app WILL be closed*/
	void FORCE_SHUTDOWN();
	void SetAppState(EAppState state);

	void Run();
	void ShowStatusMenu(struct AppStatusMenuLayoutBuilder& builder);
private:


	void BreakCurrentLoop();
	ftxui::ScreenInteractive m_Screen = ftxui::ScreenInteractive::TerminalOutput();

	Application();
	
	ftxui::Component m_stateMenuLayout = nullptr;
	EAppState m_appState;

	std::array<class AppMenu*, 3> m_app_Menus;
	uint8_t m_lastMenu;
};