// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#pragma once

class Command
{
public:
	Command(const std::string& cmdName, const std::string& commandStr, const std::string& m_commandType, const std::string& description);
	~Command();
	Command() = default;

	inline std::string Get_CMD_Name() const
	{
		return m_cmdName;
	}
	inline std::string Get_CMD_Str() const
	{
		return m_commandStr;
	}
	inline std::string Get_CMD_Type() const
	{
		return m_commandType;
	}
	inline std::string Get_CMD_Description() const
	{
		return m_description;
	}
	

	std::string m_cmdName;
	std::string m_commandStr;
	std::string m_commandType;
	std::string m_description;


	

};