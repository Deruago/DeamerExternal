#ifndef DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_OOPMODEL_H
#define DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_OOPMODEL_H

#include <vector>

namespace deamer::external::cpp::tool::oopsyntaxrecognizer
{
	struct FunctionObject;
	struct PropertyObject;
	struct Type;
	struct FunctionArgument;

	struct OopModel
	{
		std::vector<Type*> types;
		std::vector<FunctionObject*> globalFunctions;
		std::vector<PropertyObject*> globalProperties;

		std::vector<Type*> allTypes;
		std::vector<FunctionObject*> allFunctions;
		std::vector<FunctionArgument*> allFunctionArguments;

		OopModel(std::vector<Type*> types_, std::vector<FunctionObject*> globalFunctions_,
				 std::vector<Type*> allTypes_, std::vector<FunctionObject*> allFunctions_,
				 std::vector<FunctionArgument*> allFunctionArguments_);

		OopModel(OopModel&) = delete;
		OopModel& operator=(OopModel&) = delete;

		~OopModel();

		std::vector<Type*> GetTypes() const;

		void Print();
	};
}

#endif // DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_OOPMODEL_H
