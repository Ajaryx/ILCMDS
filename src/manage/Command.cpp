// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#include "PCH.hpp"
#include "manage/Command.hpp"

Command::Command(const std::string& cmdName, const std::string& commandStr, const std::string& type, const std::string& description)
{
	this->m_cmdName = cmdName;
	this->m_commandStr = commandStr;
	this->m_type = type;
	this->m_description = description;

}
Command::~Command()
{

}