// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#include "PCH.hpp"
#include "core/Application.hpp"
#include "menus/AppMainMenu.hpp"
#include "menus/AppAddCommandMenu.hpp"
#include "menus/AppStatusMenu.hpp"

/*std::array<AppMenu, 4>*/

//Main Menu : Index 0
//List Commands Menu : Index 1
//Add Command Menu : Index 2


using namespace ftxui;

Application::Application()
{
	m_appState = EAppState::E_MAIN_MENU;
	m_lastMenu = 0;
	m_app_Menus = std::array<AppMenu*, 3>();
}

void Application::InitMenus()
{
	//AppStatusMenu is not a "real" menu only an info menu, therefore do not put it in the menu list
	m_app_Menus[MAIN_MENU_INDEX] = new AppMainMenu();
	m_app_Menus[MAIN_MENU_INDEX]->Build();


	m_app_Menus[ADD_COMMAND_MENU_INDEX] = new AppAddCommandMenu();
	m_app_Menus[ADD_COMMAND_MENU_INDEX]->Build();


	SetAppState(EAppState::E_MAIN_MENU);
	
}
void Application::Run()
{
	m_Screen.Loop(Renderer(m_stateMenuLayout, [&] { return m_stateMenuLayout->Render(); }));
}
void Application::FORCE_SHUTDOWN()
{
	std::quick_exit(EXIT_FAILURE);
}
void Application::SetAppState(EAppState state)
{
	m_lastMenu = (uint8_t)m_appState;

	if (state != EAppState::E_LAST)
	m_appState = state;

	switch (state)
	{
		case EAppState::E_MAIN_MENU:
			m_stateMenuLayout = m_app_Menus[MAIN_MENU_INDEX]->GetLayout();
			break;

		case EAppState::E_ADD_COMMAND_MENU:
			m_stateMenuLayout = m_app_Menus[ADD_COMMAND_MENU_INDEX]->GetLayout();
			break;

		case EAppState::E_LAST:
			m_stateMenuLayout = m_app_Menus[m_lastMenu]->GetLayout();
			break;
	}
	Run();
	
}
void Application::ShowStatusMenu(AppStatusMenuLayoutBuilder& builder)
{
	std::unique_ptr<AppMenu> app = std::make_unique<AppStatusMenu>(builder);
	app->Build();
	m_stateMenuLayout = app->GetLayout();
	Run();
}