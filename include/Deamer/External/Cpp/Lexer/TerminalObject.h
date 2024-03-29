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

#ifndef DEAMER_EXTERNAL_LEXER_TERMINALOBJECT_H
#define DEAMER_EXTERNAL_LEXER_TERMINALOBJECT_H

#include <iostream>
#include <string>
#include <utility>
#include <cstddef>

namespace deamer::external::cpp::lexer
{
	/*!	\class TerminalObject
	 *
	 *	\brief This class is used to contain data about parsed Terminals, in the lexer stage.
	 */
	class TerminalObject
	{
	public:
		const std::size_t Type;
		const std::string Value;
		const int LineNumber;
		const int ColumnNumber;

	public:
		TerminalObject(std::string value_, const int lineNumber_ = -1, const int columnNumber_ = -1, std::size_t type_ = 0)
			: Type(type_),
			  Value(std::move(value_)),
			  LineNumber(lineNumber_),
			  ColumnNumber(columnNumber_)
		{
		}

		~TerminalObject() = default;

		void Print() const
		{
			std::cout << "Value: " << Value << " Line number: " << LineNumber
					  << " ColumnNumber: " << ColumnNumber << "\n";
		}

		std::size_t GetType() const
		{
			return Type;
		}

		std::string GetValue() const
		{
			return Value;
		}

		int GetLineNumber() const
		{
			return LineNumber;
		}

		int GetColumnNumber() const
		{
			return ColumnNumber;
		}
	};
}

#endif // DEAMER_EXTERNAL_LEXER_TERMINALOBJECT_H
