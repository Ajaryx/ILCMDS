// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#include "PCH.hpp"
#include "menus/AppStatusMenu.hpp"
#include "core/Application.hpp"

using namespace ftxui;

/*-----------------Status Menu Options--------------------*/
AppStatusMenuLayoutOption AppStatusMenuLayoutOption::Info(const std::string& headline,
	const std::string& description,
	const std::string& btnText)
{
	
	return AppStatusMenuLayoutOption();


}
AppStatusMenuLayoutOption AppStatusMenuLayoutOption::Warning(const std::string& headline,
	const std::string& description,
	const std::string& btnText)
{


	return AppStatusMenuLayoutOption();
}
AppStatusMenuLayoutOption AppStatusMenuLayoutOption::FatalError(const std::string& headline,
	const std::string& description,
	const std::string& btnText,
	const std::function<void()> on_click)
{
	return AppStatusMenuLayoutOption();

}
AppStatusMenuLayoutOption AppStatusMenuLayoutOption::Choose()
{
	return AppStatusMenuLayoutOption();
}
/*-------------------------------------------*/

AppStatusMenu::AppStatusMenu(Application* const app, const AppStatusMenuLayoutOption& layoutOption) : AppMenu(app)
{
	this->m_Option = layoutOption;
}
AppStatusMenu::~AppStatusMenu()
{

}
void AppStatusMenu::BuildAndRun()
{

}