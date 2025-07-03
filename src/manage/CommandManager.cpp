// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#include "PCH.hpp"
#include "manage/CommandManager.hpp"
#include "manage/Command.hpp"
#include "menus/AppStatusMenu.hpp"
#include "core/Application.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;


/*-----------------------------------------------------------------*/

static void to_json(json& j, const Command& command)
{
	j = json{ {"commandName", command.Get_CMD_Name()},
		{"command String", command.Get_CMD_Str()},
		{"command Type", command.Get_CMD_Type()},
		{"command Description", command.Get_CMD_Description()}
	
	};
}
static void from_json(const json& j, Command& command)
{
	j.at("commandName").get_to(command.m_cmdName);
	j.at("command String").get_to(command.m_commandStr);
	j.at("command Type").get_to(command.m_commandType);
	j.at("command Description").get_to(command.m_description);

}

/*-----------------------------------------------------------------*/

CommandManager::CommandManager()
{
	//msg log for creating new dat file for the user?
	m_path = fs::path(fs::current_path() / "data.dat").string();
}
CommandManager::~CommandManager()
{

}
bool CommandManager::Init()
{
	return LoadAllCommands();
}
bool CommandManager::LoadAllCommands()
{

	std::ifstream file;
	file.exceptions(std::ios_base::failbit | std::ios_base::badbit);
	try
	{
		file.open(m_path + "fe");
	}
	catch (const std::ios_base::failure& exc)
	{
		AppMenu* appMenu = new AppStatusMenu(&Application::GetInstance(), AppStatusMenuLayoutBuilder::FatalError("FATAL_FILE_LOAD_ERROR", "FILE STREAM ERROR: " +
			std::string(std::strerror(errno)) +
			R"(
			The program cannot continue running because the command save file is missing. 
			Please make sure you haven't deleted the file while the program was running. 
			You can resolve this issue by restarting the program.)" + "\nError code: " + std::to_string(errno)
			
			, [&]() { Application::GetInstance().FORCE_SHUTDOWN(); }));

		appMenu->BuildAndRun();

		delete appMenu;
		appMenu = nullptr;

		return false;
	}
	json j = json::parse(file);
	
	for (const auto& item : j)
	{
		m_v_commands.push_back(new Command(item.get<Command>()));
	}

	return true;
}
void CommandManager::Add(const std::string& cmdName,
	const std::string& commandStr,
	const std::string& type,
	const std::string& description)
{

	if (cmdName.empty() ||
		commandStr.empty() ||
		type.empty() ||
		description.empty())
	{
		return;
	}
	m_v_commands.push_back(new Command(cmdName, commandStr, type, description));

	SaveAllCommands();

}

void CommandManager::SaveAllCommands()
{
	std::ofstream file(m_path);
	file.exceptions(std::ios_base::failbit | std::ios_base::badbit);

	
	

	json j = json::array();

	for (const auto& item : m_v_commands)
	{
		j.push_back(*item);
	}
	
	file << j.dump(4);

	file.close();

	

}
