// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#include "PCH.hpp"
#include "core/Application.hpp"
#include "menus/AppMainMenu.hpp"

using namespace ftxui;
Application::Application()
{
	
}

Application::~Application()
{
}
void Application::Run()
{
	AppMenu* menu = new AppMainMenu(this);
	menu->BuildAndRun();
	delete menu;
	menu = nullptr;
}
void Application::drawUI(Component& comp)
{
	m_Screen.Loop(comp);
}
void Application::BreakCurrentLoop()
{
	m_Screen.Exit();
}
void Application::FORCE_SHUTDOWN()
{
	std::exit(EXIT_FAILURE);
}