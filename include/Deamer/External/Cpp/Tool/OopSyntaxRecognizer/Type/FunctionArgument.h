#ifndef DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_FUNCTIONARGUMENT_H
#define DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_FUNCTIONARGUMENT_H

#include <string>

namespace deamer::external::cpp::tool::oopsyntaxrecognizer
{
	struct Type;

	struct FunctionArgument
	{
		Type* type;
		std::string name;

		FunctionArgument(Type* type_ = nullptr, const std::string& name_ = "");

		void SetType(Type* type_);

		void SetName(const std::string& name_);

		std::string GetName() const;

		Type* GetType() const;
	};

}

#endif // DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_FUNCTIONARGUMENT_H
