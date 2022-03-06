#ifndef DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_FUNCTIONOBJECT_H
#define DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_FUNCTIONOBJECT_H

#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/Type.h"
#include <vector>

namespace deamer::external::cpp::tool::oopsyntaxrecognizer
{
	struct FunctionArgument;

	struct FunctionObject
	{
		std::string name;
		Type* returnType;
		std::vector<FunctionArgument*> arguments;

		FunctionObject(const std::string& name_ = "", Type* returnType_ = nullptr,
					   std::vector<FunctionArgument*> arguments_ = {});

		void SetName(const std::string& name_);

		void SetReturnType(Type* returnType_);

		void AddArgument(FunctionArgument* argument);

		std::string GetName() const;

		Type* GetReturnType() const;

		std::vector<FunctionArgument*> GetFunctionArguments() const;

		void Print();
	};

}

#endif // DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_FUNCTIONOBJECT_H
