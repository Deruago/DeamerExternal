#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/PropertyObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/Type.h"

deamer::external::cpp::tool::oopsyntaxrecognizer::PropertyObject::PropertyObject(
	Type* type_, const std::string& name_)
	: type(type_),
	  name(name_)
{
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::PropertyObject::SetName(
	const std::string& name_)
{
	name = name_;
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::PropertyObject::SetType(Type* type_)
{
	type = type_;
}

deamer::external::cpp::tool::oopsyntaxrecognizer::Type*
deamer::external::cpp::tool::oopsyntaxrecognizer::PropertyObject::GetType() const
{
	return type;
}

std::string deamer::external::cpp::tool::oopsyntaxrecognizer::PropertyObject::GetName() const
{
	return name;
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::PropertyObject::Print()
{
}
