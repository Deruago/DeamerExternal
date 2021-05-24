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

#ifndef DEAMER_EXTERNAL_CPP_AST_TEMPLATENODEBASE_H
#define DEAMER_EXTERNAL_CPP_AST_TEMPLATENODEBASE_H

#include "Deamer/External/Cpp/Ast/Node.h"

namespace deamer::external::cpp::ast
{
	template<typename LanguageBaseNode, typename Derived>
	class TemplateNodeBase : public Node
	{
	public:
		TemplateNodeBase() = default;

		TemplateNodeBase(NodeInformation information_, std::vector<Node*> nodes_ = {},
						 std::vector<size_t> baseValues_ = {})
			: Node(information_, nodes_, baseValues_)
		{
		}

		~TemplateNodeBase() override = default;

	public:
	};
}

#endif // DEAMER_EXTERNAL_CPP_AST_TEMPLATENODEBASE_H
