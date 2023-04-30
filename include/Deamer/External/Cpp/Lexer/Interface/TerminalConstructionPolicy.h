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

#ifndef DEAMER_EXTERNAL_LEXER_INTERFACE_TERMINALCONSTRUCTIONPOLICY_H
#define DEAMER_EXTERNAL_LEXER_INTERFACE_TERMINALCONSTRUCTIONPOLICY_H

namespace deamer::external::cpp::lexer
{
	enum class TerminalConstructionPolicy
	{
		// Standard terminal construction
		// Output contains only
		ignore_deleted_terminals,

		// Includes deleted terminals
		include_deleted_terminals,
	};
}

#endif // DEAMER_EXTERNAL_LEXER_INTERFACE_TERMINALCONSTRUCTIONPOLICY_H