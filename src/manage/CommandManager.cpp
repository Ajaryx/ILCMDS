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
using namespace ftxui;

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
	m_path = fs::path(fs::current_path() / DEFAULT_DATA_FILE_NAME).string();
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
	
	//Create data file if not created	
	if (!file)
	{
		Application::GetInstance().ShowStatusMenu(AppStatusMenuLayoutBuilder::Info("INFO", R"(It looks like you're running the program for the first time. 
		The JSON data list is created for the commands. 
		(NOTE: DO NOT DELETE THE FILE WHILE THE PROGRAM IS RUNNING, AND DO NOT OPEN THE FILE WHILE THE PROGRAM IS RUNNING.))" + std::string("\nPATH: " + m_path)));

		
		//nothing to read
		CreateDataFile();

		return false;
	}
	
	
	//return true cuz its no error
	if (IsDataFileEmpty(file))
	{
		return true;
	}
	json j;
	//parse error handling
	try
	{
		j = json::parse(file);
	}
	catch (json::exception& exc)
	{
		
		Application::GetInstance().ShowStatusMenu(AppStatusMenuLayoutBuilder::Choose("JSON_PARSE_ERROR",
			std::string("ERROR: " + std::string(exc.what())) + R"(
		File could not be converted please make sure that you have not made any changes to the file.
		Do you want to continue? (Your saved commands will not be listed and will be overwritten))"
			, [&]() { CreateDataFile(); Application::GetInstance().SetAppState(EAppState::E_LAST);  }, [&]() { Application::GetInstance().FORCE_SHUTDOWN(); }, Color::Red1));

		

		return false;
	}

	//fill vector with all saved Commands
	for (const auto& item : j)
	{
		m_v_commands.push_back(new Command(item.get<Command>()));
	}

	return true;
}

bool CommandManager::IsDataFileEmpty(std::ifstream& file) const
{
	file.seekg(0, std::ios_base::end);
	std::streampos pos = file.tellg();
	file.seekg(std::ios_base::beg);

	return pos <= 0;
}

bool CommandManager::CreateDataFile()
{
	std::ofstream file; 
	file.exceptions(std::ios_base::failbit | std::ios_base::badbit);
	try 
	{
		file.open(m_path);
	}
	//program cannot create file... [ABORT]
	catch(const std::ios_base::failure& exc)
	{
		Application::GetInstance().ShowStatusMenu(AppStatusMenuLayoutBuilder::FatalError("CANNOT_CREATE_FILE",
			std::string("ERROR: " + std::string(exc.what())) + std::string("\n") + strerror(errno) + "\n" +
			R"(THE PROGRAM HAS NO RIGHTS TO CREATE THE FILE!)" + "\nPATH: " + m_path
			+ "\nPROGRAM CANNOT CONTINUE [ABORT]" + "\nERROR CODE: " + std::to_string(errno),
			[&]() { Application::GetInstance().FORCE_SHUTDOWN(); }));
		
	
		return false;
	}

	return true;


}
bool CommandManager::Add(const std::string& cmdName,
	const std::string& commandStr,
	const std::string& type,
	const std::string& description)
{
	//Checking for empty fields
	if (cmdName.empty() ||
		commandStr.empty() ||
		type.empty() ||
		description.empty())
	{
		Application::GetInstance().ShowStatusMenu(AppStatusMenuLayoutBuilder::Info("EMPTY_INPUT",
			R"(You have not filled out all the information required to create this command. 
		Please make sure you have filled out everything and try again.)"));
	

		return false;
	}

	m_v_commands.push_back(new Command(cmdName, commandStr, type, description));

	if(SaveAllCommands())
	Application::GetInstance().ShowStatusMenu(AppStatusMenuLayoutBuilder::Info("EMPTY_INPUT",
		"Command created successfully"));
	
	return true;
}

bool CommandManager::SaveAllCommands()
{
	std::ofstream file;
	file.exceptions(std::ios_base::failbit | std::ios_base::badbit);

	try
	{
		file.open(m_path);
	}
	catch(const std::ios_base::failure& exc)
	{
		Application::GetInstance().ShowStatusMenu(AppStatusMenuLayoutBuilder::Warning("CANNOT_SAVE_COMMAND",
		std::string("ERROR: " + std::string(exc.what())) + R"(
		program has no rights to write to the file)" + "\nPATH: " + m_path + 
			"\nERROR CODE: " + std::to_string(errno)));
		

		return false;
	}

	json j = json::array();

	for (const auto& item : m_v_commands)
	{
		j.push_back(*item);
	}
	
	file << j.dump(4);

	file.close();
}
