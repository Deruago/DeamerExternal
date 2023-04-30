/*
 * Copyright 2021 Thimo Bohmer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http ://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissionsand
 * limitations under the License.
 */
/*
 * Part of the Deamer External.
 * For more information go to: https://github.com/Deruago/DeamerExternal
 */

#ifndef DEAMER_EXTERNAL_PARSER_INTERFACE_PARSER_H
#define DEAMER_EXTERNAL_PARSER_INTERFACE_PARSER_H

#include "Deamer/External/Cpp/Ast/Tree.h"
#include "Deamer/External/Cpp/Parser/Interface/ASTConstructionPolicy.h"
#include <string>
#include <utility>

namespace deamer::external::cpp::parser
{
	class Parser
	{
	public:
		Parser() = default;
		virtual ~Parser() = default;

	public:
		virtual ast::Tree* Parse(const std::string& text) const
		{
			return Parse(text, ASTConstructionPolicy::ast);
		}

		virtual ast::Tree*
		Parse(const std::string& text,
			  ::deamer::external::cpp::parser::ASTConstructionPolicy constructionPolicy) const
		{
			throw std::logic_error(
				"Parser.Parse(const std::string&, "
				"::deamer::external::cpp::parser::ASTConstructionPolicy): Unimplemented function");
		}

		virtual ast::Tree* Parse(std::vector<const ::deamer::external::cpp::lexer::TerminalObject*>
									 terminalObjects) const
		{
			return Parse(std::move(terminalObjects), ASTConstructionPolicy::ast);
		}

		virtual ast::Tree*
		Parse(std::vector<const ::deamer::external::cpp::lexer::TerminalObject*> terminalObjects,
			  ::deamer::external::cpp::parser::ASTConstructionPolicy constructionPolicy) const
		{
			throw std::logic_error(
				"Parser.Parse(std::vector<const lexer::TerminalObject*>, "
				"::deamer::external::cpp::parser::ASTConstructionPolicy): Unimplemented function");
		}
	};
}

#endif // DEAMER_EXTERNAL_PARSER_INTERFACE_PARSER_H
