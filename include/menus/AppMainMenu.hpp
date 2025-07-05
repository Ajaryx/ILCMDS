// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#pragma once
#include "menus/AppMenu.hpp"


class AppMainMenu : public AppMenu
{
public:
	AppMainMenu();
	~AppMainMenu();

	
private:
	
	
	void Build() override;

	//Creates a Menu and handle Menu Event
	ftxui::Component CreateMenuLayout(ftxui::Component& menu);

	int m_MenuSelected = 0;

};