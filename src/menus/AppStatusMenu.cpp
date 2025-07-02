// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#include "PCH.hpp"
#include "menus/AppStatusMenu.hpp"
#include "core/Application.hpp"

using namespace ftxui;

/*-----------------Status Menu Options--------------------*/
AppStatusMenuLayoutBuilder AppStatusMenuLayoutBuilder::Info(const std::string& headline,
	const std::string& description,
	std::function<void()> on_click)
{

	Component btn = Button("OK", on_click);


	AppStatusMenuLayoutBuilder builder;


	builder.headline = headline;
	builder.description = description;


	builder.layout = Renderer(btn, [=]()
		{
			return vbox({
				
				text(builder.headline) | underlined| bold | center,
				filler() | size(HEIGHT, EQUAL, 2),

				paragraphAlignCenter(builder.description) | borderHeavy | hcenter,
				filler() | size(HEIGHT, EQUAL, 2),
				btn->Render(),
				
				});

		});
	
		return builder;
}
AppStatusMenuLayoutBuilder AppStatusMenuLayoutBuilder::Warning(const std::string& headline,
	const std::string& description,
	std::function<void()> on_click)
{
	

	return AppStatusMenuLayoutBuilder();
}
AppStatusMenuLayoutBuilder AppStatusMenuLayoutBuilder::FatalError(const std::string& headline,
	const std::string& description,
	const std::function<void()> on_click)
{

	return AppStatusMenuLayoutBuilder();
}
AppStatusMenuLayoutBuilder AppStatusMenuLayoutBuilder::Choose(const std::string& headline,
	const std::string& description,
	std::function<void()> on_click_Yes,
	std::function<void()> on_click_No)
{
	return AppStatusMenuLayoutBuilder();
}
/*-------------------------------------------*/

AppStatusMenu::AppStatusMenu(Application* const app, const AppStatusMenuLayoutBuilder& layoutOption) : AppMenu(app)
{
	this->m_Option = layoutOption;
}
AppStatusMenu::~AppStatusMenu()
{

}
void AppStatusMenu::BuildAndRun()
{
	GetApplication()->drawUI(m_Option.layout);
}