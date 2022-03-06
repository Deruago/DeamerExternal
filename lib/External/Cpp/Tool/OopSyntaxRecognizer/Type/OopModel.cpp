#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/OopModel.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/FunctionArgument.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/FunctionObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/PropertyObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/Type.h"
#include <iostream>

deamer::external::cpp::tool::oopsyntaxrecognizer::OopModel::OopModel(
	std::vector<Type*> types_, std::vector<FunctionObject*> globalFunctions_,
	std::vector<Type*> allTypes_, std::vector<FunctionObject*> allFunctions_,
	std::vector<FunctionArgument*> allFunctionArguments_)
	: types(types_),
	  globalFunctions(globalFunctions_),
	  allTypes(allTypes_),
	  allFunctions(allFunctions_),
	  allFunctionArguments(allFunctionArguments_)
{
}

deamer::external::cpp::tool::oopsyntaxrecognizer::OopModel::~OopModel()
{
	for (auto* type : allTypes)
	{
		delete type;
	}
	for (auto* function : allFunctions)
	{
		delete function;
	}
	for (auto* functionArgument : allFunctionArguments)
	{
		delete functionArgument;
	}
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::Type*>
deamer::external::cpp::tool::oopsyntaxrecognizer::OopModel::GetTypes() const
{
	return types;
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::OopModel::Print()
{
	for (auto& type : types)
	{
		type->Print();
	}

	for (auto& function : globalFunctions)
	{
		function->Print();
	}
}
