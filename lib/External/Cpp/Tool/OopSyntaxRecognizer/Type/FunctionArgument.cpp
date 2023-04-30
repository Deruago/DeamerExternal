#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/FunctionArgument.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/Type.h"

deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionArgument::FunctionArgument(Type* type_,
	const std::string& name_): type(type_),
	                           name(name_)
{
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionArgument::SetType(Type* type_)
{
	type = type_;
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionArgument::SetName(const std::string& name_)
{
	name = name_;
}

std::string deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionArgument::GetName() const
{
	return name;
}

deamer::external::cpp::tool::oopsyntaxrecognizer::Type* deamer::external::cpp::tool::oopsyntaxrecognizer::
FunctionArgument::GetType() const
{
	return type;
}
