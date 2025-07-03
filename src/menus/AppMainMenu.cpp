
// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#include "PCH.hpp"
#include "menus/AppMainMenu.hpp"
#include "menus/AppAddCommandMenu.hpp"
#include "core/Application.hpp"

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

	Component container = Container::Vertical({ menu });


	Component combinedLayout = Renderer(container, [&]()
		{
			return vbox(
				{

					vbox({
						hbox({text("Main Menu") | underlined | bold | borderHeavy}),
						vbox({paragraph(PROJ_LOGO) | color(Color::Green) | border | hcenter})}),
					filler() | size(HEIGHT, EQUAL, 2),
					separator(),
					filler() | size(HEIGHT, EQUAL, 2),
					
					menu->Render(),
					filler() | size(HEIGHT, EQUAL, 8),
					
					hbox({text("Arrow keys left right or tab to navigate. Enter to confirm") | borderDashed, filler(), 
						text(PROJ_VERSION) | borderDashed | color(Color::Grey27) | align_right})
					
				});
		});

	GetApplication()->drawUI(combinedLayout);
}
#include "menus/AppStatusMenu.hpp"
Component AppMainMenu::CreateMenuLayout(Component& menu)
{
	auto entries = std::vector<std::string>({ "List Commands", "Add Commands", "Edit Commands", "[MORE OPTIONS WILL COME]"});
	MenuOption menuOpt = MenuOption::HorizontalAnimated();
	

	menu = Menu(entries, &m_MenuSelected, menuOpt);
	
	
	menu |= CatchEvent([&](Event evt)
		{
			if (evt == Event::Return)
			{
				
				switch (m_MenuSelected)
				{
					//List Commands
					case 0:

					{
						
					}
						break;
						//Add Commands
					case 1:
					{
						AppMenu* appMenu = new AppAddCommandMenu(GetApplication());
						appMenu->BuildAndRun();
						delete appMenu;
						appMenu = nullptr;
					}
						
						break;
						//Edit Commands
					case 2:

						break;
				}
				

				return true;
			}
			return false;
		});

	Component menuLayout = Renderer(menu, [&]() {

		return vbox(
			{
				menu->Render(),
			});
		});

	return menuLayout;
}
