// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#include "PCH.hpp"
#include "menus/AppStatusMenu.hpp"

using namespace ftxui;

/*-----------------Status Menu Options--------------------*/
AppStatusMenuLayoutBuilder AppStatusMenuLayoutBuilder::Info(const std::string& headline,
	const std::string& description,
	std::function<void()> on_click,
	ftxui::Color overallColor)
{

	Component btn = Button("OK", on_click);


	AppStatusMenuLayoutBuilder builder;


	builder.headline = headline;
	builder.description = description;


	builder.layout = Renderer(btn, [=]()
		{
			return vbox({
				
				text(builder.headline) | underlined| bold | color(overallColor) | center,
				filler() | size(HEIGHT, EQUAL, 2),

				paragraphAlignCenter(builder.description) | borderHeavy | color(overallColor) | hcenter,
				filler() | size(HEIGHT, EQUAL, 2),
				btn->Render() | size(HEIGHT, EQUAL, 3),
				
				});

		});
	
		return builder;
}
AppStatusMenuLayoutBuilder AppStatusMenuLayoutBuilder::Warning(const std::string& headline,
	const std::string& description,
	std::function<void()> on_click,
	ftxui::Color overallColor)
{

	Component btn = Button("OK", on_click);


	AppStatusMenuLayoutBuilder builder;


	builder.headline = headline;
	builder.description = description;


	builder.layout = Renderer(btn, [=]()
		{
			return vbox({

				text(builder.headline) | underlined | bold | center,
				filler() | size(HEIGHT, EQUAL, 1),
				text("WARNING") | underlined | color(overallColor) | center,
				filler() | size(HEIGHT, EQUAL, 2),

				paragraphAlignCenter(builder.description) | borderHeavy | color(overallColor) | hcenter,
				filler() | size(HEIGHT, EQUAL, 2),
				btn->Render() | size(HEIGHT, EQUAL, 3),

				});

		});

	return builder;
}
AppStatusMenuLayoutBuilder AppStatusMenuLayoutBuilder::FatalError(const std::string& headline,
	const std::string& description,

	const std::function<void()> on_click,
	ftxui::Color overallColor)
{
	ButtonOption opt = ButtonOption::Border();

	Component btn = Button("OK", on_click);


	AppStatusMenuLayoutBuilder builder;


	builder.headline = headline;
	builder.description = description;


	builder.layout = Renderer(btn, [=]()
		{
			return vbox({

				text(builder.headline) | underlined | bold | center,
				filler() | size(HEIGHT, EQUAL, 1),
				text("FATAL ERROR") | underlined | color(overallColor) | center,
				filler() | size(HEIGHT, EQUAL, 2),

				paragraphAlignCenter(builder.description) | borderHeavy | color(overallColor) | hcenter,
				filler() | size(HEIGHT, EQUAL, 2),
				btn->Render() | size(HEIGHT, EQUAL, 3),

				});

		});

	return builder;
}
AppStatusMenuLayoutBuilder AppStatusMenuLayoutBuilder::Choose(const std::string& headline,
	const std::string& description,
	std::function<void()> on_click_Yes,
	std::function<void()> on_click_No,
	ftxui::Color overallColor)
{

	Component btnYes = Button("OK", on_click_Yes);
	Component btnNo = Button("NO", on_click_No);

	AppStatusMenuLayoutBuilder builder;

	builder.headline = headline;
	builder.description = description;

	Component btnCont = Container::Vertical({ btnYes, btnNo });

	builder.layout = Renderer(btnCont, [=]()
		{
			return vbox({

				text(builder.headline) | underlined | bold | color(overallColor) |center,
				filler() | size(HEIGHT, EQUAL, 1),
				text("CHOOSE AN OPTION") | underlined | center,
				filler() | size(HEIGHT, EQUAL, 2),

				paragraphAlignCenter(builder.description) | borderHeavy | color(overallColor) | hcenter,
				filler() | size(HEIGHT, EQUAL, 2),
				btnYes->Render() | size(HEIGHT, EQUAL, 3),
				filler() | size(HEIGHT, EQUAL, 1),
				btnNo->Render() | size(HEIGHT, EQUAL, 4),

				});

		});

	return builder;
}
/*-------------------------------------------*/

AppStatusMenu::AppStatusMenu(const AppStatusMenuLayoutBuilder& layoutOption)
{
	this->m_Option = layoutOption;
}
AppStatusMenu::~AppStatusMenu()
{

}
void AppStatusMenu::BuildAndRun()
{
	Application::GetInstance().drawUI(m_Option.layout);
}