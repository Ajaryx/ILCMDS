
// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#include "PCH.hpp"
#include "menus/AppMainMenu.hpp"

using namespace ftxui;

AppMainMenu::AppMainMenu(Application* const app) : AppMenu(app)
{
	
}

AppMainMenu::~AppMainMenu()
{
}
void AppMainMenu::BuildAndRun()
{
	Component menu = Menu(std::vector<std::string>(), &m_MenuSelected);
	Component menuComp = CreateMenuLayout(menu);

	Component container = Container::Vertical(
		{
			menu
		});


	Component combinedLayout = Renderer(container, [&]()
		{
			return vbox(
				{
					hbox({
						paragraph(logo)

					}) | border | hcenter,
					
					filler() | size(HEIGHT, GREATER_THAN, 5),

					vbox({
							menu->Render(),
						
						}),

					filler() | size(HEIGHT, GREATER_THAN, 5),
						text("version 0.1.0") | align_right

				}) | flex_grow;
		});


	GetApplication()->drawUI(combinedLayout);
}
Component AppMainMenu::CreateMenuLayout(Component& menu)
{
	MenuOption options;
	options.entries = std::vector<std::string>({"List Commands", "Add Commands"});
	
	menu = Menu(options);

	menu |= CatchEvent([&](Event evt)
		{
			if (evt == Event::Return)
			{
				switch (m_MenuSelected)
				{
					case 0:
						GetApplication()->BreakCurrentLoop();
						break;

					case 1:

						break;
				}
				
				return true;
			}
			return false;
		});

	Component menuLayout = Renderer(menu, [&]() {

		return vbox(
			{
				menu->Render()
			});
		});

	return menuLayout;
}
