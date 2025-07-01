// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#include "PCH.hpp"
#include "manage/CommandManager.hpp"
#include "manage/Command.hpp"

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
void from_json(const json& j, Command& command)
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

	std::ifstream file(m_path);

	if (!file)
	{
		//LOG: file doesnt exists or the program started the first time
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
	if(!file)
	{
		//LOG file couldnt overwritten or created
		return;
	}

	json j = json::array();

	for (const auto& item : m_v_commands)
	{
		j.push_back(*item);
	}
	
	file << j.dump(4);

	file.close();

	

}
