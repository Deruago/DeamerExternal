#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/FunctionObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/FunctionArgument.h"
#include <iostream>

deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject::FunctionObject(
	const std::string& name_, Type* returnType_, std::vector<FunctionArgument*> arguments_)
	: name(name_),
	  returnType(returnType_),
	  arguments(arguments_)
{
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject::SetName(
	const std::string& name_)
{
	name = name_;
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject::SetReturnType(
	Type* returnType_)
{
	returnType = returnType_;
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject::AddArgument(
	FunctionArgument* argument)
{
	arguments.push_back(argument);
}

std::string deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject::GetName() const
{
	return name;
}

deamer::external::cpp::tool::oopsyntaxrecognizer::Type*
deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject ::GetReturnType() const
{
	return returnType;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionArgument*>
deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject::GetFunctionArguments() const
{
	return arguments;
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject::Print()
{
	std::cout << "Global Function: " << GetName() << " " << GetReturnType()->GetTypeName()
			  << " Args(";
	for (const auto& argument : GetFunctionArguments())
	{
		std::cout << argument->GetType()->GetTypeName() << " " << argument->GetName();
		std::cout << ", ";
	}
	std::cout << ")\n";
}
