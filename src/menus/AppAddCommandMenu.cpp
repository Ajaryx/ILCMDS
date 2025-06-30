// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#include "PCH.hpp"
#include "menus/AppAddCommandMenu.hpp"
#include "core/Application.hpp"

using namespace ftxui;

AppAddCommandMenu::AppAddCommandMenu(Application* const app) : AppMenu(app)
{

}
AppAddCommandMenu::~AppAddCommandMenu()
{

}

void AppAddCommandMenu::BuildAndRun()
{
	//comp defines
	Component inputContainer;
	Component input_CMD_NameBar;
	Component input_CMD_StrBar;
	Component input_CMD_Bar;
	Component input_CMD_Desc_Bar;
	Component btn = Button("Confirm", []() {});
	
	//build
	Component inputBars = BuildUserInputsLayout(inputContainer, input_CMD_NameBar, input_CMD_StrBar, input_CMD_Bar, input_CMD_Desc_Bar);


	Component combinedContainer = Container::Vertical({ inputContainer });

	Component combinedLayout = Renderer(combinedContainer, [&]() 
		{
			return hbox({

				vbox({
					vbox({paragraph(PROJ_LOGO) | color(Color::Green)}) | border,
					filler(),
					hbox({text("Add Command Menu") | underlined | bold | border | hcenter})}) ,
					filler(),
					separator(),
					filler(),
				vbox({
				inputBars->Render() | border,
					filler(),
					btn->Render(),
				}),
				
			

				}) | flex;
		});


	GetApplication()->drawUI(combinedLayout);

}
ftxui::Component AppAddCommandMenu::BuildUserInputsLayout(
	ftxui::Component& container,
	ftxui::Component& NameBar,
	ftxui::Component& cmdStrBar,
	ftxui::Component& cmdType,
	ftxui::Component& cmdDescBar)
{
	//NameBarOption
	InputOption NameBarOpt;
	InputOption cmdStrOpt;
	InputOption cmdTypeOpt;
	InputOption cmdDescOpt;

	MakeInputBarOptions(
		NameBarOpt,
		cmdStrOpt,
		cmdTypeOpt,
		cmdDescOpt);

	
	NameBar = Input(NameBarOpt);
	cmdStrBar = Input(cmdStrOpt);
	cmdType = Input(cmdTypeOpt);
	cmdDescBar = Input(cmdDescOpt);


	container = Container::Vertical({ NameBar, cmdStrBar, cmdType, cmdDescBar });

	Component combinedInputLayout = Renderer(container, [&]()
		{
			return vbox
			({
				hbox({text("Type the command name (e.g. mkdir):") | underlined}),  filler() | size(HEIGHT, EQUAL, 1), NameBar->Render(),
				separator(),
				hbox({text("Type the command str (e.g. mkdir build):") | underlined}), filler() | size(HEIGHT, EQUAL, 1), cmdStrBar->Render(),
				separator(),
				hbox({text("Type the command type (e.g. Terminal, CMD):") | underlined}), filler() | size(HEIGHT, EQUAL, 1), cmdType->Render(),
				separator(),
				hbox({text("Type the command Desc (e.g. creates a directory):") | underlined}), filler() | size(HEIGHT, EQUAL, 1), cmdDescBar->Render(),
			});

		});


	return combinedInputLayout;
}

void AppAddCommandMenu::MakeInputBarOptions(
	ftxui::InputOption& NameOpt,
	ftxui::InputOption& cmdStrOpt,
	ftxui::InputOption& cmdTypeOpt,
	ftxui::InputOption& cmdDescBarOpt)
{
	
	NameOpt = InputOption::Default();
	cmdStrOpt = InputOption::Default();
	cmdTypeOpt = InputOption::Default();
	cmdDescBarOpt = InputOption::Default();

	//placeholder
	NameOpt.placeholder = "Command name";
	cmdStrOpt.placeholder = "Command string command";
	cmdTypeOpt.placeholder = "Command type";
	cmdDescBarOpt.placeholder = "Command Description";

	//enable/disable multilines
	NameOpt.multiline = false;
	cmdStrOpt.multiline = true;
	cmdTypeOpt.multiline = false;
	cmdDescBarOpt.multiline = true;


	//set strings
	NameOpt.content = &CMD_NameStr;
	cmdStrOpt.content = &CMD_Str_Str;
	cmdTypeOpt.content = &CMD_TypeStr;
	cmdDescBarOpt.content = &CMD_DescStr;
	
	//OnChange funcs
	NameOpt.on_change = [&]()
		{
			if (CMD_NameStr.length() > maxCharacterLenght)
			{
				CMD_NameStr.resize(maxCharacterLenght);
			}
		};
	cmdStrOpt.on_change = [&]()
		{
			if (CMD_Str_Str.length() > maxCharacterLenght)
			{
				CMD_Str_Str.resize(maxCharacterLenght);
			}
		};
	cmdTypeOpt.on_change = [&]()
		{
			if (CMD_TypeStr.length() > maxCharacterLenght)
			{
				CMD_TypeStr.resize(maxCharacterLenght);
			}
		};
	cmdDescBarOpt.on_change = [&]()
		{
			if (CMD_DescStr.length() > maxCharacterLenght)
			{
				CMD_DescStr.resize(maxCharacterLenght);
			}
		};


	//...

}
